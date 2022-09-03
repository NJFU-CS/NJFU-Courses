/*
设计一个Fraction类的结构，该类表示一个可以单步前进的广义整数。该类有以下两个私有属性
	int den; //单步前进的步进距离,也就是执行++运算后的增长量；
	int num; //当前的整数值
设计和实现该类相应的结构函数，print函数，并重载它的前缀++运算符号和后缀++运算符号。
该类完成后，如下main()函数可以执行。
void main()
{
 Fraction b(1,10),a(4,-8);

  (a++).print();
  a.print();

  a = b++;
  a.print();

  a = ++b;
  a.print();
  
}
执行的结果为
-8
-4
10
12
*/
#include<iostream>
using namespace std;

class Fraction
{
private:
    /* data */
    int den; //单步前进的步进距离,也就是执行++运算后的增长量；
	int num; //当前的整数值
public:
    Fraction(/* args */) :den(0),num(0) {}
    Fraction(int den,int num) : Fraction() {this->den=den,this->num=num;}
    void print() const { cout << num << endl;}
    Fraction& operator ++() {
        num+=den;
        return *this;
    }
    Fraction operator ++(int) {
        Fraction old = *this;
        ++ *this;
        return old;
    }
    ~Fraction() {}
};
int main()
{
     Fraction b(1,10),a(4,-8);

  (a++).print();
  a.print();

  a = b++;
  a.print();

  a = ++b;
  a.print();
}