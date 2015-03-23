#include <stdio.h>
#include <stdlib.h>

#include "matdin.h"

Matriz * cria(int lin, int col) {
	Matriz * mat = (Matriz *) malloc(sizeof(Matriz));

	mat->lin = lin;
	mat->col = col;
	mat->v   = (float **) malloc(mat->lin * sizeof(float *));

	int i;
	for (i = 0; i < lin; i++) {
		mat->v[i] = (float *) malloc(col * sizeof(float));
	}

	return mat;
}

void libera(Matriz * mat) {
	int i, j;

	for (i = 0; i < mat->lin; i++) {
		free(mat->v[i]);
	}

	free(mat->v);
}

float acessa(Matriz * mat, int lin, int col) {
	return mat->v[lin][col];
}

void atribui(Matriz * mat, int lin, int col, float val) {
	mat->v[lin][col] = val;
}

void imprime(Matriz * mat) {
	int i, j;

	for (i = 0; i < mat->lin; i++) {
		printf("Linha: %d - ", i + 1);

		for (j = 0; j < mat->col; j++) {
			printf("%d: %.2f ", j + 1, mat->v[i][j]);
		}

		printf("\n");
	}
}

Matriz * transpor(Matriz * mat, int lin, int col) {
	int i, j;
	Matriz * rmat = cria(lin, col);

	for (i = 0; i < lin; i++) {
		for (j = 0; j < col; j++) {
			rmat->v[i][j] = mat->v[j][i];
		}
	}

	return rmat;
}

