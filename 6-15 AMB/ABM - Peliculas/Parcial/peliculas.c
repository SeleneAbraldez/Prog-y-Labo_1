#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "peliculas.h"

int menu(void){
    int option;
    system("cls");
    printf("---Menu de Opciones---\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Salir\n\n");
    printf("0- Hardcodeo\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}
