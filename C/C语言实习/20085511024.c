#include<stdio.h>
#include<math.h>
int isprime(int n);
int main()
{
	int flag=0;/*标志*/ 
	int i;
	int j;
	int num=0;/*有多少个数*/ 
	//scanf("%d",&k);
	for(i=2;i<1000;i=i+2){
		
		for(j=2;j<1000;j++){
			if(isprime(j)&&isprime(i-j)){/*判断*/ 
				flag=1;
				num++;/*个数加1*/ 
				break;
			}else{
				flag=0;
				
			}
		}
	}
	if(num==499){ /*若果个数是499*/ 
		printf("yes");
		
	}else{
		printf("no");/*如果不是*/ 
	}
}
int isprime(int n)/*判断是不是素数*/ 
{
	int flag=1;
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			flag=0;
			break;
		}
	}
	return flag;
}
