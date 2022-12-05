#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

NODE insert_rear(int item,NODE first)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    if(first==NULL)
    {
        first=temp;
        temp->rlink=temp;
        temp->llink=temp;
        return first;
    }
    NODE last=first->llink;
    temp->rlink=first;
    first->llink=temp;
    last->rlink=temp;
    temp->llink=last;
    return first;
}

NODE delete_front(NODE first)
{
    if(first==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(first->rlink==first)
    {
        printf("Item deleted is %d\n",first->info);
        free(first);
        return NULL;
    }
    NODE last=first->llink;
    NODE curr=first;
    first=first->rlink;
    printf("Item deleted is %d\n",curr->info);
    first->llink=last;
    last->rlink=first;
    free(curr);
    return first;
}

NODE insert_right(int value,NODE first)
{
    NODE tem,curr,last;
    int num;
    tem=(NODE)malloc(sizeof(struct node));
    tem->info=value;
    tem->llink=NULL;
    tem->rlink=NULL;
    printf("Enter the node after which you want to insert the item:\n");
    scanf("%d",&num);
    curr=first;
    while(curr->rlink!=first)
    {
        if(curr->info==num)
        {
            last=curr->rlink;
            tem->rlink=last;
            last->llink=tem;
            tem->llink=curr;
            curr->rlink=tem;
            return first;
        }
        curr=curr->rlink;
    }
    curr->rlink=tem;
    tem->llink=curr;
    tem->rlink=first;
    first->llink=tem;
    return first;
}

void display(NODE first)
{
    if(first==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    NODE curr=first;
    NODE last=first->llink;
    while(curr!=last)
    {
        printf("%d ",curr->info);
        curr=curr->rlink;
    }
    printf("%d ",curr->info);
}

int main()
{
    NODE first=NULL;
    int choice,item,value;
    for(;;)
    {
    printf("\nEnter your choice:\n1.Insert rear\n2.Delete front\n3.Insert right\n4.Display\n5.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the value:\n");
               scanf("%d",&item);
               first=insert_rear(item,first);
               break;
        case 2:first=delete_front(first);
               break;
        case 3:printf("Enter the value to be inserted:\n");
               scanf("%d",&value);
               first=insert_right(value,first);
               break;
        case 4:display(first);
               break;
        case 5:exit(0);
    }
    }
    return 0;
}
