#include <stdio.h>
#include <stdlib.h>

#define size 5

int myQueue[size];
int num;
int ele;

int main()
{
    for (;;)
    {
        printf("\n1}Enqueue\n2}Dequeue\n3}Display\n4}Exit\nEnter your choice:");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nEnter a valid number\n");
        }
    }
}