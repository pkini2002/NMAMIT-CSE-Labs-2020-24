//C program to find whether the entered string is palindrome or not
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int top=-1,front=0;
int stack[MAX];

void push(char);
void pop();

int main()
{
    int i,choice;
    char s[MAX],b;
    while(1)
    {
        printf("1.Enter the string\n2.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the string:\n");
                   scanf("%s",s);
                   for(i=0;s[i]!='\0';i++)
                   {
                       b=s[i];
                       push(b);
                   }
                   for(i=0;i<(strlen(s)/2);i++)
                   {
                       if(stack[top]==stack[front])
                       {
                           pop();
                           front++;
                       }
                       else
                       {
                           printf("%s is not palindrome\n",s);
                           break;
                       }
                   }
                   if((strlen(s)/2)==front)
                    printf("%s is a palindrome\n",s);
                   front=0;top=-1;
                   break;
            case 2:exit(0);
            default: printf("Enter the correct choice!!\n");
        }
    }
    return 0;
}

void push(char a)
{
    top++;
    stack[top]=a;
}

void pop()
{
    top--;
}
