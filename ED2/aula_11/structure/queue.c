#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void initQueue(QUEUE *queue)
{
    queue->first = 0;
    queue->last = queue->first;
}

int isEmpty(QUEUE queue)
{
    return (queue.first == queue.last && queue.first == 0);
}

void insertQueue(QUEUE *queue, int value)
{
    if (queue->last == MAXTAM)
    {
        printf(" Erro fila esta cheia\n");
        return;
    }
    NODE *node;
    node = malloc(sizeof(NODE));
    node->value = value;
    queue->values[queue->last] = node;
    queue->last++;
}

int retrive(QUEUE *queue)
{
    NODE *node;
    if (isEmpty(*queue))
    {
        printf("Erro fila esta vazia\n");
        return '\0';
    }
    node = queue->values[queue->first];
    queue->first++;

    if (queue->first == MAXTAM)
    {
        queue->first = 0;
        queue->last = 0;
    }

    return node->value;
}

void printQueue(QUEUE queue)
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