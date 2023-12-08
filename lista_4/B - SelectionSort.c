#include <stdio.h>

#define exch(a, b) { int tt = a; a = b; b = tt; }

void selectionSort(int arr[], int n) {
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[m]) {
                m = j;
            }
        }

        if (i != m) {
            exch(arr[i], arr[m]);
        }
    }
}

int main() {
    int arr[1000];
    int n = 0;

    // Leitura dos números da entrada
    while (n < 1000 && scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    // Aplica o algoritmo de ordenação selection sort
    selectionSort(arr, n);

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

    return 0;
}
