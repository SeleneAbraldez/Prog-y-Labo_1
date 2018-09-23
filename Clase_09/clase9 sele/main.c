#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT 2

//#define LIBRE 1
//#define DATO 0

int main()
{
    char seguir='s';
    int opcion=0;
    ePersona personas[CANT];

    init(personas, CANT);

    do{
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Modificar persona\n");
        printf("4- Imprimir personas ordenada por apellido y nombre\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                alta(personas, CANT);
                break;
            case 2:
                baja(personas, CANT);
                break;
            case 3:
                modificar(personas, CANT);
                break;
            case 4:
                ordenar(personas, CANT);
                imprimir(personas, CANT);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir == 's');

    return 0;
}
