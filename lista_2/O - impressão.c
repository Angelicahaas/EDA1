#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    celula *pl;
    for (pl = le->prox; pl != NULL; pl = pl->prox) {
        printf("%d ->", pl->dado);
    }
    printf("NULL\n");
}

void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    } else {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
}