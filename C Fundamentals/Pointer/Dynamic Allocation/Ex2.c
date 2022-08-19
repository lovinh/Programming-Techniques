#include <stdio.h>
#include <stdlib.h>
// Chiến thuật số 1
// int *readFromFile(const char *fileName, int *m, int *n);
// void getHighDamageLocation(int *matrix, int m, int n);

// Chiến thuật số 2
int **readFromFile(const char *fileName, int *m, int *n);
void getHighDamageLocation(int **matrix, int m, int n);
// void printOut(int *p, int m, int n)
// {
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             printf("%d ", *(p + n * i + j));
//         }
//         printf("\n");
//     }
// }
void printOut(int **p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int m, n;
    int **p = readFromFile("coordinate.txt", &m, &n);
    printOut(p, m, n);
    getHighDamageLocation(p, m, n);
    return 0;
}

// Chiến thuật số 2:
int **readFromFile(const char *fileName, int *m, int *n)
{
    FILE *finp = fopen(fileName, "r");
    if (finp == NULL)
    {
        printf("Cannot open file %s!", fileName);
        return NULL;
    }

    // Đọc kích thước ma trận
    fscanf(finp, "%d %d", m, n);

    // Cấp phát:
    // Cấp phát m con trỏ cấp 1:
    int **res = (int **)malloc((*m) * sizeof(int *));
    // Cấp phát m mảng:
    for (int i = 0; i < (*m); i++)
    {
        res[i] = (int *)malloc((*n) * sizeof(int));
    }

    // Đọc ma trận
    for (int i = 0; i < (*m); i++)
    {
        for (int j = 0; j < (*n); j++)
        {
            fscanf(finp, "%d", &res[i][j]);
        }
    }

    // Trả về
    return res;
}

void getHighDamageLocation(int **matrix, int m, int n)
{
    // In ra hàng hoặc cột gây thiệt hại nhiều nhất
    // Lưu lại: hàng hay cột
    //          toạ độ
    //          Điểm thiệt hại cao nhất
    int coordinateRow = 0, coordinateCol = 0;
    int maxPointRow = 0, maxPointCol = 0;

    // Duyệt theo hàng
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        // Duyệt từng phần tử của hàng
        for (int j = 0; j < n; j++)
        {
            sum += matrix[i][j];
        }
        if (maxPointRow <= sum)
        {
            maxPointRow = sum;
            coordinateRow = i;
        }
    }
    // Duyệt theo cột
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        // Duyệt từng phần tử của cột
        for (int j = 0; j < m; j++)
        {
            sum += matrix[j][i];
        }
        if (maxPointCol <= sum)
        {
            maxPointCol = sum;
            coordinateCol = i;
        }
    }
    if (maxPointRow <= maxPointCol)
    {
        printf("Column %d", coordinateCol);
    }
    else
        printf("Row %d", coordinateRow);
}
// Chiến thuật số 1:
// int *readFromFile(const char *fileName, int *m, int *n)
// {
//     FILE *finp = fopen(fileName, "r");
//     if (finp == NULL)
//     {
//         printf("Cannot open file %s!", fileName);
//         return NULL;
//     }

//     // Đọc kích thước ma trận
//     fscanf(finp, "%d %d", m, n);

//     // Cấp phát
//     int *p = (int *)malloc((*m) * (*n) * sizeof(int));

//     // Đọc ma trận
//     for (int i = 0; i < (*m); i++)
//     {
//         for (int j = 0; j < (*n); j++)
//         {
//             fscanf(finp, "%d", p + (*n) * i + j);
//         }
//     }

//     // Trả về
//     return p;
// }
// void getHighDamageLocation(int *matrix, int m, int n)
// {
//     // In ra hàng hoặc cột gây thiệt hại nhiều nhất
//     // Lưu lại: hàng hay cột
//     //          toạ độ
//     //          Điểm thiệt hại cao nhất
//     int coordinateRow = 0, coordinateCol = 0;
//     int maxPointRow = 0, maxPointCol = 0;

//     // Duyệt theo hàng
//     for (int i = 0; i < m; i++)
//     {
//         int sum = 0;
//         // Duyệt từng phần tử của hàng
//         for (int j = 0; j < n; j++)
//         {
//             sum += *(matrix + n * i + j);
//         }
//         if (maxPointRow <= sum)
//         {
//             maxPointRow = sum;
//             coordinateRow = i;
//         }
//     }
//     // Duyệt theo cột
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         // Duyệt từng phần tử của hàng
//         for (int j = 0; j < m; j++)
//         {
//             sum += *(matrix + n * j + i);
//         }
//         if (maxPointCol <= sum)
//         {
//             maxPointCol = sum;
//             coordinateCol = i;
//         }
//     }
//     if (maxPointRow <= maxPointCol)
//     {
//         printf("Column %d", coordinateCol);
//     }
//     else
//         printf("Row %d", coordinateRow);
// }