#include<stdio.h>
int GYS(int a,int b);
int main()
{
	int x,y; /*两个数 */ 
	int max,min;
	if(x>y){
		max=x;
		min=y;
	}else{
		max=y;
		min=x; 
	}/*求出最大最小*/ 
	scanf("%d %d",&max,&min);/*输入*/ 
	printf("GYS = %d, GBS = %d",GYS(max,min),max*min/GYS(max,min));/*输出*/ 
}
int GYS(int a,int b)
{
	
	if(a%b==0){  /*如果a%b=0；返回b*/ 
		return b;
	}else{
		return GYS(b,a%b);/*如果不是返回GBS（b,a/b）*/ 
	}
	
}

