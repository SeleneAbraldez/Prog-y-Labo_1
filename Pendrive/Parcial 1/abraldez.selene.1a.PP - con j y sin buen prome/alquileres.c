#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alquileres.h"
#include "utn.h"
#include "juegos.h"
#include "clientes.h"


void inicializAlquiler(eAlquiler* alqui, int lenAlqui){
    for(int i=0; i<lenAlqui; i++){
        alqui[i].isEmpty = 1;
    }
}

int lugarLibreAlquiler(eAlquiler* alqui, int lenAlqui){
    int index = -1;
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int encontrAlquilerxID(eAlquiler* alqui, int lenAlqui){
    int idAux = getValidInt("Ingrese ID Alquiler: ", "Valor no valido. ", 0, 1000);
    int ret = -1;
    for(int i=0; i < lenAlqui; i++){
        if(alqui[i].idA == idAux && alqui[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int imprimirAlquiler(eAlquiler alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    char descripcion[41];
    cargarJuegos(jueg, lenJueg, alqui.idJuego, descripcion);
    char apellido[31];
    char nombre[31];
    cargarCliente(clien, lenClien, alqui.idCliente, apellido, nombre);
    printf("\nidA: %d\nJuego: %s\nCliente: %s\nFecha: %d/%d/%d\n\n", alqui.idA, descripcion, apellido, alqui.diaDeAlquiler.dia, alqui.diaDeAlquiler.mes, alqui.diaDeAlquiler.anio);
    return 0;
}

int imprimirAlquileres(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    for(int i = 0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0){
            imprimirAlquiler(alqui[i], lenAlqui, jueg, lenJueg, clien, lenClien);
        }
    }
    return 0;
}


int altaAlquiler(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int ret = -1;
    eAlquiler altaAlqui;
    int index = lugarLibreAlquiler(alqui, lenAlqui);
    int idA;

    if(index == -1){
        printf("!! - No mas hay espacio\n");
    } else {
        idA = index + 100;
        altaAlqui.idA = idA;
        printf("-Alquiler %d\n",idA);
        altaAlqui.idJuego = seleccionarJuego(jueg, lenJueg);
        altaAlqui.idCliente = seleccionarCliente(clien, lenClien);
        altaAlqui.diaDeAlquiler.dia =getValidInt("Ingrese dia de alquiler: ","Dia no valido", 1, 30);
        altaAlqui.diaDeAlquiler.mes =getValidInt("Ingrese mes de alquiler: ","Mes no valido", 1, 12);
        altaAlqui.diaDeAlquiler.anio =getValidInt("Ingrese anio de alquiler: ","Anio no valido", 2000, 2018);
        altaAlqui.isEmpty = 0;
        alqui[index] = altaAlqui;
        ret = 0;
    }
    return ret;
}



void cargarJuegos(eJuegos* jueg, int lenJueg, int idJuegos, char descripcion[]){
    for(int i=0; i<lenJueg; i++){
        if(jueg[i].idJ == idJuegos){
            strcpy(descripcion, jueg[i].descripcion);
            break;
        }
    }
}

int seleccionarJuego(eJuegos* jueg, int lenJueg){
    int idJuego = -1;
    int juegCont = 0;
    printf("\nJuegos: \n");
    for(int i=0; i<lenJueg; i++){
        if(jueg[i].isEmpty == 0){
            printf("%d - %s\n", jueg[i].idJ, jueg[i].descripcion);
            juegCont++;
        }
    }
    if(juegCont == 0){
        printf("!! - No hay juegos cargados.\n");
    }else{
        idJuego = getValidInt("\nSeleccione ID de juego: ", "ID no valida.", 0, 20);
    }
    return idJuego;
}



void cargarCliente(eClientes* clien, int lenClien, int idCliente, char apellido[], char nombre[]){
    for(int i=0; i<lenClien; i++){
        if(clien[i].idC == idCliente){
            strcpy(apellido, clien[i].apellido);
            strcpy(nombre, clien[i].nombre);
            break;
        }
    }
}

int seleccionarCliente(eClientes* clien, int lenClien){
    int idMenu = -1;
    int contClien = 0;
    printf("\nClientes: \n");
    for(int i=0; i<lenClien; i++){
        if(clien[i].isEmpty==0){
            printf("%d - %s %s\n", clien[i].idC, clien[i].apellido, clien[i].nombre);
            contClien++;
        }
    }
    if(contClien == 0){
        printf("!! - No hay clientes cargados.\n");
    }else{
        idMenu = getValidInt("\nSeleccione ID de cliente: ", "ID no valida.", 0, 100);
    }
    return idMenu;
}





float promedioImportes(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    float conAlqui = 0;
    float importeTotal = 0;
    float promedio = -1;
    float importe;

    for(int i = 0; i<lenAlqui; i++){
        for(int j=0; j<lenJueg; j++){
            if(alqui[i].idJuego == jueg[j].idJ && alqui[i].isEmpty == 0 && jueg[j].isEmpty == 0){
                importe = jueg[j].importe;
                importeTotal = importeTotal + importe;
                conAlqui++;
            }
        }
    }

    promedio = importeTotal / conAlqui;
    printf("\n\t--Promedio y total de los juegos-- \n\n");
    printf("Total: %.2f\t\t", importeTotal);
    printf("Promedio: %.2f\n\n", promedio);
    return promedio;
}

int bajoPromedio(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){ //funcional pero repitiendo codigo
    float conAlqui = 0;
    int bajoProm = 0;
    float importeTotal = 0;
    float promedio = -1;
    float importe;

    for(int i = 0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0){
            for(int j=0; j<lenJueg; j++){
                if(jueg[j].isEmpty == 0){
                    if(alqui[i].idJuego == jueg[j].idJ){
                        importe = jueg[j].importe;
                        importeTotal = importeTotal + importe;
                        conAlqui++;
                    }
                }
            }
        }
    }
    promedio = importeTotal / conAlqui;

    for(int i = 0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0){
            for(int j=0; j<lenJueg; j++){
                if(jueg[j].isEmpty == 0){
                    if(alqui[i].idJuego == jueg[j].idJ){
                        if(jueg[j].importe<promedio){
                            bajoProm++;
                        }
                    }
                }
            }
        }
    }

    printf("\n--Juegos cuyo importe no superan el promedio: ");
    printf(" %d \n", bajoProm);
    return 0;
}

void bajoPromedioPunt(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien, float prome){
    int bajoProm = 0;

    printf("dentro funcion %f \n", prome);

    /*for(int i = 0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0){
            for(int j=0; i<lenJueg; j++){
                if(jueg[j].isEmpty == 0){
                    if(alqui[i].idJuego == jueg[j].idJ){
                        if(jueg[i].importe<promedio){
                            bajoProm++;
                        }
                    }
                }
            }
        }
    }

    printf("\n--Juegos cuyo importe no superan el promedio: ");
    printf(" %f - ", promedio);
    printf(" %d\n", bajoProm);*/
}


void listarClientesxJuego(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int idJueg;
    int idClien;
    char descripcion[51];
    int flag = 0;

    idJueg = seleccionarJuego(jueg, lenJueg);
    cargarJuegos(jueg, lenJueg, idJueg, descripcion);

    printf("\n--Alquileres de %s--\n", descripcion);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].idJuego == idJueg){
            idClien = alqui[i].idCliente;
            for(int j=0; j<lenClien; j++){
                if(clien[j].isEmpty == 0 && clien[j].idC == idClien){
                    printf("\nAlquiler %d:\n", alqui[i].idA);
                    imprimirCliente(clien[j]);
                    flag = 1;
                }
            }
        }
    }
    if(flag == 0){
        printf("No hay clientes que mostrar. \n");
    }
}

