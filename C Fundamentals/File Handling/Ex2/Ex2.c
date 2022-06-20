#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define newline printf("\n")
#define MAX_LEN 100
void readFromFile(FILE *finp, char arr[][100], float p1[], float p2[], float p3[], int *n);
void printInfo(char name[], float p1, float p2, float p3);
int getMaxAvenragePoint(float p1[], float p2[], float p3[], int n);
int main(const char *args)
{
    FILE *finp;
    char arr[MAX_LEN][MAX_LEN];
    int n;
    float p1[MAX_LEN], p2[MAX_LEN], p3[MAX_LEN];
    readFromFile(finp, arr, p1, p2, p3, &n);
    // In toàn bộ danh sách sinh viên
    for (int i = 0; i < n; i++)
    {
        printInfo(arr[i], p1[i], p2[i], p3[i]);
    }
    int id = getMaxAvenragePoint(p1, p2, p3, n);
    printf("Thong tin sinh vien co diem TB cao nhat:\n");
    printInfo(arr[id], p1[id], p2[id], p3[id]);
    return 0;
}
void readFromFile(FILE *finp, char arr[][100], float p1[], float p2[], float p3[], int *n)
{
    finp = fopen("sinhvien.txt", "r");
    fscanf(finp, "%d", n);
    fgetc(finp);
    printf("n = %d\n", *n);
    for (int i = 0; i < *n; i++)
    {
        fgets(arr[i], MAX_LEN, finp);
        arr[i][strlen(arr[i]) - 1] = '\0';
        printf("Name: %s had read!\n", arr[i]);
        fscanf(finp, "%f %f %f", &p1[i], &p2[i], &p3[i]);
        fgetc(finp);
    }
}
void printInfo(char name[], float p1, float p2, float p3)
{
    printf("Ho va ten: %s\n", name);
    printf("Diem so: %f %f %f\n", p1, p2, p3);
}
int getMaxAvenragePoint(float p1[], float p2[], float p3[], int n)
{
    int idResult = 0;
    float max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max <= ((p1[i] + p2[i] + p3[i]) / 3))
        {
            max = ((p1[i] + p2[i] + p3[i]) / 3);
            idResult = i;
        }
    }
    return idResult;
}
