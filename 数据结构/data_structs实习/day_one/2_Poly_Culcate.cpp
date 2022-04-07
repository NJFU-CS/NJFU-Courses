/*
2．	一元多项式计算
功能要求：
（1）能够按照指数降序排列建立并输出多项式；
（2）能够完成两个多项式的相加、相减，并将结果输出；
*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

typedef struct LNode* PtrToLNode,*List;
struct LNode {
    int coef;//系数
    int index;//指数
    PtrToLNode next;
};
//建立头节点
void InitList(List* a) {
    *a = (List)malloc(sizeof(struct LNode));
    (*a)->next = NULL;
}
//读入数据
void Read(List a) {
    int c,i;
    while(1) {
        scanf("%d %d",&c,&i);
        if(c==0 && i==0) {
            break;
        }else{
            PtrToLNode NewNode = (PtrToLNode)malloc(sizeof(struct LNode));
            NewNode->coef = c;
            NewNode->index = i;
            //std :: cout << NewNode->coef << " "<<NewNode->index << std::endl;
            NewNode->next = (a)->next;
            (a)->next = NewNode;
        }
    }
}

//输出链表
void PrintList(List a) {

    PtrToLNode p = a->next;
    while(p) {
        if(p->index>0)
            printf("%+dx^%d",p->coef,p->index);
        else if(p->index==0)
            printf("%+d",p->coef);
        else 
            printf("%+dx^(%+d)",p->coef,p->index);
        p = p->next;
    }
    printf("\n");
}
//c = a+b
void PolyPlus(List a,List b,List c) {
    PtrToLNode pa = a->next;
    PtrToLNode pb = b->next;
    PtrToLNode pc = c;
    while(pa && pb)
        if(pa->index == pb->index) {
            //指数相等
            //std::cout << "1";
            int c = pa->coef + pb->index;
            if( c!= 0) {
                //系数不等于0
                InitList(&(pc->next));
                pc->next->coef = c;
                pc->next->index = pa->index;
            }
            pa = pa->next;
            pb = pb->next;
            pc = pc->next;
        }else if(pa->index > pb->index) {
            //std::cout << "2";
            InitList(&(pc->next));
            pc->next->coef = pa->coef;
            pc->next->index = pa->index;
            pa = pa->next;
            pc = pc->next;
        }else{
            //std::cout << "3";
            InitList(&(pc->next));
            pc->next->coef = pb->coef;
            pc->next->index = pb->index;
            pb = pb->next;
            pc = pc->next;
        }

    //处理余下链表
    pc->next = pa ? pa : pb;
}
//c = a-b
void PolyMinus(List a,List b,List c) {
    PtrToLNode pa = a->next;
    PtrToLNode pb = b->next;
    PtrToLNode pc = c;
    while(pa && pb)
        if(pa->index == pb->index) {
            //指数相等
            //std::cout << "1";
            int c = pa->coef - pb->index;
            if( c!= 0) {
                //系数不等于0
                InitList(&(pc->next));
                pc->next->coef = c;
                pc->next->index = pa->index;
            }
            pa = pa->next;
            pb = pb->next;
            pc = pc->next;
        }else if(pa->index > pb->index) {
            //std::cout << "2";
            InitList(&(pc->next));
            pc->next->coef = pa->coef;
            pc->next->index = pa->index;
            pa = pa->next;
            pc = pc->next;
        }else{
            //std::cout << "3";
            InitList(&(pc->next));
            pc->next->coef = -pb->coef;
            pc->next->index = pb->index;
            pb = pb->next;
            pc = pc->next;
        }

    //处理余下链表
    if(pa) {
        pc->next = pa;
    }
    while(pb) {
        InitList(&(pc->next));
        pc->next->coef = -pb->coef;
        pc->next->index = pb->index;
        pc = pc->next;
        pb = pb->next;
    }
}


void DeleteList(List a) {
    PtrToLNode p = a->next;
    PtrToLNode pre = a;
    while(p) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

int main()
{
    List a = NULL;
    List b = NULL;
    List c = NULL;
    List d = NULL;
    InitList(&a);
    InitList(&b);
    InitList(&c);
    InitList(&d);
    c->coef = 0;
    c->index = 0;
    Read(a);
    Read(b);
    PrintList(a);
    PrintList(b);

    PolyPlus(a,b,c);

    PrintList(c);

    PolyMinus(a,b,d);

    PrintList(d);

    DeleteList(a);
    DeleteList(b);
    DeleteList(c);
    DeleteList(d);
}
/*
1 2
2 3
3 4
4 5
5 6
6 7
7 8
0 0
4 4
6 6
8 8
9 9
0 0
*/