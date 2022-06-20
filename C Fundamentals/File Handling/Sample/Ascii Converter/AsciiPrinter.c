#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void printOut(FILE *file)
{
    int img_wd = 0, res = 0;
    char c;
    file = fopen("Image.txt", "r");
    while (!feof(file))
    {
        c = getc(file);
        printf("%c", c);
    }
    printf("\nImage width: %d", res);
}
void count(const char *text)
{
    printf("%d\n", strlen(text));
}
int main(const char *arg)
{
    FILE *f;
    printOut(f);
    // count("YYYJJG##BBGBBBGGBBB#BBBBBBBGBBGGGGGGGGGGBBGBBBBBBBBBBG5YY?5P555555GGGGG55PP5PYJJ5PPPPPGPPP555PP55555555555Y5Y5YY55YYYYY55YY5YYYYYYYYYYYYYYJYJJJJJYYJJJJJJJ?????JJJJJ?J??YYYY5P55PPPB##@Y!7JYY??JYPGBBBBGPPPPP5YJJ???????????????????J???????JJ?JJJJJJJJJJJJJJJJJJJJJJJ???????");
    return 0;
}