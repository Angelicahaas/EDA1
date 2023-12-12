#include <stdio.h>

typedef int Item;
int loc;

// Função de busca binária modificada para rastrear a posição
// onde a chave deveria ser inserida se não for encontrada
int buscaBinaria(Item arr[], int inicio, int fim, int chave) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Verificar se a chave está presente no meio
        if (chave == arr[meio]) {
            loc = meio + 1; // Ajuste para imprimir loc quando o elemento é encontrado
            return meio;
        } else if (chave > arr[meio]) {
            loc = meio + 1;
            inicio = meio + 1;
        } else {
            loc = meio;
            fim = meio - 1;
        }
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

int main() {
    unsigned int n, m;
    scanf("%u %u", &n, &m);
    Item lstn[n];

    // Ler os elementos do array ordenado
    for (int i = 0; i < n; i++)
        scanf("%d", &lstn[i]);

    // Realizar buscas binárias para os M números
    for (int i = 0; i < m; i++) {
        int ms, var;
        scanf("%d", &ms);
        var = buscaBinaria(lstn, 0, n - 1, ms);

        // Imprimir o resultado da busca
        if (var == -1)
            printf("%d\n", loc); // Se a chave não for encontrada, imprime a posição
        else
            printf("%d\n", var); // Se a chave for encontrada, imprime o índice
    }

    return 0;
}
