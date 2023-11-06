#include <stdio.h>


unsigned long F91(unsigned long N) {
    if (N >= 101) {
        return N - 10;
    }
    else {
        F91(F91(N + 11));

        }
}


int main() {
    unsigned long n = 1;
    while (scanf("%lu", &n) && n != 0) {
        printf("f91(%lu) = %lu\n", n, F91(n));
    }
    return 0;

}