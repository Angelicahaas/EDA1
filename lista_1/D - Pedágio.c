#include <stdio.h>

int main(){
    int L=0, D=0, K=0, P=0;
    int pedagio=0;
    int custoKm=0;
    int total=0;
    
    scanf("%d %d", &L, &D);
    scanf("%d %d", &K, &P);


    if(L>=1 && L<=10000 && D>=1 && D<=10000){
        pedagio = L/D;
        pedagio = pedagio*P;
        custoKm = L*K;
        total = custoKm + pedagio;

        printf("%d\n", total);
    }else{
        return 0;
    }
    
    return 0;
}