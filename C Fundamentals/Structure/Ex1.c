#include <stdio.h>
#include <stdlib.h>

// Nhập một điểm (x, y).
// Tính khoảng cách hai điểm A, B
typedef struct
{
    float x;
    float y;
} Diem;
Diem middle(Diem d1, Diem d2)
{
    Diem res;
    res.x = (d1.x + d2.x) * 0.5;
    res.y = (d1.y + d2.y) * 0.5;
    return res;
}
int main(int argc, char const *argv[])
{
    Diem d1 = {1, 2};
    // printf("%f %f", d1.x, d1.y);
    // Diem diem[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     scanf("%f %f", &diem[i].x, &diem[i].y);
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%f %f\n", diem[i].x, diem[i].y);
    // }
    Diem d2 = {5, 8};
    Diem d3 = middle(d1, d2);
    printf("%f %f", d3.x, d3.y);
    return 0;
}
