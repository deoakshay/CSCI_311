#include<stdio.h>

int fibo(int x,int a[10],int n);
int main()
{
 int i,j,n,x,ch,c,flag,low,high,mid;
 int a[10];
 printf("How many elements you want to enter?\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter a data:\n");
  scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
  printf("%d\t",a[i]);
 }
 do
 {
  printf("\nMENU\n1.Linear Search\n2.Binary Search\n3.Fibonacci Search\n4.Exit\n");
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:/*linear search*/
   printf("\nEnter an element for searching:");
   scanf("%d",&x);
   for(i=0;i<n;i++)
   {
    if(a[i]==x)
    {
     flag=1;
     printf("\nElement is present at the positon %d\n",i+1);
     break;
    }
    else
    flag=0;
   }
   if(flag==0)
   printf("Element is not present\n");
   break;
   case 2:/*binary search*/
   printf("\nEnter an element for searching:");
   scanf("%d",&x);
   high=n-1;
   low=0;
   while(low<=high)
   {
    mid=(low+high)/2;
    if(a[mid]==x)
    {
     printf("\nElement is present at the position %d\n",mid+1);
     break;
    }
    else
    {
     if(a[mid]<x)
     low=mid+1;
     else
     high=mid-1;
    }
   }
   if(low>high)
   printf("\nElement not found.\n");
   break;
   case 3:/*fibonacci search*/
   printf("\nEnter an element you want to search:");
   scanf("%d",&x);
   c=fibo(x,a,n);
   if(c==-1)
   printf("\nElement not found\n");
   else
   printf("\nElement is present at the position %d\n",c);
   break;
   case 4:/*exit*/
   break;
  }
 }while(ch<4);
}

int fibo(int x,int a[10],int n)
{
 int f1,f2,mid,t;
 f1=1;
 f2=1;
 while(f1<n)
 {
  f1=f1+f2;
  f2=f1-f2;
 }
 f1=f1-f2;
 f2=f2-f1;
 mid=n-f1+1;
 if(a[mid]==x)
 return(mid+1);
 while(a[mid]!=x)
 {
  if(mid!=-1||x<a[mid])
  {
   if(f2==-1)
   return(-1);
   mid=mid-f2;
   t=f1-f2;
   f1=f2;
   f2=t;
  }
  else
  {
   if(f1==1)
   return(-1);
   mid=mid+f2;
   f1=f1-f2;
   f2=f2-f1;
  }
 }
 return(mid+1);
}

/*Output
How many elements you want to enter?
5
Enter a data:
1
Enter a data:
2
Enter a data:
3
Enter a data:
6
Enter a data:
5
1       2       3       6       5
***MENU***
1.Linear Search
2.Binary Search
3.Fibonacci Search
4.Exit

Enter your choice:1

Enter an element for searching:6

Element is present at the positon 4

***MENU***
1.Linear Search
2.Binary Search
3.Fibonacci Search
4.Exit

Enter your choice:2

Enter an element for searching:2

Element is present at the position 2
*/
