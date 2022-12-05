//Static implementation of stacks using structures
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

struct stack
{
    int top;
    int items[STACK_SIZE];
};


void push(int,struct stack *);
int pop(struct stack *);
void display(struct stack *);


int main()
{
     struct stack s;
     s.top=-1;
     int item,choice,i;
     int top,p;
     while(1)
     {
         printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
         printf("Enter your choice:\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:printf("Enter the element to be inserted:\n");
                    scanf("%d",&item);
                    push(item,&s);
                    break;
            case 2:p=pop(&s);
                    printf("Item deleted:%d\n",p);
                    break;
            case 3:display(&s);
                   break;
            default:exit(0);
         }
     }
    return 0;
}

void push(int item,struct stack *s)
{
    if(s->top==STACK_SIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        s->top++;
        s->items[s->top]=item;
    }
}

int pop(struct stack *s)
{
    int delitem;
    if(s->top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        delitem=s->items[s->top];
        s->top--;
    }
    return delitem;
}

void display(struct stack *s)
{
    int i;
    if(s->top==-1)
        printf("Stack is empty\n");
    else
    {
        printf("Elements in stack are:\n");
        i=s->top;
        while(i>-1)
        {
            printf("%d\t",s->items[i]);
            i--;
        }
    }
}
