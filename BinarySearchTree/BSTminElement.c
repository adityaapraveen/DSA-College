#include <stdio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
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

int minElement(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return minElement(root->left);
    }
}

int main()
{
    struct Node *root = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("The minimum element is %d\n", minElement(root));

    return 0;
}