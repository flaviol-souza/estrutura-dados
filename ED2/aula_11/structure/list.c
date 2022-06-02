#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void initList(LIST *list)
{
    list->first = NULL;
    list->last = NULL;
}

int isEmpty(LIST *list)
{
    return (list->first == NULL);
}

int insert(LIST *list, int value)
{
    NODE *node;
    node = malloc(sizeof(NODE));
    if (node == NULL)
        return 0; /*False*/

    node->value = value;
    node->next = NULL;

    if (isEmpty(list) == 1)
    {
        list->first = node;
    }
    else
    {
        list->last->next = node;
    }

    list->last = node;

    return 1; /*True*/
}

int delete (LIST *list, NODE *n)
{
    NODE *node, *nodePrevious = NULL;
    if (isEmpty(list) == 1)
        return 0; /*False*/

    node = list->first;
    while (node != NULL)
    {
        if (node->value == nodePrevious->value && node->next == nodePrevious->next)
        {
            if (nodePrevious == NULL)
            {
                list->first = node->next;
            }
            else
            {
                nodePrevious->next = node->next;
            }
            free(node);
            break;
        }
        nodePrevious = node;
        node = node->next;
    }

    return 1; /*True*/
}

NODE *searchList(LIST *list, int value)
{
    NODE *node;
    if (isEmpty(list) == 1)
        return NULL; /*False*/

    node = list->first;
    while (node != NULL)
    {
        if (node->value == value)
        {
            return node;
        }
        else
        {
            node = node->next;
        }
    }
    return NULL;
}

int size(LIST *list)
{
    NODE *node;
    int cont = 0;
    node = list->first;

    while (node != NULL)
    {
        cont++;
        node = node->next;
    }
    return cont;
}

void printNode(NODE *node)
{
    if (node != NULL)
        printf("\n|V.: %i|P.: %p|", node->value, node->next);
}

void printList(LIST *list)
{
    /*Imprime os elementos na sua ordem de precedência*/
    if (isEmpty(list) == 1)
    {
        printf("\n\nA lista esta vazia\n\n");
    }
    else
    {
        NODE *node = list->first;
        int t = size(list);
        printf("\n\nA lista tem %i nos", t);

        while (node != NULL)
        {
            printNode(node);
            node = node->next;
        }
    }
    return;
}