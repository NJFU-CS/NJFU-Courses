#ifndef RW_CPP
#define RW_CPP

#include "ReservedWorld.h"
#include <iostream>
#include <algorithm>

ReservedWorld::ReservedWorld(/* args */)
{
    is = nullptr;
    os = nullptr;
}

ReservedWorld::~ReservedWorld()
{
    delete is;
    delete os;
}

void ReservedWorld::in(){
    is = new std::ifstream("src/data.dat");
    std::string s;
    while(*is >> s){
        data.push_back(s);
    }
    is->close();
    is->clear();
}

void ReservedWorld::count(){
    is = new std::ifstream("ReservedWorld.cpp");
    if(is){
        int reserve_count = 0;
        int not_reserve = 0;
        std::string s;
        while(*is >> s){
            // std::cout << s << " ";
            if(find(data.begin(),data.end(),s)!=data.end()){
                reserve_count++;
            }else{
                not_reserve++;
            }
        }
        is->close();
        is->clear();
        std::cout << reserve_count << std::endl
                << not_reserve;
        os = new std::ofstream("result/count.dat");
        *os << "reserve word = " << reserve_count << std::endl
            << "not reserve word = " << not_reserve << std::endl;
        os->close();
        os->clear();
    }else{
        std::cout << "readfile error" << std::endl;
    }

}

std::ostream &operator<<(std::ostream &os,ReservedWorld &obj){
    for(auto i:obj.data){
        os << i << ",";
    }
    return os;
}

#endif