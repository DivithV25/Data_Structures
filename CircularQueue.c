#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct circularqueue
{
    int data;
};
struct circularqueue queue[MAX];
int front = -1;
int rear = -1;
void insert(int value);
void display();
void delete();
int main()
{
    int ch, value;
    while (1)
    {
        printf("\nEnter the operation to be performed:\n");
        printf("1.insert\n2.delete\n3.display\n");
        scanf("%d", &ch);
        switch (ch)
        {
 case 1:
            printf("\nEnter the value to be inserted:\n");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}

void insert(int value)
{
    if ((front == 0 && rear == MAX - 1) || rear + 1 == front)
    {
        printf("FULL");
        return;
    }
    if (front == -1)
       front = rear = 0;
    else
        rear = (rear + 1) % MAX;
    queue[rear].data = value;
}
void delete()
{
    if (front == -1)
    {
        printf("Empty");
        return;
    }
    else
    {
        printf("The value that is deleted is %d\n", queue[front].data);
        front = (front + 1) % MAX;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Empty \n");
    }
    else
    {
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf(" %d ", queue[i].data);
        }
        printf("%d", queue[rear].data);
    }
}
