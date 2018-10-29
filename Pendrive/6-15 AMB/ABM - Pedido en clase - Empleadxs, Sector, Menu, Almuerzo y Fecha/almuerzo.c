#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"
#include "utn.h"
#include "empleadxs.h"
#include "menu.h"


void inicializarAlmuerzo(eAlmuerzo* almuer, int lenAlmuer){
    for(int i=0; i<lenAlmuer; i++){
        almuer[i].isEmpty = 1;
    }
}

int lugarLibreAlmuerzo(eAlmuerzo* almuer, int lenAlmuer){
    int index = -1;
    for(int i=0; i<lenAlmuer; i++){
        if(almuer[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int encontrarAlmuerzoxID(eAlmuerzo* almuer, int lenAlmuer){
    int idAux = getValidInt("Ingrese ID almuerzo: ", "Valor no valido. ", 0, 1000);
    int ret = -1;
    for(int i=0; i < lenAlmuer; i++){
        if(almuer[i].idA == idAux && almuer[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int imprimirAlmuerzo(eAlmuerzo almuer, int lenAlmuer, eEmpleadx* empl, int lenEmpl, eMenu* menuu, int lenMenu){
    char nombri[41];
    cargarEmpleadxs(empl, lenEmpl, almuer.idEmpleadx, nombri);
    char comida[31];
    cargarMenus(menuu, lenMenu, almuer.idMenu, comida);
    printf("\nidA: %d\nEmpleadx: %s\nMenu: %s\nFecha: %d/%d/%d\n\n", almuer.idA, nombri, comida, almuer.diaDeAlmuerzo.dia, almuer.diaDeAlmuerzo.mes, almuer.diaDeAlmuerzo.anio);
    return 0;
}

int imprimirAlmuerzos(eAlmuerzo* almuer, int lenAlmuer, eEmpleadx* empl, int lenEmpl, eMenu* menuu, int lenMenu){
    for(int i = 0; i<lenAlmuer; i++){
        if(almuer[i].isEmpty == 0){
            imprimirAlmuerzo(almuer[i], lenAlmuer, empl, lenEmpl, menuu, lenMenu);
        }
    }
    return 0;
}


int altaAlmuerzo(eAlmuerzo* almuer, int lenAlmuer, eEmpleadx* empl, int lenEmpl, eMenu* menuu, int lenMenu){
    int ret = -1;
    eAlmuerzo altaAlmuer;
    int index = lugarLibreAlmuerzo(almuer, lenAlmuer);
    int idA;

    if(index == -1){
        printf("!! - No mas hay espacio\n");
    } else {
        idA = index + 100;
        altaAlmuer.idA = idA;
        altaAlmuer.idEmpleadx = seleccionarEmpleadx(empl, lenEmpl);
        altaAlmuer.idMenu = seleccionarMenu(menuu, lenMenu);
        altaAlmuer.diaDeAlmuerzo.dia =getValidInt("Ingrese dia de nacimiento: ","Dia no valido", 1, 30);
        altaAlmuer.diaDeAlmuerzo.mes =getValidInt("Ingrese mes de nacimiento: ","Mes no valido", 1, 12);
        altaAlmuer.diaDeAlmuerzo.anio =getValidInt("Ingrese anio de nacimiento: ","Anio no valido", 1700, 2018);
        altaAlmuer.isEmpty = 0;
        almuer[index] = altaAlmuer;
        ret = 0;
    }
    return ret;
}

int bajaAlmuerzo(eAlmuerzo* almuer, int lenAlmuer, eEmpleadx* empl, int lenEmpl, eMenu* menuu, int lenMenu){
    int ret = -1;
    int idAux = encontrarAlmuerzoxID(almuer, lenAlmuer);
    int conBaja;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado el almuerzo. \n");
    }else{
        imprimirAlmuerzo(almuer[idAux], lenAlmuer, empl, lenEmpl, menuu, lenMenu);
        conBaja = getChar("Confirmar eliminacion? 's' para confirmar, otra tecla para cancelar");
        if (conBaja!='s'){
            printf("Eliminacion cancelada. \n");
        }else{
            almuer[idAux].isEmpty= 1;
            ret = 0;
        }
    }
    return ret;
}


void cargarEmpleadxs(eEmpleadx* empl, int lenEmpl, int idEmpleadxs, char nombre[]){
    for(int i=0; i<lenEmpl; i++){
        if(empl[i].legajo == idEmpleadxs){
            strcpy(nombre, empl[i].nombre);
            break;
        }
    }
}

int seleccionarEmpleadx(eEmpleadx* empl, int lenEmpl){
    int idEmpleadx = -1;
    int emplCont = 0;
    printf("\nSectores: \n\n");
    for(int i=0; i<lenEmpl; i++){
        printf("%d - %s\n", empl[i].legajo, empl[i].nombre);
        emplCont++;
    }
    if(emplCont == 0){
        printf("!! - No hay empleadxs cargadxs.\n");
    }else{
        idEmpleadx = getValidInt("Seleccione ID de empleadx: ", "ID no valida.", 0, 500);
    }
    return idEmpleadx;
}



void cargarMenus(eMenu* menuu, int lenMenu, int idMenu, char descripcion[]){
    for(int i=0; i<lenMenu; i++){
        if(menuu[i].idM == idMenu){
            strcpy(descripcion, menuu[i].descripcion);
            break;
        }
    }
}

int seleccionarMenu(eMenu* menuu, int lenMenu){
    int idMenu = -1;
    int menuCont = 0;
    printf("\nSectores: \n\n");
    for(int i=0; i<lenMenu; i++){
        printf("%d - %s\n", menuu[i].idM, menuu[i].descripcion);
        menuCont++;
    }
    if(menuCont == 0){
        printf("!! - No hay menus cargados.\n");
    }else{
        idMenu = getValidInt("Seleccione ID de menu: ", "ID no valida.", 0, 500);
    }
    return idMenu;
}

void hardcodeoAlmuerzo(eAlmuerzo* almuer){
     eAlmuerzo y[]={
        {100, 1, 4, {30, 5, 2018}, 0},
        {101, 3, 2, {06, 5, 2018}, 0},
        {102, 2, 4, {21, 5, 2018}, 0},
        {103, 1, 5, {04, 5, 2018}, 0},
        {104, 4, 3, {19, 5, 2018}, 0},
        {105, 1, 1, {24, 5, 2018}, 0},
        {106, 5, 3, {13, 5, 2018}, 0},
        {107, 3, 4, {17, 6, 2018}, 0},
        {108, 2, 5, {18, 6, 2018}, 0},
        {109, 4, 4, {20, 6, 2018}, 0},
        {110, 1, 2, {10, 6, 2018}, 0},
    };

    for(int i=0; i<11; i++){
        almuer[i] = y[i];
    }
    printf("\tHardcodeo hecho!\n");
}
