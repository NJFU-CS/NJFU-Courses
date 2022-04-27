#include "BigInt.h"

BigInt::BigInt()
{
    data.push_back(-1);
}

BigInt::BigInt(std::string s) : BigInt()
{
    int num = 0;
    int i = 0;
    for (i = s.length() - 4; i > 0; i -= 4)
    {
        // std::cout << i << ";";

        ss << s.substr(i, 4);
        ss >> num;
        ss.clear();
        data.push_back(num);
    }
    ss << s.substr(0, i + 4);
    ss >> num;
    ss.clear();
    data.push_back(num);
}

std::string BigInt::toString()
{
    std::string result, s;
    auto i = data.end();
    i--;
    while (i != data.begin())
    {
        
        ss << *i;
        ss >> s;
        if(s.size()<4){
            result.append(4 - s.size(), '0');
        }
        result += s;
        // result += ',';
        i--;
        ss.clear();
    }
    result.erase(0, result.find_first_not_of('0'));
    return result;
}