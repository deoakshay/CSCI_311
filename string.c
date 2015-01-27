#include<stdio.h>
#include<string.h>

int main()
{
char s1[20],s2[10];
int l,ch,c;
do
{
printf("\nMENU:\n1.Length\n2.Copy\n3.Reverse\n4.Compare\n5.Lower\n6.Upper
\n7.Concat\n8.Substring\n9.Exit\n");

printf("\nEnter a string:");
scanf("%s",&s1);

printf("Enter the choice:");
scanf("%d",&ch);

switch(ch)
{
case 1: //length
l=strlen(s1);
printf("\nLength of string is: \n");
printf("%d",l);
break;

case 2: //copy
//scanf("%s",s2);
strcpy (s2,s1);
printf("\nCopy of given string: %s \n",s2);
break;

/*case 3: //reverse
strcpy (s2,s1);
strrev(s1);
printf("Reverse of given string: %s \n",s2);
break;
*/
case 4: //compare
printf("Enter string2:\n");
scanf("%s",&s2);
c=strcmp(s1,s2);
if(c<0)
{
printf("s2 is greater than s1");
}
else if(c>0)
{
printf("s1 is greater than s2");
}
else
printf("Both are equal");
break;

/*case 5: //lower
strlwr(s1);
break;

case 6: //upper
strupr(s1);
break;
*/
case 7: //concat
printf("Enter another string: \n");
scanf("%s",&s2);
strcat(s1,s2);
printf("Concated string: %s",s1);
break;

case 8: //substring
printf("Enter another string: \n");
scanf("%s",&s2);
strstr(s1,s2);
if(c==0)
printf("Substring absent");
else
printf("Substring present");
break;

case 9:
printf("EXIT");
break;
}
}
while(ch!=9);

return 0;
}
