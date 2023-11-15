#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->prox = (*f)->prox;
    (*f)->prox = novaCelula;
    (*f)->dado = x;
    (*f) = novaCelula;
}

int desenfileira(celula **f, int *y) {
    celula *novaCelula = (*f)->prox;
    *y = novaCelula->dado;
    
    if (*f == novaCelula) {
        return 0;
    } else {
        (*f)->prox = novaCelula->prox;
        
    return 1;
    }
}
