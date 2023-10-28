%{
	#include<stdio.h>
	#include<stdlib.h>
	extern FILE *yyin;
%}

%token RETURN MAIN INT BEGIN END FOR RELOP EQ IF ENDIF ENDFOR DO TO SC NUMBER ID SP NL

%%
stmt:INT SP MAIN NL BEGIN NL s1 NL s2 NL s3 NL s4 NL s5 NL ENDIF NL ENDFOR NL s6 NL END {printf("Valid Code\n");exit(0);}

s1:INT SP ID '[' NUMBER ']' SC

s2:INT SP ID EQ ID '[' NUMBER ']' SC

s3:FOR SP ID EQ NUMBER SP TO SP ID '-' NUMBER SP DO

s4:IF SP ID '[' ID ']' RELOP ID

s5:ID EQ ID '[' ID ']' SC

s6: RETURN '(' ID ')'

%%

int yywrap(){}

int yyerror(char *msg){
   printf("Invalid Code\n");
   exit(0);
}

int main(int argc,char *argv[]){
   if(argc!=2){
      printf("Invalid Usage: ./a.out in.txt\n");
      exit(0);
   }
   yyin=fopen(argv[1],"r");
   yyparse();
   return 0;
}
