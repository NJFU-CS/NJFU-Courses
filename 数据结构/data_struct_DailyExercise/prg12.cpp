/*设计一个函数
	Reqalphaarray(DIMLIMIT  arraylimit[], int alphaarray[], int n , int L)
其功能是求出n维数组的每一维的alpha值。也就是每一维中单个元素的字节数。
arraylimit数组，表示了数组每一维的上下限下标。L表示数组中，最基本元素的字节数。*/
#include<iostream>
#define N 100
using namespace std;

/*其中DIMLIMIT是如下结构体：*/
typedef struct{
	int c;           //下限
	int d;           //上限
} DIMLIMIT;

//获取arraylimit数据函数如下：
void Inputarraylimit(DIMLIMIT  arraylimit[], int *n)
{
	int i;

	printf("Please Input dimension number\n");
	scanf("%d", n);
	for(i = 1; i <= *n; i++)
	{
		scanf("%d %d", &(arraylimit[i].c), &(arraylimit[i].d));
	}

}

//显示alpha值程序如下
void Printalphaarray(int alphaarray[], int n)
{
	int i;

	for(i = 1; i <=n; i++)
	{
		printf("alphaarray[%d] = %d\n", i, alphaarray[i]);
	}
}

void Reqalphaarray(DIMLIMIT  arraylimit[], int alphaarray[], int n , int L) {
	for(int i=1;i<=n;i++) {
		alphaarray[i] = L;
		for(int j=i+1 ;j<=n;j++) {
			alphaarray[i] *= (arraylimit[j].d-arraylimit[j].c+1);
		}
	}
}
//当执行如下的main函数后
int main(int argc, char* argv[])
{
	int n;   //实际维数
	DIMLIMIT arraylimit[N];      //上下限数组
	int alphaarray[N];           //alphaarray
	int L =  4;

	Inputarraylimit(arraylimit, &n);
	Reqalphaarray(arraylimit, alphaarray, n , L);
	Printalphaarray(alphaarray, n);
	return 0;
}
/*
如果输入为
4 5 6 7 10 -1 23 3 9
执行的结果为
alphaarray[1] = 2800
alphaarray[2] = 700
alphaarray[3] = 28
alphaarray[4] = 4
*/