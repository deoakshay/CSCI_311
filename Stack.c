#include<stdio.h>
#include<string.h>

int a,b,ch,n,k,t,top,x,p,i,l,len,j,stk[50];
char op,str[50],st[50],s[50],A,B;

void push(char st[50],int *,char);
char pop(char st[50],int *);
int prior(char);
int pri(char c);
void in_post(char []);
void in_pre(char []);
void po_in();
void pre_in();
int post_eval(char []);
int pre_eval(char []);
int evl(int,int,char);
void push1(int b[50],int,int *);  //for evaluation
int pop1(int b[50],int *);	  //for evaluation
void print(char []);


int main()
{
 char sg[50];
 do
 {
  printf("\n MENU:\n\t1. INFIX TO POSTFIX\n\t2. INFIX TO PREFIX\n\t");
  printf("3. POSTFIX TO INFIX\n\t4. PREFIX TO INFIX\n\t");
  printf("5. POSTFIX EVALUATION\n\t6. PREFIX EVALUATION\n");
  printf("\n\nENTER YOUR CHOICE:\t");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: //INFIX TO POSTFIX
	   in_post(sg);
	   print(sg);
	   break;

   case 2: //INFIX TO PREFIX
           in_pre(sg);
	   print(sg);
           break;

   case 3: //POSTFIX TO INFIX
	   po_in();
	   break;

   case 4: //PREFIX TO INFIX
	   pre_in();
	   break;

   case 5: //POSTFIX EVALUATION
	   in_post(sg);
	   print(sg);
	   x=post_eval(sg);
	   printf("\nRESULT OF EXPRESSION IS :\t%d",x);
	   break;

   case 6: //PreFIX EVALUATION
           in_pre(sg);
           print(sg);
           x=pre_eval(sg);
           printf("\nRESULT OF EXPRESSION IS :\t%d",x);
           break;

  }
  printf("\n\nDO YOU WANT TO CONTINUE?:\n");
  scanf("%s",&op);
 }while(op=='y');
}

int pri(char c)
{
	if(c=='+'||c=='-')
	  return (1);
	if(c=='*'||c=='/')
  	  return (2);
	if(c=='^')
	  return (3);
	if(c=='(')
	  return (4);
	if(c==')')
	  return (5);
	else
 	  return (6);
}


void in_post(char a[50])
{
 	printf("\n\nENTER THE INFIX EXPRESSION:\n");
        scanf("%s",&str);
        printf("\n\nTHE POSTFIX EXPRESSION IS..\n");
	top=-1;k=0;
	for(i=0;str[i]!='\0';i++)
	{
	  p=pri(str[i]);
	  if(p==6)
	  {
	    //printf("%c",str[i]);
	    a[k++]=str[i];
	  }
	  else
	  {
	    if(top==-1)
	    {
		push(st,&top,str[i]);
 	    }
	    else
	    {
		if(p==4)
	        {
		   push(st,&top,str[i]);
	        }
	        else
	        {
		   if(p==5)
	           {
			while(st[top]!='('&&top!=-1)
			{
			    x=pop(st,&top);
	      		    //printf("%c",x);
			    a[k++]=x;

	     		}
	     		top--;
	    	   }
 	    	   else
	    	   {
	     		if(p<pri(st[top])&&st[top]!='(')
	     		{
	       		   while(p<pri(st[top])&&st[top]!=-1)
	      		   {
		 		x=pop(st,&top);
              			//printf("%c",x);
				a[k]=x;
				k++;
	      		   }
	     		}
	     		else
	     		{
			   push(st,&top,str[i]);
	     		}
	    	   }
	        }
	    }
	  }
	}
	for(j=top;j!=-1;j--)
	{
	  x=pop(st,&top);
	  //printf("%c",st[j]);
	  a[k++]=x;
	}
	a[k]='\0';
}

