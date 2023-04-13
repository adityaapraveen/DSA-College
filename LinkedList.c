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

int main()
{
    return 0;
}