#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <windows.h>  
#include <string.h>  

typedef struct Student  
{  
   char name[100]; //姓名  
   char num[100];  //学号  
   char sex;//性别 (w代表女生m代表男生)  
   int age;//年龄  
   int score;//成绩  
}stu;  
typedef struct LNode  
{  
    stu data;  
    struct LNode *next;  
}LinkList;  

char nam[100];//名字  
char nu[100];//学号  
char s;//性别  
int ag;//年龄  
int sc;//成绩  

void welocome()//登陆界面  
{  
    system("color b1");  
    printf("````````````````````````````````````````````````````````````````````````````````");  
    printf("\n");  
    printf("\n");  
    printf("\n");  
    printf("  ***********************  欢迎登录学生信息管理平台 *************************  \n");  
    printf("\n");  
    printf("\n");  
    printf("\n");  
    printf("````````````````````````````````````````````````````````````````````````````````");  
}  

void menu()//功能菜单  
{  
    system("color e3");  
    printf("    |________________________________________________|\n");  
    printf("    |                                                |\n");  
    printf("    |                学生信息管理系统                |\n");  
    printf("    |                                                |\n");  
    printf("    |               0、退出系统                      |\n");  
    printf("    |               1、增加学生信息                  |\n");  
    printf("    |               2、删除学生信息                  |\n");  
    printf("    |               3、修改学生信息                  |\n");  
    printf("    |               4、查找学生的信息                |\n");  
    printf("    |               5、按照学生成绩排序              |\n");  
    printf("    |               6、浏览全部学生信息              |\n");  
    printf("    |               7、保存学生信息到文件            |\n");  
    printf("    |                                                |\n");  
    printf("    |________________________________________________|\n");  
    return ;  
}  

void InitList( LinkList *&L)//初始化链表  
{  
    L=(LinkList *)malloc(sizeof(LinkList));  
    L->next=NULL;  
}  

void ListInsert(LinkList *&L,LinkList *p)//插入新的节点  
{  
    LinkList *q=NULL;  
    q=L;  
    p->next=q->next;  
    q->next=p;  
}  

void addstu(LinkList *&L)//增加新的学生  
{  
    system("color f2");  
    printf("请输入学生的信息：\n");  
    printf("学号：");  
    scanf("%s",nu);  
    LinkList *q=L->next;  
    while(q!=NULL )  
    {  
        if(strcmp(q->data.num,nu)==0)//判断是否存在  
        {  
            printf("该生已存在\n");  
            break;  
        }  
        q=q->next;  
    }  
    if(q==NULL)  
    {  
        LinkList *p;  
        InitList(p);  
        strcpy(p->data.num,nu);  
        printf("姓名：") ;  
        scanf("%s",nam) ;  
        strcpy(p->data.name,nam);  
        printf("性别：（w为男 m为女）");  
        scanf(" %c",&s);  
        p->data.sex=s;  
        printf("年龄：");  
        scanf("%d",&ag);  
        p->data.age=ag;  
        printf("总成绩：");   
        scanf("%d",&sc);  
        while(sc>100||sc<0){
            printf("输入有误，请重新输入\n");
            scanf("%d",&sc);  
        }
        p->data.score=sc;  
        ListInsert(L,p);  

    }  
}  

void deletestu(LinkList *L)//删除学生  
{  
    system("color f4");  
    printf("请输入您要删除的学生的学号:");  
    scanf("%s",nu);  
    //判断  
    LinkList *p,*pre;  
    if(L->next==NULL)  
    {  
        printf("还没有学生信息,请增加学生信息\n");  
        return;  
    }  
    pre=L;  
    p=pre->next;  
    int judge=0;  
    while(p)  
    {  
         if(strcmp(p->data.num,nu)==0)  
         {  
                 judge=1;  
                 pre->next =p->next;  
                 free(p);  
                 printf("删除学生成功\n");  
                 break;  
         }  
         pre=p;  
         p=p->next;  
    }  
    if(judge==0)  
       printf("该生不存在\n");  
}  

