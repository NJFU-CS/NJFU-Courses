#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
	char *s=(char*)malloc(100*sizeof(char));/*∑÷≈‰ƒ⁄¥Ê*/ 
	int i;
	gets(s);/* ‰»Î*/
	int alpha=0;
	int digit=0;
	int space=0;
	int other=0;
	for(i=0;s[i]!='\0';i++){
		if(isalpha(s[i])){
			alpha++;
		}
		if(isdigit(s[i])){
				digit++;
		}
		 if(isspace(s[i])){
			space++;
		}
				
	}
	printf("alpha = %d\n",alpha);
	printf("digit = %d\n",digit);
	printf("space = %d\n",space);
	printf("other = %d\n",i-alpha-digit-space);
}



