#include<iostream>
using namespace std;
#include<ctime>

using namespace std;

void ShellInsert(int a[],int n,int delta) {
    for(int i=delta+1 ; i<n ; ++i) {
        if(a[i-delta] > a[i]) {
            a[0] = a[i];
            int j = i;
            for(j = i-delta ;j>0 && a[0] < a[j];j-=delta) {
                a[j+delta] = a[j];
            }
            a[j+delta] = a[0];
        }
    }
}

void Shell_sort(int a[],int n,int delta[],int length) {
    for(int i = length-1 ;i >= 0 ;i--) {
        ShellInsert(a,n,delta[i]);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int a[51];
    int detla[]={1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484,7174453,21523360};
    for(int i=1;i<=50;i++) {
        a[i] = rand()%50;
    }
    Shell_sort(a,sizeof(a)/sizeof(int),detla,sizeof(detla)/sizeof(int));
    for(int i=1;i<=50;i++) {
        cout << a[i] << " ";
    }
}