#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *v, int l, int r);
void merge(int *v, int l, int m, int r);

int main() {
    int n; // Número de elementos
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // Leitura dos números da entrada
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Aplica o algoritmo de ordenação merge sort
    mergeSort(arr, 0, n - 1);

    // Imprime a sequência ordenada
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);

        // Adiciona espaço se não for o último número
        if (i < n - 1) {
            printf(" ");
        }
    }

    // Quebra de linha após o último número
    printf("\n");

    free(arr); // Libera a memória alocada para o array

    return 0;
}

void mergeSort(int *v, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

void merge(int *v, int l, int m, int r) {
    int tam = r - l + 1;
    int *aux = (int *)malloc(tam * sizeof(int));
    int n = l;
    int p = m + 1;
    int k = 0;

    while (n <= m && p <= r) {
        if (v[n] <= v[p]) {
            aux[k++] = v[n++];
        } else {
            aux[k++] = v[p++];
        }
    }

    while (n <= m) {
        aux[k++] = v[n++];
    }

    while (p <= r) {
        aux[k++] = v[p++];
    }

    k = 0;
    for (n = l; n <= r; n++) {
        v[n] = aux[k++];
    }

    free(aux);
}
