#include <stdio.h>
#include <stdlib.h> //need thhis library for malloc,calloc,realloc

typedef struct node
{
    int val;
    struct node *link;
} node;

typedef struct list
{
    node *head;
    int numelements;
} list;

list *create_list()
{
    list *lst = (list *)malloc(sizeof(list));
    (*lst).head = NULL;
    lst->numelements = 0;
    printf("Size of the list is : %d\n", lst->numelements);
    return lst;
}

void add_front(list *lst, int element)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->val = element;
    new_node->link = lst->head;
    lst->head = new_node;
    lst->numelements++;
}

void traversing(list *lst)
{
    node *current = lst->head;
    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->link;
    }
}

int main()
{
    list *lst = create_list();
    int element;
    printf("Enter element to be entered to the front : ");
    scanf("%d", &element);
    add_front(lst, element);
    traversing(lst);
}