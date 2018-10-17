#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro, *ptr; //punt basi
    int vec[5], *p;

    printf("Nro: %d\n", nro);
    nro = 7;
    printf("Ptr: %p\n", ptr);
    ptr = &nro;
    printf("Ptr: %p\n", ptr);
    *ptr = 13;
    printf("Nro: %d\n", nro);

    for(int i = 0; i<5; i++){ //sin punt
        vec[i]=i+3;
        printf("%d ", vec[i]);
    }
    printf("\n");

    p=vec;
    for(int i = 0; i<5; i++){ //con punt
        *(p+i)=i+5;
        printf("%p: ", &p[i]);
        //printf("%d ", vec[i]);
        printf("%d ", p[i]);  //es lo meeeesmo que ^
    }

    return 0;
}
