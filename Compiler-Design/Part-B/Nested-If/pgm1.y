%{
	#include<stdio.h>
	#include<stdlib.h>
	int count=0;
%}

%token IF RELOP S ID NUMBER NL

%%
stmt:if_stmt NL {printf("Number of nested if statements is %d\n",count);exit(0);}

if_stmt:IF '(' cond ')' '{' if_stmt '}' {count++;} | S;
cond:x RELOP x;
x:ID | NUMBER;
%%

int yyerror(char *msg){
   printf("Invalid\n");
   exit(0);
}

main(){
	printf("Enter the statement:\n");
	yyparse();
}
