#include <stdio.h>

#define MAX_SIZE 61

int main() {
    int pares[MAX_SIZE][2]; // Matriz para contar o número de botas para cada tamanho e pé (0 para esquerdo, 1 para direito)
    int tamanho;
    char lado;
    int contador = 0;

    // Inicialize a matriz de contagem
    for (int i = 30; i <= 60; i++) {
        pares[i][0] = 0; // Esquerdo
        pares[i][1] = 0; // Direito
    }

    while (scanf("%d %c", &tamanho, &lado) != EOF) {
        if (lado == 'E') {
            if (pares[tamanho][1] > 0) {
                pares[tamanho][1]--;
                contador++;
            } else {
                pares[tamanho][0]++;
            }
        } else if (lado == 'D') {
            if (pares[tamanho][0] > 0) {
                pares[tamanho][0]--;
                contador++;
            } else {
                pares[tamanho][1]++;
            }
        }
    }

    printf("%d\n", contador);

    return 0;
}
