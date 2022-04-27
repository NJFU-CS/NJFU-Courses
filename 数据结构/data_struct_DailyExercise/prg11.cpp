/*设计一个函数separatepn函数格式如下：
void separatepn(int a[],int n)
将数组a中a[1]-a[n]的数重新排列，使得所有正数（包括0）排在所有负数之前。算法复杂度为O(n)，函数里只能有一个循环语句。
*/
#include<iostream>
using namespace std;
void separatepn(int a[],int n) {
    int i=1;
    int j=n-1;
    while(i<j) {
        while(i<j && a[j]<0) {
            j--;
        }
        
        while(i<j && a[i]>=0) {
            i++;
        }
        swap(a[i],a[j]);
    }
}
int main()
{
    int a[]={-1,-1,-2,-3,-4,-5,0,1,2,3,4,5,6};
    separatepn(a,sizeof(a)/sizeof(int));
    for(auto i:a) {
        cout << i << " ";
    }
}