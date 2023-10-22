%{
    #include<stdio.h>
    #include<stdlib.h>
    int s=0,w=0,l=0,c=0;
%}

WORD [^ \t\n , \.:]+
EOL [\n]
BLANK [ ]

%%
{WORD} {w++; c=c+yyleng;}
{EOL} {l++;}
{BLANK} {s++;}
%%

int yywrap(){}

int main(int argc,char *argv[]){
    if(argc!=2){
       printf("The program needs 2 arguments\n");
       exit(0);
    }
    
    yyin=fopen(argv[1],"r");
    yylex();
    printf("Number of characters is %d\nNumber of spaces is %d\nNumber of words is %d\nNumber of lines is %d\n",c,s,w,l);
    return 0;
}
