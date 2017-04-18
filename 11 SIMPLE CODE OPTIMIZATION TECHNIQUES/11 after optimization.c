//AFTER OPTIMIZATION:

#include<stdio.h>
//#include<conio.h>
void main()
{
int x,y,i;
int a[5]={1,2,3,4,5};
printf("\nAfter Optimization");
x=add();
printf("\nThe value of X is %d",x);
y=m(a);
printf("\nThe value of Y is %d",y);
matrix();
//getch();
}
int add()
{
return 8;
}
int m(int a[5])
{
int max,i;
max=a[0];
i=5;
while(--i)
{
if(a[i]>max)
{
max=a[i];
}}
return max;
}
matrix()
{
int c=0;
int b[6][6],mi,mj,i,j;
printf("\nEnter the limit");
scanf("%d%d",&mi,&mj);
for(i=0;i<mi;i++)
{
for(j=0;j<mj;j++)
{ c++;
b[i][j]=1;   }
b[i][i]=0;
}
printf("Count=%d",c);
for(i=0;i<mi;i++)
{printf("\n");
for(j=0;j<mj;j++)
{
printf("\t%d",b[i][j]);
}}}
