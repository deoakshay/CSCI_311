#include<stdio.h>
#include<malloc.h>

struct qnode
{
int data;
struct qnode *link;
}*f,*r,*temp,*newnode;
int main()
{
void display();
int x,ch;
char c;
do
{
printf("\nMENU:\n1.Insertion of queue\n2.Delete");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1://insert
do
{
newnode=(struct qnode*)malloc(sizeof(struct qnode));
printf("Enter the value:");
scanf("%d",&newnode->data);
newnode->link=NULL;
if(r==NULL)
{
r=f=newnode;
r->link=f;
}
else
{
r->link=newnode;
r=newnode;
r->link=f;
}

printf("Do you want to continue?(y/n):");
scanf("%s",&c);
}while(c=='y');
printf("\nAfter insertion the queue is:");
display();
break;

case 2://delete
do
{
if(r==NULL)
{
printf("\nQueue is empty");
break;
}
else
{
if(f==r)
{
x=f->data;
r=f=NULL;
}
else
{
temp=f;
f=f->link;
r->link=f;
x=temp->data;
temp=NULL;
}
printf("\nDeleted element is:%d",x);
}
printf("\nDo you want to continue?(y/n):");
scanf("%s",&c);
}while(c=='y');
printf("\nAfter deletion the queue is:");
display();
break;

default:printf("\nWrong choice");
break;

}
}while(ch<3);

return 0;
}


void display()
{
if(f==NULL)
{
printf("There is no element to display");
}
else
{
temp=f;
printf("Queue is:\n");
while(temp->link!=f)
{

printf("%d\t",temp->data);
temp=temp->link;
}
printf("%d\t",temp->data);
}

}
