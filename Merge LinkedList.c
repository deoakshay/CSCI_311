#include<stdio.h>
#include<malloc.h>

struct node* insert(struct node*,int );
void disp(struct node *head);
void merge();
int x,m,n,i;
struct node
{
int data;
struct node* link;
}*head,*h1,*h2,*h3,*q,*p,*temp;

main()
{
printf("Enter no. of nodes for list-1:\n");
scanf("%d",&n);
h1=insert(h1,n);
disp(h1);

printf("\nEnter no. of nodes for list-2:\n");
scanf("%d",&m);
h2=insert(h2,m);
disp(h2);

printf("\nMerged link list is:\n");
merge();
disp(h3);
}

struct node *insert(struct node *head,int n)
{
for(i=0;i<n;i++)
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter data for node %d:",i);
scanf("%d",&x);
p->data=x;
if(head==NULL)
{
//head=(struct node*)malloc(sizeof(struct node));
head=p;
head->link=NULL;
temp=head;
}
else
{
p->link=NULL;
temp->link=p;
temp=p;
}
}
return(head);
}

void disp(struct node *head)
{
temp=head;
while(temp->link!=NULL)
{
printf("%d\t",temp->data);
temp=temp->link;
}
printf("%d\t",temp->data);
}

void merge()
{
while(h1!=NULL && h2!=NULL)
{
if(h3==NULL)
{
if(h1->data<h2->data)
{
h3=h1;
q=h1;
h1=h1->link;
}
else
{
h3=h2;
h2=h2->link;
q=h2;
}
}
else
{
if(h1->data>h2->data)
{
q->link=h2;
q=h2;
h2=h2->link;
}
else
{
q->link=h1;
q=h1;
h1=h1->link;
}
}
}
if(h1!=NULL && h2==NULL)
q->link=h1;
else
q->link=h2;
}
