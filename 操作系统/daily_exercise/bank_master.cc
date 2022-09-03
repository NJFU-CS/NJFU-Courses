#include <iostream>
#include <vector>
using namespace std;

template<class T>
void operator+=(vector<T> &a,vector<T> &b){
    if(a.size()==b.size()){
        for (int i = 0; i < a.size();i++){
            a.at(i) += b.at(i);
        }
    }
}

template<class T>
void operator-=(vector<T> &a,vector<T> &b){
    if(a.size()==b.size()){
        for (int i = 0; i < a.size();i++){
            a[i] -= b[i];
        }
    }
}

template<class T>
bool operator<=(const vector<T> &a,const vector<T> &b){
    if(a.size()==b.size()){
        for (int i = 0; i < a.size();i++){
            if(a[i] > b[i]){
                return false;
            }
        }
        return true;
    }else{
        cout << "length error" << endl;
        exit(0);
    }
}

template<class T>
bool operator>=(const vector<T> &a,const vector<T> &b){
    if(a.size()==b.size()){
        for (int i = 0; i < a.size();i++){
            if(a[i] < b[i]){
                return false;
            }
        }
        return true;
    }else{
        cout << "length error" << endl;
        exit(0);
    }
}

class Martex {
private:
    int PID;
    int PID_NUM = 5;
    vector<int> request;
    vector<int> available = {3, 3, 2};
    vector<vector<int>> max = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    vector<vector<int>> allocation = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    vector<vector<int>> need = {{7, 4, 3}, {1, 2, 2}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1}};

public:
    Martex(int _PID,vector<int>& _request){
        PID = _PID-1;
        request = _request;
    }
    //尝试接受
    bool accept(){
        if(request<=need[PID] && request <= available){
            return true;
        }else{
            return false;
        }
        
    }
    //分配
    void option(){
        allocation[PID] += request;
        need[PID] -= request;
        available -= request;
    }

    bool safeTest(){
        vector<int> work = available;
        bool finish[PID_NUM] = {false};
        int sum = 0;
        for(int j=0;j<PID_NUM;j++){
            
            for (int i = 0; i < PID_NUM;i++){
                if(finish[i]==true){
                    continue;
                }else if(finish[i]==false && need[i]<=work){
                    work += need[i];
                    finish[i] = true;
                    sum = 0;
                    for(auto i:finish){
                        sum += i;
                    }
                    if(sum==PID_NUM){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    //打印表格
    void show()
    {
        cout << "max" << endl;
        for (auto i : max)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        cout << endl
             << "allocation" << endl;
        for (auto i : allocation)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        cout << endl
             << "need" << endl;
        for (auto i : need)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        cout << endl
             << "available" << endl;
        for (auto i : available)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};
    


class bankMaster
{
private:
    vector<int> request = {2 ,2, 1};
    Martex martex = *(new Martex(1,request));
public:
    void show(){
        martex.show();
    }
    void setRequest(){
        cout << "cin three dimension vector" << endl;
        int a, b, c;
        cin >> a >> b >> c;
        request.clear();
        request.push_back(a);
        request.push_back(b);
        request.push_back(c);
    }
    void flush()
    {
        if(martex.accept()){
            if(martex.safeTest()){
                martex.option();
                cout << "do request" << endl;
            }else{
                cout << "unsafe" << endl;
                exit(0);
            }
        }else{
            cout << "check request" << endl;
            exit(0);
        }
    }

    
};

int main()
{
    bankMaster b;
    b.show();
    b.setRequest();
    b.flush();
}