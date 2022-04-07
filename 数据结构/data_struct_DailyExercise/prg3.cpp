/*设计一个函数
void LinkReverse(List *pla)*/
#include<iostream>
using namespace std;
/*其功能将带头结点的单向链表反转。la是一个带头结点的链表，函数的目的是逆转这个链表，也就是第一个结点变成最后一个结点，第二个结点变为倒数第二个结点，以此类推。该函数的空间复杂度为O(1），
也就是该函数不能定义数组变量和使用动态分配函数。
其中List是如下结构体：*/
typedef struct T_Node{
	int d;
	struct T_Node *next;
} Node, *List;
//如下的main函数执行后
//创建头指针为la的链表
void createlink(List *pla)
{
	int i;
	Node *p;

	*pla = (Node *)malloc(sizeof(Node));     //创建头结点
	p = *pla;

	for(i = 1; i <=10;i++)
	{
		p->next = (Node *)malloc(sizeof(Node));		
		p = p->next;
		p->d = i;
		p->next = NULL;
	}
}

void LinkReverse(List *pla) {
	Node* p = (*pla)->next->next;
	while(p) {
		Node *temp = p;
		p = p->next;
		temp->next = (*pla)->next;
		(*pla)->next = temp;
	}
}

int main( )
{
	List la, p;
	int i;

	createlink(&la);
	LinkReverse(&la);

	p = la->next;
	for(i = 1; i <=10;i++)
	{
		printf("%4d",p->d);
		p = p->next;
	}
	printf("\n");
}
/*执行的结果为
  10   9   8   7   6   5   4   3   2   1*/
