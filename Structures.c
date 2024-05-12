#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct emp
{
    char name[50];
    int id;
    char dept[50];
    float sal;
};
void depsal(struct emp *ptr, int n);
int main()
{
    int i, n;
    printf("Enter the number of employees:");
    scanf("%d", &n);
    struct emp *ptr = (struct emp *)malloc(sizeof(struct emp));
    for (i = 0; i < n; i++)
    {
        printf("Name of emp %d:\n", i + 1);
        scanf("%s", ((ptr + i)->name));
        printf("Id of emp %d:\n", i + 1);
        scanf("%d", &((ptr + i)->id));
        printf("Enter the name of the department of emp %d:\n",i+1);
        scanf("%s", ((ptr + i)->dept));
        printf("Enter the salary of the employee %d:\n", i + 1);
        scanf("%f", &((ptr + i)->sal));
    }

    for (i = 0; i < n; i++)

    {

        printf("Name of employee %d : %s\n", i + 1, ((ptr + i)->name));
        printf("Id of employee %d : %d\n", i + 1, ((ptr + i)->id));
        printf("Name of the department is %s\n", ((ptr + i)->dept));
        printf("Salary of employee  %d is %f\n", i + 1, ((ptr + i)->sal));
    }
    depsal(ptr, n);
}

void depsal(struct emp *ptr, int n)
{
    char d[50];
    int i;
    float total = 0;
    printf("Enter the name of the department to calculate the total salary of the department:");
    scanf("%s", d);
    for (i = 0; i < n; i++)
    {
        if (strcmp((ptr + i)->dept, d) == 0)
        {
            total = total + (ptr + i)->sal;
        }
    }
    printf("Total salary of the department is = %f", total);
}
