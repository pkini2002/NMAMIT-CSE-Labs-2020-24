%{
#include "y.tab.h"
%}

%%
"return" {return RETURN;}
"int" {return INT;}
"main" {return MAIN;}
"for" {return FOR;}
"=" {return EQ;}
">" {return GT;}
"<" {return LT;}
"if" {return IF;}
";" {return SC;}
"++" {return INC;}
[0-9]+ {return NUMBER;}
[a-zA-Z][a-zA-Z0-9_]* {return ID;}
\n {return NL;}
[ \t]+ {return SP;}
. {return yytext[0];}
%%
