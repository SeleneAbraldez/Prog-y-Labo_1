#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "utn.h"


void inicializarDirectores(eDirectorx* dire, int lenDire){
    for(int i=0; i<lenDire; i++){
        dire[i].isEmpty = 1;
    }
}

int lugarLibreDirectorx(eDirectorx* dire, int lenDire){
    int index = -1;
    for(int i=0; i<lenDire; i++){
        if(dire[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int encontrarDirectorxID(eDirectorx* dire, int lenDire){
    int idAux = getValidInt("Ingrese ID de directorx: ", "Valor no valido. ", 0, 500);
    int ret = -1;
    for(int i=0; i < lenDire; i++){
        if(dire[i].id == idAux && dire[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int imprimirDirectorx(eDirectorx* dire, int index){
    printf("-Directorx ID: %d\nNombre: %s\nNacionalidad: %s\nFecha de nacimiento: %d/%d/%d\n\n", dire[index].id, dire[index].nombre, dire[index].nacionalidad, dire[index].nacimiento.dia, dire[index].nacimiento.mes, dire[index].nacimiento.anio);
    return 0;
}

int imprimirDirectores(eDirectorx* dire, int lenDire){
    for(int i = 0; i<lenDire; i++){
        if(dire[i].isEmpty == 0){
            printf("-Directorx ID: %d\nNombre: %s\nNacionalidad: %s\nFecha de nacimiento: %d/%d/%d\n\n", dire[i].id, dire[i].nombre, dire[i].nacionalidad, dire[i].nacimiento.dia, dire[i].nacimiento.mes, dire[i].nacimiento.anio);
        }
    }
    return 0;
}



void cargarDirectores(eDirectorx* dires, int lenPel, int idDirectorx, char nombre[]){
    for(int i=0; i<lenPel; i++){
        if(dires[i].id == idDirectorx){
            strcpy(nombre, dires[i].nombre);
            break;
        }
    }
}

int seleccionarDirectorx(eDirectorx* dires, int lenDire){
    int idDirectorx = -1;
    int direcont = 0;
    printf("\nDirectores: \n\n");
    for(int i=0; i<lenDire; i++){
        if(dires[i].isEmpty==0){
           printf("%d - %s\n", dires[i].id, dires[i].nombre);
            direcont++;
        }
    }
    if(direcont == 0){
        printf("!! - No hay directores cargadxs.\n");
    }else{
        idDirectorx = getValidInt("Seleccione ID de directorx: ", "ID no valida.", 0, 500);
    }
    return idDirectorx;
}




int altaDirectorx(eDirectorx* dire, int lenDire){
    int ret = -1;
    eDirectorx altaDire;
    int index = lugarLibreDirectorx(dire, lenDire);
    int id;

    if(index == -1){
        printf("!! - No mas hay espacio\n");
    } else {
        id = index + 1;
        altaDire.id = id;
        getValidString("Ingrese nombre: ", "Valor no valido.", altaDire.nombre);
        getValidString("Ingrese nacionalidad: ", "Valor no valido.", altaDire.nacionalidad);
        altaDire.nacimiento.dia =getValidInt("Ingrese dia de nacimiento: ","Dia no valido", 1, 30);
        altaDire.nacimiento.mes =getValidInt("Ingrese mes de nacimiento: ","Mes no valido", 1, 12);
        altaDire.nacimiento.anio =getValidInt("Ingrese anio de nacimiento: ","Anio no valido", 1700, 2018);
        altaDire.isEmpty = 0;
        dire[index] = altaDire;
        ret = 0;
    }
    return ret;
}

int bajaDirectorx(eDirectorx* dire, int lenDire){
    int ret = -1;
    int idAux = encontrarDirectorxID(dire, lenDire);
    int conBaja;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado directx con esa ID. \n");
    }else{
        imprimirDirectorx(dire, idAux);
        conBaja = getChar("Confirmar eliminacion? 's' para confirmar, otra tecla para cancelar");
        if (conBaja!='s'){
            printf("Eliminacion cancelada. \n");
        }else{
            dire[idAux].isEmpty= 1;
            ret = 0;
        }
    }
    return ret;
}



void hardcodeoDirectores(eDirectorx* dires){
    eDirectorx y[]={
        {1, "Quentin Tarantino", "Estados Unidos", {27, 3, 1963}, 0},
        {2, "Brad Silberling", "Estados Unidos", {8, 9, 1963}, 0},
        {3, "Bernardo Bertolucci", "Italia", {16, 3, 1941}, 0},
    };

    for(int i=0; i<3; i++){
        dires[i] = y[i];
    }
    printf("\tHardcodeo hecho!\n");
}
