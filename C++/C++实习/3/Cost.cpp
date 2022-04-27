#ifndef COST_CPP
#define COST_CPP

#include "Cost.h"
#include <iostream>
#include <algorithm>
#include <map>

Cost::Cost()
{
    is = nullptr;
    os = nullptr;
}

Cost::~Cost(){
    delete is;
    delete os;
}

void Cost::in(){
    is = new std::ifstream("src/data.dat");
    if(is==nullptr){
        std::cout << "input error" << std::endl;
        exit(0);
    }
    Item item;
    while(*is>>item){
        data.push_back(item);
    }
}

void Cost::out(){
    const std::vector<std::string> s{"free_in","stable_long_out", "stable_local_out", "free_long_out", "free_local_out"};
    for (int i = 0; i < s.size();i++){
        os = new std::ofstream("result/"+s.at(i)+".dat");
        std::for_each(data.begin(), data.end(), [i,this](Item &item)
                      {
                          if (item.getServe() == i)
                          {
                              *(this->os) << item;
                          }
                      });
    }
}

void Cost::cost(){
    std::map<std::string, double> cost;
    float money[] = {0.50, 0.02, 0.06, 1.00, 0.60};
    for(auto i:data){
        float plus = money[i.getServe()] * i.getTime();
        if(cost.find(i.getNum())!=cost.end()){
            //存在
            cost.find(i.getNum())->second += plus;
        }else{
            cost.insert({i.getNum(),plus});
        }
    }
    // for(auto i:cost){
    //     std::cout << std::fixed <<i.first << ":" << i.second << std::endl;
    // }
    os = new std::ofstream("result/cost.dat");
    std::for_each(cost.begin(), cost.end(), [this](const std::pair<std::string, double> &pair)
                  { *(this->os) << std::fixed <<pair.first << " cost is " << pair.second << std::endl; });
    os->close();
    os->clear();
}

std::ostream &operator<<(std::ostream &os, const Cost &cost){
    for(auto i:cost.data){
        os << i.getNum() << " " << i.getServe() << " " << i.getTime() << std::endl;
    }
    return os;
}

#endif