#include <stdio.h>
#include <stdlib.h>
/* FILA CIRCULAR (por ARRANJADORES) --- Created on Mar 05 2022
 *  AUTHOR : Flavio Souza
 *  DESCRIPTION :
 *       Implementação de uma fila circular, por meio de arranjadores (array), com as operações básicas.
 */
#define MAXTAM 3

typedef struct
{
    char values[MAXTAM];
    int idx_last, idx_first;
} QUEUE;

void init(QUEUE *queue)
{
    queue->idx_last = 0;
    queue->idx_first = 0;
}

int isEmpty(QUEUE queue)
{
    return (queue.idx_last == 0 && queue.idx_first == 0);
}

void insert(QUEUE *queue, char value)
{
    if (queue->idx_last + 1 == queue->idx_first || (queue->idx_last == MAXTAM && queue->idx_first == 0))
    {
        printf("Erro fila esta cheia\n");
        return;
    }

    if (queue->idx_last >= MAXTAM && queue->idx_first != 0)
    {
        queue->idx_last = 0;
    }
    queue->values[queue->idx_last] = value;
    queue->idx_last++;
}

char retrive(QUEUE *queue)
{
    char value;
    if (isEmpty(*queue))
    {
        printf("Erro fila esta vazia\n");
        return '\0';
    }

    value = queue->values[queue->idx_first];
    queue->idx_first++;

    if (queue->idx_first >= MAXTAM && queue->idx_last != 0)
    {
        queue->idx_first = 0;
    }

    return value;
}

void print(QUEUE queue)
{
    int aux, index, size;

    if (isEmpty(queue))
    {
        printf("Erro fila esta vazia\n");
        return;
    }
    size = MAXTAM;
    if (queue.idx_first > queue.idx_last)
    {
        size = MAXTAM - queue.idx_last;
    }
    else if (queue.idx_last > queue.idx_first)
    {
        size = queue.idx_last - queue.idx_first;
    }
    index = queue.idx_first;

    printf("\nFILA:\n\t");
    for (aux = 1; aux <= size; aux++)
    {
        if (index >= MAXTAM)
        {
            index = 0;
        }
        printf(" %c", queue.values[index]);
        index++;
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

    insert(&fila, 'E');
    print(fila);

    return 0;
}