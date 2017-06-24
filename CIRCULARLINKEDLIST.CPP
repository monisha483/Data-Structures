#include<iostream.h>
#include<conio.h>
#include<process.h>
struct circular
{
 int val; circular *next;
};
circular *start=NULL;
void insertbg()
{
 circular *newptr=new circular;
 circular *ptr;
 if(!newptr)
 {
 cout<<"\nmemory full"; return;
 }
 cout<<"\nenter value to insert:"; cin>>newptr->val;
 //1st insertion ck
 if(start==NULL)
 {start=newptr;
  start->next=start;
  cout<<"\nfirst insertion at bg successful";
 }
 else
 {ptr=start;
  while(ptr->next!=start)
  {ptr=ptr->next;
  }
  ptr->next=newptr;
  newptr->next=start;
  start=newptr;
  cout<<"\ninsertion at bg successful";
 }
}

void insertend()
{
 circular *newptr=new circular;
 circular *ptr;
 if(!newptr)
 {
 cout<<"\nmemory full"; return;
 }
 cout<<"\nenter value to insert:"; cin>>newptr->val;
 //1st insertion ck
 if(start==NULL)
 {start=newptr;
  start->next=start;
  cout<<"\nfirst insertion at end successful";
 }
 else
 {ptr=start;
  while(ptr->next!=start)
  {ptr=ptr->next;
  }
  ptr->next=newptr;
  newptr->next=start;
  cout<<"\ninsertion successful";
 }
}
void deletionbg()
{
 circular *ptr, *temp;
 if(start==NULL)
 {cout<<"\ncircular linked list empty";
 return;
 }
 ptr=start;
 while(ptr->next!=start)
 {
  ptr=ptr->next;
 }
 temp=start;
 start=temp->next;
 ptr->next=start;
 delete temp;
 cout<<"\ndeletion at bg successful";
}

void deletionend()
{circular *ptr, *preptr;
 if(start==NULL)
 {cout<<"\ncircular linked list empty";
 return;
 }
 ptr=start;
 while(ptr->next!=start)
 {preptr=ptr;
  ptr=ptr->next;
 }
 preptr->next=start;
 delete ptr;
 cout<<"\ndeletion at end successful";
}
void display()
{circular *ptr;
 if(start==NULL)
 {cout<<"\ncircular linked list empty";
 return;
 }
 ptr=start;
 while(ptr->next!=start)
 {
  cout<<ptr->val<<' ';
  ptr=ptr->next;
 }
 cout<<ptr->val;
}

void main()
{int ch; clrscr();
 do{
 cout<<"\nmenu\n1.insert at beginning\n2.insert at end"
     <<"\n3.delete at beginning\n4.delete at end"
     <<"\n5.display\n6.exit"
     <<"\nenter your choice: ";
 cin>>ch;
 switch(ch)
 {
  case 1:insertbg(); break;
  case 2:insertend(); break;
  case 3:deletionbg(); break;
  case 4:deletionend(); break;
  case 5:display(); break;
  case 6:exit(0);
 }
 }while(ch!=6);
getch();
}