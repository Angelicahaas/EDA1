#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 10;
    int *b = &a;
    int **c = &b;        // poteiro para uma variavel do tipo int *

    printf("&a = %p, a =  %d\n", &a, a);
    printf("&b = %p, b =  %p, *b = %d\n", &b, b, *b); // %p = endereço
    printf("&c = %p, c =  %p, *c = %p, **c = %d\n\n", &c, c, *c, **c);
    

    **c = 99;

    printf("&a = %p, a =  %d\n", &a, a);
    printf("&b = %p, b =  %p, *b = %d\n", &b, b, *b); // %p = endereço
    printf("&c = %p, c =  %p, *c = %p, **c = %d\n\n", &c, c, *c, **c);
    

    return 0;
}