#include <stdio.h>
#include <string.h>

void invstring(char *str, int tamanho) {
    if (tamanho < 0) {
        return;
    }

    printf("%c", str[tamanho]);
    invstring(str, tamanho - 1);
}

int main() {
    char str[500];
    scanf("%s", str);

    int tamanho = strlen(str);
    invstring(str, tamanho - 1);

    printf("\n");

    return 0;
}
