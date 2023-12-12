#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
} Elemento;

int buscaBinaria(Elemento *vetor, int inicio, int fim, int alvo) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio].valor == alvo) {
            return meio;
        }
        if (vetor[meio].valor < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

void merge(Elemento *v, int inicio, int meio, int fim) {
    Elemento *v2 = malloc(sizeof(Elemento) * (fim - inicio + 1));
    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        if (v[i].valor < v[j].valor) {
            v2[k++] = v[i++];
        } else {
            v2[k++] = v[j++];
        }
    }

    while (i <= meio) {
        v2[k++] = v[i++];
    }

    while (j <= fim) {
        v2[k++] = v[j++];
    }

    k = 0;
    for (i = inicio; i <= fim; i++) {
        v[i] = v2[k++];
    }

    free(v2);
}

void mergeSort(Elemento *v, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);

    Elemento *dados = (Elemento *)malloc(tamanho * sizeof(Elemento));

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &dados[i].valor);
    }

    mergeSort(dados, 0, tamanho - 1);

    int alvo;
    while (scanf(" %d", &alvo) != EOF) {
        int resultado = buscaBinaria(dados, 0, tamanho - 1, alvo);
        printf("%s\n", resultado != -1 ? "sim" : "nao");
    }

    free(dados);

    return 0;
}
