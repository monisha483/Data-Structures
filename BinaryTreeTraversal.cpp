#include<iostream>
#include<queue>
using namespace std;
int h;
struct btree
{
 int val; btree *left, *right;
};
btree *root=NULL;
queue <btree*> Q;

void create(btree *rt,int H)
{
if(H==h)
{
 return;
}
btree *lptr=new btree;
btree *rptr=new btree;
if(!lptr||!rptr)
{cout<<"\nno memory"; return;}
lptr->left=NULL;
lptr->right=NULL;
rptr->left=NULL;
rptr->right=NULL;
cout<<"\nenter left of"<<rt->val<<": "; cin>>lptr->val;
rt->left=lptr;
cout<<"\nenter right of"<<rt->val<<": "; cin>>rptr->val;
rt->right=rptr;
//
H++;
create(lptr,H);
create(rptr,H);
H--;
return;
}

void pre(btree *rt)
{
 if(rt==NULL)
  {
  return;
  }

 cout<<rt->val<<' ';
 pre(rt->left);
 pre(rt->right);
 return;
 }
 void in(btree* rt)
{
 if(rt==NULL)
  {return;
  }
 in(rt->left);
 cout<<rt->val<<' ';
 in(rt->right);
 return;
 }
 void post(btree* rt)
 {
  if(rt==NULL)
  {return;
  }
 post(rt->left);
 post(rt->right);
 cout<<rt->val<<' ';
 return;
 }
 
 void levelorder()
 {
	 btree *node=new btree;
	 if(root==NULL)
	 {
		 return;
	 }
	 Q.push(root);
	 while(!Q.empty())
	 {
		 node=Q.front();
		 cout<<node->val<<' ';
		 Q.pop();
		 if(node->left!=NULL)
		 {
			 Q.push(node->left);
		 }
		 if(node->right!=NULL)
		 {
		 Q.push(node->right);
		 }
		
	 }
 }
 
 int main()
{int H,ch;   btree * t=new btree;
 cout<<"\nenter no levels of btree:";
 cin>>h;
 cout<<"\nenter val of root";
 cin>>t->val;
 H=0;  root=t;
 create(root, H);
 cout<<"\ntree created";

 do{
 cout<<"\nmenu\n1.preorder\n2.inorder\n3.postorder"
     <<"\n4.level order\n5.exit\nenter traversal option: ";
 cin>>ch;
 switch(ch)
 {
 case 1:cout<<"\npreorder: ";
	pre(root);
	break;
 case 2:cout<<"\ninorder: ";
	in(root);
	break;
 case 3:cout<<"\npostorder: ";
	post(root);
	break;
 case 4:
    levelorder();
	break;
 case 5:
    break;
 }
 }while(ch!=5);
 return 0;
}