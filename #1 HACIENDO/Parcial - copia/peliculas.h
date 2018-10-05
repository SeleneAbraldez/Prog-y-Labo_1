#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

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

int imprimirPelicula(ePeliculas* pelis, int index);

int imprimirPeliculas(ePeliculas* pelis, int lenPel);


int altaPelicula(ePeliculas* pelis, int lenPel);

int modificarPelicula(ePeliculas* pelis, int lenPel);

int bajaPelicula(ePeliculas* pelis, int lenPel);


void hardcodeoPeliculas(ePeliculas* pelis);



#endif // PELICULAS_H_INCLUDED
