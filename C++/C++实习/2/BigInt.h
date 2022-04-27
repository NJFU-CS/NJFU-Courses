#pragma once
#include <list>
#include <string>
#include <sstream>
class BigInt
{
private:
    std::list<int> data;
    std::stringstream ss;

public:
    BigInt();
    BigInt(std::string s);
    std::string toString();
};

