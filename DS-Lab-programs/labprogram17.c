//Student info using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    char name[20];
    int usn,sem;
    struct node *link;
}*first=NULL;

int c=0;

void insert_pos(int i)
{
    if(i<=c+1 && i>0)
    {
        struct node *p,*t,*q;
        p=(struct node *)malloc(sizeof(struct node));
        printf("Enter usn:\n");
        scanf("%d",&p->usn);
        printf("Enter sem:\n");
        scanf("%d",&p->sem);
        printf("Enter name:\n");
        scanf("%s",p->name);
        p->link=NULL;
        if(first==NULL)
        first=p;
        else if(i==1)
        {
            p->link=first;
            first=p;
        }
        else
        {
            int count=1;
            t=first;
            q=first;
            while(count!=i)
            {
                q=t;
                t=t->link;
                count++;
            }
            q->link=p;
            p->link=t;
        }
        c++;
    }
    else
    printf("Error cannot insert\n");
}

void del()
{
    struct node *p;
    p=first;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if(first->link==NULL)
    {
        printf("Deleted details are:\n");
        printf("\nUSN:%d",first->usn);
        printf("Sem:%d",first->sem);
        printf("Name:%s",first->name);
        free(first);
        first=NULL;
    }
    else
    {
        first=p->link;
        printf("Deleted details are:\n");
        printf("\nUSN:%d",p->usn);
        printf("Sem:%d",p->sem);
        printf("Name:%s",p->name);
        free(p);
    }
    c--;
}

void display()
{
    struct node *p;
    p=first;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Student details are:\n");
    while(p->link!=NULL)
    {
        printf("\nUSN:%d",p->usn);
        printf("Sem:%d",p->sem);
        printf("Name:%s",p->name);
        p=p->link;
        printf("\n");
    }
    printf("\nUSN:%d",p->usn);
    printf("Sem:%d",p->sem);
    printf("Name:%s",p->name);
    p=p->link;
}

int main()
{
    printf("Student information linked list\n");
    while(1)
    {
        int f,ch;
        printf("\nMenu\t1.Insert\t2.Delete\t3.Display\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter position to insert\n");
                   scanf("%d",&f);
                   insert_pos(f);
                   break;

            case 2:del();
                   break;

            case 3:display();
                   break;

            default:printf("Invalid!\n");
                    exit(0);
        }
    }
    return 0;
}

