#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleadxs.h"
#include "almuerzo.h"
#include "utn.h"


void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]){
    for(int i=0; i<tamComida; i++){
        if(comidas[i].idC == idComida){
            strcpy(cadena, comidas[i].descripcion);
            break;
        }
    }
}



void mostrarAlmuerzos(eEmpleado empleados[], eComida comidas[], eAlmuerzo almuerzos[], int tamAlm, int tamCom, int tamEmp){
      char comida[20];
      char nombre[20];
        for (int i = 0; i<tamAlm; i++){
            cargarDescripcionComida(comida,tamCom,almuerzos[i].idComida,comida);
            cargarNombreEmpleado(empleados, tamEmp, almuerzos[i].idEmpleado, nombre);
            printf("%d\t%d\t%s\t%s", almuerzos[i].idA, almuerzos[i].idEmpleado, nombre, comida);
        }
        printf("Almuerzo\tLegajo\tNombre\tComida");
        system("pause"); ///ACOMODAR Y PONER BIEN EL PPRINT
}
