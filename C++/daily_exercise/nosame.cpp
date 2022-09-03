#include<iostream>
using namespace std;

bool nosame(int *a, int m, int n) {
    int flag = 0;
    for(int i=0 ; i< m*n-1 ; ++i ) {
        
        if(i%(m+1)==0 || i/(m+1)==0) continue;

        for(int j=0; j < m*n ; ++j) {
            
            if(j%(n+1)==0 || j/(n+1)==0) continue;

            if(a[i]==a[j]) { cout << "have same" << endl ; return false; };
            
        }
    }
    return true;
}

int main()
{
    int a[5][6] = { {0},
                    {0,1,2,3,4,5},
                    {0,11,12,13,14,15},
                    {0,21,22,23,24,25},
                    {0,31,32,33,34,35}, };
    cout << nosame(*a,4,5);
}