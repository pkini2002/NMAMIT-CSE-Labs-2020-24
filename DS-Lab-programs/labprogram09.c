//Priority queue
#include <stdio.h>
#include <stdlib.h>

#define size 3

struct queue
{
    int items[size];
    int rear,front;
};

void insert(struct queue *,int);
void delet(struct queue *);
void display(struct queue *);

int main()
{
    struct queue q;
    q.rear=-1;
    q.front=0;
    int choice,item;
    while(1)
    {
        printf("Enter your choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the item to be inserted:\n");
                   scanf("%d",&item);
                   insert(&q,item);
                   break;
            case 2:delet(&q);
                   break;
            case 3:display(&q);
                   break;
            case 4:exit(0);
        }
    }
    return 0;
}

void insert(struct queue *q,int item)
{
    int j;
    if(q->rear==size-1)
    {
        printf("Priority queue is full\n");
    }
    else
    {
        j=q->rear;
        while(j>=0 && item<q->items[j])
        {
            q->items[j+1]=q->items[j];
            j--;
        }
        q->items[j+1]=item;
        q->rear++;
    }
}

void delet(struct queue *q)
{
    int ele;
    if(q->front > q->rear)
        printf("Queue is empty\n");
    else
    {
        ele=q->items[q->front];
        printf("%d deleted\n",ele);
        q->front=q->front+1;
    }
    if(q->front > q->rear)
    {
        q->front=0;
        q->rear=-1;
    }
}

void display(struct queue *q)
{
    int i;
    if(q->front > q->rear)
        printf("Queue is empty\n");
    else
    {
        printf("Elements in queue are:\n");
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d\t",q->items[i]);
        }
        printf("\n");
    }
}
