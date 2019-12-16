#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define t 100
void fun(struct student *s);
void fun1(struct student *s);
void fun2(struct student *s);
void fun3(struct student *s);
void fun4(struct student *s);
void fun5(struct student *s);
void fun6(struct student *s);
struct student
{
	char no[20];
	char name[20];
	char spec[20];
	int grade;
	char sex[20];
};
void main()
{
		struct student s[t]={{"10001","zhang","chinese",12,"male"},
		{"10002","wang","math",13,"fale"},
		{"10003","lisi","chemsi",12,"male"},
		{"10004","mazhi","english",13,"fale"},
		{"10005","kuko","math",14,"male"}
	   };
	fun(s);
}
void fun(struct student *s)
{
int n;
printf("\n\n\t\t学生档案管理系统");
printf("\n\n\t----------------------------------------");
printf("\n\n\t\t1：录入学生信息系统");
printf("\n\n\t\t2：修改学生信息系统");
printf("\n\n\t\t3：删除学生信息系统");
printf("\n\n\t\t4：查询学生信息系统");
printf("\n\n\t\t5：输出学生信息系统");
printf("\n\n\t\t6：退出系统");
printf("\n\n\t----------------------------------------");
printf("\n\n请选择你要的服务（按数字1~6进入）：");
scanf("%d",&n);
system("cls");
if(n==1)
{
printf("\n\n\t\t欢迎进入录入学生系统");
fun1(s);
}
else if(n==2)
{
printf("\n\n\t\t欢迎进入修改学生系统");
fun5(s);
}
else if(n==3)
{
printf("\n\n\t\t欢迎进入删除学生系统");
fun6(s);
}
else if(n==4)
{
printf("\n\n\t\t欢迎进入查询学生系统");
printf("\n\n\t----------------------------------------");
printf("\n\n\t\t1：按学号查询学生信息系统");
printf("\n\n\t\t2：按班级查询学生信息系统");
printf("\n\n\t----------------------------------------");
printf("\n\n请选择你要的服务（按数字1~2进入）：");
scanf("%d",&n);
system("cls");
if(n==1)
{
printf("\n\n\t\t1：按学号查询学生信息系统");
fun2(s);
}
else if(n==2)
{
printf("\n\n\t\t1：按班级查询学生信息系统");
fun3(s);
}
else
{
printf("\n\n\t\t数据错误");
}
}
else if(n==5)
{
printf("\n\n\t\t欢迎进入输出学生系统");
fun4(s);
} else if(n==6)
{
printf("\n\n\t\t谢谢使用学生管理系统！\n");
printf("\n\n\t\t请双击Enter键退出系统:");
getchar();
getchar();
exit(0);
}
else
printf("\n\n\t\t数据错误");
}
void fun1(struct student *s)
{
int n,i;
char d;
printf("\n\n\t请输入学生的数量:");
scanf("%d",&n);
for(i=5;i<n+5;i++)
{
printf("\n\t\t请输入学生学号：");
scanf("%s",s[i].no);
printf("\n\t\t请输入学生姓名：");
scanf("%s",s[i].name);
printf("\n\t\t请输入学生专业：");
scanf("%s",s[i].spec);
printf("\n\t\t请输入学生年级：");
scanf("%d",&s[i].grade);
printf("\n\t\t请输入学生性别：");
scanf("%s",s[i].sex);
getchar('\n');
system("cls");
}
printf("\n\n\t\t学号\t姓名\t专业\t年级\t性别");
printf("\n\t---------------------------------------------------");
for(i=0;i<n+5;i++)
{
printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s",s[i].no,s[i].name,s[i].spec,s[i].grade,s[i].sex);
}
printf("\n\t---------------------------------------------------\n");
printf("返回首页（请按任意键）：");
scanf("%c",&d);
system("cls");
fun(s);
}
void fun2(struct student *s)
{
char a[20],d;
int i;
printf("\n\n\t请输入要查询学生的学号(10001~10005)：");
scanf("%s",a);
for(i=0;i<5;i++)
{
if(!strcmp(s[i].no,a))
{
printf("\n\t此学生的信息：");
printf("\n\n\t\t学号\t姓名\t专业\t年级\t性别");
printf("\n\t---------------------------------------------------");
printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s\n",s[i].no,s[i].name,s[i].spec,s[i].grade,s[i].sex);
printf("\n\t---------------------------------------------------");
}
if(i==4&&s[i].no!="10005")
{
printf("\n\t\t查无此人！");
}
}
printf("\n\n返回首页（请按任意键）：");
getchar();
scanf("%c",&d);
system("cls");
fun(s);
}
void fun3(struct student *s)
{
int i,a;
char d;
printf("\n\n\t请输入要查询学生的班级(12~14)：");
scanf("%d",&a);
for(i=0;i<5;i++)
{
if(a==s[i].grade)
{
printf("\n\t此学生的信息：");
printf("\n\n\t\t学号\t姓名\t专业\t年级\t性别");
printf("\n\t---------------------------------------------------");
printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s\n",s[i].no,s[i].name,s[i].spec,s[i].grade,s[i].sex);
printf("\n\t---------------------------------------------------");
}
if(i==4&&s[i].grade!=a)
{
printf("\n\t\t查无此人！");
}
}
printf("\n\n返回首页（请按任意键）：");
getchar();
scanf("%c",&d);
system("cls");
fun(s);
}
void fun4(struct student *s)
{
int i;
char d;
printf("\n\n\t\t学号\t姓名\t专业\t年级\t性别");
printf("\n\t---------------------------------------------------");
for(i=0;i<5;i++)
{
printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s",s[i].no,s[i].name,s[i].spec,s[i].grade,s[i].sex);
}
printf("\n\t---------------------------------------------------\n");
printf("返回首页（请按任意键）：");
scanf("%c",&d);
getchar();
system("cls");
fun(s);
}
void fun5(struct student *s)
{
char a[20],d;
int i;
printf("\n\n\t请输入要修改学生的姓名：");
scanf("%s",a);
for(i=0;i<5;i++)
{
if(!strcmp(s[i].name,a))
{ printf("\n\t\t请输入修改学号：");
scanf("%s",s[i].no);
printf("\n\t\t请输入修改专业：");
scanf("%s",s[i].spec);
printf("\n\t\t请输入修改年级：");
scanf("%d",&s[i].grade);
printf("\n\t\t请输入修改性别：");
scanf("%s",s[i].sex);
getchar('\n');
system("cls");
}
}
printf("\n\n\t\t学号\t姓名\t专业\t年级\t性别");
printf("\n\t---------------------------------------------------");
for(i=0;i<5;i++)
{
printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s",s[i].no,s[i].name,s[i].spec,s[i].grade,s[i].sex);
}
printf("\n\t---------------------------------------------------\n");
printf("返回首页（请按任意键）：");
scanf("%c",&d);
system("cls");
fun(s);
}
void fun6(struct student *s)
{
char a[20],d;
int i,k;
printf("\n\n\t请输入要删除学生的姓名：");
scanf("%s",a);
for(i=0;i<5;i++)
{
if(!strcmp(s[i].name,a))
{
s[i]=s[i+1];
printf("\n\t此学生的信息：");
printf("\n\n\t\t学号\t姓名\t专业\t年级\t性别");
printf("\n\t---------------------------------------------------");
for(k=0;k<4;k++)
{
printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s\n",s[k].no,s[k].name,s[k].spec,s[k].grade,s[k].sex);
}
printf("\n\t---------------------------------------------------");
}
if(i==4)
{
printf("没有此人！");
}
}
printf("返回首页（请按任意键）：");
getchar();
scanf("%c",&d);
system("cls");
fun(s);
}