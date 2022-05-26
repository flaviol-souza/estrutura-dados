#include <stdio.h>
#include <stdlib.h>

typedef struct vertex
{
    int value;
    struct vertex *next;
} VERTEX;

typedef struct graph
{
    int value;
    VERTEX *edges;
    struct graph *next;
} GRAPH;

VERTEX *initVertex(int value)
{
    VERTEX *vertex = malloc(sizeof(VERTEX));
    vertex->value = value;
    vertex->next = NULL;
    return vertex;
}

GRAPH *initGraph(int value)
{
    GRAPH *graph = (GRAPH *)malloc(sizeof(GRAPH));
    graph->value = value;
    graph->next = NULL;
    graph->edges = NULL;
    return graph;
}

GRAPH *search(GRAPH *graph, int value)
{
    while ((graph != NULL) && (graph->value != value))
    {
        graph = graph->next;
    }
    return graph;
}

VERTEX *searchEgde(GRAPH *graph, int value_a, int value_b)
{
    GRAPH *head = search(graph, value_a);
    VERTEX *edge = NULL;
    if (head != NULL)
    {
        edge = head->edges;
        while ((edge != NULL) && (edge->value != value_b))
        {
            edge = edge->next;
        }
    }
    return edge;
}

GRAPH *insert(GRAPH *graph, int value)
{
    GRAPH *head = search(graph, value);
    if (head == NULL)
    {
        head = initGraph(value);
        head->next = graph;
    }
    return head;
}

void insertEdgeWay(GRAPH *graph, int value_a, int value_b)
{
    GRAPH *head = search(graph, value_a);
    VERTEX *egde = initVertex(value_b);
    egde->next = head->edges;
    head->edges = egde;
}

void insertEdge(GRAPH *graph, int value_a, int value_b)
{
    VERTEX *vertex = searchEgde(graph, value_a, value_b);
    if (vertex == NULL)
    {
        insertEdgeWay(graph, value_a, value_b);
        insertEdgeWay(graph, value_b, value_a);
    }
}

void delete(GRAPH *graph, int value)
{
    GRAPH *previous = NULL;
    while ((graph != NULL) && (graph->value != value))
    {
        previous = graph;
        graph = graph->next;
    }
    if (graph != NULL)
    {
        if (previous != NULL)
        {
            previous->next = graph->next;
        }
        free(graph->edges);
        free(graph);
    }
}

void deleteEgdeWay(GRAPH *graph, int value_a, int value_b)
{
    GRAPH *head = search(graph, value_a);
    if (head != NULL)
    {
        VERTEX *ant = NULL;
        VERTEX *current = head->edges;
        while ((current) && (current->value != value_b))
        {
            ant = current;
            current = current->next;
        }
        if (ant == NULL)
        {
            head->edges = current->next;
        }
        else
        {
            ant->next = current->next;
        }
        free(current);
    }
}

void deleteEgde(GRAPH *graph, int value_a, int value_b)
{
    VERTEX *edge = searchEgde(graph, value_a, value_b);
    if (edge != NULL)
    {
        deleteEgdeWay(graph, value_a, value_b);
        deleteEgdeWay(graph, value_b, value_a);
    }
}

void print(GRAPH *graph)
{
    GRAPH *current = graph;
    VERTEX *edge = NULL;
    while (graph != NULL)
    {
        printf("\n | %i | ->", current->value);
        edge = current->edges;
        while (edge != NULL)
        {
            printf(" | %i |->", edge->value);
            edge = edge->next;
        }
        printf(" NULL");
        current = current->next;
    }
}

int qtdVertex(GRAPH *graph){
    ///Dado um grafo (GRAPH) calcule a quantidade de vertices, cuidado com a repetição para grafos não direcionados
}

int equalsGraph(GRAPH *graph_a, GRAPH *graph_b){
    ///Dado dos grafos, implemene um algoritmo que vefique se são eguais, cuidados com os grafos direcionados
}

int main()
{
    GRAPH *graph = initGraph(4);
    graph = insert(graph, 1);
    graph = insert(graph, 2);
    graph = insert(graph, 3);

    insertEdge(graph,1,3);
    insertEdge(graph,1,4);
    insertEdge(graph,2,4);

    deleteEgde(graph, 4, 2);

    delete (graph, 1);
    print(graph);

    return 0;
}
