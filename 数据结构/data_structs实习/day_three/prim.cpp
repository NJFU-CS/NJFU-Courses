#include<iostream>
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

int FindMin(Graph graph ,int dist[]) {
    int min = INFINITY;
    int num = -1;
    Vertex V;
    for(V = 0 ; V < graph->Nv ;V++) {
        if( dist[V]!=0 && dist[V] < min) {
            min = dist[V];
            num = V;
        }
    }
    return num;
}

bool Prim(Graph graph) {
    int dist[MAXSIZE] = {0};
    Vertex Path[MAXSIZE] ;
    for(Vertex V = 0; V < graph->Nv ;V++) {
        Path[V] = -1;
    }
    for(Vertex V = 0 ; V<graph->Nv ;V++) {
        dist[V] = graph->a[0][V];
        if(dist[V] < INFINITY)
            Path[V] = 0;
    }
    //dist[0] = 0;

    for(int i=1 ;i<graph->Nv ;i++) {
        Vertex V = FindMin(graph,dist);
        dist[V] = 0;
        for(Vertex W = 0 ;W<graph->Nv ;W++) {
            if(dist[W]!=0 && graph->a[V][W] < dist[W]) {
                dist[W] = graph->a[V][W];
                Path[W] = V;
            }
        }
        
    }
    
    for(Vertex V = 0 ;V<graph->Nv ;V++) {
        if(dist[V]!=0) {
            cout << "min Tree is not exist" << endl;
            return false;
        }
    }
    for(Vertex V = 0; V<graph->Nv ;V++) {
            cout << Path[V] << " ";
        }
    cout << endl;
    for(Vertex V = 1;V<graph->Nv ;V++) {
        cout << "(" << Path[V] << "," << V << ")" << endl;
    }
    return true;
}

int main()
{
    Graph graph = BuildGraph();
    //PrintGraph(graph);
    Prim(graph);

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