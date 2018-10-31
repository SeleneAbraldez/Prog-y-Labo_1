#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "juegos.h"
#include "utn.h"

void inicializarJuegos(eJuegos* jueg, int lenJueg){
    for(int i=0; i<lenJueg; i++){
        jueg[i].isEmpty = 1;
    }
}

int lugarLibreJuegos(eJuegos* jueg, int lenJueg){
    int index = -1;
    for(int i=0; i<lenJueg; i++){
        if( jueg[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int encontrarJuegoxID(eJuegos* jueg, int lenJueg){
    int idAux = getValidInt("Ingrese ID de juego: ", "Valor no valido. ", 0, 100);
    int ret = -1;
    for(int i=0; i < lenJueg; i++){
        if(jueg[i].idJ == idAux && jueg[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int imprimirJuego(eJuegos jueg){
    printf("\nidJ: %d\nDescripcion: %s\nImporte: %.2f\n\n", jueg.idJ, jueg.descripcion, jueg.importe);
    return 0;
}

int imprimirJuegos(eJuegos* jueg, int lenJueg){
    for(int i = 0; i<lenJueg; i++){
        if(jueg[i].isEmpty == 0){
            imprimirJuego(jueg[i]);
        }
    }
    return 0;
}


int altaJuego(eJuegos* jueg, int lenJueg){
    int ret = -1;
    eJuegos altaJueg;
    int index = lugarLibreJuegos(jueg, lenJueg);
    int idJ;

    if(index == -1){
        printf("!! - No mas hay espacio\n");
    } else {
        idJ = index + 1;
        altaJueg.idJ = idJ;
        printf("-Juego %d\n",idJ);
        getValidStringLen("Ingrese descripcion: ", "Valor no valido.", "Dato debe ser menor a 50 caracteres: ", altaJueg.descripcion, 51);
        altaJueg.importe = getValidFloat("Ingrese importe: ", "Valor no valido. ", 0 , 100000);
        altaJueg.isEmpty = 0;
        jueg[index] = altaJueg;
        ret = 0;
    }
    return ret;
}

int modificarJuego(eJuegos* jueg, int lenJueg){
    int ret = -1;
    int idAux = encontrarJuegoxID(jueg, lenJueg);
    int menuModi;
    char contModi = 's';
    eJuegos modiJueg;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado juego. \n");
    }else{
        imprimirJuego(jueg[idAux]);
        do{
                printf("Que desea modificar?\n");
                printf("\t1- Descripcion\n");
                printf("\t2- Importe\n");
                printf("\t3- Salir\n");
                scanf("%d", &menuModi);
                switch(menuModi){
                    case 1:
                        getValidStringLen("Ingrese nueva descripcion: ", "Valor no valido.","Dato debe ser menor a 50 caracteres: ", modiJueg.descripcion, 51);
                        strcpy(jueg[idAux].descripcion, modiJueg.descripcion);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 2:
                        modiJueg.importe = getValidFloat("Ingrese nuevo importe: ", "Valor no valido. ", 0 , 100000);
                        jueg[idAux].importe= modiJueg.importe;
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 3:
                        break;
                    default :
                        printf("Error, ingrese numero entre 1 y 3.\n");
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

int bajaJuego(eJuegos* jueg, int lenJueg){
    int ret = -1;
    int idAux = encontrarJuegoxID(jueg, lenJueg);
    int conBaja;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado juego. \n");
    }else{
        imprimirJuego(jueg[idAux]);
        conBaja = getChar("Confirmar eliminacion? 's' para confirmar, otra tecla para cancelar");
        if (conBaja!='s'){
            printf("Eliminacion cancelada. \n");
        }else{
            jueg[idAux].isEmpty= 1;
            ret = 0;
        }
    }
    return ret;
}


int ordenarJuegos(eJuegos* jueg, int lenJueg){
    int ret = -1;
    eJuegos auxJueg;
    for(int i =0 ; i<lenJueg-1 ; i ++){
        for(int j= i+1 ; j<lenJueg; j++){
            if(jueg[j].importe>jueg[i].importe && jueg[j].isEmpty==0 && jueg[i].isEmpty==0){
                auxJueg = jueg[i];
                jueg[i] = jueg[j];
                jueg[j] = auxJueg;
             }else if(jueg[j].importe==jueg[i].importe && strcmp(jueg[j].descripcion,jueg[i].descripcion)<0 && jueg[j].isEmpty==0 && jueg[i].isEmpty==0){
                auxJueg = jueg[i];
                jueg[i] = jueg[j];
                jueg[j] = auxJueg;
            }
        }
    }
    printf("\t1--Listado de juegos Importe y Descripcion\n\n");
    ret = 0;
    return ret;
}

void ordenarJuegosXImporteBurb(eJuegos* jueg, int lenJueg){
    eJuegos auxJueg;
    int flagNoEstaOrdenado = 1;
    while (flagNoEstaOrdenado==1)
    {
         flagNoEstaOrdenado = 0;
         for (int i = 1; i < lenJueg; i++)
         {
             if (jueg[i].importe > jueg[i - 1].importe)
             {
                 auxJueg = jueg[i];
                 jueg[i] = jueg[i - 1];
                 jueg[i - 1] = auxJueg;
                 flagNoEstaOrdenado = 1;
            }
         }
    }
}


void hardcodeoJuegos(eJuegos* jueg){
     eJuegos y[]={
        {1, "Truco", 5000, 0},
        {2, "Uno", 7000, 0},
        {3, "Ludo", 5000, 0},
        {4, "Serpien", 5000, 0},
        {5, "Chancho", 3000, 0},
    };

    for(int i=0; i<5; i++){
        jueg[i] = y[i];
    }
    printf("\tHardcodeo juegos hecho!\n");
}