void listarJuegosxCliente(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int idClien;
    int idJueg;
    char apellido[51];
    char nombre[51];
    int flag = 0;

    idClien = seleccionarCliente(clien, lenClien);
    cargarCliente(clien, lenClien, idClien, apellido, nombre);



    printf("\n--Alquileres de %s %s--\n", apellido, nombre);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].idCliente == idClien){
            idJueg = alqui[i].idJuego;
            for(int j=0; j<lenJueg; j++){
                if(jueg[j].isEmpty == 0 && jueg[j].idJ == idJueg){
                    printf("\nAlquiler %d:\n", alqui[i].idA);
                    imprimirJuego(jueg[j]);
                    flag = 1;
                }
            }
        }
    }
    if(flag == 0){
        printf("No hay juegos que mostrar. \n");
    }
}


void listarJuegosMenosAlqui(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int menosCon = 0;
    int menosConAux;
    int flagMenos = 0;

    for(int j=1; j<lenJueg+1; j++){
        if(jueg[j].isEmpty == 0){
            for(int i=0; i<lenAlqui; i++){
            if(alqui[i].isEmpty == 0){
                if(alqui[i].idJuego == j){
                    menosCon++;
                    printf("id %d - ", j);
                    printf("%d ", menosCon);
                }
            }
        }
        if(flagMenos == 0){
            menosConAux = menosCon;
            flagMenos = 1;
        }
        if(menosCon < menosConAux){
            menosConAux = menosCon;
        }
        menosCon = 0;
        }
    }

    printf("Minimo: %d \n", menosConAux);

    printf("\n--Juego/s menos alquilado/s (%d veces)--\n", menosConAux);
    for(int j=1; j<lenJueg+1; j++){
        if(jueg[j-1].isEmpty == 0){
            for(int i=0; i<lenAlqui; i++){
                if(alqui[i].isEmpty == 0){
                    if(alqui[i].idJuego == j){
                        menosCon++;
                    }
                }
            }
            if(menosCon == menosConAux){
                imprimirJuego(jueg[j-1]);
            }
            menosCon = 0;
        }
    }

}


