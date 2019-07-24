#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "peliculas.h"


void inicializarPeliculas(ePeliculas* pelis, int lenPel){
    for(int i=0; i<lenPel; i++){
        pelis[i].isEmpty = 1;
    }
}

int lugarLibrePeliculas(ePeliculas* pelis, int lenPel){
    int index = -1;
    for(int i=0; i<lenPel; i++){
        if( pelis[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int encontrarPeliculaID(ePeliculas* pelis, int lenPel){
    int idAux = getValidInt("Ingrese ID de pelicula: ", "Valor no valido. ", 0, 1000);
    int ret = -1;
    for(int i=0; i < lenPel; i++){
        if(pelis[i].id == idAux && pelis[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int imprimirPelicula(ePeliculas* pelis, int lenPel, int index, eDirectorx* dires){
    char nombre[41];
    cargarDirectores(dires, lenPel, pelis->idDirectorx, nombre);
    printf("-Pelicula ID: %d\nTitulo: %s\nAnio: %d\nDirectorx: %s\n\n", pelis[index].id, pelis[index].titulo, pelis[index].anio, nombre);
    return 0;
}

int imprimirPeliculas(ePeliculas* pelis, int lenPel, eDirectorx* dires, int lenDire){
    char nombre[41];
    for(int i = 0; i<lenPel; i++){
        if(pelis[i].isEmpty == 0){
            cargarDirectores(dires, lenPel, pelis->idDirectorx ,nombre);
            printf("-Pelicula ID: %d\nTitulo: %s\nAnio: %d\nDirectorx: %s\n\n", pelis[i].id, pelis[i].titulo, pelis[i].anio, nombre);
        }
    }
    return 0;
}


int altaPelicula(ePeliculas* pelis, int lenPel, eDirectorx* dires, int lenDire){
    int ret = -1;
    ePeliculas altaPeli;
    int index = lugarLibrePeliculas(pelis, lenPel);
    int id;

    if(index == -1){
        printf("!! - No mas hay espacio\n");
    } else {
        id = index + 1;
        altaPeli.id = id;
        getValidString("Ingrese titulo: ", "Valor no valido.", altaPeli.titulo);
        altaPeli.anio =getValidInt("Ingrese Anio: ","Anio no valido", 1895, 2018);
        getValidString("Ingrese nacionalidad: ", "Valor no valido.", altaPeli.nacionalidad);
        altaPeli.idDirectorx = seleccionarDirectorx(dires, lenDire);
        altaPeli.isEmpty = 0;
        pelis[index] = altaPeli;
        ret = 0;
    }
    return ret;
}

int modificarPelicula(ePeliculas* pelis, int lenPel, eDirectorx* dires, int lenDire){
    int ret = -1;
    int idAux = encontrarPeliculaID(pelis, lenPel);
    int menuModi;
    char contModi = 's';
    ePeliculas modiPeli;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado la pelicula. \n");
    }else{
        imprimirPelicula(pelis, lenPel, idAux, dires);
        do{
                printf("Que desea modificar?\n");
                printf("\t1- Titulo\n");
                printf("\t2- Anio\n");
                printf("\t3- Nacionalidad\n");
                printf("\t4- Director\n");
                printf("\t5- Salir\n");
                scanf("%d", &menuModi);
                switch(menuModi){
                    case 1:
                        getValidString("Ingrese nuevo titulo: ", "Valor no valido.", modiPeli.titulo);
                        strcpy(pelis[idAux].titulo, modiPeli.titulo);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 2:
                        modiPeli.anio =getValidFloat("Ingrese nuevo anio: ","Valor no valido", 1895, 2018);
                        pelis[idAux].anio=modiPeli.anio;
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 3:
                        getValidString("Ingrese nueva nacionalidad: ", "Valor no valido.", modiPeli.nacionalidad);
                        strcpy(pelis[idAux].nacionalidad, modiPeli.nacionalidad);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 4:
                        modiPeli.idDirectorx = seleccionarDirectorx(dires, lenDire);
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

int bajaPelicula(ePeliculas* pelis, int lenPel, eDirectorx* dires, int lenDire){
    int ret = -1;
    int idAux = encontrarPeliculaID(pelis, lenPel);
    int conBaja;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado la pelicula. \n");
    }else{
        imprimirPelicula(pelis, lenPel, idAux, dires);
        conBaja = getChar("Confirmar eliminacion? 's' para confirmar, otra tecla para cancelar");
        if (conBaja!='s'){
            printf("Eliminacion cancelada. \n");
        }else{
            pelis[idAux].isEmpty= 1;
            ret = 0;
        }
    }
    return ret;
}




void hardcodeoPeliculas(ePeliculas* pelis){
    ePeliculas y[]={
        {1, "Death Proof", 2007, "Americana", 1, 0},
        {2, "The Dreamers", 2003, "Francesa", 1, 0},
        {3, "Lemony Snicket", 2004, "Americana", 2, 0},
        {4, "From Dusk Till Dawn", 1996, "Americana", 1, 0},
        {4, "Reservoir Dogs", 1992, "Americana", 1, 0},
    };

    for(int i=0; i<5; i++){
        pelis[i] = y[i];
    }
    printf("\tHardcodeo hecho!\n");
}





