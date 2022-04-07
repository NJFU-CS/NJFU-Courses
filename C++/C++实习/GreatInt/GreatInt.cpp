#include "GreatInt.h"
#include <iostream>
#include <malloc.h>
#include <stack>
using namespace std;
GreatInt::GreatInt(string nums) {
	head = (Queue)malloc(sizeof(*head));
	head->i = -1;
	signal = false;						//正负号
	int length = nums.size();
	if (!length) {						//默认构造一个空的对象
		head->next = head;
		tail = head;
		signal = false;
		return;
	}

	if (nums[0] == '-')					//正负号
	{
		signal = true;
	}

	Queue current = head;
	while (length > 0 + signal) {
		string temp;
		if (length >= 4 + signal) {		//四位一组进行赋值
			temp = string(nums, length - 4, 4);
		}
		else {
			temp = string(nums, 0 + signal, length - signal);
		}
		Queue tempn = (Queue)malloc(sizeof(*tempn));
		tempn->i = stoi(temp);    
		current->next = tempn;    //链表的建立
		current = current->next;
		length -= 4;
	}
	current->next = head;
	tail = current;
}
GreatInt::~GreatInt() {
	Queue current = head;
	tail->next = NULL;
	while (current) {
		head = head->next;
		free(current);
		current = head;
	}    //链表的删除
}
GreatInt::GreatInt(const GreatInt& a) {
	head = (Queue)malloc(sizeof(*head));
	head->i = -1;
	Queue current = head;

	Queue pro = (a.head)->next;
	while (pro != a.head)				//将链表从头开始深copy
	{
		Queue temp = (Queue)malloc(sizeof(*temp));
		temp->i = pro->i;
		current->next = temp;
		current = current->next;
		pro = pro->next;
	}

	current->next = head;
	tail = current;

	signal = a.signal;
}
GreatInt GreatInt::operator+(const GreatInt& rhs) const
{
	string result;
	bool check = false;
	if (this->signal == rhs.signal) {		//同号直接相加，再判断正负号
		result = add(*this, rhs);
		if (this->signal == true)
			check = true;
	}
	else {
		if (this->signal == false)			//异号正的减去负数的绝对值
			result = min(*this, rhs);
		else
			result = min(rhs, *this);
	}

	if (check) {
		result = "-" + result;
	}

	return GreatInt(result);
}
GreatInt GreatInt::operator-(const GreatInt& rhs) const
{
	string result;
	bool check = false;
	if (this->signal == rhs.signal) {			//同号则两数绝对值相减并判断正负号
		result = min(*this, rhs);
		if (this->signal == true)
			check = true;
	}
	else {
		result = add(*this, rhs);				//异号则两数绝对值相加并判断正负号
		if (this->signal == true)
			check = true;
	}

	if (check) {
		if (result[0] == '-') {
			result.erase(0);
		}
		else {
			result = "-" + result;
		}
	}
	return GreatInt(result);
}
string int_string(int i) {						//数字转化为四位字符串
	if (i >= 1000)
		return to_string(i);
	else if (i >= 100)
		return "0" + to_string(i);
	else if (i >= 10)
		return "00" + to_string(i);
	else if (i >= 0)
		return "000" + to_string(i);
	else
		return "0";
}
string GreatInt::add(const GreatInt& lhs, const GreatInt& rhs) const {		//绝对值相加
	int add_sum;
	int sign = 0;

	string result;
	Queue currentl = (lhs.head)->next;
	Queue currentr = (rhs.head)->next;
	while (currentl != lhs.head && currentr != rhs.head)
	{
		add_sum = currentl->i + currentr->i + sign;
		if (add_sum >= 10000)
			sign = 1;
		else
			sign = 0;
		add_sum %= 10000;
		result = int_string(add_sum) + result;
		currentl = currentl->next;
		currentr = currentr->next;
	}

	Queue pro = (currentl == lhs.head) ? currentr : currentl;
	Queue headcheck = (currentl == lhs.head) ? rhs.head : lhs.head;

	while (pro != headcheck)
	{
		result = int_string((pro->i + sign) % 10000) + result;
		sign = (pro->i + sign) / 10000;
		pro = pro->next;
	}

	if (sign == 1) {
		result = to_string(1) + result;
	}

	return result;
}
string GreatInt::min(const GreatInt& lhs, const GreatInt& rhs) const {			//绝对值相减
	int check = lhs.compare(rhs);
	Queue currentl, currentr;
	Queue endl, endr;
	bool zf = 0;
	string result;
	if (check == 0) {
		return "0";
	}
	else if (check == 1) {
		currentl = lhs.head->next;
		endl = lhs.head;
		currentr = rhs.head->next;;
		endr = rhs.head;
	}
	else {
		currentl = rhs.head->next;
		endl = rhs.head;
		currentr = lhs.head->next;
		endr = lhs.head;
		zf = 1;
	}

	int min_sum;
	int sign = 0;
	while (currentl != endl && currentr != endr)
	{
		min_sum = currentl->i - currentr->i + sign;
		if (min_sum < 0) {
			sign = -1;
			min_sum += 10000;
		}
		else
			sign = 0;
		result = int_string(min_sum) + result;
		currentl = currentl->next;
		currentr = currentr->next;
	}

	while (currentl != endl)
	{
		if ((currentl->i + sign) < 0) {
			sign = -1;
			result = int_string(currentl->i + sign + 10000) + result;
		}
		else {
			result = int_string(currentl->i + sign) + result;
			sign = 0;
		}
		currentl = currentl->next;
	}

	if (zf == 1) {
		result = "-" + result;
	}

	return result;
}
int GreatInt::compare(const GreatInt& rhs) const {			//判断两数绝对值大小
	Queue currentl = this->head->next;
	Queue currentr = (rhs.head)->next;
	stack<short> store;

	while (currentl != this->head && currentr != rhs.head)
	{
		if (currentl->i == currentr->i) {
			store.push(0);
		}
		else if (currentl->i > currentr->i) {
			store.push(1);
		}
		else
			store.push(-1);
		currentl = currentl->next;
		currentr = currentr->next;
	}

	if (currentl != this->head) {
		return 1;
	}
	else if (currentr != rhs.head) {
		return -1;
	}

	while (1) {
		if (store.size() == 0)
			return 0;
		if (store.top() == 0)
		{
			store.pop();
		}
		else if (store.top() == 1) {
			return 1;
		}
		else if (store.top() == -1) {
			return -1;
		}
	}
}


