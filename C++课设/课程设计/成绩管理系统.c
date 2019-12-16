#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
//typedef int Elemtype;
typedef int status;
typedef struct node
{
	int ID;
	char  Name[12];
	char  Sex;
	int Math;
	int English;
	int Major;
	struct node* next;
}node, * linklist;

void Creat_Stu_Mas(linklist* L, int len);
status GetElem(linklist L, int i);
status Insertlist(linklist* L, int i);
status Traverselist(linklist L);
status Deletelist(linklist* L, int i, char *name_i);
int Longlist(linklist L);
status Clearlist(linklist* L);

int main(void)
{
	int len, j, i;
	char name[12];
	//int a,b,c,d;
	//char SEX,NAME[12];

	linklist L = NULL;
	printf("How many students do you have?\n");
	scanf("%d", &len);
	Creat_Stu_Mas(&L, len);
	printf("\n");//输入信息

	printf("Which Student`s information do you want to know?\n");
	printf("if you want to find ,please input 1 or not 0\n");
	scanf("%d", &j);
	printf("\n");
	if (j)
	{
		printf("which stduent do you want to know?\n");
		printf("No.");
		scanf("%d", &i);

		GetElem(L, i);
		//printf("第%d个元素的内容是：%d", i, e);
	}
	printf("\n");

	printf("Do you want to add a student?\n");
	printf("if you want to add ,please input 1 or not 0\n");
	scanf("%d", &j);
	if (j)
	{
		printf("Where do you want it?\n");
		printf("position:");
		scanf("%d", &i);
		printf("\n");
		printf("please add student information\n");
		//scanf("%d", &e);
		Insertlist(&L, i);
		printf("Student`s information list\n");
		Traverselist(L);
	}
	printf("\n");
	printf("Which student`s do you want to delete?\n");
	printf("if you want to delete input 1 or not 0\n");
	scanf("%d", &j);
	if (j)
	{
		printf("Where do you want to delete?");
		scanf("%d", &i);
		Deletelist(&L, i,&name[12]);
		printf("You delet %s student`s information", name[12]);
		printf("Student`s information list：");
		Traverselist(L);
	}

	printf("\n");
	printf("Do you want to delet all informations?\n");
	printf("if you want to delete input 1 or not 0\n");
	scanf("%d", &j);
	if (j)
	{
		Clearlist(&L);
		Traverselist(L);
		printf("OK！");
	}
	printf("\n");

	printf("Do you want to konw how many students now?\n");
	printf("if you want , input 1 or not 0\n");
	scanf("%d", &j);
	if (j)
		printf("%d\n", Longlist(L));

	return 0;
}

void Creat_Stu_Mas(linklist* L, int len)
{
	linklist r;
	int id,math,english,major;
	char sex,name[12],a;
	(*L) = (linklist)malloc(sizeof(node));

	r = *L;//头链表为空的链表；

	for (int i = 0; i < len; ++i)
	{
		linklist p = (linklist)malloc(sizeof(node));
		printf("Please input No.%dstudent`s informations\n", i + 1);
		printf("Student`s ID:");
		scanf("%d", &id);
		gets(&a);
		printf("\n");

        printf("------------------------------------------------------\n");
        printf("                                                      \n");
		printf("Student`s six:");
		scanf("%c",&sex);
		gets(&a);
		printf("\n");
		printf("                                                      \n");
		printf("------------------------------------------------------\n");
        
        printf("------------------------------------------------------\n");
        printf("                                                      \n");
		printf("Student`s name:");
		scanf("%S",&name);
		printf("\n");
		printf("                                                      \n");
		printf("------------------------------------------------------\n");
        
        printf("------------------------------------------------------\n");
        printf("                                                      \n");
		printf("Math Grades:");
		scanf("%d", &math);
		printf("\n");
		printf("                                                      \n");
		printf("------------------------------------------------------\n");
        
        printf("------------------------------------------------------\n");
        printf("                                                      \n");
		printf("English Grades:");
		scanf("%d", &english);
		printf("\n");
		printf("                                                      \n");
		printf("------------------------------------------------------\n");
        
        printf("------------------------------------------------------\n");
        printf("                                                      \n");
		printf("Major Grades:");
		scanf("%d", &major);
		printf("\n");
		printf("                                                      \n");
		printf("------------------------------------------------------\n");
		p->ID = id;
		p->Math=math;
		p->English=english;
		p->Major=major;
		strcpy(p->Name,name);
		p->Sex=sex;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

status GetElem(linklist L, int i)
{
	linklist p = L->next;
	int j = 1;
	if (!p || j > i)
		printf("error\n");
	while ( p &&j < i)
	{
		p = p->next;
		++j;
	}
	/*if (!p || j > i)
		printf("查找失败\n");*/
	printf("----------------------------------------------------------------------\n");
	printf("                                                                        \n");
	printf("name:%s\n",p->Name);
	printf("ID:%d\n",p->ID);
	printf("Sex:%c\n",p->Sex);
	printf("Math:%d\n",p->Math);
	printf("English:%d\n",p->English);
	printf("Major:%s\n",p->Major);
	printf("                                                                        \n");
	printf("-----------------------------------------------------------------------\n");

	return OK;
}

status Insertlist(linklist* L, int i)
{
	linklist p = *L;
	linklist s;
	int j = 1;
	int math,english ,id ,major;
	char sex,name[12];
	if (!p || j > i)
		printf("error");
	while (p && j < i)
	{
		p = p->next;
		++j;
	}

	/*if (!p || j > i)
		printf("插入出错");*/

	s = (linklist)malloc(sizeof(node));
	printf("Please,Insert stdudent`s informations\n");
	printf("------------------------------------------------\n");
	printf("Name:");
	scanf("%s",&name);
	printf("\n");

	printf("ID:");
	scanf("%d",&id);
	printf("\n");

	printf("Sex:");
	scanf("%c",&sex);
	printf("\n");

	printf("Math:");
	scanf("%d",&math);
	printf("\n");

	printf("English:");
	scanf("%d",&english);
	printf("\n");

	printf("Major:");
	scanf("%d",&major);
	printf("\n");

	printf("                                                     \n");
	printf("------------------------------------------------------\n");

	s->ID = id;
	s->Math=math;
	s->English=english;
	s->Major=major;
	strcpy(s->Name,name);
	s->Sex=sex;//strcpy(s->Sex,sex);

	s->next = p->next;
	p->next = s;

	return OK;
}

status Deletelist(linklist* L, int i, char *name_i)
{
	linklist p, q;
	int j = 1;
	p = *L;
	if (!(p->next) || j > i)
		printf("error\n");

	while ((p->next) && j < i)
	{
		p = p->next;
		++j;
	}
	/*if (!(p->next) || j > i)
		printf("删除失败");*/

	q = p->next;
	strcpy(name_i,q->Name);
	p->next = q->next;
	free(q);

	return OK;
}

status Traverselist(linklist L)
{
	linklist p;
	p = L->next;
	while (p)
	{
		printf("Name:%s", p->Name);
		printf("  ID:%d",p->ID);
		printf("  Sex:%c",p->Sex);
		printf("  Math:%d",p->Math);
		printf("  English:%d",p->English);
		printf("  Major:%d",p->Major);
		printf("\n");
		printf("------------------------------------------\n");
		p = p->next;
	}
	printf("\n");
	return OK;
}

status Clearlist(linklist* L)
{
	linklist p, q;
	p = *L;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

int Longlist(linklist L)
{
	linklist p;
	p = L->next;
	int j = 0;
	while (p)
	{
		p = p->next;
		++j;
	}

	return j;
}