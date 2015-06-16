
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

graph_t *graph_init(graph_t *g)
{
	graph_t *n = (graph_t*) malloc(sizeof(graph_t));
	int i = 0, j = 0;

	for (i = 0; i < 50; i++) {
		n->vertices[i] = 0;

		for (j = 0; j < 50; j++) {
			n->edges[i][j] = 0;
		}
	}

	return n;
}

graph_t *graph_insert_edge(graph_t *g, int x, int y)
{
	g->edges[x][g->vertices[x]] = y;
	g->vertices[x]++;

    g->edges[y][g->vertices[y]] = x;
    g->vertices[y]++;

    g->nedges++;

	return g;
}

void graph_print(graph_t *g)
{
	int i = 0, j = 0, k = 0;

	for (i = 0; i < g->nvertices; i++) {
		if (g->vertices[i] > 0) {
			printf("%d:", i);

			for (j = 0; j < g->nvertices; j++) {
				printf(" %d", g->edges[i][j]);
			}

			printf("\n");
		}
	}
}

void a(int z[50], int t)
{
	int i = 0;

	for(; i<t;i++){
		printf("%d ", z[i]);
	}

	printf("\n");
}

int _graph_minimum_path(graph_t *g, int x, int y, int z[50], int t)
{
	int i, j, k;

	// se tiver ligação direta então o retorno é 1
	for (i = 0; i < g->nedges; i++) {
		if (g->edges[x][i] == y) {
			return 1;
		}
	}

	// passa por todas as edges procurando por um caminho.
	for (i = 0; i < g->nedges; i++) {
		// caso aquele vertice já tenha sido visitado ele é descartado neste loop.
		for (j = 0; j < t; j++) {
			if (z[j] == g->edges[x][i]) {
				i++; break;
			}
		}

		// registra o vertice que a edge atual aponta.
		z[t] = g->edges[x][i];
		t++;

		// chama a função de calcular o mínimo no vertice atual.
		k = _graph_minimum_path(g, g->edges[x][i], y, z, t);

		// caso o retorno seja maior que 0 então ele achou algo
		if (k > 0) {
			return k;
		}
	}

	return 0;
}

int graph_minimum_path(graph_t *g, int x, int y)
{
	int z[50], i = 0;

	for (; i < 50; i++) {
		z[i] = 0;
	}

	return _graph_minimum_path(g, x, y, z, 0);
}
