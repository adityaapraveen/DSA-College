#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        // If the tree is empty, create a new node and set it as the root
        return createNode(data);
    }

    // Otherwise, do recursive insertion
    if (data < root->data)
    {
        // Insert in the left subtree
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        // Insert in the right subtree
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to search for a node
struct Node *searchNode(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        // If the root is NULL or the data is found, return the root
        return root;
    }

    if (data < root->data)
    {
        // Search in the left subtree
        return searchNode(root->left, data);
    }
    else
    {
        // Search in the right subtree
        return searchNode(root->right, data);
    }
}

// Function to find the minimum value in the tree
struct Node *findMinNode(struct Node *root)
{
    if (root == NULL || root->left == NULL)
    {
        return root;
    }

    return findMinNode(root->left);
}

// Function to find the maximum value in the tree
struct Node *findMaxNode(struct Node *root)
{
    if (root == NULL || root->right == NULL)
    {
        return root;
    }

    return findMaxNode(root->right);
}

// Function to delete a node from the tree
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        // Delete from the left subtree
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        // Delete from the right subtree
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node found, perform deletion
        if (root->left == NULL)
        {
            // Node has no left child
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            // Node has no right child
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        struct Node *minNode = findMinNode(root->right);
        root->data = minNode->data;
        root->right = deleteNode(root->right, minNode->data);
    }

    return root;
}

// Function to perform preorder traversal of the tree
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        // Print the data of the current node
        printf("%d ", root->data);

        // Visit the left subtree
        preorderTraversal(root->left);

        // Visit the right subtree
        preorderTraversal(root->right);
    }
}

// Function to perform inorder traversal of the tree
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        // Visit the left subtree
        inorderTraversal(root->left);

        // Print the data of the current node
        printf("%d ", root->data);

        // Visit the right subtree
        inorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the tree
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        // Visit the left subtree
        postorderTraversal(root->left);

        // Visit the right subtree
        postorderTraversal(root->right);

        // Print the data of the current node
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    int searchData = 40;
    struct Node *searchResult = searchNode(root, searchData);
    if (searchResult != NULL)
    {
        printf("%d found in the binary search tree.\n", searchData);
    }
    else
    {
        printf("%d not found in the binary search tree.\n", searchData);
    }

    printf("Minimum value in the binary search tree: %d\n", findMinNode(root)->data);
    printf("Maximum value in the binary search tree: %d\n", findMaxNode(root)->data);

    printf("Preorder traversal of the binary search tree: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the binary search tree: ");
    postorderTraversal(root);
    printf("\n");

    int deleteData = 30;
    root = deleteNode(root, deleteData);
    printf("Inorder traversal after deleting %d: ", deleteData);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
