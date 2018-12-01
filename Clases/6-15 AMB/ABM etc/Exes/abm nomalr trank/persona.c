#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(ePersona lista[], int len){
    int i;
    for(i=0; i<len; i++){
        lista[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(ePersona lista[], int len){
    int i;
    int retorno = -1;

    for(i=0; i<len; i++){
        if(lista[i].isEmpty == 1){
            retorno = i;
            break;
        }
    }
    return retorno;
}


void alta(ePersona lista[], int len){
    int index;

    index = obtenerEspacioLibre(lista, len);

    if(index != -1){
        //hay espacio libre
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[index].nombre);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lista[index].apellido);

        printf("Ingrese dni: ");
        scanf("%ld", &lista[index].dni);

        printf("Ingrese dia: ");
        scanf("%d", &lista[index].feNac.dia);
        printf("Ingrese mes: ");
        scanf("%d", &lista[index].feNac.mes);
        printf("Ingrese anio: ");
        scanf("%d", &lista[index].feNac.anio);

        lista[index].isEmpty = 0;

    }
    else{
        //no hay espacio libre
        printf("!!-No hay espacio libre. \n\n");
    }
    return;
}


/*void baja(ePersona lista[], int len){
    int dniAux;

    printf("Ingresar dni: ");
    scanf("%ld", &dniAux);

    for(int i=0;i<len;i++){
        if(dniAux==lista[i]&&isEmpty==0){
            isEmpty[i]=1;
            flag=1;
        }
    }

    if(flag==0){
        printf("Dato no encontrado");
    }
    break;
}*/
