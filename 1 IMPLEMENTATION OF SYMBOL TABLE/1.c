#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct table
{
char var[10];
int value;
};
struct table tb1[20];
int i,j,n;
void create();
void modify();
int search(char variable[],int n);
void insert();
void display();
void main()
{
int ch,result=0;
char v[10];
do
{
//clrscr();
printf("\n1. CREATE\n2. INSERT\n3. MODIFY\n4. SEARCH\n5. DISPLAY\n6.EXIT ");
printf("\n Enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:            create();break;
case 2:            insert();break;
case 3:            modify();break;
case 4:               printf("\n Enter the variable to be searched for : ");
                       scanf("%s",v);
                       result=search(v,n);
                       if(result==0)
printf("\n The variable doest not belong to the table.");
else
printf("\nVariable=%s\tValue=%d\tLocation=%d",tb1[result].var,tb1[result].value,result);
//getch();
break;
case 5:            display();break;
case 6:            exit(1);
}
}
while(ch!=6);
//getch();
}
void create()
{
printf("\nEnter the number of entries: ");
scanf("%d",&n);
printf("\nEnter the variable and the value:\n");
for(i=1;i<=n;i++)
{
scanf("%s%d",tb1[i].var,&tb1[i].value);
check:
if(tb1[i].var[0]>='0'&&tb1[i].var[0]<='9')
{
printf("\nThe variable should not start with an alphabet.\nEnter the Correct  variable name :");
scanf("%s%d",tb1[i].var,&tb1[i].value);
goto check;
}
for(j=1;j<i;j++)
{
if(strcmp(tb1[i].var,tb1[j].var)==0)
{
printf("\nThe variable already exists.Enter another variable :\n");
scanf("%s%d",tb1[i].var,&tb1[i].value);
goto check;
}
}
}
printf("\n The table after creation is : \n");
display();
}
void insert()
{
if(i>=20)
printf("\n Cannot insert. Table is full.\n");
else
{
n++;
printf("\n Enter the variable and the value : ");
scanf("%s%d",tb1[n].var,&tb1[n].value);
check:
if(tb1[i].var[0]>='0'&&tb1[i].var[0]<='9')
{
printf("\nThe variable should not start with an alphabet.\nEnter the Correct variable name :");
scanf("%s%d",tb1[i].var,&tb1[i].value);
 goto check;
}
for(j=1;j<n;j++)
{
if(strcmp(tb1[j].var,tb1[i].var)==0)
{
printf("\nThe variable already exists.Enter another variable :\n");
scanf("%s%d",tb1[i].var,&tb1[i].value);
goto check;
}
}
printf("\n The table after creation is : \n");
display();
}
}
void modify()
{
char variable[10];
int result=0;
printf("\n Enter the variable to be searched for : ");
scanf("%s",variable);
result=search(variable,n);
if(result==0)
 printf("\n The variable doest not belong to the table.");
else
{
printf("\n The current value of the variable %s is %d.\n Enter the new variableand its value",tb1[result].var,tb1[result].value);
scanf("%s%d",tb1[result].var,&tb1[result].value);
check:
if(tb1[i].var[0]>='0'&&tb1[i].var[0]<='9')
{
printf("\nThe variable should not start with an alphabet.\nEnter the Correct variable name :");
scanf("%s%d",tb1[i].var,&tb1[i].value);
goto check;
}
}
printf("\n The table after creation is : \n");
display();
}
int search(char variable[],int n)
{
int flag;
for(i=1;i<=n;i++)
if(strcmp(tb1[i].var,variable)==0)
{
flag=1;
break;
}
if(flag==1)
return i;
else
return 0;
}
void display()
{
printf("\nVARIABLE\tVALUE\n");
for(i=1;i<=n;i++)
printf("\n%s\t\t%d",tb1[i].var,tb1[i].value);
//getch();
}
