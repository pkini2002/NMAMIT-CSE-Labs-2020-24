//Circular doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * llink,*rlink;
};
typedef struct node * NODE;

NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}

NODE insert_front(int item,NODE first)
{
    NODE temp;
    temp=getnode();
    temp->info=item;
    temp->llink=temp->rlink=temp;
    if(first==NULL)
    {
        return temp;
    }
    NODE last=first->llink;
    last->rlink=temp;
    temp->llink=last;
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

NODE delete_rear(NODE first)
{
    if(first==NULL)
    {
        printf("cdll is empty\n");
        return NULL;
    }
    if(first->rlink==first)
    {
        printf("Item deleted=%d\n",first->info);
        free(first);
        return NULL;
    }
    NODE prev,last;
    last=first->llink;
    prev=last->llink;
    prev->rlink=first;
    first->llink=prev;
    printf("Item deleted=%d\n",last->info);
    free(last);
    return first;
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("Cdll is empty\n");
        return;
    }
    cur=first;
    while(cur!=first->llink)
    {
        printf("%d\t",cur->info);
        cur=cur->rlink;
    }

    printf("%d\n",cur->info);
}
int main()
{
    int item,choice;
    NODE first=NULL;
    for(;;)
    {
        printf("1.Insert front\n2.Delete rear\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%d",&item);
                first=insert_front(item,first);
                break;
            case 2:
                first=delete_rear(first);
                break;
            case 3:
                display(first);
                break;
            case 4:exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
