/*
1．	迷宫求解
任务：可以输入一个任意大小的迷宫数据，用非递归的方法求出一条走出迷宫的路径，并将路径输出；
要求在上交资料中请写明：存储结构、基本算法（可以使用程序流程图）、源程序、测试数据和结果、算法的时间复杂度、
另外可以提出算法的改进方法；
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;
typedef int Vertex;

//边的定义
typedef struct ENode *Edge,*PtrToEdge;
struct ENode {
    Vertex V1;
    Vertex V2; 
};
//邻接点
typedef struct AdjVNode* AdjEdge,*PtrToAdjEdge;
struct AdjVNode {
    Vertex V;
    PtrToAdjEdge next;
};
//图
struct GNode* PtrTOGraph,*Graph;
struct GNode {
    PtrToAdjEdge *a;
    int Ne;//点
    int Nv;//边
}graph;

void InitGraph(int nv) {
    int i;
    graph.a = (PtrToAdjEdge*)malloc(sizeof(PtrToAdjEdge)*nv);
    graph.Nv = nv;
    for(i=0;i<graph.Nv;i++) {
        graph.a[i] = (PtrToAdjEdge)malloc(sizeof(struct AdjVNode));
        graph.a[i]->next = nullptr ;
    }
}

void Insert(Edge edge) {
    //头节点不存数据
    //单向图
    PtrToAdjEdge NewNode = (PtrToAdjEdge)malloc(sizeof(struct AdjVNode));
    NewNode->V = edge->V2;
    NewNode->next = graph.a[edge->V1]->next;
    graph.a[edge->V1]->next = NewNode;
}

void BuildGraph() {
    int nv;
    cin >> nv;
    InitGraph(nv);
    cin >> graph.Ne;
    int i;
    
    for(i=0 ;i<graph.Ne; i++) {
        Edge edge = (Edge)malloc(sizeof(struct ENode));
        int v1,v2;
        cin >> v1 >> v2;
        edge->V1 = v1;
        edge->V2 = v2;
        Insert(edge);
    }
}

void Print() {
    for(int i=0;i<graph.Nv;i++) {
        cout << i << " : ";
        
        PtrToAdjEdge p = graph.a[i]->next;
        while(p) {
            cout << p->V << " ";
            p = p->next;
        }
        cout << endl;
    }
}
//非递归的DFS
void Path(Vertex V,Vertex S) {
    int *visited = (int *)malloc(sizeof(int)*graph.Nv);
    int *path = (int *)malloc(sizeof(int)*graph.Nv);
    for(int i=0;i<graph.Nv;i++) {
        visited[i] = -1;
    }

    std::stack<Vertex> stack;
    stack.push(V);
    path[V] = -1;
    while(!stack.empty()) {
        
        Vertex W = stack.top();
        stack.pop();
        
        if(visited[W]==-1){
            visited[W] = 1;
            PtrToAdjEdge p;
            for(p = graph.a[W]->next ; p ;p = p->next) {
                if(visited[p->V]==-1) {
                    stack.push(p->V);
                    path[p->V] = W;
                    if(p->V==S) {
                        //输出路径
                        int i=p->V;
                        while(i!=-1) {
                            cout << i << " ";
                            i = path[i];
                        }
                        return ;
                    }
                }
            }
        }
    }
}

int main()
{
    BuildGraph();
    Print();
    Path(0,7);
}

/*
8 10
0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 7
6 7
*/