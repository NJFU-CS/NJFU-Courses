/*设计一个表示平面上圆形状的circle类结构如下：*/
#include<iostream>
#include<cmath>
using namespace std;

class circle 
{
protected:
	double x,y;     //x和y表示为圆的圆心坐标 
	double r;       //r表示圆的半径
public:
	circle(double a,double b, double c);              //初始化圆的属性，a,b为圆心坐标，c为半径
	friend int relation(circle c1, circle c2);
};
/*
relation为该类的友元函数，它判断c1和c2两个圆的关系。
返回0表示两个圆完全重合；返回1表示两个圆没有交集，完全分开；返回2表示两个圆有重叠（相切也表示重叠）。
该类及其友元函数完成后，如下main()函数可以执行。*/

circle::circle(double a,double b, double c) : x(a) , y(b) , r(c) { }   
int relation(circle c1, circle c2) {
    if(c1.r==c2.r&&c1.x==c2.x&&c1.y==c2.y) return 0;
    else if(sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y)) > c1.r+c2.r) return 1;
    else return 2;
}


int main()
{
	circle c1(2,2,2);
	circle c2(29,1,2);
	circle c3(2,2,10);
	circle c4(0,0,0);
	circle c5(3,4,5);

	switch(relation(c1,c1))
	{
	case 0:
		cout << "overlapping" << endl;
		break;
	case 1:
		cout << "separate" << endl;
		break;
	case 2:
		cout << "intersect"<< endl;
	}

	switch(relation(c2, c3))
	{
	case 0:
		cout << "overlapping" << endl;
		break;
	case 1:
		cout << "separate" << endl;
		break;
	case 2:
		cout << "intersect"<< endl;
	}

	switch(relation(c4, c5))
	{
	case 0:
		cout << "overlapping" << endl;
		break;
	case 1:
		cout << "separate" << endl;
		break;
	case 2:
		cout << "intersect"<< endl;
	}

}
/*
执行的结果为
overlapping
separate
intersect
?
*/