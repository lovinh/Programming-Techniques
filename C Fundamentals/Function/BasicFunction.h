#include <ctype.h>
#define MAX_LEN 100
#ifndef BasicFunction
/*
    Convert a string into a integer.
    Parameter: s - a string that need to convert to an integer number.
    Return: An integer converting from input string.
*/
int atoi(const char s[])
{
    int i, result = 0, sign;
    for (i = 0; isspace(s[i]); i++)
        ; // Skip white space.
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
    {
        i++; // Skip this sign
    }
    while (s[i] != '\0')
    {
        if (isdigit(s[i]))
        {
            result = 10 * result + (s[i] - '0');
        }
        i++;
    }
    return result * sign;
}
#endif
