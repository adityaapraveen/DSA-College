#include <stdio.h>

#define MAX_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_SIZE];

void Enqueue()
{
    int item;
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX_SIZE - 1)
            rear = 0;
        else
            rear++;
    }
    printf("Enter the value to be inserted : ");
    scanf("%d", &item);
    queue[rear] = item;
}

void Dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX_SIZE - 1)
            front = 0;
        else
            front++;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue Elements are : \n");
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i < MAX_SIZE; i++)
            printf("%d ", queue[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    for (;;)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Enqueue();
            display();
            break;
        case 2:
            Dequeue();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid option chosen\n");
        }
    }
}
