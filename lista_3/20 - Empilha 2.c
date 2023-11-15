#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int empilha(pilha *p, int x) {
    // Verifica se a pilha está cheia
    if (p->topo == p->N) {
        // Se estiver cheia, redimensiona o vetor
        p->N *= 2; // Pode ser ajustado conforme necessário
        p->dados = realloc(p->dados, p->N * sizeof(int));
        if (p->dados == NULL) {
            // Falha na alocação de memória
            return 0;
        }
    }

    // Insere o elemento na pilha
    p->dados[p->topo] = x;
    p->topo++;

    return 1; // Inserção bem sucedida
}
