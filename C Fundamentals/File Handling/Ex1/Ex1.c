#include <stdlib.h>
#include <stdio.h>
#define newline printf("\n")
void readFromFile(FILE *finp, int arr[], int *n);
void printArray(int arr[], int n);
void sort(int arr[], int n);
int main(const char *args)
{
    FILE *finp;
    int arr[100], n = 0;
    readFromFile(finp, arr, &n);
    printf("Mang chua sap xep: ");
    printArray(arr, n);
    printf("Mang da sap xep: ");
    sort(arr, n);
    printArray(arr, n);
    fclose(finp);
    return 0;
}
// fscanf()
void readFromFile(FILE *finp, int arr[], int *n)
{
    finp = fopen("input.txt", "r");
    fscanf(finp, "%d", n);
    for (int i = 0; i < *n; i++)
    {
        fscanf(finp, "%d", &arr[i]);
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
void sort(int arr[], int n)
{
    // Selection sort
    int p = 0, min = 0, tmp;
    for (int i = 0; i < n; i++)
    {
        min = arr[i];
        p = i;
        for (int j = i; j < n; j++)
        {
            if (min >= arr[j])
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
