#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[50];
    struct node *next;
};
struct node *head = NULL;
void insert(char *name);
void delete(char *name);
void display();
int main()
{
    int ch;
    char name[50];
    while (1)
    {
        printf("\n Enter the operation to be performed:\n");
        printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the name to be inserted:");
            scanf("%s", name);
            insert(name);
            break;

        case 2:
            printf("Enter the name to be deleted:");
            scanf("%s", name);
            delete (name);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}
void insert(char *name)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    strcpy(newnode->name, name);
    if (head == NULL || (strcmp(head->name, name)) >= 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *curr = head;
        while ((curr->next != NULL) && (strcmp(curr->next->name, name)) < 0)
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}
void delete(char *name)
{
    struct node *temp = head;
    struct node *prev = NULL;
    if (temp != NULL && strcmp(temp->name, name) == 0)
    {
        head = temp->next;
        free(temp);
        return;
    }
    else
    {
        while (temp != NULL && (strcmp(temp->name, name)) != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("name not found");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("the list is empty");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf(" %s ", temp->name);
        temp = temp->next;
    }
}
