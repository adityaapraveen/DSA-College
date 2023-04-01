#include <stdio.h>

#define size 5
int stack[size];
int top = -1;
int num;

void push()
{
    if (top == size - 1)
    {
        printf("\n!!STACKOVERFLOW!!\n");
    }
    else
    {
        int x;
        printf("\nElement to be pushed:");
        scanf("%d", &x);
        top += 1;
        stack[top] = x;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("\n!!STACKUNDERFLOW!!\n");
    }
    else
    {
        int x;
        printf("\nElement to be popped:");
        scanf("%d", &x);
        top -= 1;
        return x;
    }
}

int peek()
{
    int x = stack[top];
    printf("\npeeked element is:");
    return x;
}

int main()
{
    for (;;)
    {
        printf("\n1}Push\n2}Pop\n3}Peek\nEnter your choice:");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        default:
            printf("Enter a valid number");
        }
    }
    return 0;
}