%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token A B NL

%%
stmt:s NL {printf("Valid String\n");exit(0);}
s:A s B | ;
%%

int yyerror(char *msg){
   printf("Invalid string\n");
   exit(0);
}

main(){
  printf("Enter the string:\n");
  yyparse();
}
