#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void empilha(celula *p, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    if (nova_celula == NULL) {
        exit(EXIT_FAILURE);
    }

    nova_celula->dado = x;
    nova_celula->prox = p->prox;
    p->prox = nova_celula;
}

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) {
        // Pilha vazia
        return 0;
    }

    celula *celula_removida = p->prox;
    *y = celula_removida->dado;
    p->prox = celula_removida->prox;
    free(celula_removida);

    return 1;
}