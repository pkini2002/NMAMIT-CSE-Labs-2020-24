%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token A B NL

%%
stmt:A A A A A A A A A A s B NL {printf("Valid String\n");exit(0);}
s:s A | ;
%%

int yyerror(char *msg){
   printf("Invalid string\n");
   exit(0);
}

main(){
   printf("Enter the string\n");
   yyparse();
}
