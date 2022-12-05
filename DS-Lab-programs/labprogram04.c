//Evaluation of postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define MAX 100

struct stack
{
   int top;
   double a[MAX];
};

void push(char,struct stack *);
double pop(struct stack *);
double compute(double,double,char);

int main()
{
    struct stack s;
    s.top=-1;
    int i;
    double op1,op2,res;
    char postfix[100],symb;
    printf("Enter the postfix expression:\n");
    gets(postfix);
    for(i=0;postfix[i]!='\0';i++)
    {
        symb=postfix[i];
        if(isdigit(symb))
          push(symb,&s);
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            res=compute(op1,op2,symb);
            s.a[++s.top]=res;
        }
    }
    res=pop(&s);
    printf("Result after evaluation= %f\n",res);
    return 0;
}

void push(char symb,struct stack *s)
{
    if(s->top==MAX-1)
    {
        printf("Stack overflow\n");
    }
    else
        s->a[++(s->top)]=symb-'0';
}

double pop(struct stack *s)
{
        if(s->top==-1)
            printf("Stack is empty\n");
        else
            return (s->a[(s->top)--]);
}

double compute(double op1,double op2,char symb)
{
    switch(symb)
    {
        case '+':return (op1+op2);
        case '-':return (op1-op2);
        case '*':return (op1*op2);
        case '/':return (op1/op2);
        case '$':
        case '^':return (pow(op1,op2));
    }

}
