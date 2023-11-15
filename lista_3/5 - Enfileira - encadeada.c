#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula* enfileira(celula *f, int x) {
    celula *new_no = (celula*)malloc(sizeof(celula));
    new_no->prox = f->prox;
    f->prox = new_no;
    f->dado = x;
    return new_no;
}