#include<stdio.h>
//#include<conio.h>
int priority(char x);
struct table
{
char op,op1,op2,op3;
}st[10];
void main()
{
char infix[10],postfix[10],stack[10];
int in,i,j=-1,k=0,sp=0,t=48;
//clrscr();
stack[0]=' ';
printf("enter the expression");
scanf("%s",&infix);
in=strlen(infix);
for(i=0;i<in;i++)
{
if(isalpha(infix[i]))
postfix[++j]=infix[i];
else
{
if(priority(infix[i])>priority(stack[sp]))
stack[++sp]=infix[i];
else
{
while(priority(infix[i])<=priority(stack[sp]))
postfix[++j]=stack[sp--];
stack[++sp]=infix[i];
}
}
}
while(sp>-1)
postfix[++j]=stack[sp--];
j=-1;
printf("postfix from %s",postfix);
for(i=0;i<in;i++)
{
if(isalpha(postfix[i]))
stack[++sp]=postfix[i];
else
{
j++;
st[j].op=postfix[i];
st[j].op1=stack[sp--];
st[j].op2=stack[sp--];
st[j].op3=t;
stack[++sp]=t;
t++;
}
}
for(k=0;k<=j;k++)
printf("\n%c%c%c%c",st[k].op3,st[k].op2,st[k].op1,st[k].op);
//getch();
}
int priority(char x)
{
if(x==' ')
return 0;
if(x=='=')
return 1;
if(x=='+'||x=='-')
return 2 ;
if(x=='*'||x=='/')
return 3;
return 4;
}
