#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

typedef struct list
{
    node *head;
    int numelements;
} list;

list *create_list()
{
    list *lst = malloc(sizeof(list));
    lst->head = NULL;
    lst->numelements = 0;
    printf("Size of the list is: %d\n", lst->numelements);
    return lst;
}

void add_front(list *lst, int element)
{
    node *new_node = malloc(sizeof(node));
    new_node->val = element;
    new_node->next = lst->head;
    lst->head = new_node;
    lst->numelements;
}

void add_back(list *lst, int element)
{
    node *new_node = malloc(sizeof(node));
    new_node->val = element;
    new_node->next = NULL;
    if (lst->head == NULL)
    {
        lst->head = new_node;
    }
    else
    {
        node *current = lst->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    lst->numelements++;
}

void delete_front(list *lst)
{
    if (lst->head != NULL)
    {
        node *temp = lst->head;
        lst->head = lst->head->next;
        free(temp);
        lst->numelements--;
    }
}

void delete_back(list *lst)
{
    if (lst->head != NULL)
    {
        if (lst->head->next == NULL)
        {
            free(lst->head);
            lst->head = NULL;
        }
        else
        {
            node *current = lst->head;
            while (current->next->next != NULL)
            {
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
        }
        lst->numelements--;
    }
}

void traverse(list *lst)
{
    node *current = lst->head;
    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main()
{
    list *lst = create_list();
    add_front(lst, 10);
    add_front(lst, 20);
    add_back(lst, 30);
    add_back(lst, 40);
    traverse(lst);
    delete_front(lst);
    delete_back(lst);
    traverse(lst);
    return 0;
}
