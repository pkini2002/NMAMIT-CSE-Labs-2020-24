%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token NUMBER ID NL
%left '+' '-'
%left '*' '/'

%%
stmt:exp NL {printf("Valid expression\n");exit(0);}
exp:exp '+' exp | exp '-' exp | exp '*' exp | exp '/' exp | '('exp')' | ID | NUMBER;
%%

int yyerror(char *msg){
   printf("Invalid expression\n");
   return 0;
}

int main(){
   printf("Enter the expression\n");
   yyparse();
   return 0;
}
