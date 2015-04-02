#include <stdio.h>
#include <stdlib.h>

struct lista{
	int v;
	struct lista* p;
};

typedef struct lista Lista;

Lista* inicializa(){
	return NULL;
}

Lista* insere(Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->v = i;
	novo->p = l;
	return novo;
}

void imprime(Lista* l){
	Lista* p;
	for(p = l; p != NULL; p = p->p){
		printf("%d\n", p->v);
	}
}

Lista* concatena(Lista* l1, Lista* l2) {
	Lista* r = l1;


	return r;
}

Lista* inverte(Lista* l) {
	Lista* proxima;
	Lista* anterior = NULL;

    	while(l != NULL) {
        	proxima = l->p;
		l->p = anterior;
		anterior = l;
		l = proxima;
    	}
	
	return anterior;
}

int minimo(Lista* l) {
	int proximo, atual = l->v;

	if (l->p == NULL) {
		return atual;
	}

	proximo = minimo(l->p);

	if (proximo < atual) {
		return proximo;
	} else  return atual;
}

void meio(Lista* l) {
	Lista* pp = l;
	Lista* p = l;

	while (pp != NULL) {
		pp = pp->p, pp = pp->p;
		p = p->p;
	}

	printf("O elemento do meio ou mais próximo dele é %d.\n", p->v);
}

void main() {
	Lista* l1; /* declara uma lista não iniciada */
    	l1 = inicializa(); /* inicia lista vazia */
    	l1 = insere(l1, 23); /* insere na lista o elemento 23 */
    	l1 = insere(l1, 45); /* insere na lista o elemento 45 */
    	l1 = insere(l1, 56); /* insere na lista o elemento 56 */
    	l1 = insere(l1, 78); /* insere na lista o elemento 78 */
	
	Lista* l2;
	l2 = inicializa();
	l2 = insere(l2, 4);
	l2 = insere(l2, 3);
	l2 = insere(l2, 2);
	l2 = insere(l2, 1);

	meio(l1);
	printf("O menor valor de é: %d\n", minimo(l1));

	printf("Invertendo a lista:\n");
	imprime(inverte(l1));

	printf("Lista Concatenada:\n");
	Lista* l3;
	l3 = concatena(l1, l2);
	imprime(l3);
}



