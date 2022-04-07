#include<iostream>
#include<stack>
#define MAXSIZE 100
#define INFINITY 1000
using namespace std;

typedef int Vertex;

typedef struct ENode *Edge;
struct ENode {
    Vertex V1;
    Vertex V2;
    int weight;
};

typedef struct GNode *Graph;
struct GNode {
    int a[MAXSIZE][MAXSIZE];
    int Nv;
    int Ne;
};

Graph CreateGraph(int Nv) {
    Graph graph = new struct GNode;
    graph->Nv = Nv;
    graph->Ne = 0;
    for(Vertex V = 0 ; V<Nv ;V++) {
        for(Vertex W = 0 ; W<Nv ;W++) {
            if(V==W) graph->a[V][W] = 0;
            else graph->a[V][W] = INFINITY;
        }
    }
    return graph;
}

void Insert(Graph graph,Edge edge) {
    graph->a[edge->V1][edge->V2] = edge->weight;
}

Graph BuildGraph() {
    int Nv;
    cin >> Nv;
    Graph graph = CreateGraph(Nv);
    cin >> graph->Ne;
    Edge edge = new struct ENode;
    for(int i=0;i<graph->Ne;i++) {
        cin >> edge->V1 >> edge->V2 >> edge->weight;
        Insert(graph,edge);
    }
    return graph;
}

void PrintGraph(Graph graph) {
    for(Vertex V = 0 ;V <graph->Nv ;V++) {
        for(Vertex W = 0; W<graph->Nv ;W++) {
            cout.width(5);
            cout << graph->a[V][W];
        }
        cout << endl;
    }
}
//************************************************
stack<Vertex> TopResult;

void Criticual(Graph graph) {
    int indegree[MAXSIZE] = {0};

    int early[MAXSIZE]={0};
    int late[MAXSIZE]={0};

    for(Vertex W= 0 ; W<graph->Nv ;W++) {
        for(Vertex V = 0; V<graph->Nv ;V++) {
            if(graph->a[V][W]!=INFINITY &&V!=W) {
                indegree[W]++;
            }
        }
    }
    //for(Vertex V=0 ;V<graph->Nv;V++) cout << indegree[V] << " ";
    stack<Vertex> S;
    for(Vertex V=0; V<graph->Nv ;V++) {
        if(indegree[V]==0) {
            S.push(V);
        }
    }
    while(!S.empty()) {
        Vertex V = S.top();
        S.pop();
        cout << V << "--";

        TopResult.push(V);

        for(Vertex W = 0;W<graph->Nv ;W++) {
            if(graph->a[V][W]!=INFINITY && V!=W) {
                if(early[W] < early[V]+graph->a[V][W]) {
                    early[W] = early[V]+graph->a[V][W];
                }
                if(--indegree[W] == 0) {
                    S.push(W);
                }
            }
        }
    }
    cout << "early "<<endl;
    for(Vertex V=0; V<graph->Nv ;V++) {
        cout << early[V] << " ";
    }

    for(Vertex V=0; V<graph->Nv; V++) {
        late[V] = early[graph->Nv-1];
    }

    

    while(!TopResult.empty()) {
        Vertex V = TopResult.top();
        TopResult.pop();
        for(Vertex W=0;W<graph->Nv;W++) {
            if(W!=V && graph->a[V][W]!=INFINITY) {
                if(late[V] > late[W]-graph->a[V][W]) {
                    late[V] = late[W]-graph->a[V][W];
                }
            }
        }
    }
    cout << "late"<<endl;
    for(Vertex V=0; V<graph->Nv ;V++) {
        cout << late[V] << " ";
    }

    int critual[MAXSIZE] = {0};
    for(Vertex V = 0; V<graph->Nv ;V++) {
        critual[V] = late[V]-early[V];
    }

    cout << "late"<<endl;
    for(Vertex V=0; V<graph->Nv ;V++) {
        cout << critual[V] << " ";
    }
    cout << "critualPath : " << endl;
    for(Vertex V=0; V<graph->Nv;V++) {
        if(critual[V]==0) {
            cout << V << "--";
        }
    }
}


int main()
{
    Graph graph = BuildGraph();
    PrintGraph(graph);
    Criticual(graph);

}

/*
8 10
0 1 1
0 2 2 
1 3 3
1 4 4
2 5 5
2 6 6
3 7 7
4 7 8
5 7 9
6 7 10
*/