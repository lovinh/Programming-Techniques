#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[100];
    scanf("%[^\n]s", s);
    printf("%s", s);
    return 0;
}
