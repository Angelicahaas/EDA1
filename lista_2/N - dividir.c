#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *next;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *pl = l->next;

    l1->next = NULL; 
    l2->next = NULL;

    celula *pl1 = l1; // acompanhar o ultimo l1
    celula *pl2 = l2;

    while (pl != NULL) {
        celula *dado = pl->next; // Salvar o próximo nó antes de alterar o ponteiro

        if (pl->dado % 2 == 0) { 
            pl2->next = pl; 
            pl2 = pl2->next; // Atualizar o último nó de l2
        } else { 
            pl1->next = pl; // Adicionar o nó a l1
            pl1 = pl1->next;
        }

        pl->next = NULL; 
        pl = dado; 
    }
}