ostream& operator<<(ostream& os, const GreatInt& rhs) {			//友好输出
	string result;
	Queue current = rhs.head->next;
	while (current != rhs.head) {
		if (current->next == rhs.head) {
			result = to_string(current->i) + result;
			break;
		}
		result = int_string(current->i) + result;
		current = current->next;
	}
	if (rhs.signal == true)
		result = "-" + result;
	os << result;
	return os;
}

void GreatInt::multiply(const int n) {							//乘法
	Queue current = this->head->next;
	int sign = 0;
	while (current != head) {
		current->i *= n;
		current->i += sign;
		sign = current->i / 10000;
		current->i %= 10000;
		if (current->next == head) {
			break;
		}
		else {
			current = current->next;
		}
	}
	while (sign > 0) {
		Queue temp = (Queue)malloc(sizeof(*temp));
		temp->i = sign % 10000;
		temp->next = head;
		current->next = temp;
		current = current->next;
		sign /= 10000;
	}
	tail = current;
	tail->next = head;
}

const GreatInt& GreatInt::factorial(int nums) {					//阶乘
	Queue current;
	if (head->next == head) {
		head->next = (Queue)malloc(sizeof(*head));
		head->next->next = head;
	}
	else {
		tail->next = NULL;
		current = head->next->next;
		while (current) {
			head = head->next;
			free(current);
			current = head;
		}
	}
	current = head->next;
	current->i = 1;
	current->next = head;
	for (int j = nums; j > 0; --j)
	{
		this->multiply(j);
	}
	return *this;
}



