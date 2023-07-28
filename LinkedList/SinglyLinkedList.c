#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void traversal()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data); // printf("%d\n ", temp->data), to display it vertically.
        temp = temp->next;
    }
    printf("\n");
}

void addFront(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void addBack(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
}

int deleteBack()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return -1;
    }

    Node *prev = NULL;
    Node *temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
    }

    int delData = temp->data;
    free(temp);

    return delData;
}

int main()
{
    int choice, ele;
    while (1)
    {
        printf("\nMENU OF SINGLE LINKED LIST\n");
        printf("\n1. Display list");
        printf("\n2. Add to front of list");
        printf("\n3. Add to back of list");
        printf("\n4. Delete from front of list");
        printf("\n5. Delete from back of list");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traversal();
            break;
        case 2:
            printf("\nEnter element to be inserted at the front: ");
            scanf("%d", &ele);
            addFront(ele);
            break;
        case 3:
            printf("\nEnter element to be inserted at the back: ");
            scanf("%d", &ele);
            addBack(ele);
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            printf("Deleted data from the back: %d\n", deleteBack());
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}
