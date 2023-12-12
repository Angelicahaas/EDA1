#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas metades ordenadas
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criação de arrays temporários
    int L[n1], R[n2];

    // Copiar dados para arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os arrays temporários de volta em arr[l..r]
    i = 0;  // Índice inicial do primeiro subarray
    j = 0;  // Índice inicial do segundo subarray
    k = l; // Índice inicial do array mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa o Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Mesclar a primeira e a segunda metade
        int m = l + (r - l) / 2;

        // Ordenar as duas metades
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mesclar as metades ordenadas
        merge(arr, l, m, r);
    }
}

int main() {
    int n;

    // Obter o número de elementos a serem ordenados
    scanf("%d", &n);

    int arr[n];

    // Obter os elementos a serem ordenados
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Chamar a função mergeSort para ordenar o array
    mergeSort(arr, 0, n - 1);

    // Imprimir o array ordenado
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
