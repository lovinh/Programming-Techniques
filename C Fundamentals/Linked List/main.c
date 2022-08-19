#include <stdio.h>
#include <stdlib.h>
#include "SingleList.c"
int main(int argc, char const *argv[])
{
    node *head = NULL;
    node *ptn = (node *)malloc(sizeof(node));
    ptn->data = 100;
    ptn->next = NULL;
    head = ptn;
    printf("%d\n", head->data);
    ptn = (node *)malloc(sizeof(node));
    ptn->data = 200;
    ptn->next = NULL;
    head->next = ptn;
    printf("%d\n", head->next->data);
    ptn = (node *)malloc(sizeof(node));
    ptn->data = 300;
    ptn->next = NULL;
    head->next->next = ptn;
    printf("%d\n", head->next->next->data);
    return 0;
}
/*
    HEAD --> {100, &{200, 0}} --> {200, &{300, 0}} --> {300, 0} --> NULL
    ptn --> {300, 0}
*/