#include <stdio.h>

void swap(int *a, int *b){
    int h = *a;     
    *a = *b;
    *b = h;
}