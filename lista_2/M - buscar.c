#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


celula *busca(celula *le, int x) {
    celula *atual = le->prox; 

    while (atual != NULL) {
        if (atual->dado == x) {
            return atual; // Encontrou o elemento, retorna o ponteiro para a célula
        }
        atual = atual->prox;
    }

    return NULL; // Elemento não encontrado
}

celula *busca_rec(celula *le, int x) {
    if (le == NULL) {
        return NULL; // Lista vazia, elemento não encontrado
    }

    if (le->dado == x) {
        return le; // Encontrou o elemento, retorna o ponteiro para a célula
    }

    return busca_rec(le->prox, x); // Chama a função recursiva para o próximo nó
}