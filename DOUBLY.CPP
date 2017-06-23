#include<iostream.h>
#include<conio.h>
#include<process.h>
struct doubly{
int val;
doubly *prev, *next;
};
doubly *start=NULL;  int flag;
void insert()
{doubly *newptr=new doubly;
 doubly *ptr;
 if(!newptr)
 {cout<<"\nmemory full";
  return;
 }
 cout<<"\nenter val:"; cin>>newptr->val;
 newptr->next=NULL;
 newptr->prev=NULL;
 //1st ins ck
 if(start==NULL){
 start=newptr;
 cout<<"\ninsertion successful";
 }
 //normal sequential insertion
 else
 {
  ptr=start;
  while(ptr->next!=NULL)
  {
  ptr=ptr->next;
   }
  ptr->next=newptr;
  newptr->prev=ptr;
  }
}

void insertbeg()
{doubly *newptr=new doubly;
 if(!newptr)
 {cout<<"\nmemory full";
  return;
 }
 cout<<"\nenter val:"; cin>>newptr->val;
 newptr->next=start;
 start->prev=newptr;
 newptr->prev=NULL;
 start=newptr;
 }

 void insertafter()
 {flag=0;
 doubly *newptr=new doubly;
 if(!newptr)
 {cout<<"\nmemory full";
  return;
 }
 int item;
 doubly *preptr, *ptr;
 cout<<"\nenter val:"; cin>>newptr->val;
 cout<<"\nenter val of node after which u wanna insert";
 cin>>item;
 ptr=start;
 while(ptr->next!=NULL)
 {if(ptr->val==item)
  {flag=1; break;}
  else
  ptr=ptr->next;
 }
 if(flag==1){
 newptr->next=ptr->next;
 (ptr->next)->prev=newptr;
 ptr->next=newptr;
 newptr->prev=ptr;
 cout<<"\ninsertion successful"; }
 else
 {
  cout<<"item not found";
 }
 }

 void del()
 {doubly*ptr;int item;
  if(start==NULL)
  {cout<<"doubly linked list empty";}
  else{
  cout<<"\nenter value to delete";
  cin>>item;
  ptr=start;
  if(start->val==item)
  {
   start=ptr->next;
   start->prev=NULL;
   delete ptr;
   cout<<"\ndeletion at beginning successful";
   return;
  }
  while(ptr!=NULL)
  {
   if(ptr->val==item)
   {ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    delete ptr;
    cout<<"\ndeletion succcessful";
   }
   else{ptr=ptr->next;}
  }
  }
 }
 void deleteafter()
 {doubly*ptr, *temp;int item;flag;
  if(start==NULL)
  {cout<<"doubly linked list empty";}
  else
  {
  cout<<"\nenter value of node after which u wanna delete";
  cin>>item;
  ptr=start;
  while(ptr->next!=NULL)
  {if(ptr->val==item)
   {flag=1;break;}
   else ptr=ptr->next;
   }
   if(flag==1)
    {temp=ptr->next;
     ptr->next=temp->next;
     temp->next->prev=ptr;
     delete temp;
     cout<<"\ndeletion successful";
     return;
    }
    else{
    cout<<"\nitem not found";
    }
  }
 }

 void display()
 {
  doubly*ptr;
  if(start==NULL)
  {cout<<"doubly linked list empty";}
  else{
  ptr=start;
  while(ptr!=NULL)
  {cout<<ptr->val<<' ';
   ptr=ptr->next;}
 }   }

 void main()
 {clrscr();
  int ch;
  do{
  cout<<"\nmenu\n1.insert sequentially\n2.insert at beginning"
      <<"\n3.insert after a node"
      <<"\n4.delete given val"
      <<"\n5.delete node after a given node"
      <<"\n6.display"
      <<"\n7.exit";
  cin>>ch;
  switch(ch)
  {
   case 1:insert(); break;
   case 2:insertbeg();break;
   case 3:insertafter();break;
   case 4:del();break;
   case 5:deleteafter();break;
   case 6:display();break;
   case 7:exit(0);
  } }while(ch!=7);
 getch();
 }