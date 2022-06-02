#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define EMPTY '\0'

void initStack(STACK *stack)
{
    stack->top = malloc(sizeof(NODE));
    stack->top->next = NULL;
    stack->size = 0;
}

int isEmpty(STACK *stack)
{
    return (stack->top == NULL || stack->top->next == NULL);
}

int size(STACK stack)
{
    return (stack.size);
}

NODE *peek(STACK *stack){
    return stack->top;
}

void push(STACK *stack, char x)
{
    NODE *aux;
    aux = malloc(sizeof(NODE));
    aux->value = EMPTY;
    stack->top->value = x;
    aux->next = stack->top;
    stack->top = aux;
    stack->size++;
}

char pop(STACK *stack)
{
    NODE *c;
    char value;
    if (isEmpty(stack))
    {
        printf("Erro: pilha esta vazia\n");
        return '?';
    }
    c = stack->top;
    stack->top = c->next;
    value = c->next->value;

    free(c);

    stack->size--;

    return value;
}

void printStack(STACK *stack)
{

    int size;
    NODE *c;
    printf("\n\n - Stack Print");

    if (isEmpty(stack))
    {
        printf("\n\tStack is empty!");
        return;
    }

    size = stack->size;
    c = stack->top;
    while (c->next != NULL)
    {
        printf("\n|%i|%c|", size, c->next->value);
        if (c->next->next != NULL)
        {
            printf("\n |");
        }

        c = c->next;
        size--;
    }
}