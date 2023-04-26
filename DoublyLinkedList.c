#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a node at the front of the doubly linked list
void insertAtFront(struct Node **head_ref, int new_data)
{
    // Allocate memory for the new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // Set the data for the new node
    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

void insertAtBack(struct Node **head_ref, int new_data)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = NULL;

    if ((*head_ref) == NULL)
    {
        new_node->prev = NULL;
        (*head_ref) = new_node;
        return;
    }

    struct Node *last = (*head_ref);
    while (last->next != NULL)
    {
        last = last->next;
    }

    new_node->prev = last;

    last->next = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver code to test the doubly linked list functions
int main()
{
    struct Node *head = NULL;

    insertAtFront(&head, 1);
    insertAtFront(&head, 2);
    insertAtFront(&head, 3);

    printf("Doubly linked list after inserting nodes at the front: ");
    printList(head);

    // Insert nodes at the back of the list
    insertAtBack(&head, 4);
    insertAtBack(&head, 5);
    insertAtBack(&head, 6);

    printf("Doubly linked list after inserting nodes at the back: ");
    printList(head);

    return 0;
}
