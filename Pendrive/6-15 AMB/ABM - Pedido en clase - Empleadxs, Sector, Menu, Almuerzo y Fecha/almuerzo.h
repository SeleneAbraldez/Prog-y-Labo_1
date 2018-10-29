#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "empleadxs.h"
#include "menu.h"

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha;

typedef struct{
    int idA;
    int idEmpleadx;
    int idMenu;
    fecha diaDeAlmuerzo;
    int isEmpty;
}eAlmuerzo;


void inicializarAlmuerzo(eAlmuerzo* almuer, int lenAlmuer);

int lugarLibreAlmuerzo(eAlmuerzo* almuer, int lenAlmuer);

int encontrarAlmuerzoxID(eAlmuerzo* almuer, int lenAlmuer);

int imprimirAlmuerzo(eAlmuerzo almuer, int lenAlmuer, eEmpleadx* empl, int lenEmpl, eMenu* menuu, int lenMenu);

int imprimirAlmuerzos(eAlmuerzo* almuer, int lenAlmuer, eEmpleadx* empl, int lenEmpl, eMenu* menuu, int lenMenu);


int altaAlmuerzo(eAlmuerzo* almuer, int lenAlmuer, eEmpleadx* empl, int lenEmpl, eMenu* menuu, int lenMenu);

int bajaAlmuerzo(eAlmuerzo* almuer, int lenAlmuer, eEmpleadx* empl, int lenEmpl, eMenu* menuu, int lenMenu);



void cargarEmpleadxs(eEmpleadx* empl, int lenEmpl, int idSector, char nombre[]);

int seleccionarEmpleadx(eEmpleadx* empl, int lenEmpl);


void cargarMenus(eMenu* menuu, int lenMenu, int idMenu, char descripcion[]);

int seleccionarMenu(eMenu* menuu, int lenMenu);





void hardcodeoAlmuerzo(eAlmuerzo* almuer);





#endif
