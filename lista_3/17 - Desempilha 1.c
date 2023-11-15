#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) {
        // A pilha está vazia
        return 0;
    }

    celula *temp = p->prox;  // Armazena o ponteiro para o nó a ser removido
    *y = temp->dado;        // Salva o valor do nó a ser removido em y
    p->prox = temp->prox;    // Atualiza o ponteiro do nó cabeça para o próximo nó
    free(temp);             // Libera a memória do nó removido

    return 1;  // Remoção bem-sucedida
}
