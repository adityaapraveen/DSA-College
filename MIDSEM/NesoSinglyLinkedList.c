#include <stdio.h>
#include <stdlib.h>

int element, choice;

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct list
{
    node *head;
    int size;
} list;

2