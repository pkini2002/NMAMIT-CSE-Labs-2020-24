//Static implementation of stacks using arrays
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

int top;
int item;
int s[10];

void push(int item,int s[10])
{
    if(top==(STACK_SIZE-1))
    {
        printf("Stack is overflow\n");
        return;
    }
    top=top+1;
    s[top]=item;
}

int pop(int s[10])
{
    int item_deleted;
    if(top==-1)
        return 0;
    item_deleted=s[top--];
    return item_deleted;
}

void display(int s[10])
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    for(i=0;i<=top;i++)
    {
        printf("%d\n",s[i]);
    }
}

int main()
{
     int item,item_deleted;
     int choice;
     top=-1;
     while(1)
     {
         printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
         printf("Enter your choice:\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:printf("Enter the element to be inserted:\n");
                    scanf("%d",&item);
                    push(item,s);
                    break;
            case 2:item_deleted=pop(s);
                    if(item_deleted==0)
                        printf("Stack is empty\n");
                    else
                        printf("Item deleted:%d\n",item_deleted);
                    break;
            case 3:display(s);
                   break;
            default:exit(0);
         }
     }
    return 0;
}
