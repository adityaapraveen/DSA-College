#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the tree
void insert(struct node **root, int data)
{
    struct node *newNode = createNode(data);
    struct node *current = *root;
    struct node *parent = NULL;

    // Find the right place to insert the new node
    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    // Insert the new node
    if (parent == NULL)
    {
        *root = newNode;
    }
    else if (data < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

// Function to delete a node from the tree
void delete(struct node **root, int data)
{
    struct node *current = *root;
    struct node *parent = NULL;

    // Find the node to be deleted
    while (current != NULL && current->data != data)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    // If the node is not found, return
    if (current == NULL)
    {
        return;
    }

    // If the node has no children, simply delete it
    if (current->left == NULL && current->right == NULL)
    {
        if (parent == NULL)
        {
            *root = NULL;
        }
        else if (current == parent->left)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(current);
    }

    // If the node has only one child, replace it with the child
    else if (current->left == NULL)
    {
        if (parent == NULL)
        {
            *root = current->right;
        }
        else if (current == parent->left)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
        free(current);
    }
    else if (current->right == NULL)
    {
        if (parent == NULL)
        {
            *root = current->left;
        }
        else if (current == parent->left)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
        free(current);
    }

    // If the node has two children, find the inorder successor and replace the node with it
    else
    {
        struct node *successor = current->right;
        struct node *successorParent = current;

        // Find the inorder successor
        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace the node with the inorder successor
        if (successorParent != current)
        {
            successorParent->left = successor->right;
        }
        successor->left = current->left;
        successor->right = current->right;

        // If the node to be deleted is the root, make the successor the new root
        if (parent == NULL)
        {
            *root = successor;
        }
        else if (current == parent->left)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }

        free(current);
    }
}