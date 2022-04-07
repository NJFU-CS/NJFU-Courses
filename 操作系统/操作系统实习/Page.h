#ifndef PAGE_CPP
#define PAGE_CPP
#include <iostream>
struct Page {
    int pagenum;
    int count;
    int next;
    bool visited;
    Page() : count(0) ,visited(true){}
    Page(int num) : Page() { pagenum = num; }
    //show what in RAM
    bool operator==(Page p){
        return pagenum==p.pagenum;
    }
    friend std::ostream &operator<<(std::ostream &os, Page obj) {
        os << "{"<<obj.pagenum <<":"<<obj.count << ":"<<obj.next << std::boolalpha<<":"<<obj.visited<<"}";
        return os;
    }
};
#endif