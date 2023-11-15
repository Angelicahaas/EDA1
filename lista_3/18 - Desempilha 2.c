#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int desempilha(pilha *p, int *y) {
    if (p->topo > 0) {
        p->topo--;
        *y = p->dados[p->topo];
        return 1; // Remoção bem sucedida
    } else {
        return 0; // Pilha vazia, remoção sem sucesso
    }
}
