
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void main()
{
	graph_t *graph = graph_init();

	int i, j, x, y;

/**
	scanf("%d", &graph->nvertices);
	j = graph->nvertices;

	for (i = 0; i < j; i++)
	{
		scanf("%d %d", &x, &y);

		graph_insert_edge(graph, x, y);
	}
**/
		graph->nvertices = 7;
		graph_insert_edge(graph, 1, 2);
		graph_insert_edge(graph, 1, 3);
		graph_insert_edge(graph, 1, 4);
		graph_insert_edge(graph, 2, 3);
		graph_insert_edge(graph, 4, 5);
		graph_insert_edge(graph, 5, 6);

	graph_print(graph);

	printf("\n");

	//printf("minimo: de 1 ao 5 é %d\n\n", graph_minimum_path(graph, 1, 5));
}
