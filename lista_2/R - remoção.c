#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p){
    if (p == NULL || p->prox ==NULL){
        return 0;
    }
    celula *lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
    return 1;
}

void remove_elemento(celula *le, int x){
    celula *ant = le;
    celula *atual = le->prox;

    while(atual != NULL){
        if (atual->dado == x) {
            ant->prox = atual->prox;
            free(atual);
            atual = ant->prox;
            return;
        } else {
            ant = atual;
            atual = atual->prox;
        }
        
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *ant = le;
    celula *atual = le->prox;

    while(atual != NULL) {
        if (atual->dado == x) {
            ant->prox = atual->prox;
            free(atual);
            atual = ant->prox;
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
}