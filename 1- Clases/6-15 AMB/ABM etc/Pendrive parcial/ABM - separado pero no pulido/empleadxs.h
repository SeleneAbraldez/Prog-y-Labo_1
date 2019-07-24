#ifndef EMPLEADXS_H_INCLUDED
#define EMPLEADXS_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
}eEmpleado;

typedef struct{
    int id;
    char descripcion[20];
}eSector;

void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void cargarNombreEmpleado(eEmpleado empleados[], int tamEmpleado, int idEmpleado, char cadena[]);

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);

int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listarEmpleadosXSector(eEmpleado x[], int tam, eSector sectores[], int tamSector);
void ordenarEmpleadosXSector(eEmpleado x[], int tam, eSector sectores[], int tamSector);
//ME FALTA HACER UNO


#endif
