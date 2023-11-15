#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct {
    no **itens;
    size_t tamanho;
    size_t capacidade;
} Pilha;

void inicializarPilha(Pilha *pilha, size_t capacidade) {
    pilha->itens = (no **)malloc(capacidade * sizeof(no *));
    pilha->tamanho = 0;
    pilha->capacidade = capacidade;
}

void empilhar(Pilha *pilha, no *item) {
    if (pilha->tamanho == pilha->capacidade) {
        pilha->capacidade *= 2;
        pilha->itens = (no **)realloc(pilha->itens, pilha->capacidade * sizeof(no *));
    }
    pilha->itens[pilha->tamanho++] = item;
}

no *desempilhar(Pilha *pilha) {
    if (pilha->tamanho == 0) {
        return NULL;
    }
    return pilha->itens[--pilha->tamanho];
}

bool pilhaVazia(Pilha *pilha) {
    return pilha->tamanho == 0;
}

void pre_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    Pilha pilha;
    inicializarPilha(&pilha, 10);

    empilhar(&pilha, raiz);

    while (!pilhaVazia(&pilha)) {
        no *atual = desempilhar(&pilha);
        printf("%d ", atual->dado);

        if (atual->dir != NULL) {
            empilhar(&pilha, atual->dir);
        }

        if (atual->esq != NULL) {
            empilhar(&pilha, atual->esq);
        }
    }

    free(pilha.itens);
}

