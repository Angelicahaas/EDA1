#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    celula *pl = le->prox;
    for (; pl != NULL; pl = pl->prox) {
        printf("%d -> ", pl->dado);
}
    printf("NULL\n");
}

void imprime_rec(celula *le) {
    celula *pl = le;
    if (pl== NULL) {
        printf("NULL\n");
        return;
    } else {
        printf("%d -> ", pl->dado);
    }
        imprime_rec(pl->prox);
    return;
}
