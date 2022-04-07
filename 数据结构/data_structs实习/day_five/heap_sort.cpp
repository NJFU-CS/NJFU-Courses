#include<iostream>
using namespace std;
#include<ctime>

void shift(int a[],int n,int p) {
    int Parent,Child;
    a[0] = a[p];
    for(Parent = p;Parent*2<n;Parent = Child) {
        Child = 2*Parent;
        if(Child+1<n && a[Child+1]>a[Child]) {
            Child++;
        }
        if(a[0] > a[Child]) {
            break;
        }else{
            a[Parent] = a[Child];
        }
    }
    a[Parent] = a[0];
}

void BuildHeap(int a[],int n) {
    for(int i=n/2 ;i>0;i--) {
        shift(a,n,i);
    }
}

void Heap_sort(int a[],int n) {
    BuildHeap(a,n);
    for(int i=n-1 ;i>0;i--) {
        a[0] = a[i];
        a[i] = a[1];
        a[1] = a[0];
        shift(a,i,1);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    int a[11];
    for(int i=1;i<sizeof(a)/sizeof(int);i++) {
        a[i] = rand()%50;
        cout << a[i] << " ";
    }
    cout <<"{" << a[11] << "}"<< endl;
    Heap_sort(a,sizeof(a)/sizeof(int));
    for(int i=0 ;i<12;i++) {
        cout << a[i] << " ";
    }
}