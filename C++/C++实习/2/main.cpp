// 链表的头结点值为-1，其余结点依次存放数据，各结点最多放四位整数，如下图表示233238766：
 
// 利用上述数据结构解决大整数的表示，以及加法、减法运算（用两个链表表示操作数）。
// 将上述数据结构应用于10位以上求素数问题和阶乘问题。
#include "../7/doublelong.cpp"
#include "BigInt.cpp"
bool isPrime(BigInt &obj){
    doublelong n(obj.toString());
    doublelong i(2);
    for (; i * i <= n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

BigInt A(BigInt &obj){
    doublelong n(obj.toString());
    doublelong result(1);
    for (doublelong i = n; i > 0;i--){
    // std::cout << i;
        result *= i;
    }
    return result.getString();
}
int main(){
    BigInt bi("500");
    std::cout << A(bi).toString();
}
