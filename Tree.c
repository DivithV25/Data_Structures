#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
void inorder();
void preorder();
void postorder();
struct node *newnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return newnode(data);

    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}
int main()
{
    int ch;
    int data;
    while (1)
    {
        printf("\nEnter the operation tobe performed:\n");
        printf("\n1.insert\n2.inorder\n3.postorder\n4.preorder\n5.exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data to be added\n");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            exit(0);
            break;
        }
    }
}
