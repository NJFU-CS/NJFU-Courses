#include "doublelong.h"
#include <algorithm>
#include <cassert>
#include <sstream>
doublelong::doublelong()
{
    flag = true;
}

doublelong::doublelong(std::string s) : doublelong()
{
    if (s.at(0) == '-')
    {
        flag = false;
        s.erase(s.begin());
    }
    this->s = s;
}
doublelong::doublelong(int num):doublelong(){
    if(num < 0){
        flag = false;
        num = -num;
    }
    std::stringstream ss;
    ss << num;
    ss >> s;
}

void doublelong::reserve_flag(){
    if(flag){
        flag = false;
    }else{
        flag = true;
    }
}

bool doublelong::operator<(const doublelong &obj)const{
    if(flag && !obj.flag){
        return true;
    }else if(!flag && obj.flag){
        return false;
    }else if(flag && obj.flag){
        if(s.length()<obj.s.length()){
            return true;
        }else if(s.length()>obj.s.length()){
            return false;
        }else{
            int i = 0;
            while (i < s.length()){
                if(s.at(i)<obj.s.at(i)){
                    return true;
                }
                if(s.at(i)>obj.s.at(i)){
                    return false;
                }
                i++;
            }
            return false;
        }
        return false;
    }
    return false;
}

bool doublelong::operator>(const doublelong &obj)const{
    return obj < *this;
}

bool doublelong::operator==(const doublelong &obj)const{
    return s == obj.s && flag == obj.flag;
}

bool doublelong::operator!=(const doublelong &obj)const{
    return !(*this == obj);
}

bool doublelong::operator<=(const doublelong &obj)const{
    return !(*this > obj);
}

bool doublelong::operator>=(const doublelong &obj)const{
    return !(*this < obj);
}

std::ostream &operator<<(std::ostream &os, const doublelong &obj)
{
    os << (obj.flag ? "" : "-") << obj.s << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, doublelong &obj)
{
    std::string s;
    is >> s;
    doublelong dl(s);
    obj = dl;
    return is;
}

doublelong doublelong::plus(const doublelong &obj)const
{
    assert(flag && obj.flag);
    std::string ls, rs;
    ls = this->s;
    rs = obj.s;
    std::reverse(ls.begin(), ls.end());
    std::reverse(rs.begin(), rs.end());

    while (ls.length() != rs.length())
    {
        if (ls.length() < rs.length())
        {
            ls += '0';
        }
        else
        {
            rs += '0';
        }
    }
    // std::cout << ls << std::endl
    //           << rs << std::endl;
    int carry = 0;
    int cur = 0;
    std::string result;
    for (int i = 0; i < ls.length(); i++)
    {
        cur = ls.at(i) - '0' + rs.at(i) - '0' + carry;
        if (cur > 9)
        {
            carry = 1;
            cur -= 10;
        }
        else
        {
            carry = 0;
        }
        result += (cur + '0');
    }
    if (carry)
        result += '1';
    std::reverse(result.begin(), result.end());
    return doublelong(result);
}

doublelong doublelong::minus(const doublelong &obj)const
{
    assert(flag && obj.flag);
    // std::cout << this->s << std::endl
    //           << obj.s << std::endl;
    std::string ls, rs;
    if(*this < obj){
        ls = obj.s;
        rs = this->s;
    }else{
        ls = this->s;
        rs = obj.s;
    }
    std::reverse(ls.begin(), ls.end());
    std::reverse(rs.begin(), rs.end());

    while (ls.length() != rs.length())
    {
        if (ls.length() < rs.length())
        {
            ls += '0';
        }
        else
        {
            rs += '0';
        }
    }
    int borrow = 0;
    int cur = 0;
    std::string result;
    for (int i = 0; i < ls.size(); i++)
    {
        cur = ls[i] - '0' - (rs[i] - '0') - borrow;
        // std::cout << cur << std::endl;
        if (cur < 0)
        {
            borrow = 1;
            cur += 10;
        }
        else
        {
            borrow = 0;
        }
        result += (char)(cur + '0');
    }
    std::reverse(result.begin(), result.end());
        // std::cout << result << std::endl;
    if(result.find_first_not_of('0')==std::string::npos){
        return doublelong(0);
    }
    result.erase(0, result.find_first_not_of('0'));
    doublelong ret(result);
    if(*this < obj){
        ret.reserve_flag();
    }
    return ret;
}