void changestu(LinkList *L)//改变学生信息  
{  
    int judge=1;  
    system("color e4");  
    printf("请输入您要修改学生的学号：\n");  
    scanf("%s",nu);  
    LinkList *q=L->next;  
    while(q!=NULL )  
    {  
        if(strcmp(q->data.num,nu)==0)  
        {  
            judge=1;  
            printf("请输入您要修改的信息选项：1.姓名 2. 总成绩  3.年龄   \n");  
            int n;  
            scanf("%d",&n);  
            switch(n)  
            {  
            case 1:  
                printf("请输入您要修改的名字：");  
                scanf("%s",nam);  
                printf("修改的名字为：%s\n",nam);  
                strcpy(q->data.name,nam);
                printf("修改名字成功！\n");  
                break;  
            case 2:  
                printf("请输入您要修改的总成绩");  
                scanf("%d",&sc);  
                printf("修改的总成绩为：%d\n",sc);  
                q->data.score=sc;  
                printf("修改总成绩成功！\n");  

                break;  
            case 3:  
                printf("请输入您要修改的年龄：");  
                scanf("%d",&ag);  
                printf("修改的年龄为：%d\n",ag);  
                q->data.age=ag;  
                printf("修改年龄成功！\n");  
                break;  
            default :  
                printf("请输入正确的选项\n");  
                break;  
            }  
        }  
        q=q->next;  
    }  
   if(judge==0)  
   {  
     printf("该生不存在\n");  
   }  
}  

void findstu(LinkList *L)//按学号或者姓名查找学生并输出该生信息  
{  
    int flag;
    system("color b1");  
    printf("1.按学号查询：\n");
    printf("2.按姓名查询：\n");
    printf("请输入查询方式：");
    scanf("%d",&flag); 
    if(flag==1){
        printf("请输入该生学号："); 
        scanf("%s",nu);  
        //判断  
        LinkList *q=L->next;  
        while(q!=NULL )  
        {  
            if(strcmp(q->data.num,nu)==0)  
            {  
                printf("姓名：%s\n",q->data.name);  
                printf("学号：%s\n",q->data.num);  
                printf("性别：%c\n",q->data.sex);  
                printf("年龄：%d\n",q->data.age);  
                printf("总成绩：%d\n",q->data.score);  
                break;  
            }  
             q=q->next;  
        }  
        if(q==NULL)  
            printf("该生不存在\n");  
    }else{
        printf("请输入该生姓名：");
        scanf("%s",nam);  
        LinkList *q=L->next;  
        while(q!=NULL )  
        {  
            if(strcmp(q->data.name,nam)==0)  
            {  
                printf("姓名：%s\n",q->data.name);  
                printf("学号：%s\n",q->data.num);  
                printf("性别：%c\n",q->data.sex);  
                printf("年龄：%d\n",q->data.age);  
                printf("总成绩：%d\n",q->data.score);  
                break;  
            }  
             q=q->next;  
        }  
        if(q==NULL)  
            printf("该生不存在\n");  
    }
}  

void display(LinkList *&L)//浏览全部学生信息  
{  
    LinkList *q=L->next;  
    if(q==NULL)  
    {  
        printf("还没有学生信息，请增加学生信息\n");  
        return;  
    }  
    while(q)  
    {  
        system("color c0");  
        printf(" 学号：%s 名字：%s 年龄：%d 性别：%c  总成绩：%d \n",q->data.num,q->data.name,q->data.age,q->data.sex,  
      q->data.score);  
        q=q->next;  
    }  
}  

void paixu(LinkList *L)//按成绩排序排序 并输出排序后的结果  
{  
    system("color f9");  
    LinkList *q,*p,*r=L->next;  
    //判断  
    if(r==NULL)  
    {  
        printf("还没有学生信息，请增加学生信息\n");  
        return;  
    }  
    while(r) //两层循环完成排序  
    {  
         p=r;  
         q=r->next;  
         LinkList *tmp;//用于排序时暂存节点  
         InitList(tmp);  
         while(q)  
         {  
             if(q->data.score > p->data.score)  
             {  
                /*先复制q结点信息到tmp*/  
                strcpy(tmp->data.num,q->data.num);  
                strcpy(tmp->data.name,q->data.name);  
                tmp->data.sex=q->data.sex;  
                tmp->data.age=q->data.age;  
                tmp->data.score=q->data.score;  
                /*再复制p结点信息到q*/  
                strcpy(q->data.num,p->data.num);  
                strcpy(q->data.name,p->data.name);  
                q->data.sex=p->data.sex;  
                q->data.age=p->data.age;  
                q->data.score=p->data.score;  
                /*最后复制exchange结点信息到p*/  
                strcpy(p->data.num,tmp->data.num);  
                strcpy(p->data.name,tmp->data.name);  
                p->data.sex=tmp->data.sex;  
                p->data.age=tmp->data.age;  
                p->data.score=tmp->data.score;  
             }  
             q=q->next;  
         }  
         r=r->next;  
    }  

    printf("排序后的学生信息是：\n");  
    display(L);  
}  

