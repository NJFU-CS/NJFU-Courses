#include<iostream>
#define Empty -1
#define Delete -2
using namespace std;

typedef struct Node *HashTable;
struct Node {
    int* data;
    char* context;
    int length;
    Node(int _length) : length(_length) { }
};

int n;

int nextPrime(int n) {
    if(n<2)return 2;
    if(n<3) return 3;
    if(n>3) {
        n = n%2 ? n : n+1;
        int i;
        while(1) {
            for( i = 2 ;i*i< n ;i++) {
                if(n%i==0) {
                    n+=2;
                    break;
                }
            }
            if(i*i>=n) {
                return n;
            }
        }
    }
}

int Hash(int data,int length) {
    return data % length;
}

HashTable InitHash(int length) {
    HashTable H = new struct Node(length);
    H->data = new int [H->length];
    H->context = new char [H->length];
    for(int i=0 ;i <H->length ;i++) {
        H->data[i] = Empty;
    }

    int num,pos;
    for(int i=0 ;i <n ;i++) {
        cin >> num;
        pos = Hash(num,H->length);
        while(H->data[pos]!=Empty) {
            pos++;
            if(pos>H->length) pos-=H->length;
        }
        H->data[pos] = num;
        H->context[pos] = num+'A';
    }
    return H;
}

void clear(HashTable H,int data) {
    H->data[data] = Delete;
}


void Find(HashTable H,int num) {
    int pos = Hash(num,H->length);
    int count = 0;
    while(H->data[pos]!=num) {
        if(H->data[pos]==Empty ) {cout << "not found" << endl; return;}
        pos++;
        count++;
        if(count>H->length) {cout << "not found" << endl; return;}
        if(pos>H->length) pos-=H->length;
    }
    
    cout << "in "<< pos <<" :("<<H->data[pos] << "," << H->context[pos] << ")" << endl;
    clear(H,pos);
    //cout << H->data[6];
}


int main()
{
    cin >> n;
    HashTable H = InitHash(nextPrime(n));
    for(int i=0;i<H->length;i++) {
        cout << "("<<H->data[i] << "," << H->context[i] << ")" << endl;
    }
    cin >> n;
    Find(H,n);
    Find(H,n);
    Find(H,n);

    delete [] H->context;
    delete [] H->data;
}
/*
10
4
5
3
7
4
6
7
9
2
3

4
*/