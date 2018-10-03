#include <stdio.h>
#include <stdlib.h>

int main(){
    char dato[15];
    int datoInt;

    printf("Ingrese el dato: ");
    scanf("%s", dato);
    datoInt = atoi(dato);

    printf("\ndatoInt: %d", datoInt+3);

    sprintf(dato,"%d",datoInt+5);

    printf("\ndato: %s", dato);

    return 0;
}
