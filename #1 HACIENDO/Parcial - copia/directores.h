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


#endif
