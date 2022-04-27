/*设计一个函数
	double getaverage(List f, int *nodenum) 
已知f为一个不带头结点单向链表的头指针，链表结点数据结构如下所示，使用递归函数，求出所有结点中数值的平均数。	
nodenum为结点数的输出参数，	返回平均数，如果为空链表，则返回0。*/
#include<iostream>
using namespace std;
/*List的结构如下：*/
typedef struct T_Node{
	int d;
	struct T_Node *next;
} Node, *List;
//createlink函数如下：
void createlink(List *pf)
{
	int i;
	Node *p;

	*pf = (Node *)malloc(sizeof(Node));
	p = *pf;
	for(i = 1; i <= 99; i++)
	{
		p->d = i;
		p->next = (Node *)malloc(sizeof(Node));
		p = p->next;
	}
	p->d = 100;
	p->next  = NULL;
}

double getaverage(List f, int *nodenum) {
	if(f==nullptr) {
		*nodenum = 0;
		return 0.0;
	}
	
	double sum =  (f->d +  getaverage(f->next,nodenum)* *nodenum)/(*nodenum + 1);
	(*nodenum )++;

	return sum;
	
}

//如下的main函数执行后
int main(int argc, char* argv[])
{
	int n;
	List f;
	double a;
	createlink(&f);
	a = getaverage(f, &n);
	printf("%d  %lf\n",n, a);
	return 0;
 }
/*执行的结果为
100  50.500000
*/