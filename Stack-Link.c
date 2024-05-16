#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int value);
void pop();
void peek();
void display();
int main()
{
    int ch;
    int value;
    while (1)
    {
        printf("\nEnter the operation to be performed:");
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data to be added:");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        }
    }
}

void push(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = top;
    top = temp;
}

void pop()
{
    if (top == NULL)
    {
        printf("Underflow");
        return;
    }
    printf("The element poped is %d\n", top->data);
    struct node *temp = top;
    top = top->next;
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Empty");
        return;
    }
    printf("%d", top->data);
}

void display()
{
    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf("\n%d\n", ptr->data);
        ptr = ptr->next;
    }
}
