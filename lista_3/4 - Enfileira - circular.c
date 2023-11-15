#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    // Verificar se a fila está cheia
    if ((f->u + 1) % f->N == f->p) {
        // A fila está cheia, redimensionar o vetor dados

        int novoN = f->N * 2;  // Dobrar o tamanho do vetor

        int *novoDados = (int *)malloc(novoN * sizeof(int));

        if (novoDados == NULL) {
            // Falha na alocação de memória
            return 0;
        }

        // Copiar os elementos da fila atual para o novo vetor
        int i = 0;
        int j = f->p;

        while (j != f->u) {
            novoDados[i] = f->dados[j];
            i++;
            j = (j + 1) % f->N;
        }

        novoDados[i] = f->dados[f->u];  // Copiar o último elemento

        // Atualizar os ponteiros e liberar o antigo vetor de dados
        f->p = 0;
        f->u = i;
        f->N = novoN;
        free(f->dados);
        f->dados = novoDados;
    }

    // Inserir o elemento x na fila
    f->u = (f->u + 1) % f->N;
    f->dados[f->u] = x;
    return 1;
}