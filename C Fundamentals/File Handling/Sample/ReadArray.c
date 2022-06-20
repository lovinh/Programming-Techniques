#include <stdio.h>
#include <stdlib.h>
#define newline printf("\n")
void sort(int arr[], int n)
{
    int min, tmp, p;
    for (int i = 0; i < n - 1; i++)
    {
        min = arr[i];
        p = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] <= min)
            {
                min = arr[j];
                p = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[p];
        arr[p] = tmp;
    }
}
void readArray(int arr[], int *n)
{
    FILE *f = fopen("E:\\Learn C\\Programming Techniques\\C Fundamentals\\File Handling\\Sample\\array.txt", "r");
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    newline;
}
int main(const char *args)
{
    int n, arr[100];
    readArray(arr, &n);
    printf("Array before sorting: ");
    printArray(arr, n);
    sort(arr, n);
    printf("Array after sorting: ");
    printArray(arr, n);
    return 0;
}