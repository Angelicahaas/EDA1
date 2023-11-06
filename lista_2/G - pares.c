#include <stdio.h>

int i = 0;

void contarPares(char st[]) {
    if (st[0] == '\0' || st[0] == '\0') {
        return;
    }

    if (st[0] == st[2]) {
        i++;
    }

    contarPares(&st[1]);
}

int main() {
    char str[201];
    scanf("%s", str);

    contarPares(str);

    printf("%d\n", i);

    return 0;
}
