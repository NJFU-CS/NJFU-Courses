/*设计一个函数
	void merge(SeqList *LA, SeqList *LB, SeqList *LC) 
该函数的功能是将递减顺序表LA和LB和合并到递减顺序表LC中
其中SeqList结构如下：
typedef  struct{ 
    int  elem[maxsize]; 
    int  last;
}SeqList; 

如下的main函数执行后
int main(int argc, char* argv[])
{
	SeqList LA, LB, LC;
	int i;

	for(i = 0; i < 10;i++)
	{
		LA.elem[i] = 20-2*i;
	}
	LA.last = 9;

	for(i = 0; i < 8;i++)
	{
		LB.elem[i] = 24-3*i;
	}
	LB.last = 7;

	merge(&LA, &LB, &LC);
	
	for(i = 0; i <= LC.last ;i++)
	{
		printf("%d ", LC.elem[i]);
	}
	printf("\n");
	return 0;
}
执行的结果为
24 21 20 18 18 16 15 14 12 12 10 9 8 6 6 4 3 2 */
#include<iostream>
#define maxsize 20
using namespace std;

typedef  struct{ 
    int  elem[maxsize]; 
    int  last;
}SeqList; 

void merge(SeqList *LA, SeqList *LB, SeqList *LC) ;

int main(int argc, char* argv[])
{
	SeqList LA, LB, LC;
	int i;

	for(i = 0; i < 10;i++)
	{
		LA.elem[i] = 20-2*i;//20 18 16 14 .... 2
	}
	LA.last = 9;

	for(i = 0; i < 8;i++)
	{
		LB.elem[i] = 24-3*i;//24 21 18 ... 3
	}
	LB.last = 7;
	merge(&LA, &LB, &LC);
	
	for(i = 0; i <= LC.last ;i++)
	{
		printf("%d ", LC.elem[i]);
	}
	printf("\n");
	
	return 0;
}

void merge(SeqList *LA, SeqList *LB, SeqList *LC) {
	int i = 0;
	int j = 0;
	
	LC->last = -1;
	while(i<=LA->last && j<=LB->last) {
		if(LA->elem[i]>=LB->elem[j]) {
			
			LC->elem[++LC->last] = LA->elem[i];
			i++;
		}else{
			LC->elem[++LC->last] = LB->elem[j];
			j++;
		}
	}
	
	while(i<=LA->last) {
		LC->elem[++LC->last] = LA->elem[i];
		i++;
	}
	while(i<=LB->last) {
		LC->elem[++LC->last] = LB->elem[j];
		j++;
	}
		
}