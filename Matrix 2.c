#include<stdio.h>
void ins_disp();
int flag,i,j,k,m2,n2,m1,n1,ch,a[7][7],maxcol[7],minrow[7],r[7],c[7],d1,d2,max,min;
int main()
{

do
{
printf("\n1.Insert & Display matrix\n2.Upper triangular matrix
\n3.Lower triangular matrix\n4.Symmetric\n5.Skew symmetric\n6.Magic square
\n7.Saddle point\n8.Inverse of matrix\n9.Exit\n");

printf("Enter the choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1://Insert & Display matrix
ins_disp();
break;

case 2://to check upr triangular mat.
for(i=0;i<m1;i++)//To check upr matrix
{
for(j=0;j<n1;j++)
{
if(i>j)
{
if(a[i][j]==0)
{
 flag=1;
}
else
{
flag=0;
break;
}
}
}
}
if(flag==0)
printf("\nMatrix is not upper triangular\n");
else
printf("\nMatrix is upper triangular\n");
break;

case 3://to check lwr triangular matrix
for(i=0;i<m1;i++)//To check lwr matrix
{
for(j=0;j<n1;j++)
{
if(i<j)
{
if(a[i][j]==0)
{
 flag=1;
}
else
{
flag=0;
break;
}
}
}
}
if(flag==0)
printf("\nMatrix is not lower triangular\n");
else
printf("\nMatrix is lower triangular\n");
break;

case 4://Symmetric
for(i=0;i<m1;i++)//To check symmetric matrix
{
for(j=0;j<n1;j++)
{
if(a[i][j]==a[j][i])
{
flag=1;
}
else
{
flag=0;
break;
}
}
}
if(flag==0)
printf("\nMatrix is not symmetric\n");
else
printf("\nMatrix is symmetric\n");
break;

case 5://To check skew symmetric matrix
for(i=0;i<m1;i++)//To check skew symm.
{
for(j=0;j<n1;j++)
{
if(i!=j)
{
if(a[i][j]=-a[j][i])
{
flag=1;
}
else
{
flag=0;
break;
}
}
}
}
if(flag==0)
printf("\nMatrix is not skew symmetric\n");
else
printf("\nMatrix is skew symmetric\n ");
break;

case 6://Magic Square
d1=0;
d2=0;
for(i=0;i<m1;i++)//To check magic square
{
r[i]=0;
c[i]=0;
for(j=0;j<n1;j++)
{
r[i]=r[i]+a[i][j];
c[i]=c[i]+a[i][j];
if(i==j)
{
d1=d1+a[i][j];
}
if(i+j==m1-1)
{
d2=d2+a[i][j];
}
}
}
for(i=0;i<m1;i++)
{
if(r[i]==c[i] && c[i]==d1 && d1==d2)
{
flag=1;
}
else
{
flag=0;
break;
}
}

if(flag==1)
printf("\nMatrix is Magic Square\n");
else
printf("\nMatrix is not Magic Square\n");
break;

case 7://Saddle point
for(i=0;i<m1;i++)//to check saddle point
{
maxcol[i]=0;
minrow[i]=a[i][0];
for(j=0;j<n1;j++)
{
if(a[j][i]>maxcol[i])
{
maxcol[i]=a[j][i];
}
if(a[i][j]<minrow[i])
{
minrow[i]=a[i][j];
}
}
}

min=maxcol[0];
for(i=0;i<m1;i++)
{
if(min>maxcol[i])
{
min=maxcol[i];
}
}
max=0;
for(i=0;i<n1;i++)
{
if(max<minrow[i])
{
max=minrow[i];
}
}

if(max==min)
{
printf("Matrix is a saddle point\n");
}
else
{
printf("Matrix is not a saddle point\n");
}
break;

case 8://Inverse

case 9:
printf("EXIT\n");
break;
}
}while(ch!=9);
}

void ins_disp()
{
printf("Enter the dimension of matrix:\n");//insert matrix
scanf("%d%d",&m1,&n1);
printf("Enter the elements of matrix:\n");
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
printf("Enter the %d row and %d column element:",i,j);
scanf("%d",&a[i][j]);
}
}

for(i=0;i<m1;i++)//print inserted matrix
{
for(j=0;j<n1;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
return 0;
}
