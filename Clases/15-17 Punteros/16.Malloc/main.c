#include <stdio.h>
#include <stdlib.h>

///malloc

int main()
{
    int* pNumero;
    pNumero = (int*) malloc(sizeof(int));

    if(pNumero == NULL){
        printf("No se ha podido liberar memoria.");
        exit(-1);
    }
    *pNumero = 5;
    printf("%d", *pNumero);
    free(pNumero);

    return 0;
}
