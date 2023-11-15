#include <stdio.h>
#include <stdlib.h>

typedef int value;

typedef struct in_it {
    value e;
    struct in_it *prox;
} in_it;

typedef struct {
    in_it *top;
    in_it *end;
    int n;
} pilha;

// Inicializa a pilha
int startstack(pilha *p) {
    p->top = NULL;
    p->end = NULL;
    p->n = 0;
    return 0;
}

// Se estiver vazia insere valor no início, senão no fim
int stackup(pilha *p, value e) {
    in_it *novo_no = malloc(sizeof(in_it));

    if (novo_no == NULL) {
        return 0;
    }

    novo_no->e = e;
    novo_no->prox = NULL;

    if (p->top == NULL) {
        p->top = novo_no;
        p->end = novo_no;
    } else {
        p->end->prox = novo_no;
        p->end = novo_no;
    }

    p->n++;
    return 1;
}

// Remove valor
value unstack(pilha *p) {
    in_it *remove = p->top;
    value x = remove->e;
    p->top = remove->prox;
    free(remove);
    p->n--;
    return x;
}


int empty(pilha *p) {
    return p->n == 0;
}


int main() {
    pilha *cardstack = (pilha *)malloc(sizeof(pilha));
    int x;

    startstack(cardstack);
    scanf("%d", &x);

    for (int i = 1; i <= x; ++i) {
        stackup(cardstack, i);
    }

    printf("Cartas descartadas: ");

    while (cardstack->n > 2) {
        printf("%d, ", unstack(cardstack));
        stackup(cardstack, unstack(cardstack));
    }

    printf("%d\n", unstack(cardstack));
    printf("Carta restante: %d\n", unstack(cardstack));

    free(cardstack);

    return 0;
}
