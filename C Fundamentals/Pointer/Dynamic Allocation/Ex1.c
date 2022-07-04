// cho một mảng n phần tử lưu trong file array.txt, thực hiện các yêu cầu sau:
// 1. Viết một hàm đọc mảng từ file array.txt và một hàm ghi một mảng lên file output.txt. Chú ý đối với hàm đọc mảng yêu cầu cấp phát bộ nhớ động cho mảng và trả về con trỏ quản lý mảng đó. --> Done!
// 2. Viết một hàm sắp xếp mảng đã cho. Hàm không trả về. Ghi mảng này vào file output.txt
// 3. Viết một hàm kiểm tra xem có bao nhiêu phần tử là số nguyên tố. Hàm trả về một mảng là dãy các số nguyên tố được tìm thấy theo thứ tự của chúng trong mảng. VD: 2 4 5 7 9 --> 2 5 7. Ghi mảng này vào file output.txt
#include <stdio.h>
#include <stdlib.h>
#define newline printf("\n")

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    newline;
}
// 1
int *readFromFile(const char *fileName, int *n);
void writeFile(const char *fileName, int *arr, int n);

// 2
void sort(int *arr, int n);

// 3
int *getPrimesArray(int *arr, int n);

int main()
{
    int n;
    printf("Nhap ten file: ");
    char name[256];
    scanf("%s", name);
    int *arr = readFromFile(name, &n);
    printArray(arr, n);
    // writeFile("output.txt", arr, n);

    sort(arr, n);
    printf("Mang sau sap xep: ");
    printArray(arr, n);
    writeFile("output.txt", arr, n);

    int *prime = getPrimesArray(arr, n);
    writeFile("output.txt", prime, prime[0]);
    free(arr);
    free(prime);
    return 0;
}

int *readFromFile(const char *fileName, int *n)
{
    FILE *finp = NULL;
    finp = fopen(fileName, "r");
    if (finp == NULL)
    {
        printf("Cannot open file %s!", fileName);
        return NULL;
    }
    fscanf(finp, "%d", n);
    int *arr = (int *)malloc((*n) * sizeof(int));
    for (int i = 0; i < *n; i++)
    {
        fscanf(finp, "%d", &arr[i]);
    }
    fclose(finp);
    return arr;
}

void writeFile(const char *fileName, int *arr, int n)
{
    FILE *fout = fopen(fileName, "a");
    for (int i = 0; i < n; i++)
    {
        fprintf(fout, "%d ", arr[i]);
    }
    fprintf(fout, "\n");
}

void sort(int *arr, int n)
{
    int tmp, p = 0, min = 0;
    for (int i = 0; i < n - 1; i++)
    {
        p = i;
        min = arr[i];
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

int *getPrimesArray(int *arr, int n)
{
    int m = n, k = 1;
    int *result = (int *)malloc((m + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int isPrime = 1;
        if (arr[i] < 2)
            isPrime = 0;
        else
        {
            for (int j = 2; j * j <= arr[i]; j++)
            {
                if (arr[i] % j == 0)
                {
                    isPrime = 0;
                }
            }
            if (isPrime == 1)
            {
                result[k] = arr[i];
                k++;
            }
        }
    }
    result[0] = k;
    return result;
}