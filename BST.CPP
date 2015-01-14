#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class tree
   {
	  public:
		 int d;
		 tree *l,*r;
		 tree()
			{
			   l=NULL;
			   r=NULL;
			}
		 tree* add(tree *root,tree *temp);
		 void inorder(tree *);
		 void preorder(tree *);
		 void postorder(tree *);
   };

tree* tree::add(tree *root,tree *temp)
   {
	  if(temp->d<root->d)
		 {
			if(root->l==NULL)
			   root->l=temp;
			else
			   add(root->l,temp);
		 }
	  else
		 {
			if(root->r==NULL)
			   root->r=temp;
			else
			   add(root->r,temp);
		 }
	  return(root);
   }

void tree::inorder(tree *h)
   {
	  tree *root;
	  root=h;
	  if(root!=NULL)
		 {
			inorder(root->l);
			cout<<"\t"<<root->d;
			inorder(root->r);
		 }
   }

void tree::preorder(tree *h)
   {
	  tree *root;
	  root=h;
	  if(root!=NULL)
		 {
			cout<<"\t"<<root->d;
			preorder(root->l);
			preorder(root->r);
		 }
   }

void tree::postorder(tree *h)
   {
	  tree *root;
	  root=h;
	  if(root!=NULL)
		 {
			postorder(root->l);
			postorder(root->r);
			cout<<"\t"<<root->d;
		 }
   }

void main()
   {
	  tree *root=NULL,*temp;
	  tree t1;
	  int n,i,ch;
	  clrscr();
	  cout<<"\nEnter no. of nodes :- ";
	  cin>>n;
	  for(i=1;i<=n;i++)
		 {
			temp=new tree();
			cout<<"\nEnter node :- ";
			cin>>temp->d;
			if(root==NULL)
			   root=temp;
			else
			   root=t1.add(root,temp);
		 }
	  cout<<"\n**************MENU*************";
	  cout<<"\n1.Inorder\n2.Preorder\n3.Postorder\n4.Exit";
	  cout<<"\nEnter your choice :- ";
	  cin>>ch;
	  switch(ch)
		 {
			case 1:t1.inorder(root);
				   break;
			case 2:t1.preorder(root);
				   break;
			case 3:t1.postorder(root);
				   break;
			case 4:exit(0);
		 }
	  getch();
   }
