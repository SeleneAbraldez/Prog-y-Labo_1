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


/** \brief inicializa isEmpty para saber si esta vacio
 *
 * \param lista de array
 * \param longitud de la lista de array
 *
 */

void init(ePersona lista[], int len);

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
void alta(ePersona lista[], int len);

/** \brief baja en espacio con dato
 *
 * \param lista de array
 * \param longitud de la lista de array
 *
 */
void baja(ePersona lista[], int len);


/** \brief realiza modificaciones en el array pasado en base al dni
 *
 * \param lista de array
 * \param longitud de la lista de array
 *
 */
void modificar(ePersona lista[], int len);

/** \brief Ordena array por apellido y nombre
 *
 * \param lista de array
 * \param longitud de la lista de array
 *
 */
void ordenar(ePersona lista[], int len);

/** \brief Imprime el array pasado, los datos existentes
 *
 * \param lista de array
 * \param longitud de la lista array
 *
 */
void imprimir(ePersona lista[], int len);



#endif // PERSONA_H_INCLUDED
