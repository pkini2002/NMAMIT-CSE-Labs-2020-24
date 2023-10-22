%{
    int is_simple=1;
%}

%%
[ \t\n]+[aA][nN][dD][ \t\n]+ {is_simple=0;}
[ \t\n]+[oO][rR][ \t\n]+ {is_simple=0;}
[ \t\n]+[bB][uU][tT][ \t\n]+ {is_simple=0;}
. {;}
%%

int yywrap(){}

int main(){
   printf("Enter the sentence. Press Ctrl+D at end\n");
   yylex();
   if(is_simple==1){
      printf("It is a simple statement");
   }
   else{
      printf("It is a compound statement");
   }
   return 0;
}
