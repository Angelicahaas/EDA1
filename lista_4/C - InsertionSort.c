#include <stdio.h>

typedef int item;
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) { item tt = a; a = b; b = tt; }
#define cmpexch(a, b) { if (less(b, a)) exch(a, b); }

void insertionSort(item arr[], int l, int r) {
    item value;
    int n, p;
    for (n = r; n > l; n--) {
        cmpexch(arr[l], arr[n]);
    }

    for (n = l + 2; n <= r; n++) {
        value = arr[n];
        for (p = n; value < arr[p - 1]; p--) {
            arr[p] = arr[p - 1]; // Puxando maior número
        }
        arr[p] = value; // Encaixando o valor
    }
}

int main() {
    item arr[50000];
    int n = 0;

    while (n < 50000 && scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    // Aplica o algoritmo de ordenação 
    insertionSort(arr, 0, n - 1);

    // Imprime a sequência ordenada por inserção
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
