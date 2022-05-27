#include <stdio.h>

long long tower(int n)
{
    // Điều kiện dừng
    if (n == 1)
    {
        return 1;
    }
    return 2 * tower(n - 1) + 1;
}
int main()
{
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);
    printf("So buoc la: %llu", tower(n));
}