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
#include<cstring>
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
    char ch[81];
    for(int i=0 ;i<n;i++) {
        p->next = new struct Node;
        p = p->next;
        //cin >> p->a ;
        cin.getline(ch,81);
        //cout << "ch=" << ch << endl;
        for(int j=0 ;ch[j]!='\0';j++) {
            p->a[j] = ch[j];
        }
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

void num(List L) {
    //统计文中所出现的英文字母的个数、数字的个数、空格的个数、总字数
    int alpha = 0;
    int digit = 0;
    int space = 0;
    int total = 0;
    PtrToNode p = L->next;
    while(p) {
        char ch;
        for(int i=0 ; p->a[i]!=0 ; i++) {
            ch = p->a[i];
            if(isalpha(ch)) {
                alpha++;
                total++;
            }else if(isdigit(ch)) {
                digit++;
                total++;
            }else if(isspace(ch)) {
                space++;
            }
        }
        p = p->next;
    }
    cout << "alpha : " <<  alpha << endl;
    cout << "dight : " << digit << endl;
    cout << "space : " << space << endl;
    cout << "total : " << total << endl;
}

void KMPNext(char ch[],int next[],int n) {
    int k = -1,j=0;
    next[0] = -1;
    while(j<n-1) {
        if(k==-1 || ch[k]==ch[j]) {
            k++;
            j++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}

int FindKMP(char string[],int num,char ch[],int n) {
    int _n = 0;
    int* next = new int[n];
    KMPNext(ch,next,n);
    
    int i=0,j=0;
    while(i<num ) {
        if(j==-1 || string[i]==ch[j]) {
            i++;
            j++;
        }else{
            j = next[j];
        }
        if(j>=n) {
            _n++;
            j = 0;
        }
    }
    return _n;
}



void string_total(List L,char ch[],int n) {
    PtrToNode p =L->next;
    int num = 0;
    while(p) {
        num+=FindKMP(p->a,strlen(p->a),ch,n);
        p = p->next;
    }
    cout << "ch_intotal = " << num << endl;
}

int Find(char string[],int num,char ch[],int n) {
    int* next = new int[n];
    KMPNext(ch,next,n);
    
    int i=0,j=0;
    while(i< num && j<n) {
        if(j==-1 || string[i]==ch[j]) {
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j>=n) {
        return i-n;
    }else{
        return -1;
    }
}

void delete_string(List L,char ch[],int n) {
    PtrToNode p =L->next;
    int pos = -1;;
    while(p) {
        pos = Find(p->a,strlen(p->a),ch,n);
        if(pos!=-1) {
            for(int i = pos+n ;p->a[i]!='\0' ;i++) {
                p->a[i-n] = p->a[i];
            }
            break;
        }
        p = p->next;
    }
    //cout << "ch_intotal = " << num << endl;
}

int main()
{
    List L = new struct Node();
    int n;
    cin >> n;
    //cout << n << endl;
    cin.get();
    L = InitList(L,n);
    num(L);
    cout << "-------------------[article] : " << endl;
    PrintList(L);

    char ch[]="gvw";
    cout << endl;
    string_total(L,ch,strlen(ch));
    cout << endl;
    cout << "--------------------delete_after[article] : " << endl;
    delete_string(L,ch,strlen(ch));

    PrintList(L);
    DeleteList(L);
}

/*
3
dbgvwefweey54
h6gvw  hw3hu6
hy6jugvwi5e
*/
