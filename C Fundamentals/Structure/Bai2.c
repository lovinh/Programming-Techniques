#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char HT[50];
    float DIEM;
    char TRUONG;
} Sinhvien;

Sinhvien *docFile(char *fileName, int *n)
{
    FILE *f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Khong the mo file %s!\n", fileName);
        return NULL;
    }
    fscanf(f, "%d", n);
    fgetc(f);
    Sinhvien *sv = (Sinhvien *)malloc((*n) * sizeof(Sinhvien));
    for (int i = 0; i < *n; i++)
    {
        fgets(sv[i].HT, 50, f);
        sv[i].HT[strlen(sv[i].HT) - 1] = '\0';
        fscanf(f, "%f", &sv[i].DIEM);
        fgetc(f);
        fscanf(f, "%c", &sv[i].TRUONG);
        fgetc(f);
    }
    fclose(f);
    return sv;
}

void inDanhSach(Sinhvien *sv, int n)
{
    printf("Danh sach sinh vien: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Ho va ten: %s\nDiem: %f\nTruong: %c\n", sv[i].HT, sv[i].DIEM, sv[i].TRUONG);
    }
}

void diemSo(Sinhvien *sv, int n)
{
    float diemA = 0, diemB = 0, diemC = 0;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].TRUONG == 'A')
            diemA += sv[i].DIEM;
        else if (sv[i].TRUONG == 'B')
            diemB += sv[i].DIEM;
        else
            diemC += sv[i].DIEM;
    }
    printf("Diem cua cac truong:\nTruong A: %f\nTruong B: %f\nTruong C: %f\n", diemA, diemB, diemC);
    printf("Truong co diem so thap nhat: ");
    if (diemA < diemB && diemA < diemC)
        printf("A");
    else if (diemB < diemA && diemB < diemC)
        printf("B");
    else
        printf("C");
}

void svCaoNhat(Sinhvien *sv, int n)
{
    int diemMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].DIEM >= diemMax)
            diemMax = sv[i].DIEM;
    }
    FILE *f = fopen("caonhat.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (sv[i].DIEM == diemMax)
            fprintf(f, "%s %c", sv[i].HT, sv[i].TRUONG);
    }
    fclose(f);
}
int main()
{
    int n;
    Sinhvien *sv = docFile("input.txt", &n);

    // Phan 1
    diemSo(sv, n);

    // Phan 2
    svCaoNhat(sv, n);
    return 0;
}
