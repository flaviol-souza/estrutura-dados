#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *newNode(int data)
{
    NODE *node;
    node = malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

NODE *insert(NODE *node, int data)
{
    if (node == NULL)
    {
        node = newNode(data);
        return node;
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    return node;
}

NODE *delete (NODE *node, int data)
{
    if (node == NULL)
        return NULL;
    else if (node->data > data)
        node->left = delete (node->left, data);
    else if (node->data < data)
        node->right = delete (node->right, data);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            node = NULL;
        }
        else if (node->left == NULL)
        {
            NODE *n = node;
            node = node->right;
            free(n);
        }
        else if (node->right == NULL)
        {
            NODE *n = node;
            node = node->left;
            free(n);
        }
        else
        {
            NODE *n = node->left;
            while (n->right != NULL)
            {
                n = n->right;
            }
            node->data = n->data;
            n->data = data;
            node->left = delete (node->left, data);
        }
    }
    return node;
}

NODE *search(NODE *node, int value)
{
    if (node != NULL)
    {
        if (value == node->data)
        {
            return node;
        }
        else if (value < node->data)
        {
            return search(node->left, value);
        }
        else if (value > node->data)
        {
            return search(node->right, value);
        }
    }

    return NULL;
}

int height(NODE *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}

int countMax(NODE *node)
{
    int h;
    h = height(node);
    return pow(2, h) - 1;
}

int count(NODE *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count(node->left) + count(node->right);
    }
}

void printPreOrder(NODE *node)
{
    if (node != NULL)
    {
        printf("%i\n", node->data);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void printInOrder(NODE *node)
{
    if (node != NULL)
    {
        printInOrder(node->left);
        printf("%i\n", node->data);
        printInOrder(node->right);
    }
}

void printPostOrder(NODE *node)
{
    if (node != NULL)
    {
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%i\n", node->data);
    }
}

void padding(char ch, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        putchar(ch);
    }
}

void printTree(NODE *node, int level)
{
    if (node == NULL)
    {
        padding('\t', level);
        puts("~");
    }
    else
    {
        printTree(node->right, level + 1);
        padding('\t', level);
        printf("%d\n", node->data);
        printTree(node->left, level + 1);
    }
}

int main()
{
    NODE *root = NULL;
    int h, countNodes, maxNode;
    root = insert(root, 14);
    insert(root, 4);
    insert(root, 15);
    insert(root, 3);
    insert(root, 9);
    insert(root, 18);
    insert(root, 7);
    insert(root, 16);
    insert(root, 5);
    insert(root, 17);
    insert(root, 20);

    h = height(root);
    countNodes = count(root);
    maxNode = countMax(root);

    printf("The Binary Tree is %i tall and has %i nodes (%i at most).\n\n", h, countNodes, maxNode);
    printTree(root, 0);
    printf("\n\n\n");

    delete (root, 18);
    printTree(root, 0);
    return 0;
}