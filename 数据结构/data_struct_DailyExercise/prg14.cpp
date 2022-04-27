//使用如下数据结构
#include<iostream>
//#define NULL 0
#define N 100
using namespace std;

typedef  struct  BiTNode {  
	int  data;
   	struct  BiTNode *lchild, *rchild;
}BiTNode, * BiTree;

int datagroup[N];
int index;
/*
设计第一个函数
void CreateTree(BiTree *t);该函数的功能是将数组datagroup中的数据，按照先序遍历方式，组成一个棵树。
datagroup数组的元素的值作为树中各个节点的数据，并规定如果某个元素的值为-1，表示对应的节点是NULL节点。*/
void CreateTree(BiTree *t) {
	*t = new struct BiTNode;	
	(*t)->lchild = nullptr;
	(*t)->rchild = nullptr;
	(*t)->data = datagroup[index];
	if(datagroup[index++]!=-1){
		CreateTree(&(*t)->lchild);
		CreateTree(&(*t)->rchild);
	}
}
//设计第二个函数
//该函数的功能是统计t所指向的树的非叶子节点数，并返回该值。
int NodeNum( BiTree t ) {
	if(t->lchild->data==-1 && t->rchild->data==-1) {
		return 0;
	}else{
		if(t->lchild->data==-1) {
			return NodeNum(t->rchild)+1;
		}else if(t->rchild->data==-1){
			return NodeNum(t->lchild)+1;
		}else{
			return NodeNum(t->lchild)+NodeNum(t->rchild)+1;
		}
	}
}

void PrintfTree(BiTree T,int n) {
	if(T) {
		PrintfTree(T->rchild,n+1);
		for(int i=0;i<n;i++) {
			cout << "  " ;
		}
		cout << T->data << endl;
		PrintfTree(T->lchild,n+1);
	}
}

int main(int argc, char* argv[])
{
	BiTree root; 
	int i;

	for(i = 0; i < 15;i++)
		scanf("%d", &datagroup[i]); 
	index = 0;
	CreateTree(&root);
	index = 0;
	PrintfTree(root,index+1);

	printf("%d\n",  NodeNum(root));
}
/*
1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 -1 -1
执行的结果为
4
*/