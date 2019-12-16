#include <iostream> 
#include <malloc.h> 
#include <string.h> 
   
using namespace std; 
typedef struct TK{ 
 char Name[20]; 
 int SeatId; 
 struct TK *next; 
}Ticket; 
   
   
typedef struct FLY 
{ 
 char FlightId[10]; 
 int Seat[50]; 
 Ticket *PersonHead; 
 struct FLY *next; 
}Flight; 
   
   
class Person{ 
public: 
 void ListInitiate(Flight **head); 
 bool Check(int *Seat,int Ch); 
 void Insert(Flight *head); 
 int Delete(Flight *head); 
 void show(Flight *head); 
 void Search(Flight *head); 
 void AddFlght(Flight *head); 
 void DeleteFlght(Flight *head); 
}; 
   
/*******************************main.cpp**********************/
/*#include "list.h" */
   
int menu() 
{ 
 int option; 
 cout<<endl<<endl; 
 cout<<"���˵�"<<endl; 
 cout<<" 1.Booking the ticket of flighting"<<endl; 
 cout<<" 2.Cancel the flighting"<<endl; 
 cout<<" 3.Display the information "<<endl; 
 cout<<" 4.Search"<<endl; 
 cout<<" 5.Add a Flight"<<endl; 
 cout<<" 6.Delete a Flight"<<endl; 
 cout<<" 0.Exit"<<endl<<endl; 
 cout<<"Please input your option:"; 
 cin>>option; 
 getchar(); 
 cout<<endl; 
 if(option>=0&&option<=6) 
 return option; 
 else 
 return -1; 
} 
int main() 
{  
   
 cout<<"------------------------->�������ϵͳ<<<<-----------------------------"<<endl; 
 cout<<"   ��ӭ��ʹ�øú���ϵͳ"<<endl; 
 Flight *head; 
 Person P; 
 P.ListInitiate(&head); 
 while(true) 
 { 
 switch(menu( )) 
 { 
 case 1:P.Insert(head);break; //Ԥ�� 
 case 2:P.Delete(head);break; //ȡ�� 
 case 3:P.show(head);break; //��ʾ 
 case 4:P.Search(head);break; //��ѯ 
 case 5:P.AddFlght(head);break; //��Ӻ��� 
 case 6:P.DeleteFlght(head);break; //ɾ������ 
 case 0:exit(0); 
 default:cout<<"Choice error!\n"; 
 } 
 }  
 return 0; 
} 
/*****************************************passenger.cpp*************************/
/*#include "List.h"*/ 
void Person::ListInitiate(Flight **head) 
{ 
 int count=0; 
 *head = (Flight *)malloc(sizeof(Flight)); 
 (*head)->PersonHead=(Ticket *)malloc(sizeof(Ticket)); 
 (*head)->PersonHead->next=NULL; 
 (*head)->next=NULL; 
 for(int i=0;i<50;i++) 
 { 
 (*head)->Seat[i]=0; 
 } 
} 
   
bool Person::Check(int *Seat,int Ch) 
{ 
 int i; 
 for(int i=0;i<50;i++) 
 { 
 if(Ch==i&&Seat[i]!=1)return 1; 
 } 
 return 0; 
} 
Flight* Index(Flight *head,char *Id) 
{ 
 Flight *p=head->next; 
   
 while(p) 
 { 
 if(strcmp(p->FlightId,Id)==0) 
 { 
 return p; 
 } 
 p=p->next; 
 } 
   
 return NULL; 
} 
/*******************************Ԥ��******************************/
void Person::Insert(Flight *head) 
{ 
 int count=0; 
 int Ch; 
 Flight *s=head; 
   
 if(s->next==NULL) 
 { 
 cout<<"���޺��࣡"<<endl; 
 return ; 
 } 
 cout<<"�����б�"<<endl; 
 s=s->next; 
 while(s!=NULL) 
 { 
 puts(s->FlightId); 
 count++; 
 if(count%5==0) 
 cout<<"\n"; 
 s=s->next; 
 } 
 count=0; 
 char FID[10]; 
 cout<<"���뺽��ID��"; 
 gets(FID); 
 s=Index(head,FID); 
 if(s==NULL) 
 { 
 cout<<"����ID����"<<endl; 
 return; 
 } 
 cout<<endl; 
 cout<<"��������λ�ɹ�ѡ��"<<endl; 
 for(int i=0;i<50;i++) 
 { 
 if(s->Seat[i]!=1) 
 { 
 cout<<i<<"��"<<"\t"; 
 count++; 
 if(count%5==0) 
 cout<<"\n"; 
 } 
 } 
 cout<<endl; 
 cout<<"������λ�ţ�\n"; 
 cin>>Ch; 
 getchar(); 
 if(!Check(head->Seat,Ch)) 
 { 
 cout<<"This Seat have been booked or it is non-existent"; 
 return ; 
 } 
 s->Seat[Ch]=1; 
 char name[20]; 
 cout<<endl; 
 cout<<"Input your Name:"; 
 gets(name); 
 Ticket *p=s->PersonHead,*q; 
   
 while(p->next!=NULL) 
 {  
 if(strcmp(p->next->Name,name)>0) 
 break; 
 p=p->next; 
 } 
   
 q=(Ticket *)malloc(sizeof(Ticket)); 
 q->next=p->next; 
 p->next=q; 
 strcpy(q->Name,name); 
 q->SeatId=Ch; 
} 
   
