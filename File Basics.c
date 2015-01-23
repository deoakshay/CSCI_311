#include<stdio.h>

struct student
{
char name[15];
int roll,m1,m2,m3,m4,total;
float perct;
}s1;

int main()
{
int ch,x;
FILE *fp;
FILE *fp1;
do
{
printf("Menu:\n1.Insert a file\n2.Display the file\n3.Search the file\n
4.Modify the file\n5.Delete a entry\n6.Exit\n");
printf("Enter choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1://Insert
{
fp=fopen("a.dat","a");
printf("Enter data:\n");
printf("Enter name:\n");
scanf("%s",&s1.name);

printf("Enter roll no:\n");
scanf("%d",&s1.roll);

printf("Enter marks of 4 subjects:\n");
scanf("%d%d%d%d",&s1.m1, &s1.m2, &s1.m3, &s1.m4);

s1.total=s1.m1+s1.m2+s1.m3+s1.m4;
s1.perct=((s1.total)/4);

fwrite(&s1,sizeof(s1),1,fp);
fclose(fp);
}
break;

case 2://Display
fp=fopen("a.dat","r");
if(fp==NULL)
printf("Error\n");
else
{
while(!feof(fp))
{
fread(&s1,sizeof(s1),1,fp);
printf("Name is: %s \n",s1.name);
printf("Rollno is: %d \n",s1.roll);
printf("M1 marks:%d\n M2 marks: %d \n M3 marks: %d \n M4 marks: %d\n ",s1.m1,s1.m2,s1.m3,s1.m4);
printf("Total:%d\n",s1.total);
printf("Percentage:%f\n",s1.perct);
}
fclose(fp);
}
break;

case 3://Search
fp=fopen("a.dat","r+");
printf("Enter roll no. to be searched:\n");
scanf("%d",&x);//Roll no to be searched is stored in x

{
fread(&s1,sizeof(s1),1,fp);
if(s1.roll==x)
printf("Record present\n");
else
printf("Record not present\n");
}
break;

case 4://Modify
fp=fopen("a.dat","w+");
printf("Enter roll no. to modify record\n");
scanf("%d",&x);//Roll no to be searched is stored in x
while(!feof(fp))
{
fread(&s1,sizeof(s1),1,fp);
if(s1.roll==x)
{
printf("Enter data:\n");
printf("Enter name:\n");
scanf("%s",&s1.name);

printf("Enter roll no:\n");
scanf("%d",&s1.roll);

printf("Enter marks of 4 subjects:\n");
scanf("%d%d%d%d",&s1.m1,&s1.m2,&s1.m3,&s1.m4);

s1.total=s1.m1+s1.m2+s1.m3+s1.m4;
s1.perct=((s1.total)/4);
fseek(fp,-sizeof(s1),SEEK_CUR);
fwrite(&s1,sizeof(s1),1,fp);
}
}
break;

case 5://Delete
printf("Enter roll no to be deleted:\n");
scanf("%d",&x);
fp=fopen("a.dat","r");
fp1=fopen("b.dat","w");
while(!feof(fp))
{
fread(&s1,sizeof(s1),1,fp);
if(s1.roll!=x)
{
fwrite(&s1,sizeof(s1),1,fp1);
}
fclose(fp);
fclose(fp1);
//delete("a.dat");
rename("b.dat","a.dat");
}
break;

case 6:
printf("EXIT\n");
break;
}
}while(ch!=6);

return 0;
}
