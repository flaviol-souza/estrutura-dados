#ifndef _LIST_H
#define _LIST_H

#define MAXTAM 1000

#include "structure.h"

typedef struct _queue
{
    NODE **values;
    int first, last;
} QUEUE;

void initQueue(QUEUE *queue);
int isEmpty(QUEUE queue);
void insertQueue(QUEUE *queue, int value);
int retrive(QUEUE *queue);
void printQueue(QUEUE queue);

#endif