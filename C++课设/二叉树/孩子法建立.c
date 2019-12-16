#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define OK    1
#define NO    0
#define TRUE  1
#define FALSE 0
#define ERROR -1

#define MAX_TREE_SIZE 100  //树的最大结点数
 
typedef int Status;
typedef char TElemType_C;
typedef struct CTNode  //孩子结点
{
    int child;
    struct CTNode *next;
}CTNode;
typedef CTNode* ChildPtr;//孩子结点指针
typedef struct
{
    int parent;//双亲结点的位置
    TElemType_C data;
    ChildPtr firstchild;//孩子链表头指针

}CTBox;
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r;//根的位置
    int n;//树的结点数
}CTree;

void InitTree_C(CTree *T);//构造空树

void FreeChild_C(ChildPtr *p);//删除孩子列表

void ClearTree_C(CTree *T);//清空树T

void DestroyTree_C(CTree *T);//销毁树T

Status TreeEmpty_C(CTree T);//判断树是否为空

Status CreateTree_C(CTree *T);//按层序序列构造树

int TreeDegree_C(CTree T);//返回树的度

int TreeDepth_C_1(CTree T);//借助双亲标志

int TreeDepth_C_1(CTree T);//不借助双亲标志

int Depth_C(CTree T,int i);//求T中第i个结点开始的深度

TElemType_C Root_C(CTree T);//返回树的根节点的值

TElemType_C Value_C(CTree T,int i);//返回树中第i个结点值（按层序计数）

int Order_C(CTree T,TElemType_C e);//返回结点e的值位置（在数组中的位置），-1代表无此结点

Status Assign_C(CTree*T,TElemType_C e,TElemType_C value);//替换结点e的值为value

TElemType_C ChildValue_C(CTree T,TElemType_C e,int order);//返回结点e的第order个孩子的值（从左到右计数）

TElemType_C Sibling_C_1(CTree T,TElemType_C e,int mark);//返回元素e的左右兄弟，mark标记左右

int Sibling_C_2(CTree T,TElemType_C e,int mark);//返回元素e的左右兄弟序号，mark标记左右

int ChildCount_C(CTree T,TElemType_C p);//返回结点p的孩子结点（子树）个数，返回负数代表结点p不存在

int ChildSeat_C(CTree T,TElemType_C p,int i);//返回树T中p结点的第i个孩子（层序计数）的位置，i=0定义为最后一个孩子。

ChildPtr SiblingSeat_C(CTree T,TElemType_C p);//返回在孩子链表中指向元素p的指针。

Status InsertChild_C(CTree *T,TElemType_C p,int i,TElemType_C e);//将结点e插入为p结点的第i个孩子（层序计数），i=0定义为最后一个孩子

Status InsertTree_C(CTree *T,TElemType_C p,int i,CTree e);//将树t插入为树T中p结点的第i颗子树，i=0定义为最后一棵树

Status DeleteTree_C(CTree *T,TElemType_C p,int i);//删除树T中p结点的第i棵子树

void LevelOrderTraverse_C(CTree T);//层序遍历

void Print_C_1(CTree T);//依赖双亲结点信息打印树。

void ShowTree_C(CTree T);//展示T的存储结构


int main (int argc,char** argv){
    CTree T,T0;
    printf("1\n函数InitTree_C测试..\n");
    {
        printf("初始化一棵空树 T..\n");
        InitTree_C(&T);
        printf("\n");
    }
    printf("5\n函数TreeEmpty_C测试..\n");
    {
        TreeEmpty_C(T)?printf("T 为空！！"):printf("T 不为空！！");
        printf("\n");
    }
    printf("6\n函数CreateTree_C测试..\n");
    {
        CreateTree_C(&T);
        printf("\n");
    }
    printf("22\n函数LevelOrderTraverse_C测试..\n");
    {
        printf("层序遍历树 T=");
        LevelOrderTraverse_C(T);
        printf("\n");
    }


return 0;
}
void InitTree_C(CTree *T){
    int i;

    printf("录入根节点的位置（非负数）：\n");
        scanf("%d",&i);
    if(i<0||i>MAX_TREE_SIZE-1)
    {
        printf(" i 值错误！\n");
        exit(ERROR);
    }
    T->r=i;
    T->n=0;

}
Status TreeEmpty_C(CTree T){
    return (T.n?FALSE:TRUE);

}

Status CreateTree_C(CTree *T){   //去掉getchar什么的一起输入不容易出错
    TElemType_C ch;
    int i;//i标记当前结点的父结点的位置
    int    j;//j标记当前结点的位置
    int k;//k标记i结点的第一个孩子的位置
    ChildPtr p,q;//q始终指向child的尾指针
    printf("录入树的根节点-->");
    getchar();//抵掉回车
    scanf("%c",&ch);
    printf("\n");
    if(ch!='^')
    {
        i=T->r;
        T->nodes[i].parent=-1;
        T->nodes[i].data=ch;
        T->nodes[i].firstchild=NULL;
        T->n++;
        
        if(i!=0)//设置第二个结点的输入位置
            j=0;
        else 
            j=1;
        k=j;
    }
    getchar();
    printf("输入结点\n");
    scanf("%c",&ch);
    while(ch!='#')
    {
        p=q=NULL;
        while(1){
        scanf("%c",&ch);
        if(ch=='^')
        break;        
        else
        {
            T->nodes[j].parent=i;
            T->nodes[j].data=ch;
            T->nodes[j].firstchild=NULL;
            T->n++;
            
            p=(ChildPtr)malloc(sizeof(CTNode));
            if(!p)
                exit(ERROR);
            p->child=j;
            p->next=NULL;
            if(T->nodes[i].firstchild==NULL)
                T->nodes[i].firstchild=p;

            else
                q->next=p;
            q=p;    
        }
        if(j+1==T->r)
            j=j+2;
        else
            j++;    
        }
        i=k;
        if(j+1==T->r)
            k=k+2;
        else 
            k++;
        scanf("%c",&ch);
    }
    return OK;
}

void LevelOrderTraverse_C(CTree T){
    int i,count;
    count=0;
    if(T.n)
    {
        count++;
        printf("%c",T.nodes[T.r].data);
        if(T.r)
            i=0;
        else
            i=1;
        while(count<T.n)
        {
            if(i!=T.r)
            {
                count++;
                printf("%c",T.nodes[i].data);
            }
            i++;
            
        }    
    }
}