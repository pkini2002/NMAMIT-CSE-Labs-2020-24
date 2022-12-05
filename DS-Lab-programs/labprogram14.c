//Implementation of doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE insert_front(NODE first,int value)
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    newnode->info=value;
    newnode->llink=NULL;
    if(first==NULL)
    {
        first=newnode;
        newnode->rlink=NULL;
        return first;
    }
    else
    {
        newnode->rlink=first;
        first->llink=newnode;
        return newnode;
    }
}

NODE delete_rear(NODE first)
{
     if(first==NULL)
    {
        printf("List is empty\n");
        return first;
    }
    int del;
    NODE curr=first;
    if(first->rlink==NULL)
    {
        del=first->info;
        free(first);
        first=NULL;
    }
    else
    {
        NODE prev=NULL;
        while(curr->rlink!=NULL)
        {
            prev=curr;
            curr=curr->rlink;
        }
        prev->rlink=NULL;
        del=curr->info;
        free(curr);
    }
    printf("Deleted item is %d\n",del);
    return first;
}

void display(NODE first)
{
     if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        NODE temp=first;
        while(temp!=NULL)
        {
            printf("%d\n",temp->info);
            temp=temp->rlink;
        }
        printf("\n");
    }
}

int main()
{
    int choice,item;
    NODE first=NULL;
    for(;;)
    {
        printf("\nEnter your choice:\n1.Insert front\n2.Delete rear\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value of the item to be inserted:\n");
                   scanf("%d",&item);
                   first=insert_front(first,item);
                   break;
            case 2:first=delete_rear(first);
                   break;
            case 3:display(first);
                   break;
            case 4:exit(0);
        }
    }
    return 0;
}
