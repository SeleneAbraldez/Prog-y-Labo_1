#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
    int dia, mes, anio;
}EFecha;

typedef struct {
    char apellido[31];
    char nombre[31];
    long int dni;
    EFecha feNac;
    int isEmpty;
}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int len);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], long int dni);

/** \brief Genera el alta en espacio vacio
 *
 * \param lista de array
 * \param longitud de la lista de array
 *
 */
void alta(ePersona[], int len);
#endif // PERSONA_H_INCLUDED
