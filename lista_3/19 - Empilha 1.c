#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int empilha(celula *p, int x) {
    if (p == NULL) {
        // Verifica se a pilha foi inicializada corretamente
        return 0;
    }

    celula *nova_celula = (celula *)malloc(sizeof(celula));
    if (nova_celula == NULL) {
        // Verifica se a alocação de memória foi bem-sucedida
        return 0;
    }

    nova_celula->dado = x;
    nova_celula->prox = p->prox;
    p->prox = nova_celula;

    return 1; // Inserção bem-sucedida

}
