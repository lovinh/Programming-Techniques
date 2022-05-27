#include <stdio.h>

long long sumDigit(long long n);
int main()
{
    long long n;
    printf("Nhap n: ");
    scanf("%lld", &n);
    printf("Tong cac chu so cua n la: %lld", sumDigit(n));
    return 0;
}

long long sumDigit(long long n)
{
    if (n < 0)
        return 0;
    if (n / 10 == 0)
        return n;
    return sumDigit(n / 10) + (n % 10);
}