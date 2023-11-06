#include <stdio.h>


int main(){
    int Xm = 0;
    int Ym = 0;
    int Xr = 0;
    int Yr = 0;
    int difX = 0;
    int difY = 0;
    int total = 0;

    scanf("%d %d %d %d", &Xm, &Ym, &Xr, &Yr );

    if(Xm<0 || Xm>1000 || Ym<0 || Ym>1000 || Xr<0 || Xr>1000 || Yr<0 || Yr>1000){
        return 0;
    }

    difX = Xr-Xm;
    difY = Yr-Ym;
    total = difX+difY;

    printf("%d\n", total);



    return 0;
}