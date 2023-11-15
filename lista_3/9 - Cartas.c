#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int top;
    int n;
} pilha;

void startstack(pilha *p, int tam) {
    p->stack = (int *)malloc(tam * sizeof(int));
    p->top = -1;
    p->n = tam;

}

void stackup(pilha *p, int value) {
    p->top++;
    p->stack[p->top] = value;
}

int unstack(pilha *p) {
    int value = p->stack[p->top];
    p->top--;
    return value;
}

void printcards(pilha *p) {
    printf("Cartas descartadas: ");
    int tamAtual = p->n - 1; //taamanho inicial da pilha
    for (int i = 0; i < tamAtual; i++) {
        printf("%d", unstack(p));
        if (i< tamAtual - 1){
            stackup(p, unstack(p)); //move o top 
            printf(", ");
        }

    }
    printf("\n");
        
}

int main() {
    int x;
    scanf("%d", &x);

    pilha cardstack;
    startstack(&cardstack, x);

    for (int i = x; i >= 1; i--) { // preenhe a pilha com valores de 1 a n
        stackup(&cardstack, i);

    }

    while (cardstack.top>= 1) {
        printcards(&cardstack);
      
    }

    printf("Carta restante: %d\n", cardstack.stack[0]);

    free(cardstack.stack);

    return 0;

}