#include<iostream>
#define Max(a,b) (a>b?a:b)
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
    int height;
    TNode(int index,ElementType X) : data({index,X}) , Left(NULL),Right(NULL),height(0) { }
};

Tree LL_roate(Tree A) {
    Tree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    return B;
}

Tree RR_roate(Tree A) {
    Tree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    return B;
}

Tree LR_roate(Tree A) {
    A->Left = RR_roate(A->Left);
    return LL_roate(A);
}

Tree RL_roate(Tree A) {
    A->Right = LL_roate(A->Right);
    return RR_roate(A);
}

int GetHeight(Tree T) {
    if(T==NULL) {
        return 0;
    }
    return T->height;
}

int getBalance(Tree T) {
    if(T==NULL) {
        return 0;
    }
    return GetHeight(T->Left)-GetHeight(T->Right);
}

Tree Insert(Tree T,int index,ElementType X) {
    if(!T) {
        T = new struct TNode({index,X});
    }else if(index > T->data.index) {
        T->Right = Insert(T->Right,index,X);
    }else if(index < T->data.index) {
        T->Left = Insert(T->Left,index,X);
    }
    
    T->height = Max(GetHeight(T->Left),GetHeight(T->Right))+1;
    //cout << T->height << endl;
    if(getBalance(T)>1) {
        if( index < T->data.index) {
            return LL_roate(T);
        }else if(index > T->data.index) {
            return LR_roate(T);
        }
    }else if(getBalance(T) < -1) {
        if( index< T->data.index) {
            return  RL_roate(T);
        }else if(index > T->data.index) {
            return RR_roate(T);
        }
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
    while(cin >> num) 
        search(T,num);

    DeleteTree(T);
    return 0;
}