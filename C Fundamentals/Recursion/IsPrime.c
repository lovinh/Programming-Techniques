#include <stdio.h>
// Bài 1: Cài đặt hàm isPrime(), nhận vào một số nguyên n, trả về True (hoặc 1) nếu n là số nguyên tố, ngược lại trả về False (Hoặc 0).
// int isPrime(int n, int i);
int isPrime(int n, int i);
int main()
{
    printf("Nhap so n: ");
    int n;
    scanf("%d", &n);
    if (isPrime(n, n - 1))
        printf("%d la so nguyen to!\n", n);
    else
        printf("%d khong la so nguyen to!\n", n);
}
int isPrime(int n, int i)
{
    if (n <= 1)
        return 0;
    if (i == 1)
        return 1;
    if (n % i == 0)
        return 0;
    return isPrime(n, i - 1);
}
// int isPrime(int n)
// {
//     if (n <= 1)
//         return 0;
//     for (int i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//             return 0;
//     }
//     return 1;
// }