#include<stdio.h>

int main()
{
int i,j,temp,ch,a[30],step,max,m,elem;
printf("Enter the no. elements:");
scanf("%d",&m);
printf("Enter elements of array:\n");
for(i=0;i<m;i++)
scanf("%d",&a[i]);
do
{
printf("\nMENU:\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Shell sort\n5.Exit\n");
printf("Enter choice:");
scanf("%d",&ch);

switch(ch)
{
case 1://bubble sort
for(j=0;j<m;j++)
{
for(i=0;i<m-1;i++)
{
if(a[i]<a[i+1])
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
} } }
printf("Sorted elements:\n");
for(i=0;i<m;i++)
printf("%d\t",a[i]);
break;

case 2://selection sort
temp=0;
for(i=0;i<m;i++)
{
max=i;
for(j=i+1;j<m;j++)
{
if(a[j]>a[i])
{
max=j;
}
temp=a[i];
a[i]=a[max];
a[max]=temp;
} }
printf("Sorted elements:\n");
for(i=0;i<m;i++)
printf("%d\t",a[i]);
break;

case 3://insertion sort
for(i=1;i<m;i++)
{
elem=a[i];
for(j=i-1;j>=0 && a[j]>elem;j--)
a[j+1]=a[j];
a[j+1]=elem;
}
printf("Sorted elements:\n");
for(i=0;i<m;i++)
printf("%d\t",a[i]);
break;

case 4://shell sort
step=m/2;
while(step>0)
{
for(i=0;i<m;i++)
{
j=step;
while(j<m)
{
if(a[j]<a[j-step])
{
temp=a[j];
a[j]=a[j-step];
a[j-step]=temp;
}
j++; }
step=step/2; } }
printf("Sorted elements:\n");
for(i=0;i<m;i++)
printf("%d\t",a[i]);
break;

case 5://exit
printf("EXIT");
break;

}
}while(ch!=5);
}
