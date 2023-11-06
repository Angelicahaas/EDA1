#include <stdio.h>

long int sumD(long int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sumD(n / 10);
    }
}

int main() {
    long int num;
    scanf("%ld", &num);

    long int result = sumD(num);

    printf("%ld\n", result);

    return 0;
}
