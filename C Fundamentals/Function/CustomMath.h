#ifndef CustomMath
#define PI 3.14159265359
double sqrt(double);

double getLength(double xA, double yA, double xB, double yB)
{
    double length = sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
    return length;
}

double getCircleSquare(double radio)
{
    return PI * PI * radio;
}

double getPower(double val, double times)
{
    double result = 1;
    while (times--)
    {
        result *= val;
    }
    return result;
}

double square(double val)
{
    return val * val;
}

double triple(double val)
{
    return val * val * val;
}
#endif