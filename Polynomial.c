#include<stdio.h>

struct poly
{
int power;
int coeff;
}p1[10],p2[10],p3[10];

int pow(int d,int y);
int main()
{
int sum,d,x,y,ch,i,j,k,m,n,l;
do
{
printf("\nMENU:\n1.Insert Poly1 & Poly2\n2.Addition\n3.Multiplication
\n4.Evalution\n5.EXIT\n");
printf("Enter the choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1://insert poly1 & poly 2
printf("Enter the number of terms to be entered for poly1:\n");//Insert 1st poly
scanf("%d",&m);

for(i=0;i<m;i++)
{
printf("Enter the co-efficient & power:\n");
scanf("%d%d",&p1[i].coeff,&p1[i].power);
}

for(i=0;i<m;i++)//Display 1st poly
{
printf("%dx^%d+ ",p1[i].coeff,p1[i].power);
}

printf("\nEnter the number of terms to be entered for poly2:\n");//Insert 2nd poly
scanf("%d",&n);

for(j=0;j<n;j++)
{
printf("Enter the co-efficient & power:\n");
scanf("%d%d",&p2[j].coeff,&p2[j].power);
}

for(j=0;j<n;j++)//Display 2st poly
{
printf("%dx^%d+ ",p2[j].coeff,p2[j].power);
}
break;

case 2://Addition
k=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(p1[i].power==p2[j].power)
{
p3[k].coeff=p1[i].coeff+p2[j].coeff;
p3[k].power=p1[i].power;
k++;
break;
}
}

if(j==n)
{
p3[k].coeff=p1[i].coeff;
p3[k].power=p1[i].power;
k++;
}
}

for(j=0;j<n;j++)
{
for(i=0;i<m;i++)
{
if(p1[i].power==p2[j].power)
break;
}

if(i==m)
{
p3[k].coeff=p2[j].coeff;
p3[k].power=p2[j].power;
k++;
}
}

printf("\nADDITION:\n");//Display addition
for(i=0;i<k;i++)
{
printf("%dx^%d+ ",p3[i].coeff,p3[i].power);
}
break;

case 3://Multiplication
k=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
x=p1[i].power+p2[j].power;
y=p1[i].coeff*p2[j].coeff;

for(l=0;l<k;l++)
{
if(p3[l].power==x)
{
p3[l].coeff=p3[l].coeff+y;
break;
}
}
if(l==k)
{
p3[k].coeff=y;
p3[k].power=x;
k++;
}
}
}
printf("\nMULTIPLICATION:\n");//Display mult
for(i=0;i<k;i++)
{
printf("%dx^%d+ ",p3[i].coeff,p3[i].power);
}
break;

case 4://Evaluation
printf("Enter the value\n");//evaluation
scanf("%d",&d);
sum=0;
for(i=0;i<m;i++)
{
x=p1[i].coeff;
y=p1[i].power;
sum=sum+x*pow(d,y);
}

printf("Evaluated answer:%d",sum);
break;

case 5:
printf("EXIT\n");
break;

}
}while(ch!=4);
}

int pow(int x, int y)
{
int i,p=1;
for(i=0;i<y;i++)
{
p=p*x;
}
return(p);
}
