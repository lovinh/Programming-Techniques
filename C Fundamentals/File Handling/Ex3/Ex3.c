#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100
#define newline printf("\n");

void readFromFile(FILE *finp, int arr1[][MAX_LEN], int arr2[][MAX_LEN], int *m1, int *n1, int *m2, int *n2);
void printMatrix(int arr[][MAX_LEN], int m, int n);
void multiplyMatrix(int res[][MAX_LEN], int arr1[][MAX_LEN], int arr2[][MAX_LEN], int m1, int n1, int m2, int n2);
void printMatrixIntoFile(FILE *fout, int arr[][MAX_LEN], int m, int n);
int main(const char *args)
{
    FILE *f;
    int arr1[MAX_LEN][MAX_LEN], arr2[MAX_LEN][MAX_LEN], res[MAX_LEN][MAX_LEN];
    int m1, n1, m2, n2;
    readFromFile(f, arr1, arr2, &m1, &n1, &m2, &n2);
    printf("Ma tran 1:\n");
    printMatrix(arr1, m1, n1);
    printf("Ma tran 2:\n");
    printMatrix(arr2, m2, n2);
    multiplyMatrix(res, arr1, arr2, m1, n1, m2, n2);
    printf("Ma tran sau nhan: \n");
    printMatrix(res, m1, n2);
    FILE *fout;
    printMatrixIntoFile(fout, res, m1, n2);
    return 0;
}
void readFromFile(FILE *finp, int arr1[][MAX_LEN], int arr2[][MAX_LEN], int *m1, int *n1, int *m2, int *n2)
{
    finp = fopen("matrix.txt", "r");
    fscanf(finp, "%d %d", m1, n1);
    for (int i = 0; i < *m1; i++)
    {
        for (int j = 0; j < *n1; j++)
        {
            fscanf(finp, "%d", &arr1[i][j]);
        }
    }
    fscanf(finp, "%d %d", m2, n2);
    for (int i = 0; i < *m2; i++)
    {
        for (int j = 0; j < *n2; j++)
        {
            fscanf(finp, "%d", &arr2[i][j]);
        }
    }
}
void printMatrix(int arr[][MAX_LEN], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        newline;
    }
}
void printMatrixIntoFile(FILE *fout, int arr[][MAX_LEN], int m, int n)
{
    fout = fopen("matrix_result.txt", "a");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(fout, "%d\t", arr[i][j]);
        }
        fprintf(fout, "\n");
    }
}

void multiplyMatrix(int res[][MAX_LEN], int arr1[][MAX_LEN], int arr2[][MAX_LEN], int m1, int n1, int m2, int n2)
{
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            for (int k = 0; k < n1; k++)
            {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}
