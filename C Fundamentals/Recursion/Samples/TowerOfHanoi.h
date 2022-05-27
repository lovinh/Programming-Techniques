#ifndef TowerOfHanoi

int getMovingStep(int n)
{
    if (n == 1)
        return 1;
    return 2 * getMovingStep(n - 1) + 1;
}
#endif