#include<stdio.h>
#include<stdlib.h>

int ele, ch, front = -1, rear = -1;

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct queue
{
    node *head;
}queue;

queue* createQ()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL; 
    printf("\nQueue created \n");
    return q;
}

//single linked list - add to front
void enQueue(queue *q, int element)
{
    if(q->head == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = element;
        temp->next = NULL;
        q->head = temp;
        if(front == -1)
        {
            front = 0;
        }
        ++rear;
        printf("\n%d has been inserted into the queue\n", (q->head)->data);
        printf("\nFront is at %d position and Rear is at %d position\n", front, rear);
    }
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = element;
        temp->next = q->head;
        q->head = temp;
        if(front == -1)
        {
            front = 0;
        }
        ++rear;
        printf("\n%d has been inserted into the queue\n", (q->head)->data);
        printf("\nFront is at %d position and Rear is at %d position\n", front, rear);
    }
}

//single linked list - delete from back
int deQueue(queue *q)
{
    if(q->head == NULL)
    {
        printf("\nQueue is empty.. Please insert items to continue!\n");
        return -1; //what if element is -1?
    } 
    else if((q->head)->next == NULL)
    {
        int delData;
        node *del;
        del = q->head;
        delData = (q->head)->data;
        q->head = NULL;
        front++;
        if(front == rear + 1)
        {
            front = -1, rear = -1;
        }
        printf("\n%d is deleted from the queue\n", delData);
        printf("\nFront is at %d position and Rear is at %d position\n", front, rear);
        free(del);
        return delData;
    }
    else
    {
        int delData;
        node *del;
        node *curr;
        curr = q->head;
        while((curr->next)->next != NULL)
        {
            curr = curr->next;
        }
        if((curr->next)->next == NULL)
        {
            delData = (curr->next)->data;
            del = curr->next;
            curr->next = NULL;
        front++;
        if(front == rear + 1)
        {
            front = -1, rear = -1;
        }
            printf("\n%d is deleted from the queue\n", delData);
            printf("\nFront is at %d position and Rear is at %d position\n", front, rear);
            free(del);
            return delData;
        }
    }
}


//single linked list - display
void display(queue *q)
{
    if(q->head == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        node *curr;
        curr = q->head;
        while(curr != NULL)
        {
            printf("\n%d", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main()
{
    queue *q = createQ();
    for(; ;)
    {
        printf("\nLINEAR QUEUE - OPERATIONS");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &ele);
                enQueue(q, ele);
                break;

            case 2:
                int del = deQueue(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                printf("\nProgram exiting!!");
                exit(0);
        }
    }
}