void listarClienteMasAlqui(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int masCon = 0;
    int masConAux = 0;

    for(int j=1; j<clien+1; j++){
        for(int i=0; i<lenAlqui; i++){
            if(alqui[i].isEmpty == 0){
                if(alqui[i].idCliente == j){
                    masCon++;
                    //printf("id %d - ", j);
                    //printf("%d ", masCon);
                }
            }
        }
        if(masCon > masConAux){
            masConAux = masCon;
        }
        masCon = 0;
    }

    //printf("Maximo: %d \n", masConAux);

    printf("\n--Cliente/s con mas alquileres (%d alquileres)--\n", masConAux);
    for(int j=1; j<clien+1; j++){
        for(int i=0; i<lenAlqui; i++){
            if(alqui[i].isEmpty == 0){
                if(alqui[i].idCliente == j){
                    masCon++;
                }
            }
        }
        if(masCon == masConAux){
            imprimirCliente(clien[j-1]);
        }
        masCon = 0;
    }

}


void listarJuegosXFecha(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int idJueg;
    eAlquiler auxAlqui;
    int flag = 0;

    auxAlqui.diaDeAlquiler.dia =getValidInt("Ingrese dia de alquiler: ","Dia no valido", 1, 30);
    auxAlqui.diaDeAlquiler.mes =getValidInt("Ingrese mes de alquiler: ","Mes no valido", 1, 12);
    auxAlqui.diaDeAlquiler.anio =getValidInt("Ingrese anio de alquiler: ","Anio no valido", 2000, 2018);

    printf("\n--Alquileres del %d/%d/%d--\n", auxAlqui.diaDeAlquiler.dia, auxAlqui.diaDeAlquiler.mes, auxAlqui.diaDeAlquiler.anio);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].diaDeAlquiler.dia == auxAlqui.diaDeAlquiler.dia && alqui[i].diaDeAlquiler.mes == auxAlqui.diaDeAlquiler.mes && alqui[i].diaDeAlquiler.anio == auxAlqui.diaDeAlquiler.anio){
            idJueg = alqui[i].idJuego;
            for(int j=0; j<lenJueg; j++){
                if(jueg[j].isEmpty == 0 && jueg[j].idJ == idJueg){
                    printf("\nAlquiler %d:\n", alqui[i].idA);
                    imprimirJuego(jueg[j]);
                    flag = 1;
                }
            }
        }
    }
    if(flag == 0){
        printf("No hay juegos que mostrar. \n");
    }
}

void listarClientesXFecha(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int idClien;
    eAlquiler auxAlqui;
    int flag = 0;

    auxAlqui.diaDeAlquiler.dia = getValidInt("Ingrese dia de alquiler: ","Dia no valido", 1, 30);
    auxAlqui.diaDeAlquiler.mes = getValidInt("Ingrese mes de alquiler: ","Mes no valido", 1, 12);
    auxAlqui.diaDeAlquiler.anio = getValidInt("Ingrese anio de alquiler: ","Anio no valido", 2000, 2018);

    printf("\n--Alquileres del %d/%d/%d--\n", auxAlqui.diaDeAlquiler.dia, auxAlqui.diaDeAlquiler.mes, auxAlqui.diaDeAlquiler.anio);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].diaDeAlquiler.dia == auxAlqui.diaDeAlquiler.dia && alqui[i].diaDeAlquiler.mes == auxAlqui.diaDeAlquiler.mes && alqui[i].diaDeAlquiler.anio == auxAlqui.diaDeAlquiler.anio){
            idClien = alqui[i].idCliente;
            for(int j=0; j<lenClien; j++){
                if(clien[j].isEmpty == 0 && clien[j].idC == idClien){
                    printf("\nAlquiler %d:\n", alqui[i].idA);
                    imprimirCliente(clien[j]);
                    flag = 1;
                }
            }
        }
    }
    if(flag == 0){
        printf("No hay clientes que mostrar. \n");
    }
}



void hardcodeoAlquiler(eAlquiler* alqui){
     eAlquiler y[]={
        {100, 1, 4, {30, 5, 2018}, 0},
        {101, 5, 2, {30, 5, 2018}, 0},
        {102, 4, 4, {21, 5, 2018}, 0},
        {103, 3, 3, {04, 5, 2018}, 0},
        {104, 1, 3, {19, 5, 2018}, 0},
        {105, 1, 4, {21, 5, 2018}, 0},
        {106, 2, 3, {13, 5, 2018}, 0},
        {107, 5, 4, {21, 6, 2018}, 0},
        {108, 2, 3, {17, 6, 2018}, 0},
        {109, 3, 4, {30, 6, 2018}, 0},
        {110, 2, 2, {10, 6, 2018}, 0},
    };

    for(int i=0; i<11; i++){
        alqui[i] = y[i];
    }
    printf("\tHardcodeo alquileres hecho!\n");
}