void in_pre(char a[50])
{
	printf("\n\nENTER THE INFIX EXPRESSION:\n");
        scanf("%s",&str);
        printf("\n\nTHE PREFIX EXPRESSION IS..\n");
	top=-1; l=0;
	len=strlen(str);
	len=len-1;
	for(i=0;str[i]!='\0';i++)
	{
	 if(str[i]=='('||str[i]==')')
	 {
	 }
	 else
	 {
	  l++;
	 }
	}
	s[l]='\0';
	l--;
	for(i=len;i>=0;i--)
	{
	 p=pri(str[i]);
	 if(p==6)
	 {
	  s[l]=str[i]; l--;
	 }
	 else
	 {
	  if(top==-1)
	  {
	    push(st,&top,str[i]);

	  }
	  else
	  {
	   if(p==5)
	   {
	     push(st,&top,str[i]);
	   }
	   else
	   {
	    if(p==4)
	    {
	     while(st[top]!=')'&&top!=-1)
	     {
		x=pop(st,&top);
	      s[l]=x;
	      l--;
	     }
	     top--;
	    }
	    else
	    {
	     if(p<pri(st[top])&&st[top]!=')')
	     {
	      while(p<pri(st[top])&&top!=-1)
	      {
		x=pop(st,&top);
	       s[l]=x;
	       l--;
	      }
	     }
	     else
	     {
		 push(st,&top,str[i]);

	     }
	    }
	   }
	  }
	 }
	}
	j=l;
	if(j>=0)
	{
	 for(t=top;t!=-1;t--)
	  s[j]=st[top];
	}
	strcpy(a,s);
}

void po_in()
{
	printf("\n\nENTER THE EXPRESSION:\n");
        scanf("%s",&str);
        printf("\n\nTHE INFIX EXPRESSION IS..\n");
	k=0; top=-1;
	for(i=0;str[i]!='\0';i++)
	{
	 p=pri(str[i]);
	 if(p==6)
	 {
	    push(st,&top,str[i]);
	 }
	 else
	 {
	  if(top!=-1)
	  {
	   B=pop(st,&top);

	   if(top==-1)
	   {
	    s[k]=str[i]; k++;
	    s[k]=B; k++;
	   }
	   else
	   {
	    A=pop(st,&top);
	    s[k]=A; k++;
	    s[k]=str[i]; k++;
	    s[k]=B; k++;
	   }
	  }
	  else
	  {
	   for(j=k-1;j>=0;j--)
	   {
 	    if(pri(s[j])==pri(s[j-1]))
	     break;
	   }
	   for(l=k;l>=j;l--)
	    s[l]=s[l-1];
	   s[j]=str[i]; k++;
	  }
	 }
	}
	s[k]='\0';
	for(k=0;s[k]!='\0';k++)
	printf("%c",s[k]);
}


void push(char st[50],int *top,char x)
{
        (*top)++;
        st[*top]=x;

}

char pop(char st[50],int *top)
{
        char x;
        x=st[*top];
        (*top)--;
        return(x);
}

void pre_in()
{
        printf("\n\nENTER THE EXPRESSION:\n");
        scanf("%s",&str);
        printf("\n\nTHE INFIX EXPRESSION IS..\n");
        top=-1; len=strlen(str);
        len=len-1;
        l=0;
        for(i=len;i>=0;i--)
        {
         p=pri(str[i]);
         if(p==6)
         {
	    push(st,&top,str[i]);
         }
         else
         {
          if(top!=-1)
          {
           A=pop(st,&top);


	   if(top==-1)
           {
            s[l]=str[i]; l++;
            s[l]=A; l++;
           }
           else
           {
            B=pop(st,&top);
            s[l]=A; l++;
            s[l]=str[i]; l++;
            s[l]=B; l++;
           }
          }
          else
          {
           k=l-1;
           for(j=k;j>=0;j--)
           {
            if(pri(s[j])==pri(str[j-1]))
             break;
           }

	 }
         for(i=l;i>j;i--)
         {
            s[l]=s[l-1];
         }
           s[j]=str[i]; l++;
          // s[l]='\0';

          }
        }

        s[l]='\0';
        for(k=0;s[k]!='\0';k++)
        printf("%c",s[k]);

}

int post_eval(char s1[50])
{
   top=-1;
   int c,r,v,x,op1,op2,l;
   l=strlen(s1);
   for(i=0;i<l;i++)
   {
       p=pri(s1[i]);

        if(p==6)
        {
            printf("\n ENTER THE VALUE OF %c:\t",s1[i]);
            scanf("%d",&x);
            push1(stk,x,&top);
        }

       else
       {
            op2=pop1(stk,&top);
            op1=pop1(stk,&top);
	    r=evl(op1,op2,s1[i]);

            push1(stk,r,&top);
       }
   }

   v=pop1(stk,&top);
   return v;

}

int pop1(int b[50],int *top)
{
   int x;
   x=b[*top];
   (*top)--;
   return x;
}

void push1(int b[50],int x,int *top)
{
    (*top)++;
    b[*top]=x;
}

