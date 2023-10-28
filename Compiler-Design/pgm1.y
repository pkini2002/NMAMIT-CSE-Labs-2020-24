%{
    #include <stdio.h>
    #include <stdlib.h>
    #include<string.h>
%}

%token INT MAIN FOR EQ GT LT IF SC NUMBER ID RETURN INC NL SP

%left '+' '-'
%left '*' '/'

%%

program: stmt_list NL {printf("Parsing successful\n");exit(0);}

stmt_list:
    stmt
    | stmt_list stmt
    | stmt_list NL // To handle multiple statements separated by newlines

stmt: INT SP MAIN '(' ')' '{' s '}' NL {printf("Main function parsed correctly\n");}
    | RETURN SP ID SC NL {printf("Return statement parsed correctly\n");}

s:
    INT SP ID '[' NUMBER ']' SC NL s {printf("int L[10]; parsed correctly\n");}
    | INT SP ID EQ ID '[' NUMBER ']' SC NL s {printf("int maxval=L[0]; parsed correctly\n");}
    | FOR '(' INT SP ID EQ NUMBER SC ID LT NUMBER SC ID INC ')' '{' s '}' NL s {printf("For condition parsed correctly\n");}
    | IF '(' ID '[' ID ']' GT ID ')' '{' st '}' NL s {printf("If construct parsed correctly\n");}
    | ;

st: RETURN SP ID SC NL
    | ID EQ ID '[' ID ']' SC NL {printf("maxval=L[i]; parsed correctly\n");}

%%

int yyerror(char *msg){
    printf("Invalid...\nParse Error: %s\n", msg);
    exit(0);
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Invalid Usage: ./a.out in.txt\n");
        exit(1);
    }
    yyparse();
    return 0;
}
