#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int s[MAX], top = -1;
void push();
void pop();
void display();
void palindrome();
int main()
{
    int ch;
    while (1)
    {
        printf("Enter the operation to be performed\n1.Push\n2.pop\n3.display\n4.palindrome\n5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            palindrome();
            break;
        case 5:
            exit(0);

        default:
            printf("Invalid Input\n");
        }
    }
}

void push()
{

    int x;

    if (top == MAX)
        printf("\nStack overflow\n");
    else
    {
        printf("\nEnter the element to be pushed:\n");
        scanf("%d", &x);
        top = top + 1;
        s[top] = x;
    }
}

void pop()
{
    if (top == -1)
        printf("\nStack underflow\n");
    else
    {
        printf("\nThe poped elements is %d\n", s[top]);
        top = top - 1;
    }
}
void display()
{
    int i;
    if (top >= 0)
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", s[i]);
        }
    }
    else
        printf("Stack Empty\n");
}
void palindrome()
{
    int floor = 0, ceil = top, flag = 0;
    while (floor < ceil)
    {
        if (s[floor] != s[ceil])
        {
            flag = 1;
            break;
        }
        floor++;
        ceil--;
    }
    if (flag == 1)
        printf("\nNot a palindrome");
    else
        printf("\nIt is a palindrome");
}
