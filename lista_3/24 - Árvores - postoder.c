#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Definição de uma pilha para ser usada no percurso pós-ordem
typedef struct {
    no **array;
    int tamanho;
    int topo;
} Pilha;

// Função para criar uma pilha
Pilha *criarPilha(int tamanho) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->array = (no **)malloc(tamanho * sizeof(no *));
    pilha->tamanho = tamanho;
    pilha->topo = -1;
    return pilha;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para empilhar um nó na pilha
void empilhar(Pilha *pilha, no *no) {
    pilha->array[++pilha->topo] = no;
}

// Função para desempilhar um nó da pilha
no *desempilhar(Pilha *pilha) {
    if (pilhaVazia(pilha))
        return NULL;
    return pilha->array[pilha->topo--];
}

// Função para percurso pós-ordem não recursivo
void pos_ordem(no *raiz) {
    if (raiz == NULL)
        return;

    Pilha *pilha1 = criarPilha(100);
    Pilha *pilha2 = criarPilha(100);

    empilhar(pilha1, raiz);

    while (!pilhaVazia(pilha1)) {
        no *temp = desempilhar(pilha1);
        empilhar(pilha2, temp);

        if (temp->esq)
            empilhar(pilha1, temp->esq);
        if (temp->dir)
            empilhar(pilha1, temp->dir);
    }

    while (!pilhaVazia(pilha2)) {
        printf("%d ", desempilhar(pilha2)->dado);
    }

    free(pilha1->array);
    free(pilha1);
    free(pilha2->array);
    free(pilha2);
}