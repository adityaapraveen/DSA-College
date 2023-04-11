#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

// Define structure for queue element
struct queueElement
{
    int data;
};

// Declare queue and other global variables
struct queueElement queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
bool isFull()
{
    return ((rear == SIZE - 1 && front == 0) || (front == rear + 1));
}

// Function to check if the queue is empty
bool isEmpty()
{
    return (front == -1);
}

// Function to add an element to the rear of the queue
void Enqueue(int element)
{
    if (isFull())
    {
        printf("\nQueue overflow\n");
    }
    else
    {
        struct queueElement newElement;
        newElement.data = element;
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = newElement;
        printf("\nElement added: %d", element);
    }
}

// Function to remove an element from the front of the queue
void Dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue underflow\n");
    }
    else
    {
        int removedElement = queue[front].data;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("\nElement removed: %d", removedElement);
    }
}

// Function to display the elements of the queue
void display()
{
    if (isEmpty())
    {
        printf("\nQueue underflow\n");
    }
    else
    {
        printf("\nQueue: ");
        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", queue[i].data);
        }
        printf("%d", queue[i].data);
    }
}

int main()
{
    int choice, element;
    for (;;)
    {
        printf("\n\nCircular Queue Operations");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to push: ");
            scanf("%d", &element);
            push(element);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting program...\n");
            break;
        default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}
