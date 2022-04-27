#include<iostream>
using namespace std;
typedef char ElementType;

typedef struct Node Pair; 
struct Node {
    int index;
    ElementType data;
};

typedef struct TNode *Tree;
struct TNode {
    Pair data;
    Tree Left;
    Tree Right;
    TNode(int index,ElementType X) : data({index,X}) , Left(NULL),Right(NULL) { }
};

Tree Insert(Tree T,int index,ElementType X) {
    if(!T) {
        T = new struct TNode({index,X});
    }else if(index > T->data.index) {
        T->Right = Insert(T->Right,index,X);
    }else if(index < T->data.index) {
        T->Left = Insert(T->Left,index,X);
    }
    return T;
}

void PrintTree(Tree T,int n = 0) {
    if(T) {
        PrintTree(T->Right,n+1);
        for(int i=0 ; i<n;i++) {
            cout << "\t";
        }
        cout << "{"<<T->data.index << "," << T->data.data <<"}"<< endl << endl;
        PrintTree(T->Left,n+1);
    }
} 

Tree InitTree() {
    Tree T = NULL;
    for(int i=10 ; i>0 ;i-=2) {
        T = Insert(T,i,'A'+i);
    }
    for(int i=1 ;i<10 ;i+=2) {
        T = Insert(T,i,'A'+i);
    }
    return T;
}

void search(Tree T,int index) {
    if(!T) {  cout << "not fount!!!" << endl; return ; }
    else if(index > T->data.index) {
        search(T->Right,index);
    }else if(index < T->data.index) {
        search(T->Left,index);
    }else{
        cout << "{"<<T->data.index << "," << T->data.data <<"}"<< endl ;
    }
}

void DeleteTree(Tree T) {
    if(T) {
        DeleteTree(T->Left);
        DeleteTree(T->Right);
        delete T;
    }
}

int main()
{
    Tree T = InitTree();
    PrintTree(T);
    int num;
    cout << "please cin num , cin ctrl+z to break" << endl;
    while(cin >> num) 
        search(T,num);

    DeleteTree(T);
    return 0;
}