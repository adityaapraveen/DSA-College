#include<stdio.h>
#include<stdlib.h>

int ele, ch, top = -1;

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct stack
{
    node *head;
}stack;

stack* createstack()
{
    stack *stk = (stack *)malloc(sizeof(stack));
    (*stk).head = NULL; 
    printf("\nStack created \n");
    return stk;
}

//single linked list - add to front
void push(stack *stk, int element)
{
    if(stk->head == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = element;
        temp->next = NULL;
        stk->head = temp;
        top++;
        printf("\n%d has been inserted into the stack. Value of top is %d\n", (stk->head)->data, top);
    }
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = element;
        temp->next = stk->head;
        stk->head = temp;
        top++;
        printf("\n%d has been inserted into the stack. Value of top is %d\n", (stk->head)->data, top);
    }
}

//single linked list - delete to front
int pop(stack *stk)
{
    if(stk->head == NULL)
    {
        printf("\nStack underflow.. Please insert items to continue!\n");
        return -1; //what if element is -1?
    } 
    else
    {
        int delData;
        node *del;
        if((stk->head)->next == NULL)
        {
            del = stk->head;
            delData = (stk->head)->data;
            stk->head = NULL;
            top--;
            printf("\n%d has been deleted from the stack. Value of top is %d\n", delData, top);
            free(del);
            return delData;
        }
        else
        {
            del = stk->head;
            delData = (stk->head)->data;
            stk->head = (stk->head)->next;
            top--;
            printf("\n%d has been deleted from the stack. Value of top is %d\n", delData, top);
            free(del);
            return delData;
        }
    }
}

//single linked list - display
void traverse(stack *stk)
{
    if(stk->head == NULL)
    {
        printf("\nStack underflow.. Please insert items to continue!\n");
    }
    else
    {
        node *curr;
        curr = stk->head;
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
    stack *stk = createlist();
    for(; ;)
    {
        printf("\nSTACKS (LINKED LIST) - OPERATIONS");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter element to be inserted to the front: ");
                scanf("%d", &ele);
                push(stk, ele);
                break;

            case 2:
                int del = pop(stk);
                break;

            case 3:
                traverse(stk);
                break;

            case 4:
                printf("\nProgram exiting!!");
                exit(0);
        }
    }
}


