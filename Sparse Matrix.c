#include<stdio.h>
tosparse(int sp1[10][3], int a[7][7], int m, int n);
printsparse(int sp1[10][3]);
readmat(int m,int n, int a[7][7]);
int main()
{
int count[15],ind[15],a[7][7],b[7][7],c[7][7],spf[15][3],sp3[15][3],sp2[15][3],
sp1[15][3],m1,n1,temp,n,m,i,k,j,ch,l,s;
do
{
printf("Menu:\n1.Conversion of 2D matrix to sparse matrix\n
2.Conversion of sparse matrix to 2D matrix\n3.Addition\n4.Simple transpose\n
5.Fast transpose\n6.Multiplication\n7.EXIT\n");

printf("Enter choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1://2D to sparse
printf("Enter dimension of matrix:\n");//Insert 2D mat.
scanf("%d%d",&m,&n);
readmat(m,n,a);
tosparse(sp1,a,m,n);
printsparse(sp1);
break;

case 2://Sparse to 2D
//Here we consider sparse mat->sp[i][j] from 'case 1' for converting to 2D.
printf("Enter no. of rows,no.of columns for 2D mat & no of non-zero elements in
it:\n");
scanf("%d%d%d",&sp1[0][0],&sp1[0][1],&sp1[0][2]);
for(i=1;i<=sp1[0][2];i++)
{
//here enter row no, col no of non-zero elements only.
printf("Enter row no, col no. & element:\n");
scanf("%d%d%d",&sp1[i][0],&sp1[i][1],&sp1[i][2]);
}
k=1;//sparse to 2D
for(i=0;i<sp1[0][0];i++)
{
for(j=0;j<sp1[0][1];j++)
{
if(sp1[k][0]==i && sp1[k][1]==j)
{
a[i][j]=sp1[k][2];
k++;
}
else
a[i][j]=0;
}
}
printf("The required 2D matrix is:\n");
for(i=0;i<sp1[0][0];i++)//printing 2D matrix
{
for(j=0;j<sp1[0][1];j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}

case 3://Addition
printf("Enter dimension of matrix1:\n");//Insert 2D mat.
scanf("%d%d",&m,&n);
readmat(m,n,a);
tosparse(sp1,a,m,n);
printsparse(sp1);
printf("Enter dimension of matrix2:\n");//Insert 2D mat2.
scanf("%d%d",&m1,&n1);
readmat(m1,n1,b);
tosparse(sp2,b,m1,n1);
printsparse(sp2);
//Addition:-
i=1;
j=1;
k=1;
while(i<=sp1[0][2] && j<=sp2[0][2])
{
if(sp1[i][0]==sp2[j][0])
{
if(sp1[i][1]==sp2[j][1])
{
sp3[k][0]=sp1[i][0];
sp3[k][1]=sp1[i][1];
sp3[k][2]=sp1[i][2]+sp2[i][2];
i++;
j++;
k++;
}
else
{
if(sp1[i][1]<sp2[j][1])
{
sp3[k][0]=sp1[i][0];
sp3[k][1]=sp1[i][1];
sp3[k][2]=sp1[i][2];
i++;
k++;
}
else
{
sp3[k][0]=sp2[j][0];
sp3[k][1]=sp2[j][1];
sp3[k][2]=sp2[j][2];
j++;
k++;
}
}
}
else
{
if(sp1[i][0]<sp2[j][0])
{
sp3[k][0]=sp1[i][0];
sp3[k][1]=sp1[i][1];
sp3[k][2]=sp1[i][2];
i++;
k++;
}
else
{
sp3[k][0]=sp2[j][0];
sp3[k][1]=sp2[j][1];
sp3[k][2]=sp2[j][2];
j++;
k++;
}
}
}
while(i<=sp1[0][2])
{
sp3[k][0]=sp1[i][0];
sp3[k][1]=sp1[i][1];
sp3[k][2]=sp1[i][2];
i++;
k++;
}
while(j<=sp2[0][2])
{
sp3[k][0]=sp1[j][0];
sp3[k][1]=sp1[j][1];
sp3[k][2]=sp1[j][2];
j++;
k++;
}
sp3[0][0]=m;
sp3[0][1]=n;
sp3[0][2]=i-1;
printf("Addition:\n");
for(i=0;i<k;i++)
{
for(j=0;j<3;j++)
{
printf("%d\t",sp3[i][j]);
}
printf("\n");
}
break;

case 4://Simple transpose
printf("Enter dimension of matrix:\n");//Insert 2D mat.
scanf("%d%d",&m,&n);
readmat(m,n,a);
tosparse(sp1,a,m,n);
for(i=0;i<=sp1[0][2];i++)//transpose
{
temp=sp1[i][0];
sp1[i][0]=sp1[i][1];
sp1[i][1]=temp;
}
printf("Transpose:\n");//printing transpose
printsparse(sp1);
break;

case 5://Fast transpose
printf("Enter dimension of matrix:\n");//Insert 2D mat.
scanf("%d%d",&m,&n);
readmat(m,n,a);
tosparse(sp1,a,m,n);
printsparse(sp1);
//Counting elements for each column:
for(i=0;i<sp1[0][1];i++)
{
count[i]=0;
}
for(i=1;i<=sp1[0][2];i++)
{
j=sp1[i][1];
count[j]++;
}
//Set starting index of each column:
ind[0]=1;
for(i=1;i<sp1[0][1];i++)
{
ind[i]=ind[i-1]+count[i-1];
}
//Insertion of row at proper position:
for(i=1;i<=sp1[0][2];i++)
{
k=ind[sp1[i][1]];
ind[sp1[i][1]]++;
spf[k][0]=sp1[i][1];
spf[k][1]=sp1[i][0];
spf[k][2]=sp1[i][2];
}
//For zeroth row:
spf[0][0]=m;
spf[0][1]=n;
spf[0][2]=i-1;
//Displaying spf:
printf("Fast transpose is:\n");
for(i=0;i<=sp1[0][2];i++)
{
printf("%d\t%d\t%d\t",spf[i][0],spf[i][1],spf[i][2]);
printf("\n");
}
break;

case 6://Multiplication
printf("Enter dimension of matrix1:\n");//Insert 2D mat1.
scanf("%d%d",&m,&n);
readmat(m,n,a);
tosparse(sp1,a,m,n);
printsparse(sp1);
printf("Enter dimension of matrix2:\n");//Insert 2D mat2.
scanf("%d%d",&m1,&n1);
readmat(m1,n1,b);
tosparse(sp2,b,m1,n1);
printsparse(sp2);
//Multiplication:
for(i=0;i<sp1[0][0];i++)
{
for(j=0;j<sp2[0][1];j++)
{
c[i][j]=0;
}
}
for(k=1;k<=sp1[0][2];k++)
{
for(l=1;l<=sp2[0][2];l++)
{
if(sp1[k][1]==sp2[l][0])
{
s=sp1[k][2]*sp2[l][2];

c[sp1[k][0]][sp2[l][1]]+=s;
}
}
}
printf("Multiplication:\n");//printing mult
for(i=0;i<sp1[0][0];i++)
{
for(j=0;j<sp2[0][1];j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
break;

case 7:
printf("Exit\n");
break;

}
}while(ch!=7);

return 0;
}

readmat(int m,int n, int a[7][7])
{
int i,j;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("Enter elements of %d row & %d column:",i,j);
scanf("%d",&a[i][j]);
}
}
}

tosparse(int sp1[10][3], int a[7][7], int m, int n)
{
int i,j,k;
//To convert to sparse:
k=1;//k is row no. of sparse mat.
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]!=0)
{
sp1[k][0]=i;
sp1[k][1]=j;
sp1[k][2]=a[i][j];
k++;
}
}
}
sp1[0][0]=m;
sp1[0][1]=n;
sp1[0][2]=k-1;
}

printsparse(int sp1[10][3])
{
int i,k,j;
k=sp1[0][2];
printf("Sparse matrix is:\n");//printing sparse mat.
for(i=0;i<=k;i++)
{
for(j=0;j<3;j++)
{
printf("%d\t",sp1[i][j]);
}
printf("\n");
}
}
