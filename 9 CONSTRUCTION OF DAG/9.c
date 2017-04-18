#include<stdio.h>
//#include<conio.h>
#include<string.h>
int exist(char);
int find(char);
int nl=0,ni=0,entry=0;
struct leaf
{
int ind;
char* label;
int ref;
char symbol;
}Leaf[10];
struct internal
{
int ind;
char c;
int left,right;
}Internal[10];
void main()
{
char exp[50];
int exp_len,i,opcount=0;
//clrscr();
printf("Enter simple assignment statement\n");
scanf("%s",exp);
exp_len=strlen(exp);
for(i=0;i<exp_len;i++)
{
if(exp[i]>='a' && exp[i]<='z')
{
if(!exist(exp[i]))
{
Leaf[nl].ind=++entry;
Leaf[nl].label="id";
Leaf[nl].ref=++opcount;
Leaf[nl].symbol=exp[i];
nl++;
}
}
else if(!(exp[i]>='a' && exp[i]<='z') && !(exp[i]=='+' || exp[i]=='*' || exp[i]=='='))
{
if(!exist(exp[i]))
{
Leaf[nl].ind=++entry;
Leaf[nl].label="num";
Leaf[nl].ref=0;
Leaf[nl].symbol=exp[i];
nl++;
}
}
}
for(i=0;i<exp_len;i++)
{
if(exp[i]=='+' || exp[i]=='*')
{
if(exp[i-2]=='+' || exp[i-2]=='*')
{
Internal[ni].ind=++entry;
Internal[ni].c=exp[i];
Internal[ni].left=find(exp[i-2]);
Internal[ni].right=find(exp[i+1]);
ni++;
}
else
{
Internal[ni].ind=++entry;
Internal[ni].c=exp[i];
Internal[ni].left=find(exp[i-1]);
Internal[ni].right=find(exp[i+1]);
ni++;
}
}
}
for(i=0;i<exp_len;i++)
{
if(exp[i]=='=')
{
Internal[ni].ind=++entry;
Internal[ni].c=exp[i];
Internal[ni].left=find(exp[i-1]);
Internal[ni].right=Internal[ni-1].ind;
ni++;
}
}
printf("Number of leaves is %d\n",nl);
printf("Number of internal nodes is %d\n",ni);
printf("List of Leaf Nodes\n");
printf("Entry\tLabel\tRef\tSymbol\n");
printf("------------------------------------------------\n");
for(i=0;i<nl;i++)
{
printf("%d\t%s\t%d\t%c\n",Leaf[i].ind,Leaf[i].label,Leaf[i].ref,Leaf[i].symbol);
}
printf("\n\nList of Internal Nodes\n");
printf("Entry\tOperator\tLeft\tRight\n");
printf("-----------------------------------------------\n");
for(i=0;i<ni;i++)
printf("%d\t%c\t\t%d\t\t%d\n",Internal[i].ind,Internal[i].c,Internal[i].left,Internal[i].right);
//getch();
}

int exist(char f)
{
int i,fl=0;
for(i=0;i<nl;i++)
if(Leaf[i].symbol==f)
fl=1;
if(fl!=0)
return 1;
else
return 0;
}
int find(char f)
{
int i,indx=0;
if(f=='+' || f=='*')
{
for(i=0;i<ni;i++)
if(Internal[i].c==f)
{
indx=Internal[i].ind;
break;
}
return indx;
}
else
{
for(i=0;i<nl;i++)
if(Leaf[i].symbol==f)
{
indx=Leaf[i].ind;
break;
}
return indx;
}
}
