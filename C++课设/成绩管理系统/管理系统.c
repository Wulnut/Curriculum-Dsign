#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
typedef struct person                               //定义结构体  
{  
    char num[10];   //学号  
    char name[20]; //姓名  
    float cyuyan;    //C语言成绩  
    float en;      //物理学成绩  
    float  ji;      //原子物理成绩
    float  guti;      //固体物理成绩  
    float  cailiao;  //材料学成绩  
}person;  
person per[200];  //定义100  
char filename[20];                                      //定义全局变量  
 void logon()                                            //登陆函数 使系统更显完善  
{  
 printf("\n\n\n\t\t\t  学生信息管理系统\n\n");  
 printf("\t\t\t     版本号：2.0\n\n");  
 printf("\n\n\n\n\t\t\t    2012年3月10日\n\n");  
 printf("\t\t\t   C区**栋514寝\n");  
 printf("\n\n\t\t\t     Ace_cm_liu\n");  
 printf("\n\n\t\t\t    导演兼制作\n");  
 //system("pause");  
}  
/*void menu_filename()  
   {  
      system("cls");  
      printf("请输入你要操作的文件名:");  
      scanf("\t%s",filename);  
    }  */
    //*********************************************************************//  
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
int menu_select()                              //菜单选择系统函数  
{  
     char c;  
      do{  
        //system("cls");  
        printf("\t\t ╭═════════■□■□═══╮\n");  
        printf("\t\t│         学生信息管理系统         │\n");  
        printf("\t\t╰═══■□■□══════════╯\n");  
        printf("\t\t   ┌─────────────-┐\n");  
        printf("\t\t   │ 1. 添加记录    2. 显示记录 │\n");  
        printf("\t\t   │                            │\n");  
        printf("\t\t   │ 3. 信息查询    4. 数据计算 │\n");  
        printf("\t\t   │                            │\n");  
        printf("\t\t   │ 5. 修改记录    6. 删除记录 │\n");  
        printf("\t\t   │                            │\n");  
        printf("\t\t   │ 0. 退出程序                │\n");  
        printf("\t\t   └─────────────-┘\n");  
        printf("\t\t请您选择(0-6):");  
        c=getchar();  
     }while(c<'0'||c>'6');  
        return (c-'0');                                      //字符减去'0'得到的是数字整型//  
}  
  
    //*********************************************************************//  
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
  
