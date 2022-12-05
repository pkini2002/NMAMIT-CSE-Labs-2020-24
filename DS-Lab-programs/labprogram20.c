#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

int count=1;

typedef struct node *NODE;

NODE create_node(int val)
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    newnode->info=val;
    newnode->llink=NULL;
    newnode->rlink=NULL;
    return newnode;
}

void set_left(NODE p,int val)
{
    if(p==NULL)
    {
        printf("Insertion is not possible\n");
    }
    else if(p->llink!=NULL)
    {
        printf("Invalid insertion\n");
        return 0;
    }
    else
     p->llink=create_node(val);
}

void set_right(NODE p,int val)
{
    if(p==NULL)
    {
        printf("Insertion is not possible\n");
    }
    else if(p->rlink!=NULL)
    {
        printf("Invalid insertion\n");
        return 0;
    }
    else
    p->rlink=create_node(val);
}

NODE create_bs_tree(NODE root,int val)
{
    if(root==NULL)
        root=create_node(val);
    else
    {
        NODE p,q;
        p=q=root;
        while(val!=p->info && q!=NULL)
        {
            p=q;
            if(val<p->info)
                q=p->llink;
            else
                q=p->rlink;
        }
        if(val==p->info)
            printf("Duplication is not possible\n");

        else if(val < p->info)
            set_left(p,val);

        else
            set_right(p,val);
    }
    return root;
}


void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d ",root->info);
        inorder(root->rlink);
    }
}

void search(NODE root,int key)
{
    NODE p,q;
    p=q=root;
    while(key!=p->info && q!=NULL)
    {
        p=q;
        if(key < p->info)
            q=p->llink;
        else
            q=p->rlink;
    }
    if(key==p->info)
        printf("Search is successful\n");
    else
        printf("Key element is not found\n");
}

int maximum(NODE root)
{
    while(root->rlink!=NULL)
    {
        root=root->rlink;
        count++;
    }
    return root->info;
}

int minimum(NODE root)
{
    while(root->llink!=NULL)
    {
        root=root->llink;
        count++;
    }
    return root->info;
}



int main()
{
    int choice,val,key,max,min;
    NODE root=NULL;
    while(1)
    {
    printf("\nEnter your choice\n1.Insert\n2.Inorder\n3.Search\n4.Maximum\n5.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the element:\n");
               scanf("%d",&val);
               root=create_bs_tree(root,val);
               break;

        case 2:inorder(root);
               break;

        case 3:printf("Enter the key to be searched\n");
               scanf("%d",&key);
               search(root,key);
               break;

        case 4:max=maximum(root);
               printf("Maximum is %d\n",max);
               break;


        case 5:min=minimum(root);
               printf("Minimum is %d\n",min);
               break;

        case 6:printf("Nodes present in tree are: %d\n",count);
               break;

        case 7:exit(0);
    }
    }

    return 0;
}
