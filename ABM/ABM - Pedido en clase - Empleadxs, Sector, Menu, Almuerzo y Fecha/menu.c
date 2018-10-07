#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "utn.h"

void inicializarMenu(eMenu* comis, int lenMen){
    for(int i=0; i<lenMen; i++){
        comis[i].isEmpty = 1;
    }
}

int lugarLibreMenu(eMenu* comis, int lenMen){
    int index = -1;
    for(int i=0; i<lenMen; i++){
        if( comis[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int encontrarMenuxID(eMenu* comis, int lenMen){
    int idAux = getValidInt("Ingrese ID cMenu: ", "Valor no valido. ", 0, 1000);
    int ret = -1;
    for(int i=0; i < lenMen; i++){
        if(comis[i].idM == idAux && comis[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int imprimirMenu(eMenu comis, int lenMen){
    printf("\nIdM: %d\nDescripcion: %s\n\n", comis.idM, comis.descripcion);
    return 0;
}

int imprimirMenus(eMenu* comis, int lenMen){
    for(int i = 0; i<lenMen; i++){
        if(comis[i].isEmpty == 0){
            imprimirMenu(comis[i], lenMen);
        }
    }
    return 0;
}


int altaMenu(eMenu* comis, int lenMen){
    int ret = -1;
    eMenu altaComis;
    int index = lugarLibreMenu(comis, lenMen);
    int idM;

    if(index == -1){
        printf("!! - No mas hay espacio\n");
    } else {
        idM = index + 1;
        altaComis.idM = idM;
        getValidString("Ingrese descripcion: ", "Valor no valido.", altaComis.descripcion);
        altaComis.isEmpty = 0;
        comis[index] = altaComis;
        ret = 0;
    }
    return ret;
}

int bajaMenu(eMenu* comis, int lenMen){
    int ret = -1;
    int idAux = encontrarMenuxID(comis, lenMen);
    int conBaja;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado la cMenu. \n");
    }else{
        imprimirMenu(comis[idAux], lenMen);
        conBaja = getChar("Confirmar eliminacion? 's' para confirmar, otra tecla para cancelar");
        if (conBaja!='s'){
            printf("Eliminacion cancelada. \n");
        }else{
            comis[idAux].isEmpty= 1;
            ret = 0;
        }
    }
    return ret;
}




void hardcodeoMenu(eMenu* comis){
     eMenu y[]={
        {1, "Ensalada", 0},
        {2, "Tortilla", 0},
        {3, "Mila de Soja", 0},
        {4, "Revuelto", 0},
        {5, "Tarta", 0},
    };

    for(int i=0; i<5; i++){
        comis[i] = y[i];
    }
    printf("\tHardcodeo hecho!\n");
}
