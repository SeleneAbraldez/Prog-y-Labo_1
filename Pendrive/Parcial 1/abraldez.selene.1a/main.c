#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#include "utn.h"

#define CANTJUEG 20
#define CANTCLIEN 100
#define CANTALQUILERES 2000

int main(){
    char seguir = 's';
    int contJueg = 0;
    int contClien = 0;
    char ayu[51];

    eJuegos juegos[CANTJUEG];
    eClientes clientes[CANTCLIEN];
    eAlquiler alquileres[CANTALQUILERES];

    inicializarJuegos(juegos, CANTJUEG);
    inicializarClientes(clientes, CANTCLIEN);
    inicializAlquiler(alquileres, CANTALQUILERES);

    do{
        switch(menu()){
            case 1:
                if(altaJuego(juegos, CANTJUEG) == 0){
                    contJueg++;
                }
                break;
            case 2:
                 if(contJueg == 0){
                    printf("No hay juegos cargados. \n");
                }else{
                     modificarJuego(juegos, CANTJUEG);
                }
                break;
            case 3:
                if(contJueg == 0){
                    printf("No hay juegos cargados. \n");
                }else{
                    if(bajaJuego(juegos, CANTJUEG) == 0){
                        contJueg--;
                    }
                }
                break;
            case 4:
                if(contJueg == 0){
                    printf("No hay juegos cargados. \n");
                }else{
                    ordenarJuegos(juegos, CANTJUEG);
                    imprimirJuegos(juegos, CANTJUEG);
                }
                break;
//
            case 5:
                if(altaCliente(clientes, CANTCLIEN) == 0){
                    contClien++;
                }
                break;
            case 6:
                if(contClien == 0){
                    printf("No hay clientes cargados. \n");
                }else{
                     modificarCliente(clientes, CANTJUEG);
                }
                break;
            case 7:
                if(contClien == 0){
                    printf("No hay clientes cargados. \n");
                }else{
                    if(bajaCliente(clientes, CANTCLIEN) == 0){
                        contClien--;
                    }
                }
                break;
            case 8:
                 if(contClien == 0){
                    printf("No hay clientes cargados. \n");
                }else{
                    ordenarClientes(clientes, CANTCLIEN);
                    imprimirClientes(clientes, CANTCLIEN);
                }
                break;

//
            case 9:
                if (contClien==0){
                    printf("No hay clientes cargadxs para realizar alta alquiler.\n");
                    if(contJueg==0){
                        printf("No hya juegos cargados para realizar alta alquiler. \n");
                    }
                }else{
                    altaAlquiler(alquileres, CANTALQUILERES, juegos, CANTJUEG, clientes, CANTCLIEN);
                }
                break;
//
            case 10:
                if (contClien==0){
                    printf("No hay clientes cargadxs para realizar tarea.\n");
                    if(contJueg==0){
                        printf("No hay juegos cargados para realizar tarea. \n");
                    }
                }else{
                    promedioImporte(alquileres, CANTALQUILERES, juegos, CANTJUEG, clientes, CANTCLIEN);
                }
                break;
            case 11:
                if (contClien==0){
                    printf("No hay clientes cargadxs para realizar tarea.\n");
                    if(contJueg==0){
                        printf("No hay juegos cargados para realizar tarea. \n");
                    }
                }else{

                }
                break;
            case 12:
                if (contClien==0){
                    printf("No hay clientes cargadxs para realizar tarea.\n");
                    if(contJueg==0){
                        printf("No hay juegos cargados para realizar tarea. \n");
                    }
                }else{
                    listarClientesxJuego(alquileres, CANTALQUILERES, juegos, CANTJUEG, clientes, CANTCLIEN);
                }
                break;
            case 13:
                if (contClien==0){
                    printf("No hay clientes cargadxs para realizar tarea.\n");
                    if(contJueg==0){
                        printf("No hay juegos cargados para realizar tarea. \n");
                    }
                }else{
                    listarJuegosxCliente(alquileres, CANTALQUILERES, juegos, CANTJUEG, clientes, CANTCLIEN);
                }
                break;



            case 16:
                if (contClien==0){
                    printf("No hay clientes cargadxs para realizar tarea.\n");
                    if(contJueg==0){
                        printf("No hay juegos cargados para realizar tarea. \n");
                    }
                }else{
                    listarJuegosXFecha(alquileres, CANTALQUILERES, juegos, CANTJUEG, clientes, CANTCLIEN);
                }
                break;
            case 17:
                if (contClien==0){
                    printf("No hay clientes cargadxs para realizar tarea.\n");
                    if(contJueg==0){
                        printf("No hay juegos cargados para realizar tarea. \n");
                    }
                }else{
                    listarClientesXFecha(alquileres, CANTALQUILERES, juegos, CANTJUEG, clientes, CANTCLIEN);
                }
                break;


            case 18:
                 if(contJueg == 0){
                    printf("No hay juegos cargados. \n");
                }else{
                    ordenarJuegosXImporteBurb(juegos, CANTJUEG);
                    imprimirJuegos(juegos, CANTJUEG);
                }
                break;
            case 19:
                 if(contClien == 0){
                    printf("No hay clientes cargadxs. \n");
                }else{
                    ordenarClientesInsercion(clientes, CANTCLIEN);
                    imprimirClientes(clientes, CANTCLIEN);
                }
                break;
//
            case 0:
                hardcodeoJuegos(juegos);
                contJueg = contJueg + 5;
                hardcodeoClientes(clientes);
                contClien = contClien + 5;
                hardcodeoAlquiler(alquileres);
                break;
//
            case 100:
                seguir = 'n';
                break;
            default:
                printf("Ingrese valor valido.\n");
                break;
            }

    system("pause");
    }while(seguir == 's');

    return 0;
}

