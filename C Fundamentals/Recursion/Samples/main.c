#include <stdio.h>
#include "Fibonacci.h"
#include "TowerOfHanoi.h"

void testDynamicProgramming()
{
    int n;
    long long memo[1000];
    for (int i = 0; i < 1000; i++)
        memo[i] = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The n-th Fibonacci number is: %lld\n", fibUsingDym(n, memo));
}
void testLoop()
{
    int n;
    long long memo[1000];
    for (int i = 0; i < 1000; i++)
        memo[i] = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The n-th Fibonacci number is: %lld\n", fibUsingLoop(n));
}
void testRecursive()
{
    int n;
    long long memo[1000];
    for (int i = 0; i < 1000; i++)
        memo[i] = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The n-th Fibonacci number is: %lld\n", fib(n));
}
int main()
{
    int n = 10;
    printf("%d", getMovingStep(n));
    return 0;
}