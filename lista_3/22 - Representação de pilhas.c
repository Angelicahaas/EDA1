#include <stdlib.h>

typedef struct {
    int *v;   // Vetor que contém os elementos da pilha
    int N;    // Tamanho de v
    int topo; // Indicador do topo
} pilha;

// Função para redimensionar a pilha
void resize_pilha(pilha *p, int novo_tamanho) {
    p->N = novo_tamanho;
    p->v = realloc(p->v, p->N * sizeof(int));
}

void empilha(pilha *p, int x) {
    // Verifica se a pilha está cheia
    if (p->topo == p->N - 1) {
        // Dobrar o tamanho do vetor da pilha
        resize_pilha(p, p->N * 2);
    }

    // Incrementa o topo e insere o elemento na pilha
    p->v[p->topo] = x;
    p->topo++;
}

int desempilha(pilha *p, int *y) {
    // Verifica se a pilha está vazia
    if (p->topo == 0) {
        return 0; // Pilha vazia, desempilhamento não é possível
    }

    // Obtém o elemento do topo e decrementa o topo
    p->topo--;
    *y = p->v[p->topo];

    // Verifica se é necessário redimensionar a pilha (por exemplo, se está muito vazia)
    if (p->topo > 0 && p->topo == p->N / 4) {
        resize_pilha(p, p->N / 2);
    }

    return 1; // Desempilhamento bem-sucedido
}
