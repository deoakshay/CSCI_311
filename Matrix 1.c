#include<stdio.h>
int main()
{
int i,j,k,m2,n2,m1,n1,ch,a[3][3],b[3][3],c[3][3];
do
{
printf("\nMENU:\n1.Insert matrix\n2.Matrix Addition\n3.Matrix Substraction
\n4.Matrix Multiplication\n5.Matrix Transpose\n6.Exit\n");

printf("Enter the choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1://Insert matrix
printf("Enter the dimension of matrix:\n");
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
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
break;

case 2://Addition
printf("Enter the dimension of another matrix:\n");//Insert 2nd matrix
scanf("%d%d",&m2,&n2);
printf("Enter the elements of matrix:\n");
for(i=0;i<m2;i++)
{
for(j=0;j<n2;j++)
{
printf("Enter the %d row and %d column element:",i,j);
scanf("%d",&b[i][j]);
}
}

printf("ADDITION:\n");//Print answer
if(m1==m2 && n1==n2)
{
for(i=0;i<m2;i++)
{
for(j=0;j<n2;j++)
{
c[i][j]=a[i][j]+b[i][j];
printf("%d\t",c[i][j]);
}
printf("\n");
}
}
break;

case 3://Substraction
printf("Enter the dimension of another matrix:\n");//Insert 2nd matrix
scanf("%d%d",&m2,&n2);
printf("Enter the elements of matrix:\n");
for(i=0;i<m2;i++)
{
for(j=0;j<n2;j++)
{
printf("Enter the %d row and %d column element:",i,j);
scanf("%d",&b[i][j]);
}
}
printf("SUBSTRACTION:\n");//print answer
if(m1==m2 && n1==n2)
{
for(i=0;i<m2;i++)
{
for(j=0;j<n2;j++)
{
c[i][j]=a[i][j]-b[i][j];
printf("%d\t",c[i][j]);
}
printf("\n");
}
}
break;

case 4://Multiplication
printf("Enter the dimension of another matrix:\n");//Insert 2nd matrix
scanf("%d%d",&m2,&n2);
printf("Enter the elements of matrix:\n");
for(i=0;i<m2;i++)
{
for(j=0;j<n2;j++)
{
printf("Enter the %d row and %d column element:",i,j);
scanf("%d",&b[i][j]);
}
}
printf("MULTIPLICATION:\n");//print answer
if(n1==m2)
{
for(i=0;i<m1;i++)
{
for(j=0;j<n2;j++)
{
c[i][j]=0;
for(k=0;k<n1;k++)
{
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
printf("%d\t",c[i][j]);
}
printf("\n");
}
}
break;

case 5://Transpose
printf("TRANSPOSE:\n");
for(i=0;i<n1;i++)//transpose
{
for(j=0;j<m1;j++)
{
c[i][j]=a[j][i];

printf("%d\t",c[i][j]);
}
printf("\n");
}
break;

case 6://Exit
printf("EXIT\n");
break;

}
}while(ch!=6);

return 0;
}
