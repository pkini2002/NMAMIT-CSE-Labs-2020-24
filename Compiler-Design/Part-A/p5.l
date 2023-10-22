%{
    #include<stdio.h>
    #include<stdlib.h>
    int pc=0,sc=0;
%}

%%
"printf" {fprintf(yyout,"writef");pc++;}
"scanf" {fprintf(yyout,"readf");sc++;}
%%

int yywrap(){}

int main(int argc,char *argv[]){
   if(argc!=3){
       printf("Invalid\n");
       exit(0);
   }
   
   yyin=fopen(argv[1],"r");
   yyout=fopen(argv[2],"w");
   yylex();
   printf("Number of print statements is %d\n",pc);
   printf("Number of scan statements is %d\n",sc);
   
   fclose(yyout);
   return 0;  
}
