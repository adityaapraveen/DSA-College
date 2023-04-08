#include <stdio.h>
#include <stdlib.h>

#define size 5

int myQueue[size];
int rear = -1;
int front = -1;
int num;
int ele;

void Enqueue()
{
    if (rear == size - 1)
    {
        printf("\nQueue OverFlow!\n");
    }
    else
    {
        if (rear == -1)
        {
            front = 0;
        }
        printf("\nElement to Enqueue:");
        scanf("%d", &ele);
        rear += 1;
        myQueue[rear] = ele;
    }
}

int Dequeue()
{
    if (rear == -1 || front > rear)
    {
        printf("\nQueue UnderFlow\n");
        return 0;
    }
    else
    {
        printf("\nDequeued element:%d", myQueue[front]);
        front += 1;
    }
    return 1;
}
void Display()
{
    int i;
    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\n***Queue***\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", myQueue[i]);
        }
    }
    return 1;
}

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
            break;
        default:
            printf("\nEnter a valid number\n");
        }
    }
}