#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the stack itself
struct Stack {
    struct Node* top;
};

// Function to create a new node with the given data and return its pointer
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to push an element onto the top of the stack
void push(struct Stack* stack, int data) {
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the top of the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to display the contents of the stack
void display(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents:\n");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Driver code to test the implementation
int main() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    display(stack);

    int popped = pop(stack);
    printf("Popped element: %d\n", popped);
    display(stack);

    return 0;
}
