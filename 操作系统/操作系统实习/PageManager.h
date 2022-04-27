#ifndef PAGEMANAGER_h
#define PAGEMANAGER_h
#include "Page.h"
#include "RAM.h"
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>

using std::pair;
using std::vector;

class PageManager {
  private:
    RAM ram;           //RAM
    vector<Page> order; // order_storage
    void next();

  public:
    PageManager();
    PageManager(vector<Page> order);
    PageManager(const PageManager &obj);
    ~PageManager();
    int get_RAM_Size() { return ram.getSIZE(); }
    void set_RAM_SIZE(int num) { ram.setSIZE(num); }
    bool OPT(int i);
    bool FIFO(int i);
    bool LRU(int i);
    bool CLOCK(int i);
    void clear();
};
PageManager::PageManager() { next(); }

PageManager::PageManager(vector<Page> order){
    this->order = order;
    next();
}

PageManager::PageManager(const PageManager &obj){
    ram = obj.ram;
    order = obj.order;
    next();
}

void PageManager::clear() { ram.clear(); }

PageManager::~PageManager() {}

void PageManager::next() {
    vector<pair<int, int>> pre; //保存已访问过的<pagenum,postion>
    int order_size = order.size();
    for (int i = order_size - 1; i >= 0; i--) {
        Page &p = order.at(i);
        // std::cout << p << std::endl;
        vector<pair<int, int>>::iterator pos =
            std::find_if(pre.begin(), pre.end(),
                         [p](auto page) { return p.pagenum == page.first; });

        if (pos == pre.end()) {
            // not found
            pre.push_back(std::make_pair<>(p.pagenum, i));
            // std::cout << "first push back" << p.pagenum << ":" << std::endl;
            p.next = order_size;
        } else {
            p.next = (*pos).second;
            // std::cout << "change" << p.pagenum << ":" << i << std::endl;
            (*pos).second = i;
        }
    }
    // std::copy(std::begin(order), std::end(order),
    //           std::ostream_iterator<Page>(std::cout, " "));
    // std::cout << std::endl;
}

bool PageManager::OPT(int i) {
    // init next
    bool flag = false;
    int order_size = order.size();
    // std::cout << ram.getCurSize() << std::endl;
    auto arr = ram.getPage();
    auto page = order.at(i);
    auto p = std::find_if(arr.begin(), arr.end(), [page](const Page &a) {
        return a.pagenum == page.pagenum;
    });
    if (p != arr.end()) {
        // find in RAM
        int choose = p - arr.begin();
        ram.setPage(choose, order.at(i));
    } else {
        flag = true;
        if (ram.getCurSize() < ram.getSIZE()) {
            ram.asList().push_back(order.at(i));
        } else {
            auto arr = ram.getPage();
            auto choose =
                std::max_element(arr.begin(), arr.end(), [](auto a, auto b) {
                    return a.next < b.next;
                });
            int choose_num = choose - arr.begin();
            ram.setPage(choose_num, order.at(i));
        }
    }
    // std::cout << ram << std::endl;
    return flag;
}

bool PageManager::FIFO(int i) {
    // std::copy(std::begin(order), std::end(order),
    //           std::ostream_iterator<Page>(std::cout, " "));
    bool ret = false;
    // for (int i = 0; i < order.size(); i++) {
    vector<Page> pages = ram.getPage();
    auto p = std::find(pages.begin(), pages.end(), order.at(i));
    if (p != pages.end()) {
        // found
        ;
    } else {
        if (ram.getCurSize() < ram.getSIZE()) {
            ram.asList().push_back(order.at(i));
        } else {

            auto max = std::max_element(
                pages.begin(), pages.end(),
                [](auto a, auto b) { return a.count < b.count; });
            int choose = max - pages.begin();
            ram.setPage(choose, order.at(i));
        }
        ret = true;
    }
    auto &list = ram.asList();
    std::for_each(list.begin(), list.end(), [](auto &p) { p.count++; });
    // std::cout << ram << std::endl;
    // }
    // std::cout << "FIFO page exchange: INT = " << INT << "  INT rate = "
    //           << INT * 1.0 / (order.size()) << std::endl;
    return ret;
}

bool PageManager::LRU(int i) {
    // std::copy(std::begin(order), std::end(order),
    //           std::ostream_iterator<Page>(std::cout, " "));
    bool flag = false;
    auto arr = ram.getPage();
    Page &page = order.at(i);
    auto p = std::find_if(arr.begin(), arr.end(), [page](Page &obj) {
        return page.pagenum == obj.pagenum;
    });
    if (p == arr.end()) {
        // not found
        flag = true;
        if (ram.getCurSize() <ram.getSIZE()) {
            ram.asList().push_back(order.at(i));
            // std::cout << "add " << order.at(i) << std::endl;
        } else {
            // std::cout << "remove " << *ram.asList().begin() << std::endl;
            ram.asList().erase(ram.asList().begin());
            ram.asList().push_back(order.at(i));
            // std::cout << "push_back " << order.at(i) << std::endl;
        }
        return true;
    } else {
        // found
        Page temp = *p;
        auto &list = ram.asList();
        // std::cout << "remove " << temp << std::endl;
        list.remove(temp);
        list.push_back(temp);
        // std::cout << "push_back " << temp << std::endl;
        return false;
    }
    // std::cout << ram << std::endl;
}

bool PageManager::CLOCK(int i) {
    // std::copy(std::begin(order), std::end(order),
    //           std::ostream_iterator<Page>(std::cout, " "));
    bool flag = false;
    auto arr = ram.getPage();
    Page &page = order.at(i);
    auto p = std::find_if(arr.begin(), arr.end(), [page](Page &obj) {
        return page.pagenum == obj.pagenum;
    });
    if (p == arr.end()) {
        // not found
        flag = true;
        if (ram.getCurSize() < ram.getSIZE()) {
            ram.asList().push_back(order.at(i));
            // std::cout << "add " << order.at(i) << std::endl;
        } else {
            auto &list = ram.asList();
            auto q =
                std::find_if(list.begin(), list.end(), [](const Page page) {
                    return page.visited == false;
                });
            // TODO: why this is not working

            // std::for_each(list.begin(), list.end(), [&](Page &page) {
            //     if (page.visited == true)
            //         page.visited ==false;
            // });
            for (auto &i : list) {
                if (i.visited == true) {
                    i.visited = false;
                }
            }
            if (q != list.end()) {
                // found
                // std::cout << *q << "ChangeTo";
                *q = order.at(i);
                // std::cout << order.at(i) << std::endl;
            } else {
                // std::cout << *list.begin() << "ChangeTo" << order.at(i)
                //           << std::endl;
                ram.setPage(0, order.at(i));
            }
        }

    } else {
        // found
        // std::cout << "found" << *p << std::endl;
        int choose = p - arr.begin();
        auto z = ram.asList().begin();
        for (int i = 0; i < choose; i++) {
            z++;
        }
        z->visited = false;
        auto &list = ram.asList();
        for (auto &i : list) {
            if (i.visited == true) {
                i.visited = false;
            }
        }
        // std::cout << ram << std::endl;
    }
    return flag;
}
#endif
