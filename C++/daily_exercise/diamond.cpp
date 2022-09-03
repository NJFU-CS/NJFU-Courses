/*设计一个函数
	void Drawdiamond(int n)
其功能是显示一个具有n行的实心菱形。这里n必须是一个奇数，且（3<=n<=21)
如 Drawdiamond(5)的显示结果为：
  *
 ***
*****
 ***
  *
该函数的实现代码只能有一个外循环语句，和一个内循环语句，不能多个循环并列。

有main函数：*/
#include<iostream>
using namespace std;
void Drawdiamond(int n);

int main()
{
	Drawdiamond(7);
	Drawdiamond(11);
	 
}

void Drawdiamond(int n)
{
	int i,j;
	int k = (n+1)/2;

	for(i = 1; i <= n;i++)
	{
		for(j = 1; j <= n; j++)
		{

			if(abs(j-k)< k - abs(i-k))
				cout << "*";
			else
				cout << " ";
		
		}
		cout << endl;
	}
}
