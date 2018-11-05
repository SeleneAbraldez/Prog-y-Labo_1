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
    cargarCliente(clien, lenClien, alqui.idCliente, apellido);
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


void cargarJuegosImporte(eJuegos* jueg, int lenJueg, int idJuegos, float importe){
    for(int i=0; i<lenJueg; i++){
        if(jueg[i].idJ == idJuegos){
            importe = jueg[i].importe;
            break;
        }
    }
}

int seleccionarJuegoxImporte(eJuegos* jueg, int lenJueg){
    int idJuego = -1;
    int juegCont = 0;
    printf("\nJuegos: \n");
    for(int i=0; i<lenJueg; i++){
        if(jueg[i].isEmpty == 0){
            printf("%d - %d\n", jueg[i].idJ, jueg[i].importe);
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



void cargarCliente(eClientes* clien, int lenClien, int idCliente, char apellido[51]){
    for(int i=0; i<lenClien; i++){
        if(clien[i].idC == idCliente){
            strcpy(apellido, clien[i].apellido);
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
            printf("%d - %s\n", clien[i].idC, clien[i].apellido);
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



int promedioImporte(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    float conAlqui = 0;
    float importeTotal = 0;
    float promedio = -1;
    float importe;

    for(int i = 0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0){
            cargarJuegosImporte(jueg, lenJueg, jueg[i].idJ, importe);
            conAlqui++;
            importeTotal = importeTotal + importe;
        }
    }
    promedio = importeTotal;
    printf("\t--Promedio y total de los salarios \n\n");
    printf("Total: %.2f\t", importeTotal);
    printf("Promedio: %.2f\n", promedio);
    return promedio;
}

int bajoPromedio(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien, float promedio){
    int bajoProm = 0;
    float importe;
    for(int i = 0; i<lenAlqui; i++){
        cargarJuegosImporte(jueg, lenJueg, jueg[i].idJ, importe);
        if(importe<promedio){
            bajoProm++;
        }
    }
    printf("\n--Juegos cuyo importe no superan el promedio.\n");
    printf("%d", bajoProm);
    return 0;
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
            for(int i=0; i<lenClien; i++){
                if(clien[i].isEmpty == 0 && clien[i].idC == idClien){
                    imprimirCliente(clien[i]);
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
    int flag = 0;

    idClien = seleccionarCliente(clien, lenClien);
    cargarCliente(clien, lenClien, idClien, apellido);

    printf("\n--Alquileres de %s--\n", apellido);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].idCliente == idClien){
            idJueg = alqui[i].idJuego;
            for(int i=0; i<lenJueg; i++){
                if(jueg[i].isEmpty == 0 && jueg[i].idJ == idJueg){
                    imprimirJuego(jueg[i]);
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

}

void listarClienteMasAlqui(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){

}

void listarJuegosXFecha(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int idJueg;
    eAlquiler auxAlqui;
    char apellido[51];
    int flag = 0;

    auxAlqui.diaDeAlquiler.dia =getValidInt("Ingrese dia de alquiler: ","Dia no valido", 1, 30);
    auxAlqui.diaDeAlquiler.mes =getValidInt("Ingrese mes de alquiler: ","Mes no valido", 1, 12);
    auxAlqui.diaDeAlquiler.anio =getValidInt("Ingrese anio de alquiler: ","Anio no valido", 2000, 2018);

    printf("\n--Alquileres de %d/%d/%d--\n", auxAlqui.diaDeAlquiler.dia, auxAlqui.diaDeAlquiler.mes, auxAlqui.diaDeAlquiler.anio);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].diaDeAlquiler.dia == auxAlqui.diaDeAlquiler.dia && alqui[i].diaDeAlquiler.mes == auxAlqui.diaDeAlquiler.mes && alqui[i].diaDeAlquiler.anio == auxAlqui.diaDeAlquiler.anio){
            idJueg = alqui[i].idJuego;
            for(int i=0; i<lenJueg; i++){
                if(jueg[i].isEmpty == 0 && jueg[i].idJ == idJueg){
                    imprimirJuego(jueg[i]);
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
    char descripcion[51];
    int flag = 0;

    auxAlqui.diaDeAlquiler.dia = getValidInt("Ingrese dia de alquiler: ","Dia no valido", 1, 30);
    auxAlqui.diaDeAlquiler.mes = getValidInt("Ingrese mes de alquiler: ","Mes no valido", 1, 12);
    auxAlqui.diaDeAlquiler.anio = getValidInt("Ingrese anio de alquiler: ","Anio no valido", 2000, 2018);

    printf("\n--Alquileres de %d/%d/%d--\n", auxAlqui.diaDeAlquiler.dia, auxAlqui.diaDeAlquiler.mes, auxAlqui.diaDeAlquiler.anio);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].diaDeAlquiler.dia == auxAlqui.diaDeAlquiler.dia && alqui[i].diaDeAlquiler.mes == auxAlqui.diaDeAlquiler.mes && alqui[i].diaDeAlquiler.anio == auxAlqui.diaDeAlquiler.anio){
            idClien = alqui[i].idCliente;
            for(int i=0; i<lenClien; i++){
                if(clien[i].isEmpty == 0 && clien[i].idC == idClien){
                    imprimirCliente(clien[i]);
                    flag = 1;
                }
            }
        }
    }
    if(flag == 0){
        printf("No hay clientes que mostrar. \n");
    }
}



/*
void listarAlquileresXJuego(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int idJueg;
    char descripcion[51];
    int flag = 0;

    idJueg = seleccionarJuego(jueg, lenJueg);
    cargarJuegos(jueg, lenJueg, idJueg, descripcion);

    printf("\n--Alquileres de %s--\n", descripcion);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].idJuego == idJueg){
            imprimirAlquiler(alqui[i], lenAlqui, jueg, lenJueg, clien, lenClien);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("No hay alquileres que mostrar. \n");
    }
}


void ordenarAlquileresxCliente(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    char nombreI[51];
    char nombreJ[51];
    eAlquiler alquiAux;

    for(int i=0; i<lenAlqui -1; i++)
    {
        for(int j = i +1; j < lenAlqui; j++)
        {
            cargarCliente(clien, lenClien, alqui[i].idCliente, nombreI);
            cargarCliente(clien, lenClien, alqui[j].idCliente, nombreJ);
            if(strcmp(nombreI, nombreJ)>0){
                alquiAux = alqui[i];
                alqui[i] = alqui[j];
                alqui[j] = alquiAux;
            }else if(strcmp(nombreI, nombreJ)==0 && alqui[i].idA > alqui[j].idA){
                alquiAux = alqui[i];
                alqui[i] = alqui[j];
                alqui[j] = alquiAux;
            }
        }
    }
}


*/

void hardcodeoAlquiler(eAlquiler* alqui){
     eAlquiler y[]={
        {100, 1, 4, {30, 5, 2018}, 0},
        {101, 3, 2, {30, 5, 2018}, 0},
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
        alqui[i] = y[i];
    }
    printf("\tHardcodeo alquileres hecho!\n");
}


