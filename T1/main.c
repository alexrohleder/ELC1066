#include <stdio.h>

#include "matdin.h"

void main () {
	Matriz * mat = cria(4, 4);
	
	atribui(mat, 0, 0, 0.5);
	atribui(mat, 0, 1, 0.6);
	atribui(mat, 0, 2, 0.7);
	atribui(mat, 0, 3, 0.8);
	atribui(mat, 1, 0, 0.4);
	atribui(mat, 1, 1, 0.3);
	atribui(mat, 1, 2, 0.2);
	atribui(mat, 1, 3, 0.1);

	Matriz * transposta = transpor(mat, 4, 4);

	imprime(mat);
	printf("\n Transposta: \n");
	imprime(transposta);
}

