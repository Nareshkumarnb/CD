#include<stdio.h>
//#include<conio.h>
#include<string.h>
void main()
{
char exp1[20],dtype[20],t;
int i,len,j=0,k,flag=0;
//clrscr();
printf("enter the expression");
scanf("%s",exp1);
len=strlen(exp1);
printf("i-integer,f-float,d-double\n");
for(i=0;i<len;i++)
{
if(exp1[i]>='a' && exp1[i]<='z')
{
printf("Enter the type of %c",exp1[i]);
//dtype[j]=getchar();
scanf("%s",&dtype[j]);
j++;
}
}
//for(i=0;i<j;i++)
//printf("%c\t",dtype[i]);
t=dtype[0];
for(k=0;k<j;k++)
{
if(t!=dtype[k])
{
printf("\nType mismatch\n");
flag=1;
break;
}
}
if(flag==0)
printf("Type of the given expression is %c",t);
//getch();
}
