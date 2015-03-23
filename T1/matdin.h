
typedef struct {
	int lin, col;
	float ** v;
} Matriz;

Matriz * cria(int lin, int col);
void libera(Matriz * mat);
float acessa(Matriz * mat, int lin, int col);
void atribui(Matriz * mat, int lin, int col, float val);
void imprime(Matriz * mat);
Matriz * transpor(Matriz * mat, int lin, int col);

