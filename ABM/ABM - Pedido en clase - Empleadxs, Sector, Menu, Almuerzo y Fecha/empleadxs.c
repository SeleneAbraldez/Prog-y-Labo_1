#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleadxs.h"
#include "menu.h"
#include "utn.h"

void inicializarEmpleadxs(eEmpleadx* empl, int lenEmp){
    for(int i=0; i<lenEmp; i++){
        empl[i].isEmpty = 1;
    }
}

int lugarLibreEmpleadx(eEmpleadx* empl, int lenEmp){
    int index = -1;
    for(int i=0; i<lenEmp; i++){
        if( empl[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int encontrarEmpleadxID(eEmpleadx* empl, int lenEmp){
    int idAux = getValidInt("Ingrese ID de empleadx: ", "Valor no valido. ", 0, 1000);
    int ret = -1;
    for(int i=0; i < lenEmp; i++){
        if(empl[i].legajo == idAux && empl[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int imprimirEmpleadx(eEmpleadx empl, eSector* sector, int lenSec){
    char sectors[21];
    cargarSectores(sector, lenSec, empl.idSector, sectors);
    printf("\nLegajo: %d\nNombre: %s\nSexo: %c\nSueldo: %.2f\nSector: %s\n\n", empl.legajo, empl.nombre, empl.sexo, empl.sueldo, sectors);
    return 0;
}

int imprimirEmpleadxs(eEmpleadx* empl, int lenEmp, eSector* sector, int lenSec){
    for(int i = 0; i<lenEmp; i++){
        if(empl[i].isEmpty == 0){
            imprimirEmpleadx(empl[i], sector, lenSec);
        }
    }
    return 0;
}


int altaEmpleadx(eEmpleadx* empl, int lenEmp, eSector* sector, int lenSec){
    int ret = -1;
    eEmpleadx altaEmpl;
    int index = lugarLibreEmpleadx(empl, lenEmp);
    int legajo;

    if(index == -1){
        printf("!! - No mas hay espacio\n");
    } else {
        legajo = index + 1;
        altaEmpl.legajo = legajo;
        getValidString("Ingrese nombre: ", "Valor no valido.", altaEmpl.nombre);
        altaEmpl.sexo = getChar("Ingrese sexo: ");
        altaEmpl.sueldo =getValidInt("Ingrese Sueldo: ","Sueldo no valido", 10000, 99999);
        altaEmpl.idSector = seleccionarSector(sector, lenSec);
        altaEmpl.isEmpty = 0;
        empl[index] = altaEmpl;
        ret = 0;
    }
    return ret;
}

int modificarEmpleadx(eEmpleadx* empl, int lenEmp, eSector* sector, int lenSec){
    int ret = -1;
    int idAux = encontrarEmpleadxID(empl, lenEmp);
    int menuModi;
    char contModi = 's';
    eEmpleadx modiEmpl;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado empleadx. \n");
    }else{
        imprimirEmpleadx(empl[idAux], sector, 5);
        do{
                printf("Que desea modificar?\n");
                printf("\t1- Nombre\n");
                printf("\t2- Sexo\n");
                printf("\t3- Sueldo\n");
                printf("\t4- Sector\n");
                printf("\t5- Salir\n");
                scanf("%d", &menuModi);
                switch(menuModi){
                    case 1:
                        getValidString("Ingrese nuevo nombre: ", "Valor no valido.", modiEmpl.nombre);
                        strcpy(empl[idAux].nombre, modiEmpl.nombre);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 2:
                        modiEmpl.sexo = getChar("Ingrese sexo: ");
                        empl[idAux].sexo = modiEmpl.sexo;
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 3:
                        modiEmpl.sueldo =getValidFloat("Ingrese nuevo sueldo: ","Valor no valido", 10000, 99999);
                        empl[idAux].sueldo=modiEmpl.sueldo;
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 4:
                        modiEmpl.idSector = seleccionarSector(sector, lenSec);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 5:
                        break;
                    default :
                        printf("Error, ingrese numero entre 1 y 5.\n");
                        break;
                }
                printf("Desea editar otro dato? Presione 's' para aceptar, aprete cualquier otra tecla para salir.\n");
                fflush(stdin);
                scanf("%c", &contModi);
            }while (contModi == 's');
            printf("Saliendo al Menu...\n");
            ret = 0;
    }
    return ret;
}

int bajaEmpleadxs(eEmpleadx* empl, int lenEmp, eSector* sector, int lenSec){
    int ret = -1;
    int idAux = encontrarEmpleadxID(empl, lenEmp);
    int conBaja;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado empleadx. \n");
    }else{
        imprimirEmpleadx(empl[idAux], sector, lenSec);
        conBaja = getChar("Confirmar eliminacion? 's' para confirmar, otra tecla para cancelar");
        if (conBaja!='s'){
            printf("Eliminacion cancelada. \n");
        }else{
            empl[idAux].isEmpty= 1;
            ret = 0;
        }
    }
    return ret;
}


void hardcodeoEmpleadxs(eEmpleadx* empl){
     eEmpleadx y[]={
        {1, "Juan", 'm', 15000, 3, 0},
        {2, "Juana", 'f', 19000, 2, 0},
        {3, "Ana", 'f', 17000, 2, 0},
        {4, "Pepe", 'm', 1000, 5, 0},
        {5, "Ari", 'f', 25000, 4, 0},
    };

    for(int i=0; i<5; i++){
        empl[i] = y[i];
    }
    printf("\tHardcodeo hecho!\n");
}


void cargarSectores(eSector* sector, int lenPel, int idSector, char descripcion[]){
    for(int i=0; i<lenPel; i++){
        if(sector[i].id == idSector){
            strcpy(descripcion, sector[i].descripcion);
            break;
        }
    }
}

int seleccionarSector(eSector* sector, int lenSec){
    int idSector = -1;
    printf("\nSectores: \n\n");
    for(int i=0; i<lenSec; i++){
        printf("%d - %s\n", sector[i].id, sector[i].descripcion);
    }
    idSector = getValidInt("Seleccione ID de sector: ", "ID no valida.", 0, 500);
    return idSector;
}
