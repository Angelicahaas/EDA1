#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois arrays ordenados
int* mergeArrays(int* arr1, int* arr2, int left1, int right1, int left2, int right2) {
    // Aloca espaço para o array mesclado
    int* mergedArray = malloc(sizeof(int) * ((right1 - left1 + 1) + (right2 - left2 + 1)));

    int i1 = left1, i2 = left2, i_merged = 0;

    // Mescla os dois arrays ordenados
    while (i1 <= right1 && i2 <= right2) {
        if (arr1[i1] <= arr2[i2]) {
            mergedArray[i_merged++] = arr1[i1++];
        } else {
            mergedArray[i_merged++] = arr2[i2++];
        }
    }

    // Adiciona elementos restantes do primeiro array, se houver
    while (i1 <= right1) {
        mergedArray[i_merged++] = arr1[i1++];
    }

    // Adiciona elementos restantes do segundo array, se houver
    while (i2 <= right2) {
        mergedArray[i_merged++] = arr2[i2++];
    }

    return mergedArray;
}

// Função para mesclar uma parte de um array
void merge(int* arr, int left, int mid, int right) {
    int auxArray[right - left + 1];
    int i1 = left, i2 = mid + 1, i_aux = 0;

    // Mescla duas partes do array
    while (i1 <= mid && i2 <= right) {
        if (arr[i1] <= arr[i2]) {
            auxArray[i_aux++] = arr[i1++];
        } else {
            auxArray[i_aux++] = arr[i2++];
        }
    }

    // Adiciona elementos restantes da primeira parte, se houver
    while (i1 <= mid) {
        auxArray[i_aux++] = arr[i1++];
    }

    // Adiciona elementos restantes da segunda parte, se houver
    while (i2 <= right) {
        auxArray[i_aux++] = arr[i2++];
    }

    // Copia os elementos ordenados de volta para o array original
    int i3 = 0;
    for (int i = left; i <= right; i++) {
        arr[i] = auxArray[i3];
        i3++;
    }
}

// Função de ordenação mergesort
void mergeSort(int* arr, int left, int right) {
    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int originalArray[n];

    // Preenche o array original
    for (int i = 0; i < n; i++) {
        scanf("%d", &originalArray[i]);
    }

    // Ordena o array original
    mergeSort(originalArray, 0, n - 1);

    // Remove elementos duplicados do array original
    int newLength = 0;
    for (int i = 1; i < n; i++) {
        if (originalArray[newLength] != originalArray[i]) {
            originalArray[++newLength] = originalArray[i];
        }
    }
    newLength++;

    // Adiciona 1 bilhão se o número de elementos for ímpar
    if (newLength % 2 != 0) {
        originalArray[newLength++] = 1000000000;
    }

    int nmu[newLength / 2];

    // Gera o array nmu
    int j = 0;
    for (int i = 0; i < (newLength / 2); i++) {
        nmu[i] = originalArray[j] + originalArray[j + 1];
        j += 2;
    }

    // Mescla originalArray e nmu em mergedArray
    int mergedLength = newLength + (newLength / 2);
    int* mergedArray = mergeArrays(originalArray, nmu, 0, newLength - 1, 0, (newLength / 2) - 1);

    // Remove elementos duplicados de mergedArray
    int newMergedLength = 0;
    for (int i = 1; i < mergedLength; i++) {
        if (mergedArray[newMergedLength] != mergedArray[i]) {
            mergedArray[++newMergedLength] = mergedArray[i];
        }
    }
    newMergedLength++;

    // Imprime a cada 4º elemento de mergedArray
    for (int i = 0; i < newMergedLength; i += 4) {
        printf("%d\n", mergedArray[i]);
    }
    printf("Elementos: %d\n", newMergedLength);

    // Libera a memória alocada dinamicamente
    free(mergedArray);

    return 0;
}
