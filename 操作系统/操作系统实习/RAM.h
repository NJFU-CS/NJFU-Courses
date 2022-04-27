#ifndef RAM_H
#define RAM_H
#include "Page.h"
#include <iostream>
#include <list>
#include <vector>
#include <assert.h>

using std::list;
using std::vector;

class RAM {
  private:
    int SIZE;
    list<Page> pages;

  public:
    RAM() { SIZE = 20; }
    RAM(int size);
    ~RAM();
    int getCurSize();
    void setSIZE(int size) { SIZE = size; }
    int getSIZE() { return SIZE; }
    vector<Page> getPage() const;
    list<Page> &asList();
    void setPage(int index, Page p);
    void clear();

    friend std::ostream &operator<<(std::ostream &os, const RAM &ram) {
        std::cout << "RAM : " << std::endl;
        for (Page i : ram.getPage()) {
            os << i << " ";
        }
        os << std::endl;
        return os;
    }
    RAM operator=(RAM obj) { pages = obj.pages;
        SIZE = obj.SIZE;
        return *this;
    }
};

RAM::RAM(int size) : SIZE(size) {}

RAM::~RAM() {}

int RAM::getCurSize() { return pages.size(); }

vector<Page> RAM::getPage() const {
    // std::cout << "!!!SIZE  = = " << pages.size() << std::endl;
    return vector<Page>(pages.begin(), pages.end());
}

list<Page> &RAM::asList() { return this->pages; }

void RAM::setPage(int index, Page page) {
    if(getCurSize()<SIZE){
        pages.push_back(page);
        // std::cout << "add " << page << std::endl;
    }else{
        auto p = pages.begin();
        for (int i = 0; i < index; i++) {
            p++;
        }
        // std::cout << *p << " changeTo ";
        *p = page;
        // std::cout << page << std::endl;
    }
}

void RAM::clear() { pages.clear(); }
#endif