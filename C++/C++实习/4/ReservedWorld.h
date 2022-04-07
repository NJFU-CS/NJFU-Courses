#ifndef RW_H
#define RW_H

#include<iostream>
#include<fstream>
#include<vector>

class ReservedWorld
{
private:
    std::ifstream *is;
    std::ofstream *os;
    std::vector<std::string> data;

public:
    ReservedWorld(/* args */);
    ~ReservedWorld();

    //只是为了方便
    friend std::ostream &operator<<(std::ostream &os, ReservedWorld &obj);

    void in();
    void count();
};

#endif