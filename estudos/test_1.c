#include <stdio.h>


int main(){
    int a = 10;
    int b, c;

    printf("&a = %p, a = %d\n", &a, a);   //%p = endereço de memoria, %d = int
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n\n", &c, c);

    b = 20;
    c = b + a;


    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n\n", &c, c);
    
    return 0;
}