#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Diem;
double khoangCach(Diem a, Diem b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
Diem *docFile(char *fileName, int *n)
{
    FILE *f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Khong the mo file %s!\n", fileName);
        return NULL;
    }
    fscanf(f, "%d", n);
    Diem *diem = (Diem *)malloc((*n) * sizeof(Diem));
    for (int i = 0; i < *n; i++)
    {
        fscanf(f, "%lf %lf", &diem[i].x, &diem[i].y);
    }
    return diem;
}

void inDay(Diem *diem, int n)
{
    printf("Danh sach diem: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%lf %lf\n", diem[i].x, diem[i].y);
    }
}

int demDoanThang(float R, Diem *diem, int n)
{
    int dem = 0;
    Diem O = {0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (khoangCach(diem[i], O) < R && khoangCach(diem[j], O) < R)
                dem++;
        }
    }
    return dem;
}

int main()
{
    // Phan 1
    int n;
    char fileName[20];
    printf("Nhap ten file: ");
    scanf("%s", fileName);
    Diem *diem = docFile(fileName, &n);
    inDay(diem, n);

    // Phan 2
    double R;
    printf("Nhap ban kinh R: ");
    scanf("%lf", &R);
    printf("So doan thang nam trong duong tron (O, R): %d\n", demDoanThang(R, diem, n));

    return 0;
}
