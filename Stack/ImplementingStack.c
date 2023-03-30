#include <stdio.h>

#define size 5
int stack[size];
int top = -1;
int num;

void push()
{
    // to check the overflow state
    if (top == size - 1)
    {
        printf("\n!!STACK OVERFLOW!!\n");
    }
    // to push element if theres no overflow
    else
    {
        int x;
        printf("\nEnter the element to be pushed:");
        scanf("%d", &x);
        top += 1; // top = top + 1;
        stack[top] = x;
    }
}
int pop()
{
    // to check if the stack doesnt have any elements to pop
    if (top == -1)
    {
        printf("\n!!STACKUNDERFLOW!!\n");
    }
    // to IGNORE the element when popped
    else
    {
        int x = stack[top];
        printf("\npopped element:%d\n", x);
        top -= 1;
        return x;
    }
}
int peek()
{
    int x = stack[top];
    printf("\npeek element is:%d\n", x);
    return x;
}

int main()
{
    for (;;)
    {
        printf("\n1}push\n2}pop\n3}peek\nEnter your choice:");
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
            printf("Choose a correct option!");
        }
    }
    return 0;
}