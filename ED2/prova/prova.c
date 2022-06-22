#include <stdio.h>
#include <stdlib.h>
#include "structure/list.h"
#include "structure/tree.h"

/*
*   Com base na árvore binária, implemente um algoritmo que popule uma lista encadeada de forma ordenada.
*   gcc prova.c structure\list.c structure\tree.c -o exec.exe -ansi -Wall -pedantic -std=c99 
*
*   INPUT:                  4
*                         /   \
*                        /     \
*                      2        6
*                    /   \     /  \
*                   1     3   5    10
*                                 /  
*                                8
* 
*
*  OUTPUT: 
*           |1|->|2|->|3|->|4|->|5|->|6|->|8|->|10|->NULL
*/

void assembleToList(LIST * list, TREE *node)
{
    /*SOLUCAO*/
    if (node != NULL)
    {
        assembleToList(list, node->left);
        insert(list, node->value);
        assembleToList(list, node->right);
    }
}

int main()
{
    TREE *root = NULL;
    LIST *list = malloc(sizeof(LIST));
    initList(list);
    root = insertTree(root, 4);
    insertTree(root, 2);
    insertTree(root, 6);
    insertTree(root, 1);
    insertTree(root, 3);
    insertTree(root, 5);
    insertTree(root, 10);
    insertTree(root, 8);

    assembleToList(list, root);
    printList(list);
    
    return 0;
}