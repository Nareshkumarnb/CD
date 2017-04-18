%{#include<stdio.h>
int flag=0;
%}
%token NUMBER ID
%%
expr: expr '+' expr |
expr '-' expr|
expr '*' expr|expr '/' expr|
'-'NUMBER|'-'ID|'('expr')'|NUMBER|ID;
%%
main()
{
printf("Enter the expression\n");
yyparse();
if(flag==0)
printf("\nExpression is valid.....\n");
return 0;
}
int yyerror(char *s)
{
printf("\nExpression is invalid");
flag=1;
return 0;
}
