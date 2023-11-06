#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *n_celula = (celula *)malloc(sizeof(celula));
    if (n_celula == NULL) {
        exit(1);
    }

    n_celula->dado = x;
    n_celula->prox = le->prox;
    le->prox = n_celula;
}

void insere_antes(celula *le, int x, int y) {
    celula *n_celula = (celula *)malloc(sizeof(celula));
    if (n_celula == NULL) {
        exit(1);
    }

    celula *atual = le->prox;
    celula *ant = le;

    while (atual != NULL && atual->dado != y) {
        ant = atual;
        atual = atual->prox;
    }

    n_celula->dado = x;
    n_celula->prox = atual;
    ant->prox = n_celula;
}
