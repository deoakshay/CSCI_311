#include<iostream.h>
#include<conio.h>
#include<process.h>

class tree
{
	public:
	char info;
	tree *left,*right;
	tree()
	{
		left=NULL;
		right=NULL;
	}
	void add(tree *,tree *);
	int height(tree *);
	void leaf_nodes(tree *root);
	void mirror(tree *root);
	void inorder(tree *root);
	void level(tree *root);
};
int main()
{
	tree *root,*temp;
	clrscr();
	char ans;
	root=new tree();
	cout<<"\n\n\tEnter data for root : ";
	cin>>root->info;
	cout<<"\n\n\tDo you want to enter more...???";
	cin>>ans;
	while(ans=='Y'||ans=='y')
	{
		cout<<"\n\n\tEnter data : ";
		temp=new tree();
		cin>>temp->info;
		root->add(root,temp);
		cout<<"\n\n\tDo you want to enter more...???";
		cin>>ans;
	}
	int cho;
	do
	{
		cout<<"\n\n\t**************************"
				<<"\n\n\t1] Find Height"
				<<"\n\n\t2] Print leaf nodes"
				<<"\n\n\t3] Mirror image"
				<<"\n\n\t4] Level-wise printing"
				<<"\n\n\t5] Exit"
				<<"\n\n\t**************************" ;
		cout<<"\n\n\tEnter your choice : ";
		cin>>cho;
		int h;
		switch(cho)
		{
			case 1://height
				h=root->height(root);
				cout<<"\n\n\tHeight of the tree is : "<<h;
			break;
			case 2://leaf nodes
				cout<<"\n\n\tLeaf nodes are :";
				root->leaf_nodes(root);
			break;
			case 3://mirror image
				root->mirror(root);
				root->level(root);
				root->mirror(root);
			break;
			case 4://level-wise printing
				root->level(root);
			break;
			case 5://exit
				exit(0);
			break;
			default:
				cout<<"\n\n\tWrong choice...!!!";
			break;
		}
	}while(cho!=6);
	getch();
	return(0);
}
void tree::add(tree *root,tree *temp)
{
	int flag=0;
	tree *head=root;
	char ch;
	while(flag==0)
	{
		cout<<"\n\n\tLeft or right child of "<<head->info<<"(L\R) : ";
		cin>>ch;
		if(ch=='L'||ch=='l')
		{
			if(head->left==NULL)
			{
				head->left=temp;
				flag=1;
			}//end inner if
			else
				head=head->left;
		}//end if
		else if(ch=='R'||ch=='r')
		{
			if(head->right==NULL)
			{
				head->right=temp;
				flag=1;
			}//end inner if
			else
				head=head->right;
		}//end else if
		else
			cout<<"\n\n\tInvalid choice...!!!";
	}//end while
}//end function
int tree::height(tree *root)
{
	tree *head=root;
	int l=0;
	int r=0;
	if(head==NULL||(head->left==NULL&&head->right==NULL))
		return(0);
	l=height(head->left);
	r=height(head->right);
	if(l>r)
		return(l+1);
	else
		return(r+1);
}
void tree::leaf_nodes(tree *root)//L-N-R
{
	if(root!=NULL)
	{
		leaf_nodes(root->left);
		if(root->left==NULL&&root->right==NULL)
			cout<<root->info<<"\t";
		leaf_nodes(root->right);
	}
}

void tree::mirror(tree *root)
{
	tree *temp;
	if(root!=NULL)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirror(root->left);
		mirror(root->right);
	}
}

void tree::level(tree *root)
{
	tree *head=root;
	tree *q1[10],*q2[10];
	int i=0,j=0,m=0,k=0,height=0;
	if(head!=NULL)
	{
		cout<<"\t"<<head->info<<endl;
		q1[i++]=head->left;
		q1[i++]=head->right;

	}
	int flag=0;
	while(flag==0)
	{
		while(j!=i)
		{
			head=q1[j++];
			if(head!=NULL)
			{
				cout<<"\t"<<head->info;
				q2[m++]=head->left;
				q2[m++]=head->right;
			}
		}
			cout<<endl;
			for(i=0;i<m;i++)
			{
				if(q2[i]!=NULL)
				{
					q1[k]=q2[i];
					k++;
				}
			}
			if(k==0)
				flag=1;
			i=k;
			k=0;
			j=0;
			m=0;
	}
}
/* OUTPUT :

				Left or right child of a(LR) : l

				Enter data for root : a

				Do you want to enter more...???y

				Enter data : s

				Left or right child of a(LR) : l

				Do you want to enter more...???y

				Enter data : d

				Left or right child of a(LR) : r

				Do you want to enter more...???y

				Enter data : f

				Left or right child of a(LR) : l

				Left or right child of s(LR) : l

				Do you want to enter more...???y

				Enter data : g

				Left or right child of a(LR) : l

				Left or right child of s(LR) : r

				Do you want to enter more...???y

				Enter data : h

				Left or right child of a(LR) : r

				Left or right child of d(LR) : r

				Do you want to enter more...???n

				**************************
				1] Find Height
				2] Print leaf nodes
				3] Mirror image
				4] Level-wise printing
				5] Exit
				**************************

				Enter your choice : 1

				Height of the tree is : 2

				Enter your choice : 2

				Leaf nodes are : f 	g    h

				Enter your choice : 3

				a
				d       s
				h       g       f
				Enter your choice : 4

				a
				s       d
				f       g       h

				Enter your choice : 5

*/
