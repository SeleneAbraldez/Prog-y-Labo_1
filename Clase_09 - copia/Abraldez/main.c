#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT 1

//#define LIBRE 1
//#define DATO 0

int main()
{
    char seguir='s';
    int opcion=0;
    ePersona personas[CANT];

    init(personas, CANT);

    do{
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Modificar persona\n");
        printf("4- Imprimir lista ordenada por apellido y nombre\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                alta(personas, CANT);
                break;
            case 2:
                //baja(personas, CANT);
                break;
            case 3:
                break;
                fflush(stdin);
            case 4:
                //imprimir(personas, CANT);
                 for(int i=0; i<CANT; i++){
                     if(personas[i].isEmpty == 0){
                        printf("DNI\tApellido\tNombre\t\tFecha de ingreso\n\n");
                        //printf("%d\t%s\t\t%s\t\t%d\n", personas[i].dni, apellido[i], nombre[i], edad[i], () );
                        printf("%ld\t \n", personas[i].dni);
                     }
                 }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir == 's');

    return 0;
}
