/*设计一个FifoTable类表示环形队列，它有四个私有属性，分别为：
	int table[SIZE];   //存放队列数据的数组
	int tail;          //队列尾指针
	int head;          //队列头指针
	int max,min;       //队列元素的界，也就是如果加入队列的元素值大于max或者小于min，加入操作无法成功。
三个公有成员函数如下
FifoTable(int max,int min);   //结构函数，设置对象的max和min值。
bool AddElement(int d);       //向队列加入一个元素d，成功返回真，否则返回假。如果队列满了，则新的值无法加入
int GetElement();             //从队列头获取一个元素，并返回该元素值。如果队列为空，则返回NULLVALUE
常量NULLVALUE和SIZE值如下
const int NULLVALUE= 999999;
const int SIZE = 10;

该类的代码完成后，如下main()函数可以执行。
*/
#include<iostream>
using namespace std;
const int NULLVALUE= 999999;
const int SIZE = 10;

class FifoTable {
 private:
    int table[SIZE];   //存放队列数据的数组
	int tail;          //队列尾指针
	int head;          //队列头指针
	int max,min;       //队列元素的界，也就是如果加入队列的元素值大于max或者小于min，加入操作无法成功。
 public:
    FifoTable(int _max,int _min);   //结构函数，设置对象的max和min值。
    bool AddElement(int d);       //向队列加入一个元素d，成功返回真，否则返回假。如果队列满了，则新的值无法加入
    int GetElement() ;             //从队列头获取一个元素，并返回该元素值。如果队列为空，则返回NULLVALUE
};


FifoTable::FifoTable(int _max,int _min) : max( _max ) , min( _min ) , head(0) , tail(0) {}

inline bool FifoTable::AddElement(int d) { 
    if(d > max || d < min)
        return false;
    if((tail+1)%SIZE==head)
        //队列满
        return false;
    table[tail] = d;
    tail=(tail+1)%SIZE;

    return true;
}

inline int FifoTable::GetElement() {
    if(head == tail)
        return NULLVALUE;
    else {
        int result = table[head];
        head = (head+1)%SIZE;
        return result;
    }
}

int main()
{
	FifoTable ft(20,-2);
	int i;

	for(i = -2; i <= 23; i++)
		ft.AddElement(i);

	for(i = 0; i < 9; i++)
		cout << ft.GetElement() << ",";

	cout << ft.GetElement() << endl;
    return 0;
}
/*
执行的结果为：
-2,-1,0,1,2,3,4,5,6,999999
*/