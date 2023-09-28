# include <stdio.h>

int main(){
    int A = 0;
    int B = 0;
    int C = 0;
    int X = 0;
    int Y = 0;
    int Z = 0;
    int quantX = 0;
    int quantY = 0;
    int quantZ = 0;
    int total = 0;

    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &X, &Y, &Z);

    if(A<1 || A>1000000 || B<1 || B>1000000 || C<1 || C>1000000 || X<1 || X>1000000 || Y<1 || Y>1000000 || Z<1 || Z>1000000){
        return 0;
    }

    quantX = X/A;
    quantY = Y/B;
    quantZ = Z/C;

    total = quantX * quantY * quantZ;

    printf("%d\n", total);

    return 0;
}