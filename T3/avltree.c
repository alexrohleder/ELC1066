
#include <stdlib.h>
#include <stdio.h>

#include "avltree.h"

int arv_max(int x, int y)
{
	return x > y ? x : y;
}

int arv_height(arv_t *arv)
{
	if (arv == NULL) {
        return 0;
	}

    return arv->height;
}

int arv_balance_factor(arv_t *arv)
{
	if (arv == NULL) {
		return 0;
	}

	return arv_height(arv->left) - arv_height(arv->right);
}

arv_t *arv_new(int v)
{
	arv_t *arv = (arv_t*) malloc(sizeof(arv_t));

    arv->value  = v;
    arv->left   = NULL;
    arv->right  = NULL;
    arv->height = 1;
    
    return arv;
}

arv_t *arv_rotate_right(arv_t *arv)
{
    arv_t *l = arv->left;
    arv_t *r = l->right;
 
    l->right = arv;
    arv->left = r;
 
    arv->height = arv_max(arv_height(arv->left), arv_height(arv->right)) + 1;
    l->height = arv_max(arv_height(l->left), arv_height(l->right)) + 1;
 
    return l;
}

arv_t *arv_rotate_left(arv_t *arv)
{
    arv_t *r = arv->right;
    arv_t *l = r->left;

    r->left = arv;
    arv->right = l;
 
    arv->height = arv_max(arv_height(arv->left), arv_height(arv->right)) + 1;
    r->height = arv_max(arv_height(r->left), arv_height(r->right)) + 1;
 
    return r;
}

arv_t *arv_insert(arv_t *arv, int key)
{
    if (arv == NULL) {
        return arv_new(key);
    }
 
    if (key < arv->value) {
        arv->left  = arv_insert(arv->left, key);
    } else {
        arv->right = arv_insert(arv->right, key);
    }
 
    arv->height = arv_max(arv_height(arv->left), arv_height(arv->right)) + 1;
 
    int balance = arv_balance_factor(arv);
 
    if (balance > 1 && key < arv->left->value) {
        return arv_rotate_right(arv);
    }
 
    if (balance < -1 && key > arv->right->value) {
        return arv_rotate_left(arv);
    }

    if (balance > 1 && key > arv->left->value) {
        arv->left = arv_rotate_left(arv->left);
        return arv_rotate_right(arv);
    }

    if (balance < -1 && key < arv->right->value) {
        arv->right = arv_rotate_right(arv->right);
        return arv_rotate_left(arv);
    }

    return arv;
}

arv_t *arv_remove(arv_t *arv, int key)
{
    if (arv == NULL) {
        return arv;
    }
 
    if (key < arv->value) {
        arv->left = arv_remove(arv->left, key);
    } else {
    	if (key > arv->value) {
        	arv->right = arv_remove(arv->right, key);
    	} else {
    		if (arv->left == NULL || arv->right == NULL) {
	            arv_t *temp = arv->left ? arv->left : arv->right;
	 
	            if(temp == NULL) {
	                temp = arv;
	                arv = NULL;
	            } else{
	            	*arv = *temp;
	            }
	 
	            free(temp);
	        } else {
	            arv_t *temp = arv_search_min(arv->right);
	            arv->value = temp->value;
	            arv->right = arv_remove(arv->right, temp->value);
	        }
    	}
    }
 
    if (arv == NULL) {
      return arv;
    }
 
    arv->height = arv_max(arv_height(arv->left), arv_height(arv->right)) + 1;
 
    int balance = arv_balance_factor(arv);
 
    if (balance > 1 && arv_balance_factor(arv->left) >= 0) {
        return arv_rotate_right(arv);
    }

    if (balance > 1 && arv_balance_factor(arv->left) < 0) {
        arv->left = arv_rotate_left(arv->left);
        return arv_rotate_right(arv);
    }

    if (balance < -1 && arv_balance_factor(arv->right) <= 0) {
        return arv_rotate_left(arv);
    }

    if (balance < -1 && arv_balance_factor(arv->right) > 0) {
        arv->right = arv_rotate_right(arv->right);
        return arv_rotate_left(arv);
    }
 
    return arv;
}

arv_t *arv_search(arv_t *arv, int v)
{
	if (arv == NULL) {
		return NULL;
	}

	if (v < arv->value) {
		return arv_search(arv->left, v);
	} else {
		if (v > arv->value) {
			return arv_search(arv->right, v);
		}
	}

	return arv;
}

arv_t *arv_search_min(arv_t *arv)
{
	arv_t* current = arv;
 
    while (current->left != NULL) {
        current = current->left;
    }
 
    return current;
}

arv_t *arv_search_max(arv_t *arv)
{
	arv_t* current = arv;
 
    while (current->right != NULL) {
        current = current->right;
    }
 
    return current;
}

void arv_print_pre(arv_t *arv)
{
	if (arv != NULL) {
		printf("%d ", arv->value);
		arv_print_pre(arv->left);
		arv_print_pre(arv->right);
	}
}

void arv_print_in(arv_t *arv)
{
	if (arv != NULL) {
		arv_print_in(arv->left);
		printf("%d ", arv->value);
		arv_print_in(arv->right);
	}
}

void arv_print_pos(arv_t *arv)
{
	if (arv != NULL) {
		arv_print_pos(arv->left);
		arv_print_pos(arv->right);
		printf("%d ", arv->value);
	}
}
