#include <stdio.h>
#include <stdlib.h>

typedef struct nodE 
{
    int data;
    struct nodE *next;
}node;

typedef struct lisT
{
    int numelem;
    struct nodE *head;
}list;

list* create_list()
{
    list *l = (list*)malloc(sizeof(list));
    l->head = NULL;
    l->numelem = 0;//aka meta data
    return l;
}

void add_front(list *l,int value)
{
    node *n = (node*)malloc(sizeof(node));
    n->next = l->head;
    n->data = value;
    l->head = n;
    l->numelem ++;
}

void add_rear(list *l,int value)
{
    node *n = (node*)malloc(sizeof(node));
    n->data = value;
    n->next = NULL;
    node *curr = (node*)malloc(sizeof(node));
    curr = l->head;
    while(curr!= NULL && curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = n;
    l->numelem++;
}

void delete_front(list *l)
{
    if (l->head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        node *del = (node*)malloc(sizeof(node));
        del = l->head;
        l->head = l->head->next;
        printf("\n\nThe deleted front node value is: %d",del->data);
        printf("\n");
        free(del);
        l->numelem--;
    }
}

void delete_rear(list *l)
{
    if (l->head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        if (l->head->next == NULL) // Only one node in the list
        {
            int val = l->head->data;
            printf("\nThe deleted element is = %d", val);
            free(l->head);
            l->head = NULL;
            l->numelem = 0;
        }
        else 
        {
            node *curr = (node*)malloc(sizeof(node));
        curr = l->head;
        while(curr!= NULL && curr->next->next != NULL)
        {
            curr = curr->next;
        }
        printf("\n\nThe deleted last node value is: %d",curr->next->data);
        printf("\n");
        free(curr->next->next);
        curr->next = NULL;
        l->numelem--;
        }
        
    }
}

void display(list *l)
{
    node *curr = (node*)malloc(sizeof(node));
    curr = l->head;
    if (l->head == NULL)
    {
        printf("\nThe list is empty");
    }
    else
    {
        int i = 1;
        while(curr!=NULL)
        {
            printf("\nElement %d = %d",i,curr->data);
            curr = curr->next;
            i++;
        }
        printf("\nNumber of elements in the list are: %d",l->numelem);
    }
    
}

int main()
{
    list *l = create_list();
    add_front(l,10);
    add_front(l,20);
    add_rear(l,40);
    add_rear(l,30);
    display(l);
    delete_rear(l);
    add_rear(l,50);
    add_front(l,30);
    display(l);
    delete_front(l);
    display(l);
}
