#include <stdio.h>
void toh(int n, char A, char B, char C);
int main()
{
    int n;
    printf("Enter the number of rings:");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
}
void toh(int n, char A, char B, char C)
{
    if (n == 1)
        printf("Move from %c to %c \n", A, C);
    else
    {
        toh(n - 1, A, C, B);
        toh(1, A, B, C);
        toh(n - 1, B, A, C);
    }
}
