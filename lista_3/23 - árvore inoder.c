#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Definição da estrutura da pilha
typedef struct pilha {
    no **itens;
    int topo;
    int capacidade;
} pilha;

// Função para criar uma nova pilha
pilha *criar_pilha(int capacidade) {
    pilha *nova_pilha = (pilha *)malloc(sizeof(pilha));
    nova_pilha->itens = (no **)malloc(capacidade * sizeof(no *));
    nova_pilha->topo = -1;
    nova_pilha->capacidade = capacidade;
    return nova_pilha;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(pilha *p) {
    return p->topo == -1;
}

// Função para verificar se a pilha está cheia
int pilha_cheia(pilha *p) {
    return p->topo == p->capacidade - 1;
}

// Função para empilhar um nó na pilha
void empilhar(pilha *p, no *item) {
    if (pilha_cheia(p)) {
        return;
    }
    p->itens[++(p->topo)] = item;
}

// Função para desempilhar um nó da pilha
no *desempilhar(pilha *p) {
    if (pilha_vazia(p)) {
        fprintf(stderr, "Erro: Pilha vazia\n");
        return NULL;
    }
    return p->itens[(p->topo)--];
}

// Função não recursiva para percurso em ordem
void em_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    pilha *p = criar_pilha(100); // Tamanho arbitrário da pilha

    no *atual = raiz;

    while (atual != NULL || !pilha_vazia(p)) {
        while (atual != NULL) {
            empilhar(p, atual);
            atual = atual->esq;
        }

        atual = desempilhar(p);
        printf("%d ", atual->dado);

        atual = atual->dir;
    }

    free(p->itens);
    free(p);
}

// Função auxiliar para criar um novo nó
no *criar_no(int dado) {
    no *novo = (no *)malloc(sizeof(no));
    novo->dado = dado;
    novo->esq = novo->dir = NULL;
    return novo;
}

