#include<stdio.h>
#include<stdlib.h>/*调用malloc函数*/

typedef struct node
{
	int math;										/*数学*/
	int phy;											/*物理*/
	int eng;											/*英语*/
	int c;											/*c语言*/
	char s[100];									/*姓名*/
	int num;											/*学号*/ 
	struct node* next;								/*下一个节点*/
}Node;
	int m;
void creat_list(Node** head,int n);/*创建n个节点的链表*/ 
void average(Node* head,int n);	/*求平均分*/
void rank(Node* head,int n,int *a,int *b,int *c,int* d); 	/*排序*/ 
void f(int *a,int n);/*rank操作*/ 
void printfmath(Node* head,int n);				/*输出数学最高分姓名学号 */
void printfphy(Node* head,int n);				/*输出数学最高分姓名学号*/ 
void printfeng(Node* head,int n);				/*输出数学最高分姓名学号 */
void printfc(Node* head,int n);					/*输出数学最高分姓名学号 */
void free_list(Node** head);					/*释放列表*/  
int main()
{
	Node* head=NULL;				/*头指针NULL*/ 
	int n;	
	putchar('\n');
	putchar('\n');
	putchar('\n');
	for(m=0;m<37;m++){
		printf("*");
	}
	printf("学生管理系统") ;
	for(m=0;m<37;m++){
		printf("*");
	}
	putchar('\n');
	printf("输入人数:");									/*几个人*/ 
	scanf("%d",&n);											/*输入*/ 
	int *a=(int*)malloc(sizeof(int)*n);/*a数组*/ 		/* 分配内存*/ 
	int *b=(int*)malloc(sizeof(int)*n);/*b数组*/ 		/* 分配内存*/
	int *c=(int*)malloc(sizeof(int)*n);/*c数组*/ 		/* 分配内存*/
	int *d=(int*)malloc(sizeof(int)*n);/*d数组*/ 		/* 分配内存*/
	creat_list(&head,n);									/*创建链表 */
	putchar('\n'); 
	average(head,n);										/* 求每门课平均*/
	rank(head,n,a,b,c,d); 									/* 排序*/
	printf("数学最高分：");								/* 数学最高分*/
	printfmath(head,a[0]);
	printf("物理最高分：");								/* 物理最高分*/
	printfphy(head,b[0]);
	printf("英语最高分：");								/*英语最高分 */
	printfeng(head,c[0]);
	printf("c语言最高分：");								/* c语言最高分*/
	printfc(head,d[0]); 
	free_list(&head); 										/*释放链表 */
} 
void creat_list(Node** head,int n)					/*创建n个节点的链表*/ 
												/*传入一个二级指针，要对头指针操作*/ 
{
	int i;
	Node* temp;
	for(i=0;i<n;i++){
		
		Node* node=(Node*)malloc(sizeof(Node));/*create new node*/
		printf("学号：");									/*学号*/ 
		scanf("%d",&node->num);
		printf("名字：");									/*名字*/ 
		scanf("%s",node->s);
		printf("数学：");
		scanf("%d",&node->math);							/*输入数学*/
		printf("物理：");
		scanf("%d",&node->phy);							/*输入物理*/
		printf("英语：");
		scanf("%d",&node->eng);							/*输入英语*/
		printf("c语言：");
		scanf("%d",&node->c);							/*输入c*/
		for(m=0;m<40;m++){
			printf("*");
		}
		putchar('\n');
		node->next=NULL;
		
		if(*head==NULL){
			*head=node;
			temp=*head;
		}else{
			temp->next=node;
			temp=temp->next;
		}
	} 
}

void average(Node* head,int n)								/*求平均分*/
{
	Node* temp=head;
	float a=0,b=0,c=0,d=0;
	while(temp!=NULL){
		a+=temp->math;
		b+=temp->phy;
		c+=temp->eng;
		d+=temp->c;
		temp=temp->next; 
	}
	printf("数学均分%.1f\n物理均分%.1f\n英语均分%.1f\nc语言均分%.1f\n"
	,a/n,b/n,c/n,d/n);
	for(m=0;m<40;m++){
			printf("*");
		}
	putchar('\n');
}

void rank(Node* head,int n,int *a,int *b,int *c,int* d)/*排序*/ 
{

	int i;
	int num=n;
	Node* temp=head;
	for(i=0;i<n;i++){
		a[i]=temp->math;
		b[i]=temp->phy;
		c[i]=temp->eng;
		d[i]=temp->c;
		temp=temp->next;
	}
	printf("数学排序\n");
	f(a,num);
	putchar('\n'); 
	printf("物理排序\n");
	f(b,num);
	putchar('\n');
	printf("英语排序\n");
	f(c,num);
	putchar('\n');
	printf("c语言排序\n");
	f(d,num);
	putchar('\n');
	for(m=0;m<40;m++){
			printf("*");
		}
	putchar('\n');
}
void f(int *a,int n)											/*rank操作*/ 
{
	int i,j;
	int t;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(a[j]>a[i]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d	",a[i]);
}
void printfmath(Node* head,int n)					/*输出数学最高分name   学号 */
{
	Node* temp=head;
	while(temp!=NULL){
		if(temp->math==n){
			printf("\nnumber   %d\tname   %s\n",temp->num,temp->s);
		}
		temp=temp->next;
	}
	for(m=0;m<30;m++){
			printf("*");
		}
	putchar('\n');
}
void printfphy(Node* head,int n)			/*输出数学最高分name   number   */ 
{
	Node* temp=head;
	while(temp!=NULL){
		if(temp->phy==n){
			printf("\nnumber   %d\tname   %s\n",temp->num,temp->s);
			
		}
		temp=temp->next;
	}
	for(m=0;m<30;m++){
			printf("*");
		}
	putchar('\n');
}
void printfeng(Node* head,int n)			/*输出数学最高分name   number    */
{
	Node* temp=head;
	while(temp!=NULL){
		if(temp->eng==n){
			printf("\nnumber   %d	name   %s\n",temp->num,temp->s);
		}
		temp=temp->next;
	}
	for(m=0;m<30;m++){
			printf("*");
		}
	putchar('\n');
}
void printfc(Node* head,int n) 			/*输出数学最高分name   number    */
{
	Node* temp=head;
	while(temp!=NULL){
		if(temp->c==n){
			printf("\nnumber   %d\tname   %s\n",temp->num,temp->s);
		}
		temp=temp->next;
	}
	for(m=0;m<30;m++){
			printf("*");
		}
	putchar('\n');
}
void free_list(Node** head)									/*释放列表*/
{
	Node* temp=*head;
	Node* prev;
	while(temp!=NULL){
		prev=temp;
		temp=temp->next; 
		free(prev);
	}
		putchar('\n');
		putchar('\n');
		for(m=0;m<37;m++){
		printf("*");
	}
	printf("检索结束") ;
	for(m=0;m<37;m++){
		printf("*");
	}
}	

