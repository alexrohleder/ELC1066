
#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void main()
{
	arv_t *root = NULL;
	arv_t *aux  = NULL;

	printf("*Utilizando o exemplo prático da apresentação de slides:\n");
	printf(" obs: exibição em pré ordem: raiz -> esq -> dir\n");

    root = arv_insert(root, 15);
    root = arv_insert(root, 27);
    root = arv_insert(root, 49);

	printf("\n**15 27 49: Rotação Simples a Esquerda -> ");
    arv_print_pre(root);

    root = arv_insert(root, 10);
    root = arv_insert(root,  8);

	printf("\n**10 08: Rotação Simples a Direita -> ");
    arv_print_pre(root);

    root = arv_insert(root, 67);
    root = arv_insert(root, 59);

	printf("\n**67 59: Rotação Dupla a Esquerda -> ");
    arv_print_pre(root);

    printf("\n\n**Teste de funções da biblioteca:\n");

 	printf("\n***arv_search(*, 27): ");
    aux = arv_search(root, 15);
    printf(aux == NULL ? "falha" : "sucesso");
 
 	printf("\n***arv_remove(15): ");
    root = arv_remove(root, 15);
    arv_print_pre(root);

    printf("\n\n");
}
