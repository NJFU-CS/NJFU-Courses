/*设计一个stack类的结构，该类可以完成栈的功能。该栈的元素类型为int，最大深度为100。它能完成push和pop方法，功能分别为压栈和出栈。
如下main()函数可以执行。*/
#include<iostream>
#define Maxsize 100
#define stack Stack

using namespace std;
using ElementType = int;


class Stack {
 private:
    ElementType data[Maxsize];
    mutable int top = -1;
 public:
    Stack( ) = default;
    void push(ElementType X) {data[++top] = X;}
    ElementType pop() const {return data[top--];};
    ~Stack() = default;
};

int main()
{
	stack s1;
	int i;

	for(i = 1; i < 10;i++)
		s1.push(i);
	for(i = 1; i <6;i++)
		cout << s1.pop()<<",";
	s1.push(200);
	cout << s1.pop()<<endl;
 
    return 0;
}
/*执行的结果为
9,8,7,6,5,200
*/