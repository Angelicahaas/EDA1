#include <stdio.h>

long int espertinho[81];

long int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    if (espertinho[n] != 0) {
        return espertinho[n];
    }
    espertinho[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return espertinho[n];
}

