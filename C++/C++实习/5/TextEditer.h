#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

class TextEditer
{
private:
    std::ifstream *is;
    std::ofstream *os;
    std::vector<std::string> text;
    std::vector<std::string> buffer;
    std::stringstream ss;
    void List(std::string &sub);
    void Insert(std::string &sub, int m);
    void Delete(int begin, int end);

public:
    TextEditer(/* args */);
    ~TextEditer();
    //只是为了方便
    friend std::ostream &operator<<(std::ostream &os,TextEditer &textediter){
        int count = 0;
        for(auto i:textediter.text){
            os << ++count << ":  " << i << std::endl;
        }
        return os;
    }
    void in();
    void out();
    void mainProcess();
};
