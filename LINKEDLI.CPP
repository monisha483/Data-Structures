#include<iostream.h>
#include<conio.h>
#include<process.h>
struct linkedlist
{int val; linkedlist *next;
};
linkedlist *start=NULL;
//start=NULL;
void insert()
{linkedlist *ptr;
 linkedlist *newptr=new linkedlist;
 if(!newptr)
 {cout<<"memory full"; return;}
 cout<<"\nenter value:";
 cin>>newptr->val;
 newptr->next=NULL;
 //first insertion ck
 if(start==NULL)
 {
  start=newptr;
   }
 else
 {ptr=start;
 //normal insertion
 while(ptr->next!=NULL)
 {ptr=ptr->next;
 }
 ptr->next=newptr;
 }
}

void Delete()
{ int item, flag=0; linkedlist *ptr, *preptr;
  if(start==NULL)
  {cout<<"\nlinked list empty"; return;}
  cout<<"\nenter value to be deleted:";
  cin>>item;
  //item is at beginning
  if(start->val==item)
  {ptr=start;
   start=start->next;
   delete ptr;
   flag=1;}
  //normal deletion
  else{
  preptr=start;
  ptr=start->next;
  while(ptr->next!=NULL)
  {if(ptr->val==item)
   {preptr->next=ptr->next;
    delete ptr;
    flag=1;break;
   }
   }//if item is at last node
  if(ptr->val==item)
  {delete ptr;
   preptr->next=NULL;
   flag=1;
  }
   }

   if(flag==1) cout<<"\nnode deleted successfully";
   else cout<<"\nitem not found";
}

void display()
{linkedlist *ptr;
 if(start==NULL)
  {cout<<"\nlinked list empty"; return;}
 ptr=start;
 while(ptr->next!=NULL)
 {cout<<ptr->val<<" ";
  ptr=ptr->next;
 }
 cout<<ptr->val;   //last node's value
}
void main()
{clrscr();
 int c;
  do{
  cout<<"\nmenu"
     <<"\n1.insert"
     <<"\n2.delete"
     <<"\n3.display"
     <<"\n4.exit"
     <<"\nenter your choice:" ;
  cin>>c;
  switch(c)
  {
  case 1:insert(); break;
  case 2:Delete(); break;
  case 3:display(); break;
  case 4:exit(0);
  }
 }while(c!=4);


getch();
}