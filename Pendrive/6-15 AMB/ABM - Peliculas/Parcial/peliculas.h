#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct{
    int id;
    char titulo[41];
    int anio;
    char nacionalidad[31];
    int idDirectorx;
}ePeliculas;

typedef struct{
    int id;
    char nombre[41];
    ///int fecha;
    char nacionalidad[31];
}eDirectorx;

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

int menu(void);

#endif // PELICULAS_H_INCLUDED
