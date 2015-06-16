
typedef struct graph {
	int edges[50][50], 
		vertices[50],
		nedges,
		nvertices;
} graph_t;

graph_t *graph_init();
graph_t *graph_insert_edge(graph_t *g, int x, int y);
void graph_print(graph_t *g);
int graph_minimum_path(graph_t *g, int x, int y);
