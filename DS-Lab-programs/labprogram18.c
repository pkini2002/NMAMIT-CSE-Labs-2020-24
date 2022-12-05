//Binary tree program
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lchild, *rchild;
};
typedef struct node *NODE;
NODE create_B_tree()
{
    NODE newnode;
    int data = 0;
    newnode = NULL;
    printf("Enter data('0'if no data)");
    scanf("%d", &data);
    if (data)
    {
        newnode = (NODE)malloc(sizeof(struct node));
        newnode->info = data;
        printf("\nLeft child of %d\n", newnode->info);
        newnode->lchild = create_B_tree();
        printf("\nRight child of %d\n", newnode->info);
        newnode->rchild = create_B_tree();
    }
    return newnode;
}
void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->lchild);
    preorder(root->rchild);
}
void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->info);
}
void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->lchild);
    printf("%d ", root->info);
    inorder(root->rchild);
}
int main()

{
    printf("Create binary tree, start from root\n");
    NODE root;
    int choice;
    root = create_B_tree();
    while (1)
    {
        printf("Select your mode of traversal for display the binary tree\n");
        printf("1.preorder 2.postorder 3.inorder 4.exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            preorder(root);
            printf("\n");
            break;
        case 2:
            postorder(root);
            printf("\n");
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
