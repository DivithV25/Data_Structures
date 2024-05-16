#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void insert(int key, int data);
void delete(int data);
void display();
struct node *head = NULL;
int main()
{
    int ch;
    int data;
    int key;
    while (1)
    {
        printf("\nEnter the operation to be performed:");
        printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data to be inserted:");
            scanf("%d", &data);
            if (head != NULL)
            {
                printf("\nEnter the key:");
                scanf("%d", &key);
            }
            insert(key, data);
            break;
        case 2:
            printf("\nEnter the data to be deleted:");
            scanf("%d", &data);
            delete (data);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}
void insert(int key, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    struct node *curr = head;
    while (curr != NULL && curr->data != key)
        curr = curr->next;
    if (curr == NULL)
    {
        printf("key not found");
        return;
    }
    newnode->prev = curr->prev;
    newnode->next = curr;
    curr->prev = newnode;
    if (newnode->prev != NULL)
        newnode->prev->next = newnode;
    else
        head = newnode;
}
void delete(int key)
{
    struct node *temp = head, *before = NULL, *after = NULL;
    while (temp != NULL && temp->data != key)
    {
        before = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("key not found");
        return;
    }
    after = temp->next;
    if (before == NULL)
    {
        head = after;
    }
    else
    {
        before->next = after;
    }
    if (after != NULL)
    {
        after->prev = before;
    }
    free(temp);
}
void display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}
