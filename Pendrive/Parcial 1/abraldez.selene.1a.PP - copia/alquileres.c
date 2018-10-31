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


void cargarJuegosImporte(eJuegos* jueg, int lenJueg, int idJuegos, float *pImporte){ //NO FUNCA
    for(int i=0; i<lenJueg; i++){
        if(jueg[i].idJ == idJuegos){
            printf("%f\n", jueg[i].importe);
            *pImporte = jueg[i].importe;
            //printf("%f\n", *pImporte);
            //error de concepto, deberia pasarimporte por puntero? aca por lo que no me levanata el importe, lo cual trae error en promedio y en bajopromedio
            break;
        }
    }
}

float cargarJuegosImportes(eJuegos* jueg, int lenJueg, int idJuegos){  //NO FUNCA, preg
    float importeaux = -1;
    for(int i=0; i<lenJueg; i++){
        if(jueg[i].idJ == idJuegos){
            printf("%f jue\n", jueg[i].importe);
            importeaux = jueg[i].importe;
            printf("%f imp1\n", importeaux);
            break;
        }
        printf("%f imp2\n", importeaux);
    }
    printf("%f imp3\n", importeaux);
    return importeaux;
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


int promedioImportes(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
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
    printf("\t--Promedio y total de los juegos \n\n");
    printf("Total: %.2f\t\t", importeTotal);
    printf("Promedio: %.2f\n", promedio);
    return promedio;
}

int bajoPromedio(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){ //funcional
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

int bajoPromedioPunt(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien, float *promedio){ //NO FUNCA, pre
    int bajoProm = 0;

    printf("hola %f -", promedio);

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
    }*/

    printf("\n--Juegos cuyo importe no superan el promedio: ");
    printf(" %f - ", promedio);
    printf(" %d\n", bajoProm);
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
            for(int j=0; j<lenClien; j++){
                if(clien[j].isEmpty == 0 && clien[j].idC == idClien){
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
    int flag = 0;

    idClien = seleccionarCliente(clien, lenClien);
    cargarCliente(clien, lenClien, idClien, apellido);

    printf("\n--Alquileres de %s--\n", apellido);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].idCliente == idClien){
            idJueg = alqui[i].idJuego;
            for(int j=0; j<lenJueg; j++){
                if(jueg[j].isEmpty == 0 && jueg[j].idJ == idJueg){
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
    int menosAlq;
    int arrayMenosAlq[lenJueg];
    int flag = 0;

    //inic
    for (int a=0; a<lenJueg; a++){
        arrayMenosAlq[a]=-1
        ;
    }

    //llena lista
    for (int i=0; i<lenJueg; i++){
        for (int j=0; j <lenAlqui; j++){
            if (jueg[i].idJ==alqui[j].idJuego && alqui[j].isEmpty==0){
                arrayMenosAlq[i]++;
            }
        }
    }
    /*
    for(int h=0; h<lenJueg; h++){
        printf("%d ", arrayMenosAlq[h]);
    }
    printf("\n");
    */
    //recorrido por array preguntando si es menor
    for (int k=0; k<lenJueg; k++){
        if (jueg[k].isEmpty == 0){
            arrayMenosAlq[k]++;
            /*
            for(int e=0; e<lenJueg; e++){
                printf("%d ", arrayMenosAlq[e]);
            }
            printf("\n");
            */
            if(flag == 0){;
                menosAlq = arrayMenosAlq[k];
                flag = 1;
            }
            if(arrayMenosAlq[k]<menosAlq){
                menosAlq=arrayMenosAlq[k];
                printf("%d \n", menosAlq);
            }
        }
    }


    printf("\nJuegos menos alquilados:\n");
    for (int p=0; p<lenJueg; p++){
        if (arrayMenosAlq[p]==menosAlq){
            imprimirJuego(jueg[p]);
        }
    }

}


void listarClienteMasAlqui(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int masAlqu=-1;
    int arrayMasAlq[lenClien];

    for (int a=0; a<lenClien; a++){
        arrayMasAlq[a]=-1;
    }

    for (int i=0; i<lenClien; i++){
        for (int j=0; j <lenAlqui; j++){
            if (clien[i].idC==alqui[j].idCliente && alqui[j].isEmpty==0){
                arrayMasAlq[i]++;
            }
        }
    }

    for (int k=0; k<lenClien; k++){
        if (clien[k].isEmpty == 0){
            arrayMasAlq[k]++;
            if(arrayMasAlq[k]>masAlqu){
                masAlqu=arrayMasAlq[k];
                printf("%d \n", masAlqu);
            }
        }
    }


    printf("\nClientes que mas alquilan:\n");
    for (int p=0; p<lenClien; p++){
        if (arrayMasAlq[p]==masAlqu){
            imprimirCliente(clien[p]);
        }
    }

}

void listarJuegosXFecha(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien){
    int idJueg;
    eAlquiler auxAlqui;
    int flag = 0;

    auxAlqui.diaDeAlquiler.dia =getValidInt("Ingrese dia de alquiler: ","Dia no valido", 1, 30);
    auxAlqui.diaDeAlquiler.mes =getValidInt("Ingrese mes de alquiler: ","Mes no valido", 1, 12);
    auxAlqui.diaDeAlquiler.anio =getValidInt("Ingrese anio de alquiler: ","Anio no valido", 2000, 2018);

    printf("\n--Alquileres de %d/%d/%d--\n", auxAlqui.diaDeAlquiler.dia, auxAlqui.diaDeAlquiler.mes, auxAlqui.diaDeAlquiler.anio);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].diaDeAlquiler.dia == auxAlqui.diaDeAlquiler.dia && alqui[i].diaDeAlquiler.mes == auxAlqui.diaDeAlquiler.mes && alqui[i].diaDeAlquiler.anio == auxAlqui.diaDeAlquiler.anio){
            idJueg = alqui[i].idJuego;
            for(int j=0; j<lenJueg; j++){
                if(jueg[j].isEmpty == 0 && jueg[j].idJ == idJueg){
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

    printf("\n--Alquileres de %d/%d/%d--\n", auxAlqui.diaDeAlquiler.dia, auxAlqui.diaDeAlquiler.mes, auxAlqui.diaDeAlquiler.anio);
    for(int i=0; i<lenAlqui; i++){
        if(alqui[i].isEmpty == 0 && alqui[i].diaDeAlquiler.dia == auxAlqui.diaDeAlquiler.dia && alqui[i].diaDeAlquiler.mes == auxAlqui.diaDeAlquiler.mes && alqui[i].diaDeAlquiler.anio == auxAlqui.diaDeAlquiler.anio){
            idClien = alqui[i].idCliente;
            for(int j=0; j<lenClien; j++){
                if(clien[j].isEmpty == 0 && clien[j].idC == idClien){
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
        {100, 1, 1, {30, 5, 2018}, 0},
        {101, 2, 3, {30, 5, 2018}, 0},
        {102, 2, 3, {21, 5, 2018}, 0},
        {103, 2, 3, {04, 5, 2018}, 0},
        {104, 1, 4, {19, 5, 2018}, 0},
        {105, 1, 2, {24, 5, 2018}, 0},
        {106, 5, 5, {13, 5, 2018}, 0},
        {107, 2, 5, {17, 6, 2018}, 0},
        {108, 1, 2, {18, 6, 2018}, 0},
        {109, 1, 4, {20, 6, 2018}, 0},
        {110, 2, 2, {10, 6, 2018}, 0},
    };

    for(int i=0; i<11; i++){
        alqui[i] = y[i];
    }
    printf("\tHardcodeo alquileres hecho!\n");
}


