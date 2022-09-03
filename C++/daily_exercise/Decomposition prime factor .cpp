/*设计一个函数，该函数的功能是将一个大于2的自然数分解素因数，并将这些素因数从小到大排列成一个数组，并返回素因数的个数。
该函数格式如下：
int factor(int n, int fac[]);
其中n为被分解的自然数，fac是存放素因数的数组。比如 n为20，则fac的值为{2,2,5}，返回值为3。

以下main函数执行后*/
#include<iostream>
#include<cmath>
using namespace std;
int factor(int n, int fac[]);
int main()
{
	int fac[32], i=0, n;

	n = factor(3600, fac);
	while(i < n)
	{
		cout << fac[i++] <<" ";
	}
	cout << endl;

}

int factor(int n, int fac[])
{
	int v = sqrt((double)n), k = 2,i=0;
	
	//k的循环值最多到根号n
	while( k <= v && k < n)
	{
		if(n%k==0)
		{
			n = n / k;
			fac[i++] = k;
		}
		else
			k++;
	}

	fac[i++] = n;
	return i;
}

