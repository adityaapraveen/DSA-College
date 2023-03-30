#include <stdio.h>

struct myShop
{
    char name[10];
    float price;
    int qty;
};
int main()
{
    struct myShop bakery;
    float total;
    printf("Enter the name of the item:");
    scanf("%s", &bakery.name);
    printf("\nEnter the price of the item:");
    scanf("%f", &bakery.price);
    printf("\nEnter the quantity of the item taken:");
    scanf("%d", &bakery.qty);
    total = bakery.price * bakery.qty;
    printf("Item:%c\nPrice:%f\nQuantity:%d\n\nTotal Price:%2f", bakery.name, bakery.price, bakery.qty, total);
}