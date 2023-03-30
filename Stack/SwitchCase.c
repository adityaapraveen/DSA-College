/*wap to implement a stack using array of structures.*/
#include <stdio.h>
#include <stdlib.h>

int ch;
#define size 5
int mystack[size];
int element;
int del;
int top = -1;

push()
{
}
pop()
{
    return del;
}
display()
{
}

int main()
{
    for (;;)
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be pushed:");
            scanf("%d", &element);
            push();
            break;
        case 2:
            del = pop();
            printf("%d", del);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}