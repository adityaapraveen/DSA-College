#include <stdio.h>

struct node
{
    int val;
    struct listnode *next;
};
typedef struct listnode listnode;

struct list
{
    struct node *head;
    int num_elements;
};
typedef struct list list;

list * create_list()
{
    list *lst = (list*)malloc(sizeof(list));
    lst->head = NULL;
    lst->num_elements;
    return lst;
}

int main()
{
    return 0;
}