void saveStuDentFile(LinkList * &L)//保存学生信息到文件  
{  
    FILE *fp;  
    LinkList *p=L->next;  
    if((fp=fopen("student.txt","w"))==NULL)// 以可写的方式打开当前目录下的.txt  
    {  
        printf("不能打开此文件，请按任意键退出\n");  
        exit(1);  
    }  
    while(p)  
    {  
        fprintf(fp,"%s  %s  %c  %d  %d  \n",p->data.num,p->data.name,p->data.sex,p->data.age,p->data.score);  
        p=p->next;  
        printf("保存成功\n");  
    }  
        fclose(fp);  
}  

void readStuDentput (LinkList *&L) //运行前把文件内容读取到电脑内存  
{  
    FILE *fp;  
    fp=fopen("student.txt","rb"); //以只读方式打开当前目录下的.txt  
    if(fp==NULL)  
    {  
        printf("不存在打开文件\n");  
        exit(0);                   //终止程序  
    }  
    int i=0;  
    while(!feof(fp))  
    {  
        char nu[100];//学号  
        char nam[100];//名字 
        char s;//性别  
        int ag;//年龄  
        int sc;//成绩  
        fscanf(fp," %s %s %c %d %d",nu,nam,&s,&ag,&sc);
        i++;  
    }  
    fclose(fp);  
    FILE *FP;  
    FP=fopen("student.txt","rb"); //以只读方式打开当前目录下的.txt  
    if(FP==NULL)  
    {  
        printf("无法打开文件\n");  
        exit(0); //终止程序  
    }  
    int b=i-1;  
    int j=1;  
        while(!feof(FP))  
        {  
            fscanf(FP,"%s %s %c %d %d",nu,nam,&s,&ag,&sc);  
            LinkList *n=(LinkList *)malloc(sizeof(LinkList));  
            strcpy(n->data.num,nu);//把后者的内容拷贝到前者中  
            strcpy(n->data.name,nam);//把后者的内容拷贝到前者中  
            n->data.sex=s;  
            n->data.age=ag;  
            n->data.score=sc;  
            ListInsert(L,n);//插入新的节点  
            n=n->next;  
            if(j==b)  
               break;  
            j++;  
        }  
    fclose(FP);    //关闭文件  
}  

int main()  
{  
    system("cls");//清屏  
    welocome();//登陆界面  
    Sleep(3000);//延缓3秒  
    LinkList *L;  
    InitList(L);  
    readStuDentput (L);//运行前把文件内容读取到电脑  
    int a;  
    int choose;  
    while(1)  
    {  
        printf("请输入您要选择的功能键：\n");  
        menu();//功能菜单  
        scanf("%d",&choose);  
        switch(choose)  
        {  
        case 0://退出  
            printf("谢谢使用！欢迎下次光临");  
            exit(0);  
        case 1://增加学生信息  
            addstu(L);//增加新的学生  
            break;  
        case 2://删除所有学生信息  
            deletestu(L);//删除学生  
            break;  
        case 3://改变个学生的信息  
            changestu(L);//改变学生信息  
            break;  
        case 4://查找某个学生的信息  
            findstu(L);//按学号查找学生并输出该生信息  
            break;  

        case 5:// 对学生成绩进行排序  
            paixu(L);  
            break;  
        case 6://输出所有学生的信息  
            display(L);  
            break;  
        case 7://保存学生信息到文件  
            saveStuDentFile(L);  
            break;  
        default:  
            printf("请输入正确的选择\n");  
            break;  
        }  
    }  
}  
