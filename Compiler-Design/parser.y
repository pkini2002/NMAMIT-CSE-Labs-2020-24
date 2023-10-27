%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%token INT MAIN FOR EQ GT LT IF SC NUMBER ID RETURN INC NL SP

%left '+' '-'
%left '*' '/'

%%

program: stmt_list

stmt_list:
    stmt
    | stmt_list stmt
    | stmt_list NL // To handle multiple statements separated by newlines

stmt: INT SP MAIN '(' ')' '{' s '}' NL
    | RETURN SP ID SC NL

s:
    | s INT SP ID '[' NUMBER ']' SC NL
    | s INT SP ID EQ ID '[' NUMBER ']' SC NL
    | s FOR '(' INT SP ID EQ NUMBER SC ID LT NUMBER SC ID INC ')' '{' s '}' NL
    | s IF '(' ID '[' ID ']' GT ID ')' '{' st '}' NL

st: RETURN ID SC NL
    | ID EQ ID '[' ID ']' SC NL

%%

int yyerror(char *msg){
    printf("Invalid...\nParse Error: %s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Invalid Usage: ./a.out in.txt\n");
        exit(1);
    }
    yyparse();
    return 0;
}
