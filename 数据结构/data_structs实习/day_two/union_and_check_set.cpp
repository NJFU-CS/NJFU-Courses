/*
1．	并查集
任务：用树形结构来表示集合，树的每个结点代表一个集合元素。实现查找（判定）元素所属集合的运算、实现集合的并运算。
功能要求：
1)	建立并输出集合的存储结构；
2)	设计并实现查找（判定）元素所属集合的运算；
3)	设计并实现集合的并运算。
界面要求：程序运行后，给出菜单项的内容和输入提示：
1.	建立集合
2.	查找（判定）元素所属集合
3.	集合的并运算
0.	退出
请选择0-3：
*/
#include<iostream>
using namespace std;

int a[10] ={-1,-1,1,2,3,-1,-1,-1,-1,-1};

int Find(int x) {
    if(-x!=a[x]) {
        a[x] = Find(a[x]);
    }
    return -a[x];
}

void un_ion(int x,int y) {
    int root1 = Find(x);
    int root2 = Find(y);
    if(a[root1]<a[root2]) {
        a[root2] = root1;
        a[root1] = root1+root2;
    }else{
        a[root1] = root2;
        a[root2] = root1+root2;
    }
}

void build() {
     for(int i=0;i<10;i++) {
        a[i] = -i;
    }
}

int main()
{
    int i;
    
    while(1){
        cin >> i;
        switch (i)
        {
            case 1:build();break;
            case 2:int num ; cin >> num ;cout <<  num << " in set " << Find(num) << endl;break;
            case 3:int a,b; cin >> a >> b; un_ion(a,b);break;
            default: i = -100; break;
        }
        if(i==-100) {
            break;
        }
    }
    for(int i=0;i<10;i++) {
        cout << a[i] << " ";
    }
}
/*1 3 1 2 2 2 0 */