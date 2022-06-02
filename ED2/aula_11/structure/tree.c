#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tree.h"

TREE *initTree(int value)
{
    TREE *node;
    node = malloc(sizeof(TREE));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TREE *insertTree(TREE *node, int value)
{
    if (node == NULL)
    {
        node = initTree(value);
        return node;
    }

    if (value < node->value)
    {
        node->left = insertTree(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = insertTree(node->right, value);
    }

    return node;
}

TREE *delete (TREE *node, int value)
{
    if (node == NULL)
        return NULL;
    else if (node->value > value)
        node->left = delete (node->left, value);
    else if (node->value < value)
        node->right = delete (node->right, value);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            node = NULL;
        }
        else if (node->left == NULL)
        {
            TREE *n = node;
            node = node->right;
            free(n);
        }
        else if (node->right == NULL)
        {
            TREE *n = node;
            node = node->left;
            free(n);
        }
        else
        {
            TREE *n = node->left;
            while (n->right != NULL)
            {
                n = n->right;
            }
            node->value = n->value;
            n->value = value;
            node->left = delete (node->left, value);
        }
    }
    return node;
}

TREE *search(TREE *node, int value)
{
    if (node != NULL)
    {
        if (value == node->value)
        {
            return node;
        }
        else if (value < node->value)
        {
            return search(node->left, value);
        }
        else if (value > node->value)
        {
            return search(node->right, value);
        }
    }

    return NULL;
}

int height(TREE *node)
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

int countMax(TREE *node)
{
    int h;
    h = height(node);
    return pow(2, h) - 1;
}

int count(TREE *node)
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

void printPreOrder(TREE *node)
{
    if (node != NULL)
    {
        printf("%i\n", node->value);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void printInOrder(TREE *node)
{
    if (node != NULL)
    {
        printInOrder(node->left);
        printf("%i\n", node->value);
        printInOrder(node->right);
    }
}

void printPostOrder(TREE *node)
{
    if (node != NULL)
    {
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%i\n", node->value);
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

void printTree(TREE *node, int level)
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
        printf("%d\n", node->value);
        printTree(node->left, level + 1);
    }
}