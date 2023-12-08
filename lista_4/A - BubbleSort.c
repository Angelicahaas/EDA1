#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[1000];
    int n = 0;

    // Leitura dos números da entrada
    while (scanf("%d", &arr[n]) != EOF && n < 1000) {
        n++;
    }

    // Aplica o algoritmo de ordenação bolha
    bubbleSort(arr, n);

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
