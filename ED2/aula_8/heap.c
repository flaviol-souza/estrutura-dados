#include <stdio.h>
#include <stdlib.h>
/* HEAP (por ARRANJADORES) --- Created on Abr 12 2022
 *  AUTHOR : Flavio Souza
 *  DESCRIPTION :
 *       Implementação de uma heap com as operações básicas.
 */

typedef struct node
{
    int priority;
} NODE;

typedef struct heap
{
    NODE *node;
    int n;
} HEAP;

HEAP *init(int n)
{
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    heap->node = (NODE *)malloc(sizeof(NODE *) * (n + 1));
    heap->n = 0;

    return heap;
}

void insert_seq(HEAP *heap, int priority)
{
    heap->n++;
    heap->node[heap->n].priority = priority;
}

void print(HEAP *heap)
{
    for (int i = 1; i <= heap->n; i++)
    {
        printf("%i \t", heap->node[i].priority);
    }
}

int root(int idx)
{
    return idx/2;
}

int left(int idx)
{
    return idx*2;
}

int right(int idx)
{
    return idx*2+1;
}

void swap(HEAP *heap, int idx_a, int idx_b)
{
    NODE temp = heap->node[idx_b];
    heap->node[idx_b] = heap->node[idx_a];
    heap->node[idx_a] = temp;
}

void down(HEAP *heap, int idx)
{
    int idx_left = left(idx);
    int idx_right = right(idx);
    int idx_major = idx;

    if (idx_left <= heap->n && heap->node[idx_left].priority > heap->node[idx].priority)
    {
        idx_major = idx_left;
    }
    if (idx_right <= heap->n && heap->node[idx_right].priority > heap->node[idx_major].priority)
    {
        idx_major = idx_right;
    }
    if (idx_major != idx)
    {
        swap(heap, idx_major, idx);
        down(heap, idx_major);
    }
}

void build(HEAP *heap)
{
    int i;
    int j = heap->n / 2;
    for (i = j; i >= 1; i--)
    {
        down(heap, i);
    }
}

void up(HEAP *heap, int idx)
{
    int j = root(idx);
    if (j >= 1)
    {
        if (heap->node[idx].priority > heap->node[j].priority)
        {
            swap(heap, j, idx);
            up(heap, j);
        }
    }
}

void insert(HEAP *heap, int new)
{
    heap->node = (NODE *)realloc(heap->node, sizeof(NODE) * (heap->n + 2));
    heap->n++;
    heap->node[heap->n].priority = new;
    up(heap, heap->n);
}

int delete (HEAP *heap)
{
    int major_priority = heap->node[1].priority;
    heap->node[1] = heap->node[heap->n];
    heap->n--;
    heap->node = (NODE *)realloc(heap->node, sizeof(NODE) * (heap->n + 1));
    down(heap, 1);
    return major_priority;
}

NODE *sort(HEAP *heap)
{
    /*implemente a função capaz de ordenar os NODEs da HEAP em uma sequencia crescente.*/
    return NULL;
}

int main(void)
{
    HEAP *heap;
    int n = 15;

    heap = init(n);
    insert_seq(heap, 92);
    insert_seq(heap, 85);
    insert_seq(heap, 90);
    insert_seq(heap, 47);
    insert_seq(heap, 71);
    insert_seq(heap, 34);
    insert_seq(heap, 20);
    insert_seq(heap, 40);
    insert_seq(heap, 46);

    printf("Vetor original...\n");
    print(heap);

    printf("\nConstruir a heap...\n");
    build(heap);
    print(heap);

    printf("\nInserir os elementos 98, 75, 43 \n");
    insert(heap, 98);
    insert(heap, 75);
    insert(heap, 43);
    print(heap);

    printf("\nRemover o elemento de maior prioridade \n");
    delete (heap);
    print(heap);

    int idx = 10;
    printf("\nAlterar no de prioridade %i para %i\n", heap->node[idx].priority, 93);
    heap->node[idx].priority = 93;
    up(heap, idx);
    print(heap);

    printf("\nDiminuir a prioridade da raiz de %i para 1.\n", heap->node[1]);
    heap->node[1].priority = 1;
    down(heap, 1);
    print(heap);

    return 0;
}