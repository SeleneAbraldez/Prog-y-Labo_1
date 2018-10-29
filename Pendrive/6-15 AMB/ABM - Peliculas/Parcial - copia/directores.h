#ifndef DIRECTORES_H_INCLUDED
#define DIRECTORES_H_INCLUDE

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha;

typedef struct{
    int id;
    char nombre[41];
    char nacionalidad[41];
    fecha nacimiento;
    int isEmpty;
}eDirectorx;

void inicializarDirectores(eDirectorx* dire, int lenDire);

int lugarLibreDirectorx(eDirectorx* dire, int lenDire);

int encontrarDirectorxID(eDirectorx* dire, int lenDire);

int imprimirDirectorx(eDirectorx* dire, int index);

int imprimirDirectores(eDirectorx* dire, int lenDire);



void cargarDirectores(eDirectorx* dires, int lenPel, int idDirectorx, char nombre[]);

int seleccionarDirectorx(eDirectorx* dires, int lenDire);



int altaDirectorx(eDirectorx* dire, int lenDire);

int bajaDirectorx(eDirectorx* dire, int lenDire);


void hardcodeoDirectores(eDirectorx* dires);


#endif
