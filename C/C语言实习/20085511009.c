#include<stdio.h>
int f(int n);
int main()
{
	int i;/*变量i*/ 
	 
	for(i=1;i<1000;i++){
		if(i==f(i)){		/*1000个数*/ 
			printf("%d\t",i);/*输出*/ 
		}
	}
}
int f(int n)	/*求出因数的和*/ 
{
	int i;
	int sum=0;
	for(i=1;i<n;i++){
		if(n%i==0){
			sum+=i;/*求和*/ 
		}
	}
	return sum;
}


