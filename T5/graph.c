
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

bool flag = false;
bool visited[10] = {false, false, false, false, false, false, false, false, false, false};

graph_t *graph_init()
{
	graph_t *n = malloc(sizeof(graph_t));

	n->nvertices = 4;
	n->vertices = (vertice_t **) malloc(10 * sizeof(vertice_t *));

	return n;
}

vertice_t *vertice_init(int v)
{
	vertice_t *n = malloc(sizeof(vertice_t));

	n->v = v;
	n->next = NULL;

	return n;
}

void graph_add_vertice(graph_t *g, vertice_t *v)
{
	g->vertices[g->nvertices] = v;
	g->nvertices++;
}

void graph_add_edge(graph_t *g, int s, int v)
{
    vertice_t *aux = malloc(sizeof(vertice_t));
    
    aux->v = v;
    aux->next = g->vertices[s];

    g->vertices[s] = aux;
}

void _graph_is_cycle_aux(int x, graph_t *g)
{
	if (visited[x] == true) {
	   flag = true;
	} else {
		visited[x] = true;
		vertice_t *aux = g->vertices[x];

		while (aux) {
		    _graph_is_cycle_aux(aux->v, g);
		    aux = aux->next;
		}
   	}
}

bool graph_is_cycle(int x, graph_t *g)
{
	int i = 0;

	for (; i < 10; i++) visited[i] = false;

	_graph_is_cycle_aux(x, g);

	return flag;
}

void main()
{
	graph_t *g = graph_init();
	
	graph_add_vertice(g, vertice_init(0));
	graph_add_vertice(g, vertice_init(1));
	graph_add_vertice(g, vertice_init(2));
	graph_add_vertice(g, vertice_init(3));

	graph_add_edge(g, 0, 1);
	graph_add_edge(g, 0, 2);
	graph_add_edge(g, 1, 2);
	graph_add_edge(g, 2, 3);
	graph_add_edge(g, 2, 0);
	graph_add_edge(g, 3, 3);

	if (graph_is_cycle(2, g)) {
		printf("O grafo é circular.\n");
	} else {
		printf("O grafo não é circular.\n");
	}
}