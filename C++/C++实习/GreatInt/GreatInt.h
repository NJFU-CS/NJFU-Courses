#ifndef GreatInt_H
#define GreatInt_H
#include<string>
using namespace std;
typedef struct queue {
	int i;
	queue* next;
}*Queue;
class GreatInt {
public:
	GreatInt(string a);
	GreatInt(const GreatInt& b);//复制构造函数
	~GreatInt();//析构函数
	friend ostream& operator<<(ostream& os, const GreatInt& rhs);
	GreatInt operator+(const GreatInt& rhs) const;		//减法运算
	GreatInt operator-(const GreatInt& rhs) const;		//加法运算
	const GreatInt& factorial(int nums);
private:
	int compare(const GreatInt& rhs) const;			//进行比较
	string add(const GreatInt& lhs, const GreatInt& rhs) const;			//辅助加减法运算
	string min(const GreatInt& lhs, const GreatInt& rhs) const;
	void multiply(const int n);							//辅助阶乘运算
	bool signal;//代表正负，TRUE为-（负号），FALSE为+（正号）
	Queue head;
	Queue tail;
};

#endif
