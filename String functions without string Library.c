#include<stdio.h>

int len(char s1[20]);
void scopy(char s1[20]);
void srev(char s1[20]);
void scat(char s1[20]);
void spali(char s1[20]);
void supr(char s1[20]);
void slwr(char s1[20]);
int scomp(char s1[20]);
int ssub(char s1[20]);

int main()
{
char s1[20],s2[20];
int c,ch;
do
{
printf("\nMENU:\n1.Length\n2.Copy\n3.Reverse\n4.Concat\n5.Palindrome\n6.Upper
\n7.Lower\n8.Compare\n9.Substring\n10.EXIT\n");
printf("Enter a string:\n ");
scanf("%s",&s1);
printf("Enter your choice:\n");
scanf("%d",&ch);
/*printf("Enter another string:\n");
scanf("%s",&s2);*/
switch(ch)
{
case 1:
len(s1);
break;

case 2:
scopy(s1);
break;

case 3:
srev(s1);
break;

case 4:
scat(s1);
break;
/*
case 5:
c=spali(s1);
if(c==0)
printf("Not Palindrome");
else
printf("Palindrome");
break;
*/

case 6:
supr(s1);
break;

case 7:
slwr(s1);
break;


case 8:
c=scomp(s1);
if(c==0)
{
printf("Strings are equal");
}
else
{
if(c==1)
printf("String1 is greater than String2");
else
{
if(c==-1)
printf("String2 is greater than String1");
}
}
break;


case 9:
ssub(s1);
break;

case 10:
printf("EXIT\n");
break;
}
}
while(ch!=10);

return 0;
}


/*1.Length*/
int len(char s1[20])
{
int i,c=0;
for(i=0;s1[i]!='\0';i++)
{
c++;
}
printf("Length: %d \n",c);
}

/*2.Copy*/
void scopy(char s1[20])
{
int i;
char s2[10];
for(i=0;s1[i]!='\0';i++)
{
s2[i]=s1[i];
}
s2[i]='\0';
printf("Copied string: %s\n",s2);
}

/*3.Reverse*/
void srev(char s1[20])
{
char s2[20];
int i,j,k;
for(i=0;s1[i]!='\0';i++);
for (j=i-1,k=0;j>=0;j--,k++)
{
s2[k]=s1[j];
}
s2[k]='\0';
printf("Reverse of given string: %s\n",s2);
}

/*4.Concat*/
void scat(char s1[20])
{
int i,j,k=0,l;
char s2[10];
printf("Enter another string:\n");
scanf("%s",&s2);
for(i=0;s1[i]!='\0';i++);
for(j=0;s2[j]!='\0';j++)
{
s1[i]=s2[j];
i++;
}
s1[i]='\0';
printf("Concated string: %s \n",s1);
}

/*5.Palindrome
void spali(char s1[20])
{
int i,j;
for(i=0;s1[j]!='\0';j--)
while(i<j)
{
if(s1[i]!=s1[j])
return(0);
i++;
j--;
}
return(1);
}
*/

/*6.Upper*/
void supr(char s1[20])
{
int i;
for(i=0;s1[i]!='\0';i++)
{
if(s1[i]>=97 && s1[i]<=122)
{
s1[i]=s1[i]-32;
}
}
printf("Upper case: %s\n",s1);
}

/*7.Lower*/
void slwr(char s1[20])
{
int i;
for(i=0;s1[i]!='\0';i++)
{
if(s1[i]>=65 && s1[i]<=91)
{
s1[i]=s1[i]+32;
}
}
printf("Lower case: %s\n",s1);
}

//8.Compare
int  scomp(char s1[20])
{
int i;
char s2[10];
printf("Enter another string:\n");
scanf("%s",&s2);
for(i=0;s1[i]!='\0';i++)
{
if(s1[i]>s2[i])
{
return(1);
}
if(s1[i]<s2[i])
{
return(-1);
}
}
if(s2[i]=='\0')
return(0);
}

/*9.Substring*/
int ssub(char s1[20])
{
int i,j;
char s2[10];
printf("Enter another string:\n");
scanf("%s",&s2);
for(i=0;s1[i]!='\0'&&s2[10]!='\0';i++)
{
if(s2[j]!='\0')
{
if(s2[j]==s1[i])
{
j++;
}
else
{
j=0;
if(s1[i]==s2[j])
{
j++;
}
}
}
}
if(j!=0)
printf("Substring present");
else
printf("Substring not present");
}
