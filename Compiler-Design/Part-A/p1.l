%{
    int vow_count=0;
    int const_count=0;
%}

%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
[\n] {return 0;}
%%

int yywrap(){}

int main(){
   printf("Enter the string with vowels and consonants: \n");
   yylex();
   printf("The number of vowels is: %d\n",vow_count);
   printf("The number of consonants is %d\n",const_count);
   return 0;
}
