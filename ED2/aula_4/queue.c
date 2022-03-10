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
    char values[MAXTAM];
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

void insert(QUEUE *queue, char value)
{
    if (queue->last == MAXTAM)
    {
        printf(" Erro fila esta cheia\n");
        return;
    }

    queue->values[queue->last] = value;
    queue->last++;
}

char retrive(QUEUE *queue)
{
    char value;
    if (isEmpty(*queue))
    {
        printf("Erro fila esta vazia\n");
        return '\0';
    }
    value = queue->values[queue->first];
    queue->first++;

    if(queue->first == MAXTAM){
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
        printf(" %c", queue.values[aux]);
    }
}

int main()
{
    QUEUE fila;

    init(&fila);

    insert(&fila, 'A');
    insert(&fila, 'B');
    insert(&fila, 'C');
    print(fila);

    retrive(&fila);
    print(fila);

    insert(&fila, 'D');
    print(fila);

    retrive(&fila);
    retrive(&fila);
    print(fila);

    return 0;
}