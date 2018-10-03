#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dato[15];
    int datoInt, i, flag, cant;

    printf("Ingrese el dato: ");
    scanf("%s", dato);

    flag = 0;
    cant = strlen(dato);

    for(i=0; i<cant; i++){
        if(!isdigit(dato[i])){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        printf("\nNo es un numero");

    }
    else{
        printf("\nEs un numero");
    }

    return 0;
}
