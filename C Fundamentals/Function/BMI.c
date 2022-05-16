// BMI = weight / (height * height)
#include <stdio.h>

float getBMIScore(float weight, float height)
{
    return weight / (height * height);
}

void logBMI(const char name[], float score)
{
    printf("Chi so BMI cua %s la: %0.1f\n", name, score);
}

int main()
{
    float BMI = 0;
    float weight = 0, height = 0;
    char s[] = "Ti";
    weight = 58.0;
    height = 1.71;

    BMI = getBMIScore(weight, height);
    logBMI(s, BMI);

    char s2[] = "Hung";
    weight = 58.0;
    height = 1.71;

    BMI = getBMIScore(weight, height);
    logBMI("Son", BMI);
}