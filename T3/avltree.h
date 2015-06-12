
#include <stdlib.h>

typedef struct arv {
	int value;
	int height;

	struct arv *left;
	struct arv *right;
} arv_t;

int arv_max(int x, int y);
int arv_height(arv_t *arv);
int arv_balance_factor(arv_t *arv);
arv_t *arv_new(int v);
arv_t *arv_rotate_right(arv_t *arv);
arv_t *arv_rotate_left(arv_t *arv);
arv_t *arv_insert(arv_t *arv, int v);
arv_t *arv_remove(arv_t *arv, int v);
arv_t *arv_search(arv_t *arv, int v);
arv_t *arv_search_min(arv_t *arv);
arv_t *arv_search_max(arv_t *arv);
void arv_print_pre(arv_t *arv);
void arv_print_in(arv_t *arv);
void arv_print_pos(arv_t *arv);
