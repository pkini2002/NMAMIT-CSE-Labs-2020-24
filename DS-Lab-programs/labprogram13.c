//Implementation of circular linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE insert_rear(NODE last,int item)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    if(last==NULL)
    {
        temp->link=temp;
        return temp;
    }

    else
    {
        NODE curr=last->link;
        while(curr!=last)
        {
            curr=curr->link;
        }
        temp->link=last->link;
        last->link=temp;
        return  temp;
    }
}

NODE delete_rear(NODE last)
{
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if(last->link==last)
    {
        printf("Item deleted is %d\n",last->info);
        free(last);
        return NULL;
    }
    else
    {
        NODE curr=last->link;
        //NODE prev=NULL;
        while(curr->link!=last)
        {
            //prev=curr;
            curr=curr->link;
        }
        curr->link=last->link;

        printf("Item deleted is %d\n",last->info);
        free(last);
        return curr;
    }
}

void display(NODE last)
{
    if(last==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    printf("Contents of linked list are:\n");
    NODE curr=last->link;
    while(curr!=last)
    {
        printf("%d ",curr->info);
        curr=curr->link;
    }
    printf("%d",curr->info);
}

int main()
{
    int choice,item;
    NODE last=NULL;
    for(;;)
    {
        printf("\nEnter your choice:\n1.Insert rear\n2.Delete rear\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value of the item to be inserted:\n");
                   scanf("%d",&item);
                   last=insert_rear(last,item);
                   break;
            case 2:last=delete_rear(last);
                   break;
            case 3:display(last);
                   break;
            case 4:exit(0);
        }
    }
    return 0;
}
