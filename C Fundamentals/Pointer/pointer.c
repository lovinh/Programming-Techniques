#include <stdio.h>
void printValue(char c, int v)
{
    printf("Value of %c: %d\n", c, v);
}
int a = 19;
int main()
{
    int a = 19;
    int *ptr = &a;
    // printf("Address of a: %d\n", &a);
    // printf("Value stored in ptr: %d\n", ptr);
    // printf("Address of ptr: %d\n", &ptr);
    // printf("Value of a: %d\n", a);
    // printf("Gia tri con tro tro toi: %d\n", *ptr);
    // (*ptr) += 10;
    // printf("Value of a: %d\n", a);
    // printf("Gia tri con tro tro toi: %d\n", *ptr);
    // int b = (*ptr) * 2;
    // printf("Value of b: %d\n", b);
    int b = 20;
    *ptr = b;
    (*ptr) += 20;
    // a = 40
    // b = 20
    printValue('a', a);
    printValue('b', b);
    ptr = &b;
    (*ptr) += 20;
    printValue('a', a);
    printValue('b', b);
    return 0;
}