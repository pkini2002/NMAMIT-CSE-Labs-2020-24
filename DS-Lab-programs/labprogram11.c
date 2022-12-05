//Implementation of queues using singly linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE insert_rear(NODE first,int item)
{
    NODE temp,curr;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=item;
    temp->link=NULL;
    if(first==NULL)
      return temp;
      curr=first;
      while(curr->link!=NULL)
      {
          curr=curr->link;
      }
      curr->link=temp;
      return first;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("List is empty\n");
        return first;
    }
    temp=first;
    temp=temp->link;
    printf("Deleted data is %d\n",first->data);
    free(first);
    return temp;
}

void display(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("List is empty\n");
    }
    printf("The elements in the linked list are:\n");
    temp=first;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{
    int choice,item;
    NODE first=NULL;
    while(1)
    {
        printf("Enter your choice:\n1.Insert rear\n2.Delete front\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element to be inserted:\n");
                   scanf("%d",&item);
                   first=insert_rear(first,item);
                   break;
            case 2:first=delete_front(first);
                   break;
            case 3:display(first);
                   break;
            case 4:exit(0);
        }
    }
    return 0;
}

