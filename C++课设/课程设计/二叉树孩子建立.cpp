#include<iostream>
 
using namespace std;
 
template<class T>
struct BiNode
{
    T data;
    BiNode<T>*lchild,*rchild;      //左孩子和右孩子指针
};
 
template<class T>
class BiTree
{
private:
    BiNode<T>*root;              //指向根节点的头指针
    BiNode<T>*Creat(BiNode<T>*bt);//构造函数的调用
    void Relief(BiNode<T>*bt);    //析构函数的调用
    
public:
    BiTree(){root=Creat(root);}
    ~BiTree(){Relief(root);}
    
};
 
template<class T>
BiNode<T>* BiTree<T>::Creat(BiNode<T>*bt)
{
    T ch;
    bt=new BiNode<T>;
    cin>>ch;
    if(ch=='#')
    {
        return NULL;
    }
    else
    {
        bt->data=ch;
        bt->lchild=Creat(bt->lchild);
        bt->rchild=Creat(bt->rchild);
    }
    return bt;
}
 
template<class T>
void BiTree<T>::Relief(BiNode<T>*bt)
{
    if(bt!=NULL)
    {
        Relief(bt->lchild);
        Relief(bt->rchild);
        delete bt;
    }
}

int main()
{
    BiTree<char>  bi;
    return 0;
}
