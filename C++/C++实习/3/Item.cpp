#ifndef ITEM_CPP
#define ITEM_CPP

#include "Item.h"
#include<iostream>
std::istream &operator>>(std::istream &is,Item &item){
    is >> item.num;
    int serve;
    is >> serve;
    item.serve = (Item::Serve)serve;
    is >> item.time;
    return is;
}

std::ostream &operator<<(std::ostream &os, Item &i){
    os << i.getNum() << " " << i.getServe() << " " << i.getTime() << std::endl;
    return os;
}
#endif