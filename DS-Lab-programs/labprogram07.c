//Ordinary queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct queue
{
    int front,rear;
    int q[MAX];
};

void push(int,struct queue *);
void pop(struct queue *);
void display(struct queue *);

int main()
{
    int choice,item;
    struct queue s;
    s.rear=-1;
    s.front=0;
    for(;;)
    {
    printf("Enter your choice:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the item to be inserted:\n");
               scanf("%d",&item);
               push(item,&s);
               break;
        case 2:pop(&s);
               break;
        case 3:display(&s);
               break;
        case 4:exit(0);

    }
    }

    return 0;
}

void push(int item,struct queue *s)
{
    if(s->rear==MAX-1)
    {
     printf("Queue is full\n");
    }
    s->rear=s->rear+1;
    s->q[s->rear]=item;
}

void pop(struct queue *s)
{
    if(s->front > s->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    else{
    int item=s->q[s->front];
    printf("Item deleted is %d\n",item);
    (s->front)++;
    }
}

void display(struct queue *s)
{

    if((s->front) > (s->rear))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        printf("Elements present in queue are:\n");
    for(int i=s->front;i<=s->rear;i++)
    {
        printf("%d ",s->q[i]);
    }
    }
}
