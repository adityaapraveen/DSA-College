#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    node *left;
    node *right;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

void preorderTraversal(node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main()
{
    node *root = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Preorder traversal of the BST: ");
    preorderTraversal(root);

    return 0;
}