#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void insert(int callerid);
void delete();
void display();

int main()
{
    int ch;
    int callerid;
    while (1)
    {
        printf("\nenter the operation to be performed:\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the callerid to be inserted:");
            scanf("%d", &callerid);
            insert(callerid);
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

void insert(int callerid)
{
    if (rear == MAX - 1)
    {
        printf("FULL\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = callerid;
    }
}
void delete()
{
    if (front == -1)
    {
        printf("Empty\n");
        return;
    }
    else
    {
        printf("The callerid removed is %d\n", queue[front]);
        front = front + 1;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("Empty");
        return;
    }
    else
    {
        int i;
        for (i = front; i != rear; i++)
        {
            printf(" %d ", queue[i]);
        }
        printf("%d", queue[rear]);
    }
}
