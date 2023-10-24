%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token LETTER DIGIT UND NL

%%
stmt:s NL {printf("Valid Expression\n"); exit(0);}
s:LETTER alphanumeric;

alphanumeric:LETTER alphanumeric | DIGIT alphanumeric | UND alphanumeric | LETTER | DIGIT | UND;
%%

int yyerror(char *msg){
   printf("Invalid expression\n");
   exit(0);
}

main(){
   printf("Enter the identifier");
   yyparse();
}
