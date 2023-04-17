#include<stdio.h>

#include<stdlib.h>

int main()
{	
	int flag=0;      /*标志*/ 
	char *s=(char*)malloc(sizeof(char)*1000);
	gets(s);
	
	int i;
	int j;
	
	for(i=0;s[i]!='\0';i++){ /*遍历*/ 
		if(s[i-1]==s[i])
			continue;/*如果前一个等于这一个*/ 
		flag=0;
		for(j=i;s[i]==s[j];j++){
			flag++;				/*标志++*/ 
	 	}
		if(flag==1){
			putchar(s[i]);
		}else{
			putchar(s[i]);
			printf("%d",flag);
			
		}
	}
	
	
}
