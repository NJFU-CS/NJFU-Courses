// 第7题：设计一个超长整数类
// 定义并实现超长整数类doublelong，要求如下：
// 64位数据长度，有符号
// 支持＋、－、＊、／运算
// 支持＋＝、－＝、／＝运算
// 支持cin>>和cout<<操作
#include<iostream>
#include"doublelong.cpp"
int main(){
    doublelong d1("9");
    doublelong d2("-91");
    std::cout << d2 * d1;
}
//111111
//222