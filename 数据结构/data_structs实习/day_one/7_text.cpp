/*
7．	文章编辑
任务：静态存储一页文章，每行最多不超过80个字符，共N行。统计文中所出现的英文字母的个数、数字的个数、空格的个数、总字数等。 
功能要求：
（1）分别统计出其中英文字母数和空格数及整篇文章总字数；
（2）统计某一字符串在文章中出现的次数，并输出该次数；
（3）删除某一子串，并将后面的字符前移。
输入数据的形式和范围：可以输入大写、小写的英文字母、任何数字及标点符号。
输出形式：
（1）分行输出用户输入的各行字符；
（2）分4行输出"全部字母数"、"数字个数"、"空格个数"、"文章总字数"；
（3）输出某一单词在文章中出现的次数；
（4）输出删除某一字符串后的文章。
*/
#include<iostream>
using namespace std;

typedef struct Node *PtrToNode,*List;
struct Node {
    char a[81];
    PtrToNode next;
    Node():next(NULL) { }
};

List InitList(List L,int n) {
    L->a[0] = n;
    PtrToNode p = L;
    for(int i=0 ;i<n;i++) {
        p->next = new struct Node;
        p = p->next;
        cin >> p->a;
    }
    return L;
}

void DeleteList(List L) {
    PtrToNode p = L->next,pre = L;
    while(p) {
        delete pre;
        pre = p;
        p = p->next;
    }
    delete pre;
}

void PrintList(List L) {
    PtrToNode p = L->next;
    for(int i=0 ;i<L->a[0];i++) {
        cout << p->a << endl;
        p = p->next;
    }
}
int main()
{
    List L = new struct Node();
    int n;
    cin >> n;
    L = InitList(L,n);
    PrintList(L);
    DeleteList(L);
}