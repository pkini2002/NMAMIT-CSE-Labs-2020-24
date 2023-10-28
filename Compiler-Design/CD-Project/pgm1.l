%{
	#include "y.tab.h"
%}

%%
"return" {return RETURN;}
"main()" {return MAIN;}
"int" {return INT;}
"begin" {return BEGIN;}
"end" {return END;}
"for" {return FOR;}
">"|">="|"<"|"<=" {return RELOP;}
"=" {return EQ;}
"if" {return IF;}
"endif" {return ENDIF;}
"endfor" {return ENDFOR;}
"do" {return DO;}
"to" {return TO;}
";" {return SC;}
[0-9]+ {return NUMBER;}
[a-zA-Z][a-zA-Z0-9_]* {return ID;}
[ ]+ {return SP;}
\n {return NL;}
. {return yytext[0];}
%%
