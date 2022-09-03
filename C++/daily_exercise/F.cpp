/*F (0) =0，F(1)=1           (n<2)         
F (n) =47 * F (n-1) + 99 * F (n-2)   (n>1)；
设计一个函数，该函数的功能是求出F(n)%c的值，其中n < 2^62，c 是小于 500的素数。
*/
#include<iostream>
using namespace std;

long F(long n)
{
    if(n>1){
        return 47*F(n-1)+99*F(n-2);
    }else if(n==1){
        return 1;
    }else{
        return 0;
    }
}
int main()
{
    long n;
    cin>>n;
    cout<<F(n)<<endl;
    return 0;
}
