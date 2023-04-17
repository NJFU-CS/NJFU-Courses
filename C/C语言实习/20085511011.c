#include<stdio.h>
int c(int i,int j);
int f(int a);/*求阶*/
int main()
{
	int n;
	int i,j;
	scanf("%d",&n);/*输入*/
	
	for(i=0;i<n+1;i++){
		for(j=0;j<i;j++){/*遍历*/
			printf("%d\t",c(i,j));
		}
		printf("\n");
	}
}
int c(int i,int j)/*求c*/
{
	/*求c j i-1*/
	/*=(i-1)!/j!*(i-1-j)！*/
	return f(i-1)/(f(j)*f(i-1-j));
	
} 
int f(int a)
{
	int i;
	int ret=1;
	for(i=1;i<=a;i++){
		ret*=i;/*求阶乘*/ 
	}
	return ret;
}

