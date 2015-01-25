#include<stdio.h>
void insert();
void Union();
void Intersection();
void diff();
void symm_diff();
int c[20],a[10],b[10],flag,i,j,k,l,m,n,ch;

int main()
{
do
{
printf("\nMENU:\n1.Insert arrays:a & b\n2.Union\n3.Intersection\n
4.Set differnce\n5.Symmetric difference\n6.EXIT\n");
printf("Enter choice:\n");
scanf("%d",&ch);

switch(ch)
{
case 1://insertion of array a & b
insert();
break;

case 2://Union
Union();
break;

case 3://intersection
Intersection();
break;

case 4://set difference:A-B
diff();
break;

case 5://symmetric difference
symm_diff();
break;

case 6://Exit
printf("EXIT\n");
break;

}
}while(ch!=6);

return 0;
}

void insert()
{
printf("Enter size of array1:\n");//insert array1-a
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter %d element of array1:",i);
scanf("%d",&a[i]);
}
printf("A={\t");//print a
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("}");

printf("\nEnter size of array2:\n");//insert array2-b
scanf("%d",&m);
for(j=0;j<m;j++)
{
printf("Enter %d element of array2:",j);
scanf("%d",&b[j]);
}
printf("B={\t");//print b
for(j=0;j<m;j++)
printf("%d\t",b[j]);
printf("}");
}

void Union()
{
k=0;
for(i=0;i<n;i++)
{
c[k]=a[i];
k++;
}
j=0;
for(i=0;i<m;i++)
{
flag=0;
for(j=0;j<n;j++)
{
if(b[i]==a[j])
{
flag=1;
break;
}
}

if(flag==0)
{
c[k]=b[i];
k++;
}
}
printf("A union B={\t");
for(i=0;i<k;i++)
printf("%d\t",c[i]);
printf("}");
}

void Intersection()
{
k=0;
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(a[i]==b[j])
{
c[k]=a[i];
k++;
}
}
}
printf("A intersection B={\t");
for(i=0;i<k;i++)
printf("%d\t",c[i]);
printf("}");
}

void diff()
{
k=0;
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(a[i]==b[j])
{
break;
}
}
if(j==m)
c[k++]=a[i];
}
printf("A-B={\t");
for(i=0;i<k;i++)
printf("%d\t",c[i]);
printf("}");
}

void symm_diff()
{
k=0;
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(a[i]==b[j])
{
break;
}
}
if(j==m)
c[k++]=a[i];
}
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(b[i]==a[j])
break;
}
if(j==n)
c[k++]=b[i];
}
printf("(A-B)U(B-A)={\t");
for(i=0;i<k;i++)
printf("%d\t",c[i]);
printf("}");
}
