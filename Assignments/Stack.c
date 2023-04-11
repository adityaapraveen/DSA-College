#include <stdio.h>

#define size 5

int top = -1;
int element;
int stack[size];

void push()
{
    if (top == size - 1)
    {
        printf("\nstackoverflow\n");
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
        printf("\nstackunderflow\n");
    }
    else
    {
        int x = stack[top];
        printf("\nPopped element:%d", x);
        top -= 1;
        return x;
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nstackunderflow\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\n   stack    \n%d\n", stack[i]);
        }
    }
}

int main()
{
    for (;;)
    {
        printf("\n1}push\n2}pop\n3)display");
        printf("\nEnter your choice:");
        scanf("%d", &element);

        switch (element)
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
            display();
            break;
        }
    }
    return 0;
}