%{
    #include<stdio.h>
    #include<stdlib.h>
    
    int com=0;
%}

%s COMMENT

%%
"//".* {com++;}
"/*" {BEGIN COMMENT;}
<COMMENT>"*/" {BEGIN 0; com++;}
<COMMENT>\n {com++;}
<COMMENT>. {;}
.|\n {fprintf(yyout,"%s",yytext);}
%%

int yywrap(){}

int main(int argc,char *argv[]){
   if(argc!=3){
      printf("Invalid Usage: ./a.out in.txt out.txt\n");
      exit(0);
   }
   yyin=fopen(argv[1],"r");
   yyout=fopen(argv[2],"w");
   yylex();
   printf("Number of comment lines is %d\n",com);
   return 0;
}
