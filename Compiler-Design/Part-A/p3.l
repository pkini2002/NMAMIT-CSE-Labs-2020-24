%{
    #include<stdio.h>
    #include<stdlib.h>
    
    int posint=0,negint=0,posfrac=0,negfrac=0;
%}

%%

[+]?[0-9]+ {posint++;}
[-][0-9]+ {negint++;} 
[+]?[0-9]*\.[0-9]+ {posfrac++;}
[-][0-9]*\.[0-9]+ {negfrac++;}
%%

int yywrap(){}

int main(int argc,char *argv[]){
    if(argc!=2){
        printf("Inalid usage\n");
        exit(0);
    }
    yyin=fopen(argv[1],"r");
    yylex();
    printf("Number of +ve integers = %d\nNumber of -ve integers is %d\nNumber of +ve fractions is %d\nNumber of -ve fractions is %d\n",posint,negint,posfrac,negfrac);
    return 0;
}
