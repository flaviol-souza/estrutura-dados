#ifndef _TREE_H
#define _TREE_H

#include "structure.h"

typedef struct _tree
{
    int value;
    struct _tree *left;
    struct _tree *right;
} TREE;

TREE *initTree(int value);
TREE *insertTree(TREE *node, int value);
TREE *deleteNodeTree(TREE *node, int value);
TREE *search(TREE *node, int value);
int height(TREE *node);
int countMax(TREE *node);
int count(TREE *node);
void printPreOrder(TREE *node);
void printInOrder(TREE *node);
void printPostOrder(TREE *node);
void printTree(TREE *node, int level);

#endif