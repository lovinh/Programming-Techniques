#ifndef Fibonacci
/*
Return the n-th Fibonacci number using Recursive Algorithm. Note that the zero-index number is 0 and the first number is 1.
 */
long long fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

/*
Return the n-th Fibonacci number using single loop algorithm. Note that the zero-index number is 0 and the first number is 1.
 */
long long fibUsingLoop(int n)
{
    long long fib2 = 0, fib1 = 1, res = 0;
    if (n == 0)
        return fib2;
    if (n == 1)
        return fib1;
    for (int i = 1; i < n; i++)
    {
        res = fib2 + fib1;
        fib2 = fib1;
        fib1 = res;
    }
    return res;
}

/*
Return the n-th Fibonacci number using dynamic programming algorithm. Note that the zero-index number is 0 and the first number is 1.
 */
long long fibUsingDym(int n, long long memo[])
{
    long long res;
    if (memo[n] != 0)
        return memo[n];
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    memo[n] = fibUsingDym(n - 2, memo) + fibUsingDym(n - 1, memo);
    return memo[n];
}
#endif
