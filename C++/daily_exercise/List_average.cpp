/*递归求链表节点平均数*/
#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
}Node,*List;

void createList(List *fp) {
    int i;
    Node* p;
    *fp = (Node*)malloc(sizeof(Node));
    p = *fp;
    for(int i=1 ; i<100 ; ++i ){
        p->data = i;
        p->next = (Node*)malloc(sizeof(Node));
        p = p->next;
    }
    p->data = 100;
    p->next = nullptr;
}

double getaverage(List f,int *nodenum) {
    double sum = 0;
    if(!f) {
        *nodenum = 0;
        return 0;
    }else {
        sum = (f->data+ getaverage(f->next,nodenum)* *nodenum)/(*nodenum+1);
        (*nodenum)++;
        return sum;
    }

}

int main()
{
    int n;
    List f;
    double a;
    createList(&f);
    a = getaverage(f,&n);
    cout << "num = " << n << " ; average = "<<a << endl;
    return 0;
}