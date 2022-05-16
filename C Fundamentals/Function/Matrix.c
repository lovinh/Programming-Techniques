// Bài tập:
// Tèo được thầy giáo yêu cầu làm một số bài toán liên quan đến ma trận. Thầy yêu cầu các nhiệm vụ sau:
// 1. Viết hàm nhập và in ma trận ra ngoài màn hình. --> Done.
// 2. Viết hàm tính tổng giá trị các ô lẻ trong ma trận (Ô lẻ là ô có tích trị số là số lẻ. (Trị số bắt đầu từ 1). --> Done
// 3. Viết hàm đảo vị trí hai cột. --> Done
// 4. Viết hàm xoá cột, hàng.
// 5. Viết hàm nhân hai ma trận.
// Do Tèo vừa tạch học phần Lập trình nâng cao nên yêu cầu của Thầy hơi khoai. Ta hãy giúp Tèo nhé!
#include <stdio.h>
#define MAX_LEN 100

void nhapMaTran(int arr[][MAX_LEN], int m, int n);
void inMaTran(int arr[][MAX_LEN], int m, int n);
int tongOLe(int arr[][MAX_LEN], int m, int n);
void daoViTriCot(int arr[][MAX_LEN], int m, int n, int ftIndex, int sdIndex);
void xoaHang(int arr[][MAX_LEN], int m, int n, int index);
void xoaCot(int arr[][MAX_LEN], int m, int n, int index);

int main()
{
    int a[MAX_LEN][MAX_LEN];
    int m, n, f_i, s_i;
    printf("Nhap kich thuoc: ");
    scanf("%dx%d", &m, &n);
    nhapMaTran(a, m, n);
    inMaTran(a, m, n);
    printf("Tong o le: %d\n", tongOLe(a, m, n));
    printf("Nhap hai cot can dao: ");
    scanf("%d%d", &f_i, &s_i);
    printf("Dao cot %d va %d!", f_i, s_i);
    daoViTriCot(a, m, n, f_i - 1, s_i - 1);
    inMaTran(a, m, n);
}

void nhapMaTran(int arr[][MAX_LEN], int m, int n)
{
    printf("Nhap ma tran (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Nhap arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Ket thuc nhap!\n");
}

void inMaTran(int arr[][MAX_LEN], int m, int n)
{
    printf("In ma tran (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("Ket thuc in!\n");
}

int tongOLe(int arr[][MAX_LEN], int m, int n)
{
    int result = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + 1) * (j + 1) % 2 != 0)
                result += arr[i][j];
        }
    }

    return result;
}

void daoViTriCot(int arr[][MAX_LEN], int m, int n, int ftIndex, int sdIndex)
{
    int tmp = 0;
    for (int i = 0; i < m; i++)
    {
        tmp = arr[i][ftIndex];
        arr[i][ftIndex] = arr[i][sdIndex];
        arr[i][sdIndex] = tmp;
    }
}