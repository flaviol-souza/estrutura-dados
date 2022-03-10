#include <stdio.h>
#include <stdlib.h>
/* FILA (por ARRANJADORES) --- Created on Mar 05 2022
 *  AUTHOR : Flavio Souza
 *  DESCRIPTION :
 *       Implementação de uma fila, por meio de arranjadores (array), com as operações básicas.
 */
#define MAXTAM 10

typedef struct
{
    int values[MAXTAM];
    int first, last;
} QUEUE;

void init(QUEUE *queue)
{
    queue->first = 0;
    queue->last = queue->first;
}

int isEmpty(QUEUE queue)
{
    return (queue.first == queue.last && queue.first == 0);
}

void insert(QUEUE *queue, int value)
{
    if (queue->last == MAXTAM)
    {
        printf(" Erro fila esta cheia\n");
        return;
    }

    queue->values[queue->last] = value;
    queue->last++;
}

int retrive(QUEUE *queue)
{
    int value;
    if (isEmpty(*queue))
    {
        printf("Erro fila esta vazia\n");
        return '\0';
    }
    value = queue->values[queue->first];
    queue->first++;

    if (queue->first == MAXTAM)
    {
        queue->first = 0;
        queue->last = 0;
    }

    return value;
}

void print(QUEUE queue)
{
    int aux;
    if (isEmpty(queue))
    {
        printf("\n A fila esta vazia.");
        return;
    }
    printf("\nFILA:\n\t");
    for (aux = queue.first; aux <= (queue.last - 1); aux++)
    {
        printf(" %i", queue.values[aux]);
    }
}

QUEUE *justPositive(QUEUE *queue)
{
    /*Dada uma fila de inteiros, escreva um programa que exclua todos os números negativos
    sem alterar a posição dos outros elementos da fila.

      Ex.1:
            queue -> 1 -5 -9 10 19 2 -21 19 -4 -6 8
            output -> 1 10 19 2 19
       Ex.2:
            stack -> -4 -7 -9 -2 7 11 -8 39 78 -9 81 47
            output -> 7 11 39 78 81 47
    */

    return NULL;
}

int main()
{
    QUEUE fila;

    init(&fila);

    insert(&fila, 1);
    insert(&fila, -9);
    insert(&fila, 21);
    print(fila);

    retrive(&fila);
    print(fila);

    insert(&fila, 10);
    print(fila);

    retrive(&fila);
    retrive(&fila);
    print(fila);

    return 0;
}