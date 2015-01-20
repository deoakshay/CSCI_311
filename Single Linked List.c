//Single Linked List
#include<stdio.h>
#include<malloc.h>

struct node
{
int data;
struct node* link;
}*head,*p,*temp,*q,*r;

struct node* disp(struct node* head);
void ins_start();
void ins_end();
main()
{
int pos,count,ch,x,i,n,t,j,y;
do
{
printf("\nMENU:\n1.CREATE\n2.Insertion at start\n3.Insertion at middle\n
4.Insertion at end\n5.Deletion at start\n6.Deletion at middle\n7.Deletion at end
\n8.Sorting\n9.Searching\n10.Reverse\n11.EXIT\n");
printf("Enter your choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1://CREATE
printf("Enter no. of nodes you want to enter:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter data for node %d:",i+1);
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
disp(head);
break;

case 2://insertion at start
ins_start();
disp(head);
break;

case 3://insertion at middle
count=1;
temp=head;
printf("Enter position:\n");
scanf("%d",&pos);
if(pos==1)
{
ins_start();
}
else
{
printf("Enter data:\n");
scanf("%d",&x);
p=(struct node*)malloc(sizeof(struct node));
temp=head;
while(count<pos)
{
temp=temp->link;
count++;
}
p->data=x;
p->link=temp->link;
temp->link=p;
disp(head);
}
break;

case 4://insertion at end
ins_end();
disp(head);
break;

case 5://deletion at start
{
temp=head;
head=head->link;
free(temp);
}
disp(head);
break;

case 6://deletion at middle
printf("Enter the position of data to be deleted:\n");
scanf("%d",&pos);
temp=head;
count=1;
while(count<pos-1)
{
temp=temp->link;
count++;
}
p=temp->link;
temp->link=p->link;
free(p);
disp(head);
break;

case 7://deletion at end
temp=head;
p=head;
while(temp->link!=NULL)
{
p=temp;
temp=temp->link;
}
p->link=NULL;
free(temp);
disp(head);
break;

case 8://sorting
for(i=1;i<=n;i++)
{
temp=head;
for(j=1;j<=n-1;j++)
{
if(temp->data<temp->link->data)
{
t=temp->data;
temp->data=temp->link->data;
temp->link->data=t;
}
temp=temp->link;
}
}
disp(head);
break;

case 9://searching
pos=0;
count=1;
printf("Enter the element to be searched in list:\n");
scanf("%d",&y);
temp=head;
while(temp->link!=NULL)
{
if(y==temp->data)
{
pos=count;
break;
}
else
{
temp=temp->link;
count++;
}
}
if(pos==0)
printf("Data not found\n");
else
printf("Data found at position:%d\n",pos);
break;

case 10://Reverse of a link list
r=NULL;
p=head;
q=head->link;
while(q!=NULL)
{
p->link=r;
r=p;
p=q;
q=q->link;
}
p->link=r;
head=p;
disp(head);
break;


case 11://exit
printf("EXIT\n");
break;

}
}while(ch!=11);
}

struct node* disp(struct node* head)
{
printf("Linked list is:\n");
temp=head;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->link;
}
}

void ins_start()
{
int x;
printf("Enter the data:\n");
scanf("%d",&x);
p=(struct node*)malloc(sizeof(struct node));
p->data=x;
p->link=head;
head=p;
}

void ins_end()
{
int u;
printf("Enter data:\n");
scanf("%d",&u);
p=(struct node*)malloc(sizeof(struct node));
p->data=u;
p->link=NULL;
temp->link=p;
temp=p;
}
