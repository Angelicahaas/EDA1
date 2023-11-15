#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y) {
    if (f == NULL || f->prox == NULL ) { // A fila está vazia
        return 0; // Retorna 0 para indicar que a remoção não foi bem-sucedida
   }

   celula *ant = f->prox;
   *y = ant->dado;
   f->prox = ant->prox;
   return 1;

}

