#include<iostream>

class doublelong{
private:
    std::string s;
    bool flag;
    doublelong plus(const doublelong &obj)const;
    doublelong minus(const doublelong &obj)const;
    doublelong mutil(int num)const;
public:
    void reserve_flag();
    std::string getString(){
        return s;
    }
    doublelong();
    doublelong(std::string s);
    doublelong(int num);
    bool operator<(const doublelong &obj)const;
    bool operator>(const doublelong &obj)const;
    bool operator==(const doublelong &obj)const;
    bool operator!=(const doublelong &obj)const;
    bool operator<=(const doublelong &obj)const;
    bool operator>=(const doublelong &obj)const;
    doublelong operator+(const doublelong &obj)const;
    doublelong operator-(const doublelong &obj)const;
    doublelong&operator++();
    doublelong operator++(int);
    doublelong&operator--();
    doublelong operator--(int);
    doublelong operator*(const doublelong &obj)const;
    doublelong operator/(const doublelong &obj)const;
    doublelong operator%(const doublelong &obj)const;
    doublelong &operator+=(const doublelong &obj);
    doublelong &operator-=(const doublelong &obj);
    doublelong &operator*=(const doublelong &obj);
    doublelong &operator/=(const doublelong &obj);
    friend std::ostream &operator<<(std::ostream &os, const doublelong &obj);
    friend std::istream &operator>>(std::istream &os, doublelong &obj);
};
