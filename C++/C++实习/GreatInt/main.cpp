#include <iostream>
#include "GreatInt.cpp"
#include <string>
using namespace std;

//类已经封装，直接使用即可
int main()
{
	string first;
	string second;
	string third;
	cout << "Please enter two nums:" << endl;

	cout << "the first: ";
	cin >> first;
	cout << "the second: ";
	cin >> second;
	GreatInt one(first);			//使用构造函数进行封装
	GreatInt two(second);

	cout << endl;
	cout << "the result of (first + second)" << endl;
	cout << one + two << endl;		//加法运算

	cout << endl;
	cout << "the result of (first - second)" << endl;
	cout << one - two << endl;		//减法运算

	cout << endl;
	cout << "factorial 100:" << endl;
	GreatInt three(third);
	cout << three.factorial(100);	//运用成员函数进行100的阶乘运算

	return 0;
}