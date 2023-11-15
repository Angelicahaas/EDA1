#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct Fila {
	Item *v;
	int tam, frente, inicio, fim;
}Fila;
 

int fila(Fila *f, int x) {
	f->tam = x;
	f->v = malloc(x * sizeof(Item));
	f->frente = 0;
	f->inicio = -1;
	f->fim = 0;
	return 1;
}


int fila_vazia(Fila *f) {
	return f->inicio == 0;
}

Item frente(Fila *f) {
	return f->v[(f->inicio+1) % f->tam];
}

int nafila(Fila *f, Item e) {
	if (f->frente >= f->tam) return 0;
	f->v[f->fim++] = e;
	f->fim = f->fim % f->tam;
	f->frente++;
	return 1;
}

void infila(Fila *f) {
	f->frente--;
	f->inicio = (f->inicio+1) % f->tam;
}

int main() {
	int p, r, ntest = 1;
	scanf("%d %d", &p, &r);
	Fila f;
	while (p !=0 || r != 0) {
		int xp;
		fila(&f, p);
		for (int i = 0; i < p; i++) {
			scanf("%d", &xp);
			nafila(&f, xp);
		}
		int j, ai;
		for (int i = 0; i < r; i++) {
			scanf("%d %d", &p, &j);
			for(int k = 0; k < p; k++) {
				Item temp = frente(&f);
				infila(&f);
				scanf("%d", &ai);
				if (ai == j)
				nafila(&f, temp);
			}
		}
		printf("Teste %d\n", ntest++);
		printf("%d\n", frente(&f));
		scanf("%d %d", &p, &r);
	}
	return 0;
}