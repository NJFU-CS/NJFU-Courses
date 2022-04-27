#ifndef COST_H
#define COST_H

#include<iostream>
#include<fstream>
#include<vector>
#include"Item.cpp"

class Cost{
private:
    std::ifstream* is;
    std::ofstream* os;
    std::vector<Item> data;

public:
    Cost();
    ~Cost();
    void in();
    void out();
    void cost();
    //只是为了调试方便
    friend std::ostream &operator<<(std::ostream &os, const Cost &cost);

};

#endif