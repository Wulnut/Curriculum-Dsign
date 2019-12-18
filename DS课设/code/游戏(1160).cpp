#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*#define OK 1
#define ERROR 0
#define OVERFLOW -1


typedef int Status;
typedef char CElemType;
typedef struct {
    CElemType val;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status InitBiTree(BiTree *T){
    (*T)->lchild = (*T)->rchild = NULL;
    return OK;
}

Status CreateBiTree(BiTree *T, int n){
    CElemType ch;
    for(int i = 0; i <= n; ++i){
        
    }
    return OK;
}

int main(){
    return 0;
}*/


int main(){
    int n;
    int t;
    while(cin>>n){
        int d[n];
        int  a = 1, b = 2, c = 3, flag = 0;
        for(int i = 0; i < n; ++i){
            cin>>d[i];
        }
        for(int i = 0; i < n; ++i){
            if(d[i] == c){
                flag = 0;
                break;
            }
            if(d[i] == b){
                t = a;
                a = c;
                c = t;
                flag = 1;
            }
            if(d[i] == a){
                t = b;
                b = c;
                c = t;
                flag = 1;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
