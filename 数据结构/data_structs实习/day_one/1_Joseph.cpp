/*
1．	约瑟夫环
任务：一堆猴子都有编号，编号是1，2，3 ... n ,这群猴子（n个）按照1 ~ n的顺序围坐一圈，
从第1开始数，每数到第m个，该猴子就要离开此圈，这样依次下来，直到圈中只剩下最后一只猴子，
则该猴子为大王。请设计算法编写程序输出为大王的猴子的编号。
*/

#include<stdio.h>
#include<stdlib.h>

int Joseph(int n,int m) {
    int *a = (int *)malloc(sizeof(int)*(n+1));
    int i;
    //初始化
    for( i=1 ; i< n+1; ++i) {
        a[i] = 1;
    }

    int j=0;//报数
    int count = 0;//计数
    int outnum = 0;//走的个数
    while(1) {
        j++;
        if(j>=n+1) j-=n; //j循环报数
        if(a[j]==1) {
            count++;
        }
        if(count == m) {
            a[j] = 0;
            count = 0;
            outnum++;
        }
        if(outnum == n-1) {
            break;
        }
    }
    for(j=1;j<n+1;j++) {
        if(a[j]==1) {
            return j;
        }
    }
    delete []a;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",Joseph(n,m)) ;
}