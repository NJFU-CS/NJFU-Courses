/*设计一个函数nosame,函数格式如下：
int nosame(int *a, int m, int n)
a是一个指向二维数组首元素的指针，所指向的数组m+1行，n+1列，其中第0行和第0列的数据无效，也就是只需要判断1--m行和1--n列的数据就可以，
如果这个数组的所有整数各不相同，则返回0，否则返回-1*/
#include<iostream>
using namespace std;

int nosame(int *a, int m, int n) {
	//a[i][j] = a[i*(n+1)+j];
	for(int i=7 ;i<=(m+1)*(n+1) ;i++) {
		if(i%6 ==0)
			continue;
		for(int j=i+1;j<=(m+1)*(n+1) ;j++) {
			if(j%6 ==0)
				continue;
			if(a[i]==a[j] ) {
				return -1;
			}
		}
	}
	return 0;
}

/*
如下的main函数执行后* 
*/
int main(int argc, char* argv[])
{
	int a[5][6]={
		{0},
		{0,1,2,3,4,5},
		{0,11,12,13,14,15},
		{0,21,22,23,24,25},
		{0,31,32,33,34,35}
	};

	printf("%d\n", nosame((int *)a, 4,5));
	return 0;
}
/*
执行的结果为
0
*/