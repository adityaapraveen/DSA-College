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
        printf("!!STACK OVERFLOW!!");
    }
    // to push element if theres no overflow
    else
    {
        int push;
        printf("\nEnter the element to be pushed:");
        scanf("%d", &push);
        top += 1; // top = top + 1;
        stack[top] = push;
    }
}
int pop()
{
    
}

int main()
{
    printf("Enter your choice:\n1}push\n2}pop\n3}peek");
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
    return 0;
}