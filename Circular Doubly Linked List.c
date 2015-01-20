#include<stdio.h>
#include<malloc.h>
struct node
{
int data;

struct node *prev;
struct node *next;
}*head=NULL,*temp,*p;

struct node* create();
void disp(struct node *);
void insert();
void delete();
void search();
int pos,flag,count,ch,x,i,n;

main()
{
do
{
printf("\nMENU:\n1.CREATE\n2.Insertion at end\n
3.Deletion at start\n4.Searching\n5.EXIT\n");
printf("Enter your choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1://create
head=create();
disp(head);
break;

case 2://insert
insert();
disp(head);
break;

case 3://delete
delete();
disp(head);
break;

case 4://searching
search();
disp(head);
break;

case 5://exit
printf("EXIT\n");
break;

}
}while(ch!=5);
}

struct node* create()
{
printf("Enter no. of nodes:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter data for %d node:",i);
scanf("%d",&x);
temp->data=x;
temp->prev=NULL;
temp->next=NULL;
if(head==NULL)
{
head=temp;
head->prev=head;
head->next=head;
p=head;
}
else
{
p->next=temp;
temp->prev=p;
temp->next=head;
head->prev=temp;
p=temp;
}
}
return(head);
}

void  disp(struct node *head)
{
printf("Linked list is:\n");
p=head;
while(p->next!=head)
{
printf("%d\t",p->data);
p=p->next;
}
printf("%d",p->data);
}

void delete()
{
p=head;
temp=head;
while(temp->next!=head)
{
temp=temp->next;
}
head=head->next;
temp->next=head;
head->prev=temp;
free(p);
}

void insert()
{
printf("enter the data:");
scanf("%d",&x);
p=(struct node*)malloc(sizeof(struct node));
p->data=x;
p->prev=NULL;
p->next=NULL;
if(head==NULL)
{
head=p;
head->next=head;
head->prev=head;
temp=head;
}
else
{
temp->next=p;
p->prev=temp;
p->next=head;
head->prev=p;
temp=p;
}
}

void search()
{
printf("Enter data to be searched:\n");
scanf("%d",&x);
count=1;
temp=head;
while(temp->next!=head)
{
if(temp->data==x)
{
flag=1;
break;
}
else
{
flag=0;
count++;
temp=temp->next;
}
}
if(temp->data==x)
{
flag=1;
}
if(flag==1)
printf("Data present at position:%d\n",count);
else
printf("Data not present\n");
}
