//Conversion of infix to postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

char infix[100],postfix[100],s[100];
int top=-1;
void push(char);
char pop();

int stack_prec(char sym)
{
    switch(sym)
    {
    case '+':
    case '-':return 2;
    case '/':
    case '*':return 4;
    case '$':
    case '^':return 5;
    case '(':return 0;
    case '#':return -1;
    default:return 8;
    }
}

int input_prec(char sym)
{
    switch(sym)
    {
    case '+':
    case '-':return 1;
    case '/':
    case '*':return 3;
    case '$':
    case '^':return 6;
    case '(':return 9;
    case ')':return 0;
    default: return 7;
    }
}

void convert()
{
    char ch;
    int i,j=0;
    push('#');
    for(i=0;infix[i];i++)
    {
        ch=infix[i];
        while(stack_prec(s[top])>input_prec(ch))
            postfix[j++]=pop();
        if(stack_prec(s[top])!=input_prec(ch))
        push(ch);
        else
            pop();
    }
    while(s[top]!='#')
        postfix[j++]=pop();
    postfix[j]='\0';
}

int main()
{
    printf("Enter infix expression:\n");
    scanf("%s",infix);
    convert();
    printf("Postfix expression is %s\n",postfix);
    return 0;
}

void push(char ele)
{
    if(top==SIZE-1)
    {
        printf("Stack overflow\n");
        return;
    }
    s[++top]=ele;
}
char pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    return s[top--];
}
