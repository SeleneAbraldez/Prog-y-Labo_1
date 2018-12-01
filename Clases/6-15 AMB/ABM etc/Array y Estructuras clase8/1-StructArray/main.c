#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

typedef struct{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
}eEmpleado;


int main()
{
    eEmpleado empleados[TAM];
    for(int i=0; i<TAM; i++){
        printf("Ingrese legajo: ");
        scanf("%d", &empleados[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(empleados[i].nombre);
        printf("Ingrese sexo: ");
        scanf("%c", &empleados[i].sexo);
        printf("Ingrese sueldo: ");
        scanf("%f", &empleados[i].sueldo);
        printf("\n");
    }
    mostrarEmpleados(empleados, TAM); // ERROR era tamaño
}

void mostrarEmpleado (eEmpleado empleado){
    printf("%d  %s  %c  %.2f \n", empleado.legajo, empleado.nombre, empleado.sexo, empleado.sueldo);
}

void mostrarEmpleados (eEmpleado lista[], int tam) {
    for(int i = 0; i<tam; i++){
        mostrarEmpleado(lista[i]); //lama lista de empleados
    }
}


