#include<iostream>
#include<time.h>
using namespace std;

int quickPass(int a[],int low,int high) {
    a[0] = a[low];
    while(low<high) {
        while(low < high && a[0]<a[high]) {
            high--;
        }
        if(low<high) {
            a[low] = a[high];
            low++;
        }
        while(low<high && a[0]>a[low]) {
            low++;
        }
        if(low<high) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = a[0];
    // cout << a[low] << "]";
    return low;
}

void Quick_sort(int a[],int low,int high) {
    if(low<high){
        int mid = quickPass(a,low,high);
        Quick_sort(a,low,mid-1);
        Quick_sort(a,mid+1,high);
    }
}

int main()
{
    int a[51];
    srand(static_cast<unsigned int>(time(0)));
    for(int i=1 ;i<=50 ;i++) {
        a[i] =  rand() %50 ;
    }
    cout << endl;
    Quick_sort(a,1,sizeof(a)/sizeof(int)-1);
    for(int i=1;i<=50 ;i++) {
        cout << a[i] << " ";
    }
    
}

