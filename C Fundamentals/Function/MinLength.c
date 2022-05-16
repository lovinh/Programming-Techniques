#include <stdio.h>
#include <math.h>
// Tìm giá trị nhỏ nhất của f(x) = sqrt(x^2 + 132^2) + sqrt((587 - x)^2 + 512^2)
// Dieu kien: x thuoc [0, 587], x nguyen.
double f(int x)
{
    return sqrt(x * x + 132 * 132) + sqrt((587 - x) * (587 - x) + 512 * 512);
}
double getMinLength()
{
    double f_res, min = f(0);
    for (int x = 1; x <= 587; x++)
    {
        f_res = f(x);
        if (f_res <= min)
        {
            min = f_res;
        }
    }
    return min;
}
int main()
{
    printf("Quang duong nho nhat Teo can di chuyen la %0.1lf\n", getMinLength());
    printf("%0.1lf\n", f(587));
    return 0;
}