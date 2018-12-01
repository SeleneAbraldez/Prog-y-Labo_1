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
        printf("\nIngrese nombre: ");
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
        printf("\n!!-No hay espacio libre. \n\n");
    }
    return;
}

void baja(ePersona lista[], int len){
    int DNIAux;
    int flagBaja = 0;
    char seguirBaja;

    printf("Ingrese DNI: ");
    scanf("%ld", &DNIAux);
    for(int i=0; i<len; i++){
       if(DNIAux==lista[i].dni){
            flagBaja = 1;
            printf("(%ld)-Desea borrar usuarix: %s %s  (%d/%d/%d)? S para continuar, cualquier otra letra para salir \n", lista[i].dni, lista[i].apellido, lista[i].nombre, lista[i].feNac.dia, lista[i].feNac.mes, lista[i].feNac.anio);
            fflush(stdin);
            scanf("%c", &seguirBaja);
            if(seguirBaja=='s'){
                lista[i].isEmpty = 1;
                printf("Usuarix eliminadx con exito. \n");
            }
       }
    }
    if(flagBaja==0){
        printf("!!-Dato no encontrado.\n");
    }
    flagBaja = 0;
}

void modificar(ePersona lista[], int len){
    int DNIAux;
    int flagMod = 0;
    char seguirMod;
    int opcionMod = 0;

    printf("Ingresar DNI: ");
    scanf("%ld", &DNIAux);
    for(int i=0; i<len; i++){
        if(DNIAux==lista[i].dni){
            flagMod = 1;
            printf("(%ld)-Desea modificar usuarix: %s %s  (%d/%d/%d)? S para continuar, cualquier otra letra para salir \n", lista[i].dni, lista[i].apellido, lista[i].nombre, lista[i].feNac.dia, lista[i].feNac.mes, lista[i].feNac.anio);
            fflush(stdin);
            scanf("%c", &seguirMod);
            if(seguirMod=='s'){
                printf("Que desea modificar? 1-DNI  2-Nombre  3-Apellido 4-Fecha // Ingrese cualquier otro numero para salir \n");
                scanf("%d", &opcionMod);
                switch(opcionMod){
                    case 1:
                        printf("Ingrese nuevo DNI: ");
                        scanf("%ld", &lista[i].dni);
                        printf("DNI modificado. Saliendo...\n");
                        break;
                    case 2:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(lista[i].nombre);
                        printf("Nombre modificado. Saliendo...\n");
                        break;
                    case 3:
                        printf("Ingrese nuevo apellido: ");
                        fflush(stdin);
                        gets(lista[i].apellido);
                        printf("Apellido modificado. Saliendo...\n");
                        break;
                    case 4:
                        printf("Ingrese nuevo dia: ");
                        scanf("%d", &lista[i].feNac.dia);
                        printf("Ingrese nuevo mes: ");
                        scanf("%d", &lista[i].feNac.mes);
                        printf("Ingrese nuevo anio: ");
                        scanf("%d", &lista[i].feNac.anio);
                        printf("Fecha modificada. Saliendo... \n");
                        break;
                    default:
                        printf("Saliendo...\n");
                        break;
                }
            }else{
                printf("Saliendo al menu principal...\n");
            }
        }
    }
    if(flagMod==0){
        printf("!!-Dato no encontrado.\n");
    }
    flagMod = 0;
}

void ordenar(ePersona lista[], int len){
    ePersona listaAux;
    int i;
    int j;

    for(i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if (strcmp(lista[i].apellido, lista[j].apellido)>0){
                listaAux = lista[i];
                lista[i] = lista[j];
                lista[j] = listaAux;
            }else if ( strcmp(lista[i].apellido, lista[j].apellido)==0 && strcmp(lista[i].nombre, lista[j].nombre)>0){
                listaAux = lista[i];
                lista[i] = lista[j];
                lista[j] = listaAux;
            }
        }
    }
}

void imprimir(ePersona lista[], int len){
    printf("\nDNI\t\tApellido\tNombre\t\tFecha de ingreso\n\n");
    for(int i=0; i<len; i++){
        if(lista[i].isEmpty == 0){
            printf("%ld\t\t%s\t\t%s\t\t(%d/%d/%d)\n", lista[i].dni, lista[i].apellido, lista[i].nombre, lista[i].feNac.dia, lista[i].feNac.mes, lista[i].feNac.anio);
        }
    }
 }
