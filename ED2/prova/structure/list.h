#ifndef _LIST_H
#define _LIST_H

#include "structure.h"

typedef struct _list
{
    NODE *first;
    NODE *last;
} LIST;

void initList(LIST *list);
int isEmpty(LIST *list);
int insert(LIST *list, int value);
int delete(LIST *list, NODE *node);
NODE *searchList(LIST *list, int value);
int size(LIST *list);
void printNode(NODE *node);
void printList(LIST *list);

#endif