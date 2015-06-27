#ifndef _GRAFO_H_
#define _GRAFO_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct _vertice {
    int v;
    struct _vertice* next;
} vertice_t;

vertice_t *vertice_init(int i);

typedef struct _graph {
    int nvertices;
    vertice_t **vertices;
} graph_t;

graph_t *graph_init(void);
void graph_add_vertice(graph_t *g, vertice_t *v);
void graph_add_edge(graph_t *g, int v1, int v2);
bool graph_is_cycle(int x, graph_t *g);

#endif