int evl(int o1,int o2,char c)
{
     int r,i;
     switch(c)
     {
          case '+': //ADDITION
                    r=o1+o2;
                    break;

          case '-': //SUBSTRACTION
                    r=o1-o2;
                    break;

          case '*': //MULTIPLICATION
                    r=o1*o2;
                    break;

          case '/': //DIVISION
                    r=o1/o2;
                    break;

          case '%': //MODULUS
                    r=o1%o2;
                    break;

          case '^': //RAISED TO
                    r=1;
                    for(i=1;i<=o2;i++)
                        r=r*o1;
                    break;

          default:  printf("\n\n wrong choice\n");

     }

     return r;
}

void print(char a[50])
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		printf("  %c",a[i]);
	}
}

int pre_eval(char s1[50])
{
   top=-1;
   int c,r,v,x,op1,op2,l;
   l=strlen(s1);
   for(i=l-1;i>=0;i--)
   {
       p=pri(s1[i]);

        if(p==6)
        {
            printf("\n ENTER THE VALUE OF %c:\t",s1[i]);
            scanf("%d",&x);
            push1(stk,x,&top);
        }

       else
       {
            op1=pop1(stk,&top);
            op2=pop1(stk,&top);
            r=evl(op1,op2,s1[i]);

            push1(stk,r,&top);
       }
   }

   v=pop1(stk,&top);
   return v;

}



/* OUTPUTS:
 MENU:
        1. INFIX TO POSTFIX
        2. INFIX TO PREFIX
        3. POSTFIX TO INFIX
        4. PREFIX TO INFIX
        5. POSTFIX EVALUATION
        6. PREFIX EVALUATION


ENTER YOUR CHOICE:      1


ENTER THE INFIX EXPRESSION:
((a+b)*(c/d))-f


THE POSTFIX EXPRESSION IS..
  a  b  +  c  d  /  *  f  -

DO YOU WANT TO CONTINUE?:
y

 MENU:
        1. INFIX TO POSTFIX
        2. INFIX TO PREFIX
        3. POSTFIX TO INFIX
        4. PREFIX TO INFIX
        5. POSTFIX EVALUATION
        6. PREFIX EVALUATION


ENTER YOUR CHOICE:      2


ENTER THE INFIX EXPRESSION:
((a+b)*(c/d))-f


THE PREFIX EXPRESSION IS..
  -  *  +  a  b  /  c  d  f

DO YOU WANT TO CONTINUE?:
y

 MENU:
        1. INFIX TO POSTFIX
        2. INFIX TO PREFIX
        3. POSTFIX TO INFIX
        4. PREFIX TO INFIX
        5. POSTFIX EVALUATION
        6. PREFIX EVALUATION


ENTER YOUR CHOICE:      3


ENTER THE EXPRESSION:
ab+cd/*f-


THE INFIX EXPRESSION IS..
a+b*c/d-f

 MENU:
        1. INFIX TO POSTFIX
        2. INFIX TO PREFIX
        3. POSTFIX TO INFIX
        4. PREFIX TO INFIX
        5. POSTFIX EVALUATION
        6. PREFIX EVALUATION


ENTER YOUR CHOICE:      5


ENTER THE INFIX EXPRESSION:
((a+b)*(c/d))-f


THE POSTFIX EXPRESSION IS..
  a  b  +  c  d  /  *  f  -
 ENTER THE VALUE OF a:  1

 ENTER THE VALUE OF b:  2

 ENTER THE VALUE OF c:  6

 ENTER THE VALUE OF d:  3

 ENTER THE VALUE OF f:  4

RESULT OF EXPRESSION IS :       2

DO YOU WANT TO CONTINUE?:
y

 MENU:
        1. INFIX TO POSTFIX
        2. INFIX TO PREFIX
        3. POSTFIX TO INFIX
        4. PREFIX TO INFIX
        5. POSTFIX EVALUATION
        6. PREFIX EVALUATION


ENTER YOUR CHOICE:      6


ENTER THE INFIX EXPRESSION:
((a+b)*(c/d))-f


THE PREFIX EXPRESSION IS..
  -  *  +  a  b  /  c  d  f
 ENTER THE VALUE OF f:  1

 ENTER THE VALUE OF d:  2

 ENTER THE VALUE OF c:  4

 ENTER THE VALUE OF b:  5

 ENTER THE VALUE OF a:  6

RESULT OF EXPRESSION IS :       21

*/
