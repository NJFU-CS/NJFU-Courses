/*
1．	八皇后问题
任务：国际西洋棋棋手马克斯·贝瑟尔于1848年提出在8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，
即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。请设计算法编写程序解决。要求：
（1）	求解并输出八皇后的一个解。
（2）	在（1）的基础上，求解并输出八皇后的所有解（92个解）。
*/
#include<iostream>
#include<cstdio>
using namespace std;

int chess[9];
int count = 0;

bool check(int a[],int i) {
    int j;
    for(j=1;j<i;j++) {
        if(abs(a[j]-a[i])==abs(i-j) || a[i] == a[j]) {
            return false;
        }
    }
    return true;
}

void Print_ans() {
    int i;
    for(i = 1; i< 9;i++) {
        cout << chess[i] << ' ';
    }
    cout << endl;
}

//八叉树递归
void solve(int i) {
    if(i>8) {
        Print_ans();
        count++;
        return ;
    }
    for(int j=1 ; j<=8 ; ++j ) {
        chess[i] = j;
        if(check(chess,i)) {
            solve(i+1);
        }
    }
    
}
int main()
{
    solve(1);
    cout << count << endl;
}