#ifndef EMPLEADXS_H_INCLUDED
#define EMPLEADXS_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[21];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
}eEmpleadx;

typedef struct{
    int id;
    char descripcion[21];
}eSector;


void inicializarEmpleadxs(eEmpleadx* empl, int lenEmp);

int lugarLibreEmpleadx(eEmpleadx* empl, int lenEmp);

int encontrarEmpleadxID(eEmpleadx* empl, int lenEmp);

int imprimirEmpleadx(eEmpleadx empl, eSector* sector, int lenSec);

int imprimirEmpleadxs(eEmpleadx* empl, int lenEmp, eSector* sector, int lenSec);



int altaEmpleadx(eEmpleadx* empl, int lenEmp, eSector* sector, int lenSec);

int modificarEmpleadx(eEmpleadx* empl, int lenEmp, eSector* sector, int lenSec);

int bajaEmpleadxs(eEmpleadx* empl, int lenEmp, eSector* sector, int lenSec);



void cargarSectores(eSector* sector, int lenPel, int idSector, char descripcion[]);

int seleccionarSector(eSector* sector, int lenSec);



void hardcodeoEmpleadxs(eEmpleadx* empl);

#endif // EMPLEADXS_H_INCLUDED
