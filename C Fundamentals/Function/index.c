
#include <stdio.h>
#include "BasicFunction.h"
#include "CustomMath.h"

#define MAX_LEN 100
int main()
{
    printf("Enter a string: ");
    char s[MAX_LEN];
    scanf("%s", s);
    printf("Converting Number: %d\n", atoi(s));
    int val = atoi(s);
    printf("Square the number: %lf\n", square(val));
    printf("Triple the number: %lf\n", triple(val));
    printf("Power the number 10 times: %lf\n", getPower(val, 10));
}