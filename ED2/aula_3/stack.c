#include <stdio.h>
#include <stdlib.h>
/* PILHA (por Apontadores) --- Created on Feb 19 2022
 *  AUTHOR : Flavio Souza
 *  DESCRIPTION :
 *       Implementação de uma pilha, por meio de apontadores, com as operações básicas.
 */
#define MAX 100

typedef struct cell
{
    char value;
    struct cell *next;
} CELL;

typedef struct
{
    CELL *top;
    int size;
} STACK;

void init(STACK *stack)
{
    stack->top = malloc(sizeof(CELL));
    stack->top->next = NULL;
    stack->size = 0;
}

int isEmpty(STACK *stack)
{
    return (stack->top == NULL || stack->top->next == NULL);
}

void push(char x, STACK *stack)
{
    CELL *aux;
    aux = malloc(sizeof(CELL));
    stack->top->value = x;
    aux->next = stack->top;
    stack->top = aux;
    stack->size++;
}

char pop(STACK *stack)
{
    CELL *c;
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

int size(STACK stack)
{
    return (stack.size);
}

void print(STACK *stack)
{

    int size;
    CELL *c;
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
        if(c->next->next != NULL)
        {
            printf("\n |");
        }
        
        c = c->next;
        size--;
    }
}

STACK *subStack(STACK *stack, char value)
{
    /*A considerar uma pilha (stack) e um valor (E),
      construa uma função capaz de extrair uma subpilha
      da pilha principal tendo o valor como base da subpilha.
      Ex.1:
            stack -> IFSP-CTD-ED2 (no qual I é a base da pilha e 2 é o topo)
            value -> E
            output -> ED2
       Ex.2:
            stack -> IFSP-CTD-ED2 (no qual I é a base da pilha e 2 é o topo)
            value -> T
           output -> TD-ED2
    */
   return NULL;
}

int main()
{
    STACK myStack;

    init(&myStack);

    push('A', &myStack);
    push('B', &myStack);
    push('C', &myStack);
    print(&myStack);

    pop(&myStack); /*recupera C*/
    print(&myStack);

    push('F', &myStack);
    print(&myStack);

    pop(&myStack); /*recupera F*/
    pop(&myStack); /*recupera B*/
    pop(&myStack); /*recupera A*/
    print(&myStack);

    return 1;
}