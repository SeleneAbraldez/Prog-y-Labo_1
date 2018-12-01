#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "empleadxs.h"

typedef struct{
    int idC;
    char descripcion[20];
}eComida;

typedef struct{
    int idA;
    int idEmpleado;
    int idComida;
}eAlmuerzo;


void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]);

void mostrarAlmuerzos(eEmpleado empleados[], eComida comidas[], eAlmuerzo almuerzos[], int tamAlm, int tamCom, int tamEmp);


#endif
