#include <stdio.h>
#include <stdlib.h>

#define size 5

int top = -1;

struct myShopArray
{
    char item[10];
    float price;
    int qty;
} stack[size];

void push()
{
    // to check if thestack with array of structures is full
    if (top == size - 1)
    {
        printf("\n!!STACKOVERFLOW!!\n");
    }
    // if not full then to add the desired element into the stack of array of structures.
    else
    {
        top++; // incrementing the top value as we are filling the first(0th) index of the stack
        printf("\nEnter the name of the item:");
        scanf("%s", stack[top].item);
        printf("\nEnter the price of the item:");
        scanf("%f", &stack[top].price);
        printf("\nEnter the quantity:");
        scanf("%d", &stack[top].qty);
    }
}

void pop()
{
    // to check the stack is underflowing
    if (top == -1)
    {
        printf("\n!!STACKUNDERFLOW!!");
    }
    // if not then the elements should be popped
    else
    {
        printf("\nPopped elements are-\nItem:%s\nPrice:%f\nQuantity:%d\n", stack[top].item, stack[top].price, stack[top].qty);
        top--; // top is being decremented as the values present in the top index are being removed(ignored)
    }
}

void display()
{
    // first to check if the stack is empty.
    if (top == -1)
    {
        printf("\n!!STACK IS EMPTY!!\n");
    }
    // to display theelements in the stack;
    else
    {
        float total = stack[top].price * stack[top].qty;
        printf("\n  --Stack--");
        for (int i = top; i >= 0; i--)
        {
            printf("\nitem:%s\nprice:%2f\nquantity:%d\nTotal price:%f\n", stack[i].item, stack[i].price, stack[i].qty, total);
        }
    }
}

int main()
{
    int num;
    for (;;)
    {
        printf("\n1}push\n2}pop\n3}Exit\nEnter your choice:");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            push();
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            exit(0);
        }
    }
}