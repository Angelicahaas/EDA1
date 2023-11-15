#include <stdio.h>
#include <stdbool.h>

#define MAX_LOVE_MOBILE 1000

typedef struct {
    int items[MAX_LOVE_MOBILE];
    int top;
} Stack;

// Função para inicializar a pilha
void initialize(Stack *stack) {
    stack->top = -1;
}

// Função para verificar se a pilha está vazia
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Função para empilhar um elemento
void push(Stack *stack, int value) {
    stack->items[++stack->top] = value;
}

// Função para desempilhar um elemento
int pop(Stack *stack) {
    return stack->items[stack->top--];
}

int main() {
    int n;

    while (1) {
        // Input o número de love mobiles
        scanf("%d", &n);

        // Verifique o fim da entrada
        if (n == 0) {
            break;
        }

        int order[MAX_LOVE_MOBILE];
        Stack sideStreet;
        initialize(&sideStreet);

        // Input a ordem dos love mobiles
        for (int i = 0; i < n; i++) {
            scanf("%d", &order[i]);
        }

        int expected = 1;
        bool possible = true;

        // Processa a ordem e verifica se é possível
        for (int i = 0; i < n; i++) {
            // Tente desempilhar até que a pilha esteja vazia ou o topo não coincida
            while (!isEmpty(&sideStreet) && sideStreet.items[sideStreet.top] == expected) {
                expected++;
                pop(&sideStreet);
            }

            // Se o elemento atual não é o esperado, empilhe-o
            if (order[i] != expected) {
                push(&sideStreet, order[i]);
            } else {
                expected++;
            }
        }

        // Verifique se todos os love mobiles foram processados
        while (!isEmpty(&sideStreet) && sideStreet.items[sideStreet.top] == expected) {
            expected++;
            pop(&sideStreet);
        }

        // Output o resultado
        if (expected - 1 == n) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
