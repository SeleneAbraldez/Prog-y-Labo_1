#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"
#include "utn.h"


void inicializarClientes(eClientes* clien, int lenClien){
    for(int i=0; i<lenClien; i++){
        clien[i].isEmpty = 1;
    }
}

int lugarLibreClientes(eClientes* clien, int lenClien){
    int index = -1;
    for(int i=0; i<lenClien; i++){
        if( clien[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

int encontrarClientexID(eClientes* clien, int lenClien){
    int idAux = getValidInt("Ingrese ID de Cliente: ", "Valor no valido. ", 0, 100);
    int ret = -1;
    for(int i=0; i < lenClien; i++){
        if(clien[i].idC == idAux && clien[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int imprimirCliente(eClientes clien){
    printf("\nidC: %d\nApellido: %s\nNombre: %s\nSexo: %c\nDomicilio: %s\n\n", clien.idC, clien.apellido, clien.nombre, clien.sexo, clien.domicilio);
    return 0;
}

int imprimirClientes(eClientes* clien, int lenClien){
    for(int i = 0; i<lenClien; i++){
        if(clien[i].isEmpty == 0){
            imprimirCliente(clien[i]);
        }
    }
    return 0;
}


int altaCliente(eClientes* clien, int lenClien){
    int ret = -1;
    eClientes altaCliente;
    int index = lugarLibreClientes(clien, lenClien);
    int idC;

    if(index == -1){
        printf("!! - No mas hay espacio\n");
    } else {
        idC = index + 1;
        altaCliente.idC = idC;
        printf("-Cliente %d\n",idC);
        getValidStringLen("Ingrese apellido: ", "Valor no valido. ", "Dato debe ser menor a 50 caracteres. " ,  altaCliente.apellido, 51);
        getValidStringLen("Ingrese nombre: ", "Valor no valido. ", "Dato debe ser menor a 50 caracteres. ", altaCliente.nombre, 51);
        altaCliente.sexo = getValidSexChar("Ingrese sexo: ", "Sexo no valido, ingrese f o m: ");
        getValidStringAlfaNumericoLen("Ingrese domicilio: ", "Valor no valido. ", "Dato debe ser menor a 50 caracteres. ", altaCliente.domicilio, 51);
        altaCliente.isEmpty = 0;
        clien[index] = altaCliente;
        ret = 0;
    }
    return ret;
}

int modificarCliente(eClientes* clien, int lenClien){
    int ret = -1;
    int idAux = encontrarClientexID(clien, lenClien);
    int menuModi;
    char contModi = 's';
    eClientes modiClien;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado Cliente. \n");
    }else{
        imprimirCliente(clien[idAux]);
        do{
                printf("Que desea modificar?\n");
                printf("\t1- Apellido\n");
                printf("\t2- Nombre\n");
                printf("\t3- Sexo\n");
                printf("\t4- Domicilio\n");
                printf("\t5- Salir\n");
                scanf("%d", &menuModi);
                switch(menuModi){
                    case 1:
                        getValidStringLen("Ingrese nuevo apellido: ", "Valor no valido. ", "Dato debe ser menor a 50 caracteres. ", modiClien.apellido, 51);
                        strcpy(clien[idAux].apellido, modiClien.apellido);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 2:
                        getValidStringLen("Ingrese nuevo nombre: ", "Valor no valido. ", "Dato debe ser menor a 50 caracteres. ", modiClien.nombre, 51);
                        strcpy(clien[idAux].nombre, modiClien.nombre);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 3:
                        modiClien.sexo = getValidSexChar("Ingrese nuevo sexo: ", "Sexo no valido, ingrese f o m");
                        clien[idAux].sexo= modiClien.sexo;
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 4:
                        getValidStringAlfaNumericoLen("Ingrese nuevo domicilio: ", "Valor no valido. ", "Dato debe ser menor a 50 caracteres. ", modiClien.domicilio, 51);
                        strcpy(clien[idAux].domicilio, modiClien.domicilio);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 5:
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

int bajaCliente(eClientes* clien, int lenClien){
    int ret = -1;
    int idAux = encontrarClientexID(clien, lenClien);
    int conBaja;
    if (idAux == -1){
        printf("!!! -  No se ha encontrado Cliente. \n");
    }else{
        imprimirCliente(clien[idAux]);
        conBaja = getChar("Confirmar eliminacion? 's' para confirmar, otra tecla para cancelar.\n");
        if (conBaja!='s'){
            printf("Eliminacion cancelada. \n");
        }else{
            clien[idAux].isEmpty= 1;
            ret = 0;
        }
    }
    return ret;
}


int ordenarClientes(eClientes* clien, int lenClien){
    int ret = -1;
    eClientes auxJueg;
    for(int i =0 ; i<lenClien-1 ; i ++){
        for(int j= i+1 ; j<lenClien; j++){
            if(strcmp(clien[j].apellido,clien[i].apellido)<0 && clien[j].isEmpty==0 && clien[i].isEmpty==0){
                auxJueg = clien[i];
                clien[i] = clien[j];
                clien[j] = auxJueg;
             }else if(strcmp(clien[j].apellido,clien[i].apellido) ==0 && strcmp(clien[j].nombre,clien[i].nombre)<0 && clien[j].isEmpty==0 && clien[i].isEmpty==0){
                auxJueg = clien[i];
                clien[i] = clien[j];
                clien[j] = auxJueg;
            }
        }
    }
    printf("\t1--Listado de Clientes Importe y Descripcion\n\n");
    ret = 0;
    return ret;
}

void ordenarClientesInsercion(eClientes* clien, int lenClien){
    int i, j;
    eClientes clienAux;
    for (i = 1; i < lenClien; i++)
    {
        clienAux = clien[i];
        j = i - 1;
        while ((j >= 0) && strcmp(clienAux.apellido, clien[j].apellido)<0)
        {
            clien[j + 1] = clien[j];
            j--;
        }
        clien[j + 1] = clienAux;
    }

    printf("\t1--Listado de Clientes Apellido (a)\n\n");
}


void hardcodeoClientes(eClientes* clien){
     eClientes y[]={
        {1, "Giga", "Ana", 'f', "Galvan 435", 0},
        {2, "Alberto", "Luis", 'm', "Colon 765", 0},
        {3, "Puertas", "Juli", 'm', "Perez 543", 0},
        {4,  "Giga", "Julia", 'f', "Chanchi 232", 0},
        {5, "Rovida", "Mile", 'f', "Galvan 478", 0},
    };

    for(int i=0; i<5; i++){
        clien[i] = y[i];
    }
    printf("\tHardcodeo Clientes hecho!\n");
}


