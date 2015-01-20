#include<stdio.h>
#include<malloc.h>

struct term
{
int pow,coeff;
struct term *link;
}*hd,*head1,*head2,*head3=NULL,*q,*temp,*temp1,*temp2,*h4;

struct term *mult(struct term*,struct term*);
struct term *insert(struct term*,struct term*);
void display_poly(struct term*);
struct term* create_poly(struct term*);
struct term* add_poly(struct term*,struct term*);
int main()
{
int ch,flag=0;
int p,c;
char y='y';
do
{
printf("\nMenu:\n1.Create\n2.Addition\n3.Multiply\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{

case 1:
printf("Enter poly1:\n");
head1=create_poly(head1);
display_poly(head1);
printf("\nEnter poly2:\n");
head2=create_poly(head2);
display_poly(head2);
break;

case 2:
head3=add_poly(head1,head2);
display_poly(head3);
break;

case 3:
h4=mult(head1,head2);
display_poly(h4);
break;

}
}while(ch<4);
}

struct term *create_poly(struct term *head)
{
int p,c;
char y='y';
head=NULL;
do
{
printf("Enter the coeff and power:");
scanf("%d%d",&c,&p);
q=(struct term*)malloc(sizeof(head1));
q->coeff=c;
q->pow=p;
q->link=NULL;
if(head==NULL)
{
head=q;
head->link=head;
temp=head;
}
else
{
temp->link=q;
q->link=head;
temp=q;
}
printf("Do you want to add more terms?");
scanf("%s",&y);
}while(y=='y');
return(head);
}

struct term *add_poly(struct term *head1,struct term *head2)
{
int flag=0;
struct term *hd=NULL;
temp1=head1;
do
{
flag=0;
temp2=head2;
do
{
if(temp1->pow==temp2->pow)
{
q=(struct term*)malloc(sizeof(head1));
q->pow=temp->pow;
q->coeff=temp1->coeff+temp2->coeff;
flag=1;
break;
}
temp2=temp2->link;
}while(temp2!=head2);
if(flag==0)
{
q=(struct term*)malloc(sizeof(head1));
q->pow=temp1->pow;
q->coeff=temp1->coeff;
}
if(hd==NULL)
{
hd=q;
hd->link=hd;
temp=hd;
}
else
{
temp->link=q;
q->link=hd;
temp=q;
}
temp1=temp1->link;
}while(temp1!=head1);
temp2=head2;
 do
{
flag=0;
temp1=head1;
do
{
if(temp1->pow==temp2->pow)
{
flag=1;
break;
}
temp1=temp1->link;
}while(temp1!=head1);
if(flag==0)
{
q=(struct term*)malloc(sizeof(head1));
q->pow=temp2->pow;
q->coeff=temp2->coeff;
if(hd==NULL)
{
hd=q;
hd->link=hd;
temp=hd;
}
else
{
temp->link=q;
q->link=hd;
temp=q;
}
}
temp2=temp2->link;
}while(temp2!=head2);
printf("Addition:\n");
return(hd);
}

void display_poly(struct term *head)
{
temp=head;
do
{
printf("%dx^%d+",temp->coeff,temp->pow);
temp=temp->link;
}while(temp!=head);
}

struct term *mult(struct term *head1, struct term *head2)
{
int x,y,flag=0;
struct term *t,*hd4=NULL;
temp1=head1;
do
{
temp2=head2;
do
{
x=temp2->pow+temp1->pow;
y=temp2->coeff*temp1->coeff;
q=(struct term*)malloc(sizeof(head1));
q->coeff=y;
q->pow=x;
if(hd4==NULL)
{
hd4=q;
hd4->link=hd4;
temp=hd4;
}
else
{
flag=0;
t=hd4;
do
{
if(t->pow==x)
{
t->coeff+=x;
flag=1;
break;
}
t=t->link;
}while(t!=hd4);
if(flag==0)
{
temp->link=q;
q->link=hd4;
temp=q;
} }
temp2=temp2->link;
}while(temp2!=head2);
temp1=temp1->link;
}while(temp1!=head1);
printf("Multiplication:\n");
return(hd4);
}
