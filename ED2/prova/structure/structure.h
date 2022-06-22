#ifndef _STRUCTURE_H
#define _STRUCTURE_H

typedef struct _node
{
    int type;
    int value;
    struct _node *next;
} NODE;

#endif