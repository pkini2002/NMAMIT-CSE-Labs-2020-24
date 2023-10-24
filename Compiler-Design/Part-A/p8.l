%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	
	int valid=1,top=-1,noopnd=0,nooprt=0,j=0,l=0;
	char opnd[10][10],oprt[10][10],a[100];
%}

%%
"(" {top++;a[top]='(';}
"{" {top++;a[top]='{';}
"[" {top++;a[top]='[';}

")" {if(a[top]!='('){
	valid=0;
    }
    else
    	top--;
    }
    
"}" {if(a[top]!='{'){
	valid=0;
    }
    else
    	top--;
    }
    
"]" {if(a[top]!='['){
	valid=0;
    }
    else
    	top--;
    }

"+"|"-"|"*"|"/" {nooprt++;strcpy(oprt[l],yytext);l++;}
[0-9]+|[a-zA-Z][a-zA-Z0-9]* {noopnd++;strcpy(opnd[j],yytext);j++;}
. {;}
[\n] {return 0;}
%%

int yywrap(){}

int main(){
    printf("Enter the expression\n");
    yylex();
    
    int k;
    
    if((valid==1) && (top==-1) && (noopnd-nooprt)==1){
        printf("The expression you entered is valid\n");
        
        printf("The operators are:\n");
        for(k=0;k<l;k++){
            printf("%s\n",oprt[k]);
        }
        
        printf("The operands are:\n");
        for(k=0;k<j;k++){
           printf("%s\n",opnd[k]);
        }
    }
    else{
        printf("The expression is invalid\n");
    }
    return 0;
}
