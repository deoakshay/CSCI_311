#include<iostream.h>
#include<conio.h>

class tree
   {
      private:
	 int data;
	 tree *left,*right;
      public:
	 tree *create();
	 void add(tree *,tree *);
	 void inorder(tree *);
	 int bl(tree *);
	 int height(tree *);
	 tree *ll(tree *);
	 tree *rr(tree *);
	 tree *lr(tree *);
	 tree *rl(tree *);
    };

tree *tree::create()
   {
      tree *r,*temp;
      int n,i,j;
      r=new tree();
      cout<<"\nEnter the number of nodes : ";
      cin>>n;
      cout<<"\nEnter root : ";
      cin>>r->data;
      r->left=r->right=NULL;
      for(i=2;i<=n;i++)
	 {
	    int x,b,test=0;
	    tree *t,*rl,*extra,*parent;
	    t=new tree();
	    cout<<"\nEnter Data : ";
	    cin>>t->data;
	    x=t->data;
	    t->left=t->right=NULL;
	    add(r,t);
	    parent=r;
	    rl=r;
	    while(rl!=NULL)
	       {
		  b=bl(rl);
		  if(b==2||b==-2)
		     {
			parent=extra;
			temp=rl;
			test=1;
		     }
		  if(x<rl->data)
		     {
			extra=rl;
			rl=rl->left;
		     }
		  else
		     {
			extra=rl;
			rl=rl->right;
		     }
	       }
	    if(test==1)
	       {
		  if(x<temp->data && x<temp->left->data)
		     {
			if(temp==r)
			   r=ll(temp);
			else if(parent->data>temp->data)
			   parent->left=ll(temp);
			else
			   parent->right=ll(temp);
		     }
		  else if(x<temp->data && x>temp->left->data)
		     {
			if(temp==r)
			   r=lr(temp);
			else if(parent->data>temp->data)
			   parent->left=lr(temp);
			else
			   parent->right=lr(temp);
		     }
		  else if(x>temp->data && x>temp->right->data)
		     {
			if(temp==r)
			   r=rr(temp);
			else if(parent->data>temp->data)
			   parent->left=rr(temp);
			else
			   parent->right=rr(temp);
		     }
		  else
		     {
			if(temp==r)
			   r=rl(temp);
			else if(parent->data>temp->data)
			   parent->left=rl(temp);
			else
			   parent->right=rl(temp);
			   temp=rl(temp);
		     }
	       }
	 }
      return(r);
   }

void tree::add(tree *r,tree *t)
   {
      if(r->data>t->data)
	 {
	    if(r->left==NULL)
	       r->left=t;
	    else
	       r->add(r->left,t);
	 }
      else
	 {
	    if(r->right==NULL)
	       r->right=t;
	    else
	       r->add(r->right,t);
	 }
   }

tree *tree::ll(tree *rl)
   {
      tree *pivot,*t;
      pivot=rl->left;
      t=pivot->right;
      pivot->right=rl;
      rl->left=t;
      return(pivot);
   }

tree *tree::ll(tree *rl)
   {
      tree *pivot,*t;
      pivot=rl->left;
      t=pivot->right;
      pivot->right=rl;
      rl->left=t;
      return(pivot);
   }

void tree::inorder(tree *h)
   {
      tree *r;
      r=h;
      if(r!=NULL)
      {
	inorder(r->left);
	cout<<"\t"<<r->data;
	inorder(r->right);
       }
   }


tree *tree::rr(tree *rl)
   {
      tree *pivot,*t;
      pivot=rl->right;
      t=pivot->left;
      pivot->left=rl;
      rl->right=t;
      return(pivot);
   }

tree *tree::lr(tree *rl)
   {
      tree *pivot,*t,*tl,*LR;
      pivot=rl->left;
      LR=pivot->right;
      t=LR->right;
      LR->left=pivot;
      LR->right=rl;
      rl->left=t;
      pivot->right=tl;
      return(LR);
   }

tree *tree::rl(tree *rl)
   {
      tree *pivot,*t,*tl,*RL;
      pivot=rl->right;
      RL=pivot->left;
      t=RL->right;
      tl=RL->left;
      RL->left=rl;
      RL->right=pivot;
      rl->right=tl;
      pivot->left=t;
      return(RL);
   }

int tree::bl(tree *root)
   {
      int r,l,c;
      if(root->left==NULL)
	 l=0;
      else
	 l=1+height(root->left);
      if(root->right==NULL)
	 r=0;
      else
	 r=1+height(root->right);
      c=l-r;
      return(c);
   }

int tree::height(tree *root)
   {
      int ht,htr,htl;
      if(root->left==NULL)
	 htl=0;
      else
	 htl=1+root->height(root->left);
      if(root->right==NULL)
	 htr=0;
      else
	 htr=1+root->height(root->right);
      if(htl<htr)
	 return(htr);
      return(htl);
   }

void main()
   {
      tree *root;
      clrscr();
      root=root->create();
      root->inorder(root);
      getch();
    }