void add()                                      //成绩的录入与添加函数  
  {  
    FILE *fp;  
    int i=0,n=0;  
    char sign='y';                              //首先定义sing='y'  
    system("cls"); 
    person p[200]  ;                             //清屏函数  系统中调用  
    while(sign!='n'&&sign!='N')                    //其实只有当输入N或n时才跳出循环  
      {  
        printf("             ----学生纪录添加----\n");  
        printf("姓名：\n");  
        scanf("\t%s",p[i].name);  
        printf("学号:\n");  
        scanf("\t%s",p[i].num);  
        printf("C语言：\n");  
        scanf("\t%f",&p[i].cyuyan);  
        printf("物理学：\n");  
        scanf("\t%f",&p[i].en);  
        printf("原子物理：\n");  
        scanf("\t%f",&p[i].ji);
        printf("固体物理：\n");  
        scanf("\t%f",&p[i].guti);  
        printf("材料学：\n");  
        scanf("\t%f",&p[i].cailiao); 
        printf("是否继续添加?(y/n)");  
        scanf("\t%c",&sign);  
        i++;  
        n=n+1;  
        system( "cls ");  
   }system("pause");                                     //等待命令  
  
   if((fp=fopen("studata.txt","a"))==NULL)                    //以2进制形式进行文件尾追加//  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return;                                         //如果文件出现错误 就返回  
       }  
        for(i=0;i<n;i++)  
        {
            fprintf(fp,"%s %s %f %f %f %f %f\n",p[i].name,p[i].num,p[i].cyuyan,p[i].en,p[i].ji,p[i].guti,p[i].cailiao);    //以2进制形式写入文件中//一次写入一个数组//  
        
        }
        //printf("file write error\n");  
        fclose(fp);                                       //关闭文件  
        system("pasue");  
  }  
     //*********************************************************************//  
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
  void scan()                        //显示记录  进行全面信息浏览  
   {  
    void amend(); 
                            //声明修改函数//  
    char sign='y';  
    FILE *fp;  
    int n;  
    system("cls");  
      if((fp=fopen("studata.txt","r"))==NULL)             //以2进制方式读取文件信息//  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return;  
       }  
     
    int i=0;
    while(fscanf(fp,"%s%s%f%f%f%f%f",per[i].name,per[i].num,&per[i].cyuyan,&per[i].en,&per[i].ji,&per[i].guti,&per[i].cailiao)!=EOF)
    { 
      
     printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
     printf("        姓名            学号       C语言    物理学    原子物理   固体物理   材料学\n");  
     printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"); 
     printf("%s %s %f %f %f %f %f\n",per[i].name,per[i].num,per[i].cyuyan,per[i].en,per[i].ji,per[i].guti,per[i].cailiao);  
     printf("\n"); 
         i++;
    }   
     system("pause");  
     system("cls");  
     printf("是否需要修改?(y/n)");  
     scanf("\t%c",&sign);  
    if(sign!='n'&&sign!='N')                    //选择是否在浏览后进行修改//  
     amend();  
     system("pause");  
  
  }  
  
     //*********************************************************************//  
     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
                                    //数据查询//  
  void query()                     //学生信息的不同方式查询  
   {      
        system("cls");
        person p[200];
        FILE *fp1;  
        int i=0;
        int n=0;  
        int m;   
        printf("\t\n请选择查询方式:\n");  
        printf("\t┌──────┐\n");  
        printf("\t│1--模糊查询 │\n");  
        printf("\t│2------姓名 │\n");  
        printf("\t│3------学号 │\n");  
        printf("\t│4------返回 │\n");  
        printf("\t└──────┘\n");  
        printf("请输入你要查询的方式\n");  
        scanf("%d",&m);  
        while(m!=1&&m!=2&&m!=3&&m!=4)  
            {  
                printf("输入错误请重新查询\n");  
                scanf("%d",&m);  
            }  
          if((fp1=fopen("studata.txt","r"))==NULL)                 //以2进制方式读取文件信息//  
          {  
             printf("cannot open the files\n");  
           }    
    
        while(fscanf(fp1,"%s%s%f%f%f%f%f",p[i].name,p[i].num,&p[i].cyuyan,&p[i].en,&p[i].ji,&p[i].guti,&p[i].cailiao)!=EOF)
        {    
             i++;
             n=n+1;
        }  
    
              
        
       if(m==1)                                                 //模糊查询  
      {  
        char s[3];                                             //定义输入的文字所占的字节 /一个汉字占2个字节 外加一结尾符此处小心溢出  
        int i=0;  
        system("cls");  
        printf("\t请输入想查询的姓:");  
        scanf("%s",s);  
        for(i=0;i<n-1;i++)                                               //文件信息已经读取到数组中 此处进行循环用于下一语句的查找  
        {  
  
          if(p[i].name[0]==s[0]&&p[i].name[1]==s[1])              //比较per[i].name与所输入的前俩个字符是否相同//  
            {  
                  printf("\t学号: %s\n",p[i].num);  
                printf("\t姓名: %s\n",p[i].name);  
                printf("\tC语言: %f\n",p[i].cyuyan);  
                printf("\t物理学: %f\n",p[i].en);  
                printf("\原子物理: %f\n",p[i].ji);
                printf("\t固体物理: %f\n",p[i].guti);  
                printf("\t材料学: %f\n",p[i].cailiao); 
            }  
        }  
     }  
  
    if(m==2)                                            //姓名查询  
       {  
        char s[20];  
        int j=0;  
        printf("\t请输入想查询的姓名:");  
        scanf("\t%s",s);  
        while(strcmp(p[j].name,s)!=0&&j<n) j++;            //比较per[i].name与所输入姓名是否相同//  
        if(j==n)
        {
            printf("无");
        }
                printf("\t学号: %s\n",p[j].num);  
                printf("\t姓名: %s\n",p[j].name);  
                printf("\tC语言: %f\n",p[j].cyuyan);  
                printf("\t物理学: %f\n",p[j].en);  
                printf("\原子物理: %f\n",p[j].ji);
                printf("\t固体物理: %f\n",p[j].guti);  
                printf("\t材料学: %f\n",p[j].cailiao); 
            
      }   
    if(m==3)                                                            //学号查询  
        {  
          char s[15];  
          int i=0;  
          printf("请输入想查询的学号：");  
          scanf("\t%s",s);  
          
          while(strcmp(p[i].num,s)!=0&&i<n)                                //比较per[i].name与所输入学号是否相同//
         i++;                         
            if(i==n)  
            {  
                printf("\t通讯录中没有此人!\n");  
                system("pause");  
                return;  
            }  
                  printf("\t学号: %s\n",p[i].num);  
                printf("\t姓名: %s\n",p[i].name);  
                printf("\tC语言: %f\n",p[i].cyuyan);  
                printf("\t物理学: %f\n",p[i].en);  
                printf("\原子物理: %f\n",p[i].ji);
                printf("\t固体物理: %f\n",p[i].guti);  
                printf("\t材料学: %d\f",p[i].cailiao); 
          }  
          fclose(fp1); 
          system("pause"); 
  }  
  
                                         
                                
 void date()  
  {  
      person per[200];
    FILE *fp;  
    struct person temp;                               //定义临时数组用于交换时存放数组信息用于后面的交换//  
    float sum;                                         //总分  
    float s[200];  
    int i=0,n=0;  
    int j,k,t;  
    int m;  
    system("cls");  
    printf("\t\n选择排序方式:\n");  
    printf("\t┌──────┐\n");  
    printf("\t│1----物理学 │\n");  
    printf("\t│2--原子物理 │\n"); 
    printf("\t│3---C语言   │\n");  
    printf("\t│4--固体物理 │\n");  
    printf("\t│5----材料学 │\n");  
    printf("\t│6----  总分 │\n");  
    printf("\t│7------返回 │\n");  
    printf("\t└──────┘\n");  
    printf("请输入你要排序的方式\n");  
    scanf("%d",&m);  
    system("cls");  
    while(m!=1&&m!=2&&m!=3&&m!=4&&m!=5&&m!=6&&m!=7)  
        {  
            printf("输入错误请重新输入\n");  
            scanf("%d",&m);  
        }  
     if((fp=fopen("studata.txt","r"))==NULL)                 //以2进制方式读取文件信息//  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return;  
       }  
  
        while(fscanf(fp,"%s%s%f%f%f%f%f",per[i].name,per[i].num,&per[i].cyuyan,&per[i].en,&per[i].ji,&per[i].guti,&per[i].cailiao)!=EOF)
        {    
             i++;
             n=n+1;
        }   
   if(m==1)  
      {  
          for(int i=0;i<n-1;i++)                           //采用冒泡法进行排序//  
          {  
             k=i;  
            for(j=i+1;j<n;j++)  
            if(per[j].en>per[k].en)                              //排序//比较大小//  
            k=j;  
            temp=per[k];per[k]=per[i];per[i]=temp;                  //当符合条件时进行数据交换//  
            }  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
             printf("        姓名           学号       C语言    物理学    原子物理   固体物理   材料学\n");  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            for(int i=0;i<n-1;i++)  
            {
                printf("%s %s %f %f %f %f %f\n",per[i].name,per[i].num,per[i].cyuyan,per[i].en,per[i].ji,per[i].guti,per[i].cailiao);  
                printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            }
                
            fclose(fp);  
        }  
  
    if(m==2)  
      {  
        for(int i=0;i<n-1;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(per[j].ji>per[k].ji)  
              k=j;  
            temp=per[k];per[k]=per[i];per[i]=temp;  
          }  
           printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
             printf("        姓名           学号       C语言    物理学    原子物理   固体物理   材料学\n");  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            for(int i=0;i<n-1;i++)  
            {
                printf("%s %s %f %f %f %f %f\n",per[i].name,per[i].num,per[i].cyuyan,per[i].en,per[i].ji,per[i].guti,per[i].cailiao);  
                printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            }
                
            fclose(fp);  
        }
    if(m==3)  
      {  
        for(int i=0;i<n-1;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(per[j].cyuyan>per[k].cyuyan)  
              k=j;  
            temp=per[k];per[k]=per[i];per[i]=temp;  
          }  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
             printf("        姓名           学号       C语言    物理学    原子物理   固体物理   材料学\n");  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            for(int i=0;i<n-1;i++)  
            {
                printf("%s %s %f %f %f %f %f\n",per[i].name,per[i].num,per[i].cyuyan,per[i].en,per[i].ji,per[i].guti,per[i].cailiao);  
                printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            }
                
            fclose(fp);  
        } 
        if(m==4)  
      {  
        for(int i=0;i<n-1;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(per[j].guti>per[k].guti)  
              k=j;  
            temp=per[k];per[k]=per[i];per[i]=temp;  
          }  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
             printf("        姓名           学号       C语言    物理学    原子物理   固体物理   材料学\n");  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            for(int i=0;i<n-1;i++)  
            {
                printf("%s %s %f %f %f %f %f\n",per[i].name,per[i].num,per[i].cyuyan,per[i].en,per[i].ji,per[i].guti,per[i].cailiao);  
                printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            }
                
            fclose(fp);  
        }  
    if(m==5)  
      {  
        for(int i=0;i<n-1;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
            if(per[j].cailiao>per[k].cailiao)  
              k=j;  
            temp=per[k];per[k]=per[i];per[i]=temp;  
          }  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
             printf("        姓名           学号       C语言    物理学    原子物理   固体物理   材料学\n");  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            for(int i=0;i<n-1;i++)  
            {
                printf("%s %s %f %f %f %f %f\n",per[i].name,per[i].num,per[i].cyuyan,per[i].en,per[i].ji,per[i].guti,per[i].cailiao);  
                printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            }
                
            fclose(fp);   
        } 
    if(m==6)  
      {  
        for(int i=0;i<n-1;i++)  
           {  
             sum=0;  
             sum=per[i].cyuyan+per[i].en+per[i].ji+per[i].guti+per[i].cailiao;  
             s[i]=sum;   
           }                                      // 第一个数组用于数组间信息操作//  
            for(int i=0;i<n-1;i++)  
         {  
              k=i;  
           for(j=i+1;j<n;j++)  
           {
                 if(s[j]>s[k])  
              k=j;
           }
            temp=per[k];per[k]=per[i];per[i]=temp;  
          }  
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
             printf("        姓名           学号       C语言    物理学    原子物理   固体物理   材料学\n");  
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            for(int i=0;i<n-1;i++)  
            {
                printf("%s %s %f %f %f %f %f\n",per[i].name,per[i].num,per[i].cyuyan,per[i].en,per[i].ji,per[i].guti,per[i].cailiao);  
                printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");  
            }
                
            fclose(fp);  
      }  
      system("pause");  
    }  
  
    //*********************************************************************//  
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
                                                 // 数据修改//  
