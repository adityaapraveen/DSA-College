#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} node;

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

node *insert(node *p, int data)
{
    if (p == NULL)
    {
        p = createnode(data);
    }
    else if (data < p->data)
    {
        p->lchild = insert(p->lchild, data);
    }
    else if (data > p->data)
    {
        p->rchild = insert(p->rchild, data);
    }
    else
    {
        printf("Element already exists");
    }
    return p;
}

void search(node *p, int key)
{
    if (p == NULL)
    {
        printf("NOT FOUND");
    }
    else if (key < p->data)
    {
        search(p->lchild, key);
    }
    else if (key > p->data)
    {
        search(p->rchild, key);
    }
    else
        printf("FOUND");
}

int main()
{
    node *root = NULL;
    int key, input;
    scanf("%d", &key);
    scanf("%d", &input);
    while (input != -1)
    {
        root = insert(root, input);
        scanf("&d", &input);
    }
    search(root, key);
}
