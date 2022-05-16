#include <stdio.h>

float getBMIScore(float weight, float height)
{
    return (weight * 1.0) / (height * height);
}

void printOut(const char s[], float score)
{
    printf("Chi so BMI cua ban %s la: %0.1f\n", s, score);
    if (score >= 25)
        printf("Ban dang hoi map! Can an it lai va tap the duc nhieu hon!\n");
    else if (score <= 18.5)
        printf("Ban dang gay! Can an nhieu len!\n");
    else
        printf("Ban qua chuan dang luon!\n");
}
int main()
{
    char s[] = "Teo";
    float weight = 80, height = 1.8;
    float BMI = getBMIScore(weight, height);
    printOut(s, BMI);
}