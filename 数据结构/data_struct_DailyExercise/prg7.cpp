/*设计一个函数
	int bracketmatch(char *str) 
该函数的功能判断由str字符串所给出的表达式里圆括号、方括号、花括号是否合法，也就是左右匹配。对其它字符不做任何处理。
(1+35))  不合法
[3]+{444}-[(333)]合法。
{1+[233}-]不合法
合法返回1，不合法返回0*/

#include<stdio.h>
int bracketmatch(char *str) {
	char c[100];
	int top = -1;
	int p=0;
	while(str[p]!='\0') {
		switch(str[p]) {
			case '(' : 
			case '[' :
			case '{' :
					c[++top] = str[p]; break;
			case ')' :
			case ']' :
			case '}' :
					if(top==-1) return 0;
					if(c[top]=='('&& str[p]==')' || c[top]=='['&& str[p]==']' || c[top]=='{'&& str[p]=='}') {
						top--;
					}else{
						return 0;
					}
					break;
			default : break;
		}
		p++;
	}
	if(top==-1)
		return 1;
	else return 0;
}
//如下的main函数执行后
int main(int argc, char* argv[])
{
	char *str="(1+5)*6 + ({3-5 + [5*9] +4}-6)";
	char *str1="(1+5)*6 + ({3-5 + [5*9] +4}-6)}"; 
	if(bracketmatch(str))
		printf("str bracket match OK!\n");
	else
		printf("str bracket match ERROR!\n");

	if(bracketmatch(str1))
		printf("str1 bracket match OK!\n");
	else
		printf("str1 bracket match ERROR!\n");

	return 0;
}
/*执行的结果为
str bracket match OK!
str1 bracket match ERROR!*/
