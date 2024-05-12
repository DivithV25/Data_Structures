#include <stdio.h>
#include <stdlib.h>
void create();
void insert();
void display();
void delete();
int a[50], n;
int main()
{
    int ch;
    while (1)
    {
        printf("Enter the choice\n");
        printf("1.create\n");
        printf("2.display\n");
        printf("3.insert\n");
        printf("4.delete\n");
        printf("5.exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();

            break;

        case 3:
            insert();

            break;

        case 4:
            delete ();

            break;

        case 5:
            exit(0);
        }
    }
}

void create()
{

    int i;

    printf("Enter the number of elements in an array\n");

    scanf("%d", &n);

    printf("Enter the elements in an array\n");

    for (i = 0; i < n; i++)

        scanf("%d", &a[i]);
}

void display()
{

    int i;

    for (i = 0; i < n; i++)
       printf("%d ", a[i]);

       printf("\n");
}

void insert()
{

    int i, p, el;
    printf("Enter the position and the element");
    scanf("%d%d", &p, &el);
    for (i = n - 1; i >= p - 1; i--)
    {
        a[i + 1] = a[i];
    }
        a[p - 1] = el;
    n++;
}

void delete()
{
    int i;
    int p;
    printf("Enter the position of the element to be deleted:");
    scanf("%d", &p);
    for (i = p; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    n--;
}
