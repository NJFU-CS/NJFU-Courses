#ifndef ITEM_H
#define ITEM_H

#include<iostream>
class Item{
private:
    std::string num;
    long time;
    enum Serve
    {
        stable_long_in, stable_local_in, free_long_in, free_local_in, stable_long_out, stable_local_out, free_long_out, free_local_out
    }serve;

public:
    friend std::istream &operator>>(std::istream &is, Item &item);
    friend std::ostream &operator<<(std::ostream &os, Item &item);
    std::string getNum(){
        return num;
    }
    long getTime(){
        return time;
    }
    int getServe(){
        return serve;
    }
};

#endif