/*******************************ȡ��Ԥ��******************************/
int Person::Delete(Flight *head) 
{ 
 char name[20],FID[10]; 
 cout<<"Input your Name:"; 
 gets(name); 
 getchar(); 
 Flight *s; 
 cout<<"Input the Flight ID:"; 
 gets(FID); 
 s=Index(head,FID); 
 if(s==NULL) 
 { 
 cout<<"����ID����"<<endl; 
 return 0; 
 } 
   
 Ticket *p=s->PersonHead->next,*pre=s->PersonHead; 
 int flag=0; 
 while(p!=NULL) 
 { 
 if(strcmp(p->Name,name)==0){ 
 flag=1; 
 break;  
 } 
 pre=p; 
 p=p->next; 
 } 
 if(flag==1){ 
 pre->next=p->next; 
 s->Seat[p->SeatId]=0; 
 free(p); 
 cout<<"��Ļ�Ʊ�Ѿ�ȡ���ɹ�"; 
 } 
 else 
 { 
 cout<<"����û��Ʊ\n"; 
 return 0;  
 } 
 return 1; 
} 
/*******************************��ʾ��Ϣ******************************/
void Person::show(Flight *head) 
{ 
 Flight *s; 
 char FID[10]; 
 cout<<"Input The Flight ID:"; 
 gets(FID); 
 s=Index(head,FID); 
 if(s==NULL) 
 { 
 cout<<"����ID����"<<endl; 
 return; 
 } 
 Ticket *p=s->PersonHead->next; 
 if(p==NULL) 
 { 
 cout<<"��û�˿Ͷ�Ʊ"<<endl; 
 return; 
 } 
 while(p!=NULL) 
 { 
 cout<<"�˿�: "<<p->Name<<" ��λ��:" <<p->SeatId; 
 p=p->next; 
 } 
} 
   
/*******************************��ѯ�����Ϣ******************************/
void Person::Search(Flight *head) 
{ 
 char name[20]; 
 cout<<"Input Your Name:"; 
 gets(name); 
 Flight *s; 
 char FID[10]; 
 cout<<"Input The Flight ID:"; 
 gets(FID); 
 s=Index(head,FID); 
 if(s==NULL) 
 { 
 cout<<"����ID����"<<endl; 
 return; 
 } 
 Ticket *p=s->PersonHead->next; 
 int flag=0; 
 while(p!=NULL) 
 { 
 if(strcmp(p->Name,name)==0){ 
 flag=1; 
 break;  
 } 
 p=p->next; 
 } 
 if(flag==1){ 
 cout<<name<<" �Ѷ���Ʊ"<<endl; 
 } 
 else 
 { 
 cout<<name<<" δ����Ʊ"<<endl; 
 } 
} 
/*******************************���Ӻ���**********************************/
void Person::AddFlght(Flight *head) 
{ 
 char FlightID[10]; 
 Flight *p=head,*q; 
 cout<<" ���뺽��ID��"; 
 gets(FlightID); 
 while(p->next) 
 { 
 p=p->next; 
 } 
   
 ListInitiate(&q); 
 p->next=q; 
 strcpy(q->FlightId,FlightID); 
 cout<<"--��������ӳɹ���"; 
} 
/**********************************ɾ������*******************************************/
void Person::DeleteFlght(Flight *head) 
{ 
 char FlightID[10]; 
 int flag=0; 
 Flight *p=head->next,*q=head; 
   
 int count=0; 
 Flight *s=head; 
   
 if(s->next==NULL) 
 { 
 cout<<" ���޺��࣡"<<endl; 
 return ; 
 } 
 cout<<" �����б�"<<endl; 
 s=s->next; 
 while(s!=NULL) 
 { 
 cout<<s->FlightId<<endl; 
 count++; 
 if(count%5==0) 
 cout<<"\n"; 
 s=s->next; 
 } 
 cout<<" ���뺽��ID��"; 
 gets(FlightID); 
 while(p) 
 { 
 if(strcmp(p->FlightId,FlightID)==0) 
 { 
 flag=1;break; 
 } 
 q=p; 
 p=p->next; 
 } 
 if(flag==0) 
 { 
 cout<<" �ú���ID�����ڣ�"; 
 return ; 
 } 
 q->next=q->next->next; 
 free(p); 
 cout<<" ������ɾ����\n"; 
}
