#include <stdio.h>
#include <string.h>
char ****get_document(char *text)
{
    return (char ****)text;
}
int main()
{
    char *text = "Learning C";
    char ****document = get_document(text);
    printf("%s", ****document);
    return 0;
}