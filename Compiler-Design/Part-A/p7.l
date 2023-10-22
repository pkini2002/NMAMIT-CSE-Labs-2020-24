%{
    #include<stdio.h>
    #include<stdlib.h>
    int id=0;
%}

%%
[_a-zA-Z][a-zA-Z0-9_]* {id++;ECHO;printf("\n");}
.+ {;}
[\n] {;}

%%

int yywrap(){}

int main(int argc,char *argv[]){
   if(argc!=2){
       printf("Invalid arguments\n");
       exit(0);
   }
   yyin=fopen(argv[1],"r");
   yylex();
   printf("Number of identifiers is %d\n",id);
   return 0;
}
