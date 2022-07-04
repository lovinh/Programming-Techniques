#include <stdio.h>
// Cho file array.txt chứa một mảng 1 chiều gôm n phần tử. Đọc file và in ra màn hình mảng đã đọc.
int main()
{
    FILE *finp = fopen("array.txt", "r");
    int n;
    fscanf(finp, "%d", &n);
    int arr[100];
    int *ptr = arr;
    for (int i = 0; i < n; i++)
    {
        fscanf(finp, "%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    return 0;
}