//设计一个函数
//	void  add_poly( Polylist pa,  Polylist pb )
#include<iostream>
using namespace std;
//其功能是pb和pb的多项式进行相加。
//其中Polylist是如下结构体：
typedef struct Polynode {
  int coef;  //因子
  int exp;   //幂
  struct Polynode *next;
}Polynode , * Polylist; 

//创建多项式的函数如下：
Polylist polycreate( ) 
{
	Polynode *rear, *head, *s;

	int c, e;
	
	rear=head=(Polynode *)malloc(sizeof(Polynode));  
	scanf("%d%d",&c,&e); 
	while(c!=0) 
	{ 	
		s=(Polynode*)malloc(sizeof(Polynode));
		s->coef=c; 
		s->exp=e; 
		rear->next=s; 
		rear=s;  
		scanf("%d%d",&c,&e); 
	}
	rear->next=NULL; 
	return(head);
}

//显示多项式的函数如下
void print(Polylist p)
{
	int j;

	p = p->next;
	while(p)
	{
		printf("%d", p->coef);
		for(j = 0; j< p->exp; j++)
			printf("*x");
		if(p->next!=NULL)
			printf(" + ");
		p = p->next;
	}
	printf("\n");
}


void  add_poly( Polylist pa,  Polylist pb ) {
	Polynode* p = pa->next;
	Polynode* q = pb->next;
	Polynode* pre = pa;
	int c ;
	while(p && q){
		if(p->exp==q->exp) {
			c = p->coef + q->coef  ;
			if(c!=0) {
				p->coef = c;
				p = p->next;
				q = q->next;
				pre = pre->next;
			}else{
				Polynode* temp = p;
				pre->next = p->next;
				p = p->next;
				q = q->next;
				free(temp);
			}
		}else{
			if(p->exp > q->exp) {
				pre->next = q;
				q = q->next;
				pre->next->next = p;
				pre = pre->next;
			}else{
				p = p->next;
				pre = pre->next;
			}
		}
	}
	if(q) {
		pre->next = q;
	}
}
//当执行如下的main函数后
int main(int argc, char* argv[])
{
	Polylist pa, pb;   //定义两个表示多项式的链表

	pa = polycreate();  //创建pa链表
	pb = polycreate();  //创建pb链表
	add_poly(pa, pb);   //做加法，结果保存在pa链表上
	print(pa);          //将加法的结果用一个多项式格式显示在输出设备上
}
/*如果从键盘输入的值如下：
5 0
3 5
4 8
0 0
5 0
3 5
4 8
0 0

则执行的结果为
10 + 6*x*x*x*x*x + 8*x*x*x*x*x*x*x*x
*/