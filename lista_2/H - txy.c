#include <stdio.h>

void txy(char *st){

    if (st[0] == '\0') {
        return;

    }
    if (st[0] == 'x') {
        printf("y");
    }
    else {
        printf("%c", st[0]);
    }

    txy(&st[1]);
}

int main() {
    char st[80];
    scanf("%s", st);
    txy(st);
    printf("\n");

    return 0;
}