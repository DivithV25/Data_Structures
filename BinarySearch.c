#include <stdio.h>
int binary_search(int arr[], int low, int high, int key);
int main()
{
    int i, n;
    printf("Enter the number of elements in  array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in an array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the element to find\n");
    scanf("%d", &key);
    int result;
    result = binary_search(arr, 0, n - 1, key);
    (result == -1) ? printf("The given element does not exist") : printf("The element %d is present in the index %d", key, result);
}

int binary_search(int arr[], int low, int high, int key)
{
    int mid;
    if (low <= high)
        mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return binary_search(arr, low, mid - 1, key);
    if (arr[mid] < key)
        return binary_search(arr, mid + 1, high, key);
    return -1;
}
