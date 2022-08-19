#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char code[10];
    char name[256];
    int quantity;
    int price;
    char unit[5];
} Items;
Items *readFromFile(const char *fileName, int *n);
void printItemInfo(Items item);
void printAllItemsInfo(Items *listItems, int n);
int main(int argc, char const *argv[])
{
    int n;
    Items *list = readFromFile("item.txt", &n);
    printAllItemsInfo(list, n);
    return 0;
}
Items *readFromFile(const char *fileName, int *n)
{
    FILE *finp = fopen(fileName, "r");
    if (finp == NULL)
    {
        printf("Cannot open file %s", fileName);
        return NULL;
    }
    fscanf(finp, "%d", n);
    Items *res = (Items *)malloc((*n) * sizeof(Items));
    for (int i = 0; i < (*n); i++)
    {
        fscanf(finp, "%s", &res[i].code);
        fgetc(finp);
        fscanf(finp, "%[^\n]s", &res[i].name);
        fgetc(finp);
        fscanf(finp, "%d %d", &res[i].quantity, &res[i].price);
        fscanf(finp, "%s", &res[i].unit);
        fgetc(finp);
    }
    return res;
}
void printItemInfo(Items item)
{
    printf("Ma san pham: %s\nTen san pham: %s\nSo luong ton: %d\nDon gia: %d\nDon vi tinh: %s\n",
           item.code, item.name, item.quantity, item.price, item.unit);
}
void printAllItemsInfo(Items *listItems, int n)
{
    printf("Hien thi thong tin san pham:\n");
    for (int i = 0; i < n; i++)
    {
        printItemInfo(listItems[i]);
    }
}
