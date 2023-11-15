#include <stdio.h>
#include <stdlib.h>

typedef struct file {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    // Verifica se a fila está cheia e redimensiona o vetor se necessário
    if (f->u == f->N) {
        int *novo_dados = (int *)realloc(f->dados, 2 * f->N * sizeof(int));
        if (novo_dados == NULL) {
            // Falha ao realocar memória
            return 0;
        }
        f->dados = novo_dados;
        f->N *= 2;
    }

    // Insere o elemento na fila e atualiza o índice da última posição ocupada (u)
    f->dados[f->u] = x;
    f->u++;

    return 1; // Inserção bem sucedida
}