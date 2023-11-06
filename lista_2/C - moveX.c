#include <stdio.h>

void moveX(char *st) {
    if (st[0] == '\0') {
        return;
    }

    if (st[0] != 'x') {
        printf("%c", st[0]);
    }

    moveX(st + 1);

    if (st[0] == 'x') {
        printf("%c", st[0]);
    }
}

int main() {
    char st[100];
    scanf("%s", st); 
    moveX(st);
    printf("\n");

    return 0;
}
