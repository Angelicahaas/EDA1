#include <stdio.h>
#include <string.h>

void contrario(char *str, int tamanho) {
    if (tamanho < 0) {
        return;
    }

    printf("%c", str[tamanho]);
    contrario(str, tamanho - 1);
}

int main() {
    char str[500];
    scanf("%s", str);

    int tamanho = strlen(str);
    contrario(str, tamanho - 1);

    printf("\n");

    return 0;
}
