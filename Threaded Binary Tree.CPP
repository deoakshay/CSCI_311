#include<iostream.h>
#include<conio.h>
class tbtnode{
	public:
	char data;
	int lbit,rbit;
	tbtnode *left,*right;
	tbtnode(char x)
	{
		data=x;
		lbit=rbit=0;
		left=right=NULL;
	}
};
class tbt{
	tbtnode *root,*dummy;
	void create1(tbtnode *p,int lf);
	tbtnode* preorder(tbtnode *t);
	tbtnode* inorder(tbtnode *t);
	public:
	void create();
	void pre();
	void ino();
};
tbtnode* tbt::inorder(tbtnode *t)
{
	if(t->rbit==1)
	{
		t=t->right;
		while(t->lbit==1)
			t=t->left;
		return t;
	}
	else
		return (t->right);
}
void tbt::ino()
{
	tbtnode *t;
	t=dummy->left;
	cout<<endl;
	while(t->lbit==1)
		t=t->left;
	while(t!=dummy)
	{
		cout<<" "<<t->data;
		t=inorder(t);
	}
}
tbtnode* tbt::preorder(tbtnode *t)
{
	if(t->lbit==1)
		return (t->left);
	if(t->rbit==1)
		return (t->right);
	while(t->rbit==0)
		t=t->right;
	return (t->right);

}
void tbt::pre()
{
	tbtnode *t;
	t=root;
	cout<<"\n";
	while(t!=dummy)
	{
		cout<<" "<<t->data;
		t=preorder(t);
	}
}
void tbt::create()
{
	dummy=new tbtnode('$');
	dummy->left=dummy;
	dummy->right=dummy;
	create1(dummy,0);
	dummy->lbit=1;
	dummy->rbit=1;
	root=dummy->left;
}
void tbt::create1(tbtnode *father,int lf)
{
	char x;
	tbtnode *p;
	cout<<"\nEnter the character data('-' for no data)::";
	cin>>x;
	if(x=='-')
	return;
	p=new tbtnode(x);
	if(lf==0)
	{
		p->lbit=father->lbit;
		p->left=father->left;
		father->left=p;
		father->lbit=1;
		p->rbit=0;
		p->right=father;
	}
	else
	{
		p->rbit=father->rbit;
		p->right=father->right;
		father->right=p;
		father->rbit=1;
		p->lbit=0;
		p->left=father;
	}
	cout<<"\nEnter left child of "<<x;
	create1(p,0);
	cout<<"\nEnter right child of "<<x;
	create1(p,1);
}

int main()
{
	int ch;
	tbt tree;
	do
	{
		clrscr();
		cout<<"\n1)Crete threaded binary tree.\
		       \n2)Inorder traversal.\
		       \n3)Preorder traversal.\
		       \n4)Postorder traversal.\
		       \n5)Exit.\
		       \n=>Enetr your choice::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				tree.create();
			break;
			case 2:
				tree.ino();
			break;
			case 3:
				tree.pre();
			break;
			case 4:
			break;
			case 5:
			break;

		}
	cout<<"\nPress any key!!";
	getch();
	}while(ch!=5);
return 0;
}
