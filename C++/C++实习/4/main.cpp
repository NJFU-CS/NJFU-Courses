// 第4题：设计一个保留字（或关键字）的统计程序
// 建立保留字文件；
// 从源数据文件（C或C++语言程序）中，读取字符或字符串，
// 与保留字文件中的保留字进行匹配比较，并统计计数。
// 输出两张表文件：保留字计数，扫描程序的次数，非保留字计数。

#include "ReservedWorld.cpp"
#include <iostream>

int main(){
    ReservedWorld rw;
    rw.in();
    // std::cout << rw;
    rw.count();
}