void amend()  
  {  
    person p[200];
    FILE *fp2;  
    int i=0;
    int n=0;  
    char s[15];  
    int m;  
   // system("cls");  
    printf("\t\n请选择修改方式:\n");  
    printf("\t┌──────┐\n");  
    printf("\t│1------姓名 │\n");  
    printf("\t│2------学号 │\n");  
    printf("\t│3------返回 │\n");  
    printf("\t└──────┘\n");  
    printf("请输入你要修改的方式\n");  
    scanf("%d",&m);  
    while(m!=1&&m!=2&&m!=3)  
        {  
            printf("输入错误请重新修改\n");  
            scanf("%d",&m);  
        }  
     if((fp2=fopen("studata.txt","r"))==NULL)                 //以2进制方式读取文件信息//  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return;  
       }  
       
       
       while(fscanf(fp2,"%s%s%f%f%f%f%f",p[i].name,p[i].num,&p[i].cyuyan,&p[i].en,&p[i].ji,&p[i].guti,&p[i].cailiao)!=EOF)
        {    
             i++;
             n=n+1;
        } 
        fclose(fp2) ;
    
 
   // system("cls");  
  if(m==1)  
    {  
      person newp;
      char s[20];  
      int i=0;  
      printf("\t请输入想修改的姓名:");  
      scanf("\t%s",s);  
      while(strcmp(p[i].name,s)!=0&&i<n) i++;                           //进行比较 找到所需要的信息  
        if(i==n)  
         {  
            printf("\t通讯录中没有此人!\n");  
            return;  
         }  
        else{  
             printf("学号：\n");  
             scanf("\t%s",&newp.num);  
             printf("姓名:\n");  
             scanf("\t%s",&newp.name);  
             printf("C语言：\n");  
             scanf("\t%f",&newp.cyuyan);  
             printf("物理学：\n");  
             scanf("\t%f",&newp.en);  
             printf("原子物理：\n");  
             scanf("\t%f",&newp.ji);
             printf("固体物理：\n");  
             scanf("\t%f",&newp.guti);
             printf("材料学：\n");  
             scanf("\t%f",&newp.cailiao);
          }  
          
    FILE *fin,*ftp;
    fin=fopen("studata.txt","r");//读打开原文件studata.txt
    ftp=fopen("tmp.txt","w");//写打开临时文件tmp.txt
    if(fin==NULL || ftp==NULL){
        printf("Open the file failure...\n");
        exit(0);
    }
    int kk=0;
    while(kk<n) //从原文件读取一行
    {
        if(strcmp(p[kk].name,s)!=0)//检验是要删除的行吗?
        {
            fprintf(ftp,"%s %s %f %f %f %f %f\n",p[kk].name,p[kk].num,p[kk].cyuyan,p[kk].en,p[kk].ji,p[kk].guti,p[kk].cailiao);//不是则将这一行写入临时文件tmp.txt
        }

       kk++;    
    }
        
    fprintf(ftp,"%s %s %f %f %f %f %f\n",newp.name,newp.num,newp.cyuyan,newp.en,newp.ji,newp.guti,newp.cailiao);//不是则将这一行写入临时文件tmp.txt

    fclose(fin);
    fclose(ftp);
    fclose(fp2);
    remove("studata.txt");//删除原文件
    rename("tmp.txt","studata.txt");//将临时文件名改为原文件名
     }  
    if(m==2)  
       {  
      person newp1;
      char s[20];  
      int i=0;  
      printf("\t请输入想修改的学号:");  
      scanf("\t%s",s);  
      while(strcmp(p[i].num,s)!=0&&i<n) i++;                           //进行比较 找到所需要的信息  
        if(i==n)  
         {  
            printf("\t通讯录中没有此人!\n");  
            return;  
         }  
        else{  
             printf("学号：\n");  
             scanf("\t%s",&newp1.num);  
             printf("姓名:\n");  
             scanf("\t%s",&newp1.name);  
             printf("C语言：\n");  
             scanf("\t%f",&newp1.cyuyan);  
             printf("物理学：\n");  
             scanf("\t%f",&newp1.en);  
             printf("原子物理：\n");  
             scanf("\t%f",&newp1.ji);
             printf("固体物理：\n");  
             scanf("\t%f",&newp1.guti);
             printf("材料学：\n");  
             scanf("\t%f",&newp1.cailiao);
          }  
          
    FILE *fin,*ftp;
    fin=fopen("studata.txt","r");//读打开原文件studata.txt
    ftp=fopen("tmp.txt","w");//写打开临时文件tmp.txt
    if(fin==NULL || ftp==NULL){
        printf("Open the file failure...\n");
        exit(0);
    }
    int kk=0;
    while(kk<n) //从原文件读取一行
    {
        if(strcmp(p[kk].num,s)!=0)//检验是要删除的行吗?
        {
            fprintf(ftp,"%s %s %f %f %f %f %f\n",p[kk].name,p[kk].num,p[kk].cyuyan,p[kk].en,p[kk].ji,p[kk].guti,p[kk].cailiao);//不是则将这一行写入临时文件tmp.txt
        }

       kk++;    
    }
        
    fprintf(ftp,"%s %s %f %f %f %f %f\n",newp1.name,newp1.num,newp1.cyuyan,newp1.en,newp1.ji,newp1.guti,newp1.cailiao);//不是则将这一行写入临时文件tmp.txt

    fclose(fin);
    fclose(ftp);
    fclose(fp2);
    remove("studata.txt");//删除原文件
    rename("tmp.txt","studata.txt");//将临时文件名改为原文件名
        
        
        } 
        
        system("pause"); 
    
    }  
      //*********************************************************************//  
      //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
                                                        //数据删除//  
