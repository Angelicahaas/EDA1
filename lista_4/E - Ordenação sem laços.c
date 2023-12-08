#include <stdio.h>

#define exch(a, b) { int tt = a; a = b; b = tt; }

void ordena(int *v, int n) {
    int m;
    for (int i = 0; i < n - 1; i++) {
        m = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[m]) {
                m = j;
            }
        }

        if (i != m) {
            exch(v[i], v[m]);
        }
    }
}

