%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token INT CHAR FLOAT SP SC CM ID NL

%%
s:type SP list SC NL {printf("Valid Declaration\n");exit(0);}
type: INT | CHAR | FLOAT;
list: ID | list CM ID | list SP CM SP ID;
%%

int yyerror(char *msg){
   printf("Invalid declaration\n");
   exit(0);
}

main(){
   printf("Enter the declaration:\n");
   yyparse();
}
