/*设计一个函数
	int stackinoutright(char inoutop[]) 
假设以I和O分别表示入栈和出栈。栈的初态和终态均为空，入栈和出栈的操作序列可表示为I和O组成的一个字符串，即为inoutop字符串。
该函数就是用于判定这个序列的操作是否合法，如果序列合法则返回0，否则为非法序列，返回-1

如下的main函数执行后*/
#include<iostream>
using namespace std;

int stackinoutright(char inoutop[])  {
	int i_count=0;
	int o_count=0;
	int p=0;
	while(inoutop[p]!='\0') {
		if(inoutop[p]=='I') {
			i_count++;
		}
		if(inoutop[p]=='O') {
			o_count++;
		}
		if(o_count > i_count) {
			return -1;
		}
		p++;
	}
	if(i_count==o_count) {
		return 0;
	}else{
		return -1;
	}
	
}

int main(int argc, char* argv[])
{
	printf("%d    %d     %d\n", stackinoutright("IIOOIIO"), stackinoutright("IIIOOIOOIIIIOOOIOO"),  stackinoutright("IIIIIIIIOOIOOOO"));

	return 0;
}
/*
执行的结果为
-1    0     -1
*/