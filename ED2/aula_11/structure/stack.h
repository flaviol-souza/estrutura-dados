#ifndef _STACK_H
#define _STACK_H

#include "structure.h"

typedef struct _stack
{
    NODE *top;
    int size;
} STACK;

void initStack(STACK *list);
int isEmpty(STACK *list);
int size(STACK stack);
void push(STACK *stack, char x);
char pop(STACK *stack);
void printStack(STACK *stack);

#endif