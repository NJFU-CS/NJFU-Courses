//使用如下数据结构
#include<iostream>
using namespace std;
//#define NULL 0
#define N 100

typedef  struct  BiTNode {  
	int  data;
    struct  BiTNode *lchild, *rchild;
}BiTNode, * BiTree;

int datagroup[N];
int num;
	
/*设计第一个函数
void CreateTree(BiTree *t);该函数的功能是将数组datagroup中的数据，按照先序遍历方式，组成一个棵树。
datagroup数组的元素的值作为树中各个节点的数据，并规定如果某个元素的值为-1，表示对应的节点是NULL节点。*/

/*设计第二个函数
void InOrder( BiTree t );该函数的功能是t所指的树，进行中序遍历，并在遍历中将数据放入数组datagroup中，
并将有效节点数（不算NULL节点）置于全局变量num中。*/
void CreateTree(BiTree *t) {
	*t = new struct BiTNode;	
	(*t)->lchild = nullptr;
	(*t)->rchild = nullptr;
	(*t)->data = datagroup[num];
	if(datagroup[num++]!=-1){
		CreateTree(&(*t)->lchild);
		CreateTree(&(*t)->rchild);
	}
}

void InOrder( BiTree t ) {
	if(t) {
		InOrder(t->lchild);
		if(t->data != -1)
		datagroup[num++] = t->data;
		InOrder(t->rchild);
	}
}

int main(int argc, char* argv[])
{
	BiTree root=nullptr; 
	int i;

	for(i = 0; i < 15;i++)
		scanf("%d", &datagroup[i]); 
	CreateTree(&root);
	num = 0;
	InOrder( root );
	for(i = 0; i < num; i++)
		printf("%d ", datagroup[i]);
	printf("\n");
}
/*
输入内容为
1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 -1 -1
执行的结果为
4 2 5 1 6 7 3
*/