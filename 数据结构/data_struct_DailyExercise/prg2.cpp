/*设计一个函数
	void  Intersection (List La, List Lb)*/
#include<iostream>
using namespace std;
/*
其功能是求Lb和La的交集，且将交集的结果置于La中，其中La和Lb的元素均为严格递增有序排列，求交集后的La的元素也为严格递增有序排列。La和Lb是带头结点的单向链表。
其中List是如下结构体：*/

typedef struct T_Node{
	int d;
	struct T_Node *next;
} Node, *List;
/*函数中，不得生成新的结点，尽量利用已经有的结点。

如下的main函数执行后*/
//创建头指针为la, lb的两个链表
void createlink(List *pla, List *plb)
{
	int i;
	Node *p;

	*pla = (Node *)malloc(sizeof(Node));     //创建头结点
	p = *pla;

	for(i = 1; i <=10;i++)
	{
		p->next = (Node *)malloc(sizeof(Node));		
		p = p->next;
		p->d = i*2;
		p->next = NULL;
	}


	*plb = (Node *)malloc(sizeof(Node));     //创建头结点
	p = *plb;

	for(i = 1; i <= 8;i++)
	{
		p->next = (Node *)malloc(sizeof(Node));		
		p = p->next;
		p->d = i+6;
		p->next = NULL;
	}
}


void  Intersection (List La, List Lb) {
	Node* p1,* p2 ,*pre;
	bool flag = true;//true为该删除
	p1 = La->next;
	pre = La;
	while(p1) {
		flag = true;
		p2 = Lb->next;
		while(p2) {
			if(p1->d == p2->d) {
				flag = false;
				break;
			}
			p2 = p2->next;
		}
		if(flag) {
			Node* temp = p1;
			p1 = p1->next;
			pre->next = p1;
			free (temp);
		}else{
			pre = pre->next;
			p1 = p1->next;
		}
	}
}

int main()
{
	int i;

	List la, lb;
	Node *p;

	createlink(&la, &lb);
	Intersection (la, lb);
	
	p = la->next;
	while(p!=NULL)
	{
		printf("%4d",p->d);
		p = p->next;
	}
	printf("\n");
}
/*
执行的结果为
   8  10  12  14
*/