doublelong doublelong::mutil(int num)const{
    std::string ls = s;
    std::string result;
    std::reverse(ls.begin(),ls.end());
    int carry = 0;
    int cur = 0;
    for(int i=0;i<ls.size();i++){
        int tmp = (ls.at(i)-'0')*num + carry;
        if(tmp > 9){
            carry = tmp / 10;
        }else{
            carry = 0;
        }
        cur = tmp % 10;
        result+=cur+'0';
    }
    if(carry!=0){
        result+=carry+'0';
    }
    std::reverse(result.begin(),result.end());
    doublelong ret(result);
    if(!flag){
        ret.reserve_flag();
    }
    return ret;
}

doublelong doublelong::operator+(const doublelong &obj)const
{
    doublelong dl;
    if (flag && obj.flag)
    {
        dl = plus(obj);
    }else if(flag && !obj.flag){
        doublelong tmp = obj;
        tmp.reserve_flag();
        dl = minus(tmp);
    }else if(!flag && obj.flag){
        doublelong tmp = *this;
        tmp.reserve_flag();
        dl = obj.minus(tmp);
    }else{
        doublelong a = *this;
        a.reserve_flag();
        doublelong b = obj;
        b.reserve_flag();
        dl = a.plus(b);
        dl.reserve_flag();
    }
    return dl;
}

doublelong doublelong::operator-(const doublelong &obj)const{
    doublelong dl;
    doublelong tmp = obj;
    tmp.reserve_flag();
    dl = *this + tmp;
    return dl;
}

doublelong&doublelong::operator++(){
    *this = *this + doublelong("1");
    return *this;
}

doublelong doublelong::operator++(int){
    doublelong old = *this;
    ++*this;
    return old;
}

doublelong&doublelong::operator--(){
    *this = *this - doublelong("1");
    return *this;
}

doublelong doublelong::operator--(int){
    doublelong old = *this;
    --*this;
    return old;
}

doublelong doublelong::operator*(const doublelong &obj)const{
    std::string ls = s,rs = obj.s;

    doublelong a(ls),b(rs);
    if(a<b){
        std::swap(a,b);
    }
    // std::cout << ls << std::endl << rs;
    doublelong ret("0");
    for(int i=0;i<b.s.length();i++){
        ret = ret.mutil(10);                                                                                                                                                                                                                                                                                                                                   
        ret = ret + a.mutil(b.s.at(i)-'0');
    }
    if(flag && obj.flag || !flag && !obj.flag){
        ;
    }else{
        ret.reserve_flag();
    }
    // std::cout << std::boolalpha << ret.flag;
    return ret;
}

doublelong doublelong::operator/(const doublelong &obj)const{
    doublelong ret;
    std::string lvalues(s), rvalues(obj.s);
    std::string quotient;
    std::string temp;
    if(rvalues == "0")
    {
        ret.s = "error";//输出错误
        ret.flag = true;
        return ret;
    }
    if(lvalues == "0")
    {
        ret.s = "0";
        ret.flag = true;
        return ret;
    }
 
    if(*this<obj)
    {
        ret.s = "0";
        ret.flag = true;
        return ret;
    }
    else if(*this==obj)
    {
        ret.s = "1";
        ret.flag = true;
        return ret;
    }
    else
    {
        unsigned int lsize, rsize;
        lsize = lvalues.size();
        rsize = rvalues.size();
        int i;
        if(rsize > 1) temp.append(lvalues, 0, rsize-1);
        for(i = rsize - 1; i < lsize; i++)
        {
            if(temp=="0"){
                temp = lvalues[i];
            }else{
                temp = temp + lvalues[i];
            }
            // std::cout << temp << std::endl;
            //试商
            for(char c = '9'; c >= '0'; c--)
            {
                doublelong t = (doublelong)rvalues * (doublelong)std::string(1, c);
                doublelong s = (doublelong)temp - t;
                if(s.flag == true)
                {
                // std::cout << s << std::endl;
                    temp = s.s;
                    quotient = quotient + c;
                    // std::cout << temp << std::endl;
                    break;
                }
            }
        }
    }
    //去除前导零
    quotient.erase(0, quotient.find_first_not_of('0'));
    ret.s = quotient;
    if(flag&&obj.flag || !flag&&!obj.flag){
        ;
    }else{
        ret.reserve_flag();
    }
    return ret;
}

doublelong doublelong::operator%(const doublelong &obj)const{
    return *this - *this / obj * obj;
}

doublelong &doublelong::operator+=(const doublelong &obj){
    *this = *this + obj;
    return *this;
}

doublelong &doublelong::operator-=(const doublelong &obj){
    *this = *this - obj;
    return *this;
}

doublelong &doublelong::operator*=(const doublelong &obj){
    *this = *this * obj;
    return *this;
}

doublelong &doublelong::operator/=(const doublelong &obj){
    *this = *this / obj;
    return *this;
}