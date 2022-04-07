// 	源数据文件中含有字符和数字，从中读取数值数据（将连续的数字字符看成一个数值数据），
// 和读取的单词（将连续的字母字符看成一个单词）分别存放在不同的文件中，并且排序后输出显示。
// 例如：源数据文件old.dat包括：asjjk 12rtr 345 dasdd9&k32*dfasfkjk##dasfdf897，
// 则生成的数据文件new1.data包括：12  345  9  32  897
// 单词文件new2.dat包括：asjjk　 rtr　 dasdd 　 k  dfasfkjk  dasfdf
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cctype>

class Analyze{
private:
    std::ifstream *is;
    std::ofstream *os1;
    std::ofstream *os2;
    std::stringstream ss;
    std::string s;

    std::vector<int> num;
    std::vector<std::string> str;

public:
    Analyze();
    ~Analyze();

    void in();
    void analyze();
    void out();
};

Analyze::Analyze(){
}

Analyze::~Analyze(){
    is->clear();
    os1->clear();
    os2->clear();
    delete is;
    delete os1;
    delete os2;
}

void Analyze::in(){
    is = new std::ifstream("src/old.dat");
    std::getline(*is, s);
    // std::cout << s << std::endl;
    is->close();
}

void Analyze::analyze(){
    std::string tmp = s;
    // std::cout << tmp << std::endl;
    std::replace_if(
        tmp.begin(), tmp.end(), [](char c)
        { return !isdigit(c); },
        ' ');
    ss << tmp;

    int anum;
    while(ss >> anum){
        num.push_back(anum);
    }

    ss.clear();
    tmp = s;
    std::replace_if(
        tmp.begin(), tmp.end(), [](char c)
        { return !(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'); },
        ' ');
    std::string astring;
    ss << tmp;
    while(ss >> astring){
        str.push_back(astring);
    }
    ss.clear();
}

void Analyze::out(){
    os1 = new std::ofstream("result/new1.dat");
    for(auto i:num){
        *os1 << i << "  ";
    }
    os1->clear();

    os2 = new std::ofstream("result/new2.dat");
    for(auto i:str){
        *os2 << i << "  ";
    }
    is->clear();
}

int main(){
    Analyze analuze;
    analuze.in();
    analuze.analyze();
    analuze.out();
}