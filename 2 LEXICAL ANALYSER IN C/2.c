#include<stdio.h>
//#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 128
#define NONE -1
#define EOS ‘\0’
#define NUM 256
#define KEYWORD 257
#define PAREN 258
#define ID 259
#define ASSIGN 260
#define REL_OP 261
#define DONE 262
#define MAX 999
char lexemes[MAX];
char buffer[SIZE];
int lastchar = -1;
int lastentry = 0;
int tokenval=NONE;
intlineno=1;
struct entry
{
char *lexptr;
int token;
}symtable[100];
struct entry keywords[]=  
{“if”,KEYWORD,”else”,KEYWORD,”for”,KEYWORD,“int”,KEYWORD,”float”,KEYWORD,”double”,KEYWORD,”char”,KEYWORD,“struct”,KEYWORD,”return”,KEYWORD,0,0};
void Error_Message(char *m)
{fprint(stderr,”line %d: %s”,lineno,m);
exit(1);
}
int look_up(char s[])
{
int k;
for(k=lastentry;k>0;k--)
if(strcmp(symtable[k].lexptr,s)==0)
return k;
return 0;
}
int insert(chars[],int tok)
{int len;
len=strlen(s);
if(lastentry+1>=MAX)
Error_Message(“Symbol Table is Full”);
if(lastchar+len+1>=MAX)
Error_Message(“Lexemes Array is Full”);
lastentry++;
symtable[lastentry].token=tok;
symtable[lastentry].lexptr=&lexemes[lastcher+1];
lastchar = lastchar + len + 1;
strcpy(smtable[lastentry].lexptr,s);
return lastentry;
}
void Initialize()
{struct entry *ptr;
for(ptr=keywords;ptr->token;ptr++)
insert(ptr->lexptr,ptr->token);
}
int lexer()
{
int t;
int val,i=0;
while(1)
{
t=getchar();
if(t == ’’ || t==’\t’);
else if(t==’\n’)
lineno++;
else if(t == ’(‘ || t == ‘)’)
return PAREN;
else if(t==‘<’ ||t==‘>’ ||t==‘<=’ ||t==‘>=’ ||t == ‘!=’)
return REL_OP;
else if(t == ’=’)
return ASSIGN;
else if(isdigit(t))
{
ungetc(t,stdin);
scanf(“%d”,&tokenval);
return NUM;
}
else if(isalpha(t))
{
while(isalnum(t))
{buffer[i]=t;
t=getchar();
i++;
if(i>=SIZE)
Error_Message(“compiler error”);
}
buffer[i]=EOS;
if(t!=EOF)
ungetc(t,stdin);
val=look_up(buffer);
if(val==0)
val=insert(buffer,ID);
tokenval=val;
return symtable[val].token;
}
else if(t==EOF)
return DONE;
else
{tokenval=NONE;
return t;
}
}
}
void main()
{
int lookahead;
char ans;
//clrscr();
printf(“\n]t]t Program for Lexical Analysis \n”);
Initialize();
printf(“\n Enter the expression and put ; at the end”);
printf(“\n Press Ctrl + Z to terminate... \n”);
lookahead=lexer();
while(lookahead!=DONE)
{
if(lookahead==NUM)
printf(“\n Number: %d”,tokenval);
if(lookahead==’+’|| lookahead==’-’|| lookahead==’*’||lookahead==’/’)
printf(“\n Operator”);
if(lookahead==PAREN)
printf(“\n Parentesis”);
if(lookahead==ID)
printf(“\n Identifier: %s“,symtable[tokenval].lexptr);
if(lookahead==KEYWORD)
printf(“\n Keyword);
if(lookahead==ASSIGN)
printf(“\n Assignment Operator”);
if(lookahead==REL_OP)
printf(“\n Relataional Operator”);
lookahead=lexer();
}
}
