#include <stdio.h>

#define size 5
int stack[size];
int top = -1;
int num;

void push()
{
    if (top == size - 1)
    {
        printf("\n!!stackoverflow\n");
    }
    else
    {
        int x;
        printf("ENter the element to be pushed:");
        scanf("%d", &x);
        top += 1;
        x = stack[top];
    }
}
int pop()
{
    if (top == -1)
    {
        printf("\n!!underflow!!\n");
    }
    else
    {
        int x;
        x = stack[top];
        printf("\nPopped element:%d\n", x);
        top -= 1;
        return x;
    }
}
int peek()
{
    int x = stack[top];
    printf("\npeeked element:%d\n", x);
}

int main()
{
    int num;

    for (;;)
    {
        printf("\npush\npop\npeek\nEnter your choice:");
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
        }
    }
    return 0;
}