void delet()  
  {  
  
    person p[200];
    FILE *fp;  
    char s[10];  
    int i=0,n=0;  
      if((fp=fopen("studata.txt","r"))==NULL)                  //以2进制方式读取文件信息//  
      {  
         printf("cannot open the files\n");  
         system("pause");  
         return;  
       }  
  
        while(fscanf(fp,"%s%s%f%f%f%f%f",p[i].name,p[i].num,&p[i].cyuyan,&p[i].en,&p[i].ji,&p[i].guti,&p[i].cailiao)!=EOF)
        {    
             i++;
             n=n+1;
        } 

    fclose(fp); 
      
    printf("学生学号：");  
    scanf("%s",s);  
    i=0;
    while(strcmp(p[i].num,s)!=0&&i<n)
    {
         i++;
     }                           //进行比较 找到所需要的信息  
        if(i==n)  
         {  
            printf("\t通讯录中没有此人!\n");  
            return;  
         }  
    else{  
    FILE *fin,*ftp;
    fin=fopen("studata.txt","r");//读打开原文件123.txt
    ftp=fopen("tmp.txt","w");//写打开临时文件tmp.txt
    if(fin==NULL || ftp==NULL){
        printf("Open the file failure...\n");
        exit(0);
    }
    int kk=0;
    while(kk<n) //从原文件读取一行
    {
        if(strcmp(p[kk].num,s)!=0)//检验是要删除的行吗?
        {
            fprintf(ftp,"%s %s %f %f %f %f %f\n",p[kk].name,p[kk].num,p[kk].cyuyan,p[kk].en,p[kk].ji,p[kk].guti,p[kk].cailiao);//不是则将这一行写入临时文件tmp.txt
        }

       kk++;    
    }
        

    fclose(fin);
    fclose(ftp);
    remove("studata.txt");//删除原文件
    rename("tmp.txt","studata.txt");//将临时文件名改为原文件名
    printf("删除成功！") ; 
} 
     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//  
                             //运用switch语句进行菜单选择//  
}
  
  int main()  
  {  


  
      int n=0;  
      logon();  
      //menu_filename();                                         //引用全局变量文件名  
      for(;;)                                                 //循环使用主界面直到遇到结束命令  
      {   
          switch(menu_select())                               // 函数的调用//  
          {  
          case 1: 
              printf("\t\t *^_^*学生记录添加 *^_^*\n");  
              add();  
              break;  
          case 2:  
              printf("\t\t *^_^*学生信息浏览 *^_^*\n");  
              scan();  
              break;  
          case 3:  
              printf("\t\t *^_^*学生信息查询 *^_^*\n");  
              query();  
              break;  
          case 4:  
              printf("\t\t *^_^*数据计算 *^_^*\n");  
              date();  
              break;  
          case 5:  
              printf("\t\t *^_^*数据修改 *^_^*\n");  
              amend();  
              break;  
          case 6:  
               printf("\t\t *^_^*数据删除 *^_^*\n");  
               delet();  
               break;  
          case 0:  
                printf("\n\t\t谢谢使用，再见!\n");  
                printf("\n\t\t");  
                system("pause");  
                exit(0);  
          }  
      }  
      

        system("pause");  
        
 
          //system("pause");  */
          return 0;
  }