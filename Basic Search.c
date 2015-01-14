#include<stdio.h>
int linear(int a[10],int x,int i,int n);
int bin_search(int a[10],int x,int l,int h);

int main()
{
 int i,j,n,x,ch,c,flag,pos,low,high,mid;
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
  printf("\nMENU\n1.Linear Search\n2.Binary Search\n3.Exit\n");
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:/*linear search*/
   printf("\nEnter an element for searching:");
   scanf("%d",&x);
   i=0;
   pos=linear(a,x,i,n);
   if(pos!=-1)
   printf("\nElement is present at the position %d.",pos);
   else
   printf("\nElement not found.\n");
   break;
   case 2:/*binary search*/
   printf("\nEnter an element for searching:");
   scanf("%d",&x);
   c=bin_search(a,x,0,n-1);
   if(c!=-1)
   printf("\nElement is present at the position %d.",c);
   else
   printf("\nElement not found.\n");
   break;
   case 3:/*exit*/
   break;
  }
 }while(ch<3);
}

int linear(int a[10],int x,int i,int n)
{
 if(i<n)
 {
  if(a[i]==x)
  return(i+1);
  else
  return(linear(a,x,i+1,n));
 }
 else
 return(-1);
}

int bin_search(int a[10],int x,int l,int h)
{
 int mid;
 if(l<h)
 {
  mid=(h+l)/2;
  if(a[mid]==x)
  return(mid+1);
  else
  {
   if(x>a[mid])
   return(bin_search(a,x,mid+1,h));
   else
   return(bin_search(a,x,l,mid));
  }
 }
 else
 return(-1);
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
4
Enter a data:
5
1       2       3       4       5
MENU
1.Linear Search
2.Binary Search
3.Exit

Enter your choice:1

Enter an element for searching:4

Element is present at the position 4.
MENU
1.Linear Search
2.Binary Search
3.Exit

Enter your choice:2

Enter an element for searching:2

Element is present at the position 2.
*/
