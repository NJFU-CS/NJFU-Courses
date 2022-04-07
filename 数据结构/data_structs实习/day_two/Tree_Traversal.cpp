/*
1．	二叉树
任务：建立二叉树，并实现二叉树的先序、中序、后序、层序遍历，求二叉树的宽度，统计二叉树中度为1的结点的个数，求根结点到指定结点的路径。
功能要求：
1)	建立二叉树存储结构；
2)	对二叉树进行先序、中序、后序、层序遍历，并输出对应遍历序列；
3)	求二叉树的宽度；
4)	统计二叉树中度为1的结点的个数；
5)	求根结点到指定结点的路径。
界面要求：程序运行后，给出菜单项的内容和输入提示：
1.	建立二叉树存储结构
2.	求二叉树的先序遍历序列（递归、非递归）
3.	求二叉树的中序遍历序列（递归、非递归）
4.	求二叉树的后序遍历序列
5.	求二叉树的层序遍历序列
6.	求二叉树的宽度、度为1的结点的个数
7.	求根结点到指定结点的路径
0.	退出
请选择0-7：

*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef char ElementType;

typedef struct TNode *PtrToTNode,*Tree;
struct TNode {
    ElementType data;
    PtrToTNode Left;
    PtrToTNode Right;
    TNode(int X) : Left(NULL),Right(NULL),data(X) { }
};

void CreateTree(Tree *T) {
    char ch;
    cin >> ch;
    if('.' == ch)
        T = NULL;
    else{
        *T = new struct TNode(ch);
        CreateTree(&((*T)->Left));
        CreateTree(&((*T)->Right));
    }
}

void PrintTree(Tree T,int n) {
    if(T) {
        PrintTree(T->Right,n+1);
        for(int i=0;i<n;i++) {
            cout << "  ";
        }
        cout << T->data << endl;
        PrintTree(T->Left,n+1);
    }
}

void PreOrder(Tree T) {
    if(T) {
        cout << T->data << " ";
        PreOrder(T->Left);
        PreOrder(T->Right);
    }
}

void MidOrder(Tree T) {
    if(T) {
        MidOrder(T->Left);
        cout << T->data << " ";
        MidOrder(T->Right);
    }
}

void PostOrder(Tree T) {
    if(T) {
        cout << T->data << " ";
        PostOrder(T->Left);
        PostOrder(T->Right);
    }
}

void LevelOrder(Tree T) {
    queue<PtrToTNode> Q;
    if(!T) return ;
    Q.push(T);
    while(!Q.empty()) {
        
        PtrToTNode p = Q.front();
        Q.pop();
        cout << p->data << ' ';

        if(p->Left) {
            Q.push(p->Left);
        }

        if(p->Right) {
            Q.push(p->Right);
        }
    }
}

void Treewide(Tree T) {
    queue<PtrToTNode> Q;
    queue<PtrToTNode> result;
    if(!T) return;
    int oldnum = 1;
    int curnum = 1;
    Q.push(T);
    while(!Q.empty()) {
        
        PtrToTNode p = Q.front();
        result.push(Q.front());
        Q.pop();

        if(p->Left) {
            curnum++;
            Q.push(p->Left);
        }

        if(p->Right) {
            curnum++;
            Q.push(p->Right);
        }
        if(curnum>oldnum) {
            oldnum = curnum;
            curnum = 0;
        }
    }
    cout << " tree width =  " << oldnum << endl;
}

void indegree1(Tree T,int &num) {
    if(T) {
        indegree1(T->Left,num);
        if((T->Left && !T->Right) || (!T->Left && T->Right)) {
            //cout << T->data << " ";
            num++;
        }
        indegree1(T->Right,num);
    }
}

void Path(Tree T,PtrToTNode q) {
    //dfs
    char path[100];
    for(int i = 0; i!=100 ;i++) {
        path[i] = -1;
    }
    if(!T) return;
    int pre = -1;
    stack<PtrToTNode> S;
    S.push(T);
    while(!S.empty()) {
        PtrToTNode p = S.top();
        S.pop();
        if(p==q) {
            char i = p->data;
            while(i!=-1) {
                cout << i << ' ';
                i = path[i];
            }
            return;
        }
        if(p->Left) {
            path[p->Left->data] = p->data;
            S.push(p->Left);
        }
        if(p->Right) {
            path[p->Right->data] = p->data;
            S.push(p->Right);
        }
            
    }
        
    
    cout << endl;
    for(int i=64;i<75;i++) {
        cout << char(i) <<":"<< path[i] << endl;
    }
}


int main()
{
    int i;
    cin >> i;
    Tree T = NULL;
    switch(i) {
        case 0 : break;
        case 1 :CreateTree(&T); break;
        case 2 :
            cout << "preorder : " << endl;
            PreOrder(T);
            break;
        case 3: 
            cout << endl << "midorder " << endl;
            MidOrder(T);
            break;
        case 4:
            cout << endl << "postorder : " << endl;
            PostOrder(T);
            break;
        case 5:
            cout << endl << "leverorder" <<endl;
            LevelOrder(T);
            break;
        case 6:
            cout << endl << "width : " << endl;
            Treewide(T);
            cout << endl;
            int n=0;
            indegree1(T,n);
            cout << "degree = 1 : " << n << endl;
            break;
        case 7: cout << "path : " << endl;
            Path(T,T->Left->Right);
            break;
        default : break;
    }
}

/*
A B C . . E . . F G . . . . 
*/
