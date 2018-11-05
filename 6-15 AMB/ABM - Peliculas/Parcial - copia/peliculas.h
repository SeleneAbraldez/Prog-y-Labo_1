#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "directores.h"


typedef struct{
    int id;
    char titulo[41];
    int anio;
    char nacionalidad[31];
    int idDirectorx;
    int isEmpty;
}ePeliculas;

void inicializarPeliculas(ePeliculas* pelis, int lenPel);

int lugarLibrePeliculas(ePeliculas* pelis, int lenPel);

int encontrarPeliculaID(ePeliculas* pelis, int lenPel);

int imprimirPelicula(ePeliculas* pelis, int lenPel, int index, eDirectorx* dires);

int imprimirPeliculas(ePeliculas* pelis, int lenPel, eDirectorx* dires, int lenDire);


int altaPelicula(ePeliculas* pelis, int lenPel, eDirectorx* dires, int lenDire);

int modificarPelicula(ePeliculas* pelis, int lenPel, eDirectorx* dires, int lenDire);

int bajaPelicula(ePeliculas* pelis, int lenPel, eDirectorx* dires, int lenDire);


void hardcodeoPeliculas(ePeliculas* pelis);



#endif // PELICULAS_H_INCLUDED
