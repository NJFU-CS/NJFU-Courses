// 程序：给定一个进程执行时的访问页面数N，进程拥有的内存块个数M，以及进程执行时页面访问次序数组page。
// 采用最佳淘汰算法OPT和最近最久未使用淘汰算法LRU，通过编程，计算这两种方法的缺页次数以及缺页率。
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct page
{
    int ID;
    int next;
    bool operator==(page &p){
        return ID == p.ID;
    }
};

class OPT
{
private:
    page p[20] =    {{7, 100}, {0, 100}, {1, 100}, {2, 100}, {0, 100}, 
                    {3, 100}, {0, 100}, {4, 100}, {2, 100}, {3, 100}, 
                    {0, 100}, {3, 100}, {2, 100}, {1, 100}, {2, 100}, 
                    {0, 100}, {1, 100}, {7, 100}, {0, 100}, {1, 100}};
    vector<page> block;
    int INT = 0;

    int Max(){
        page max = {0,-1};
        int m = -1;
        for (int i = 0; i < block.size();i++)
        {
            if(block[i].next>max.next){
                max = block[i];
                m = i;
            }
        }
        return m;
    }

    int inBlock(page &p){
        for (int i = 0; i < block.size();i++){
            if(block[i]==p){
                return i;
            }
        }
        return -1;
    }

    void print(){
        for(auto i:block){
            cout << i.ID << " ";
        }
        cout << endl;
    }
public:
    OPT(){
        for (int i = 20; i >= 0; i--)
        {
            int pos = i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (p[j].ID == p[i].ID)
                {
                    p[j].next = pos;
                    pos = j;
                }
            }
        }
    }

    void option(){
        block.push_back(p[0]);
        block.push_back(p[1]);
        block.push_back(p[2]);
        for (int i = 3; i < 20;i++){
            if(inBlock(p[i])==-1){
                INT++;
                block[Max()] = p[i];
                // print();
            }else{
                block[inBlock(p[i])] = p[i];
            }
        }
    }

    void result(){
        cout << "less of page index = " << INT << "   percent = " << INT* 1.0/20 << endl;
    }

    
};

class LRU{
    page p[20] =    {{7, 100}, {0, 100}, {1, 100}, {2, 100}, {0, 100}, 
                    {3, 100}, {0, 100}, {4, 100}, {2, 100}, {3, 100}, 
                    {0, 100}, {3, 100}, {2, 100}, {1, 100}, {2, 100}, 
                    {0, 100}, {1, 100}, {7, 100}, {0, 100}, {1, 100}};
    deque<page> block;
    int INT = 0;

public:


    int inBlock(page &p){
        for (int i = 0; i < block.size();i++){
            if(block[i]==p){
                return i;
            }
        }
        return -1;
    }

    void option(){
        for (int i = 0; i < 20;i++){
            if(inBlock(p[i])!=-1){
                page tmp = block[inBlock(p[i])];
                block.erase(block.begin()+inBlock(p[i]));
                block.push_back(tmp);
            }else{
                if(block.size()==3){
                    block.pop_front();
                }
                block.push_back(p[i]);
                INT++;
            }
            // print();
        }
    }
    void print(){
        for(auto i:block){
                cout << i.ID << " ";
            }
        cout << endl;
    }

    void result(){
        cout << "less of page index = " << INT << "   percent = " << INT* 1.0/20 << endl;
    }
};

int main()
{
    OPT opt;
    opt.option();
    opt.result();

    LRU lru;
    lru.option();
    lru.result();
}