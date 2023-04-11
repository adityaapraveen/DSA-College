#include <stdio.h>

#define MAX_SIZE 5

int front = -1;
int rear = -1;

struct Queue
{
    int data;
};

struct Queue queue[MAX_SIZE];

void Enqueue()
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue overflow.\n");
    }
    else
    {
        int element;
        printf("Enter the element to be pushed: ");
        scanf("%d", &element);
        rear += 1;
        queue[rear].data = element;
        if (front == -1)
        {
            front = 0;
        }
        printf("Element %d has been pushed.\n", element);
        display();
    }
}

void Dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow.\n");
    }
    else
    {
        int element = queue[front].data;
        front += 1;
        printf("Element %d has been popped.\n", element);
        display();
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Current queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i].data);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    for (;;)
    {
        printf("\n1. Enqueue element\n2. Dequeue element\n3. Display queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
