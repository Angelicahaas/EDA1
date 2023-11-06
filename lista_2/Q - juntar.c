#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *l3_atual = l3;
    l1 = l1->prox;
    l2 = l2->prox;

    while (l1 != NULL && l2 != NULL) {
        if (l1->dado < l2->dado) {
            l3_atual->prox = l1;
            l1 = l1->prox;
        } else {
            l3_atual->prox =l2;
            l2 = l2->prox;
        }
        l3_atual = l3_atual->prox;
    }

    while (l1 != NULL) {
        l3_atual->prox = l1;
        l1 = l1->prox;
        l3_atual =l3_atual->prox;
    }

       while (l2 != NULL) {
        l3_atual->prox = l2;
        l2 = l2->prox;
        l3_atual =l3_atual->prox;
    }
    
    l3_atual->prox = NULL;
}