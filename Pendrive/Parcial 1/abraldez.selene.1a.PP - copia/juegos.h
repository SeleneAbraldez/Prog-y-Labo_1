#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct{
    int idJ;
    char descripcion[51];
    float importe;
    int isEmpty;
}eJuegos;

/** \brief Funcion para inicializar juegos, todos los isEmpty en 1
 * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
 */
void inicializarJuegos(eJuegos* jueg, int lenJueg);

/** \brief Funcion para encontrar el lugar libre en juegos
 * \param lista puntero ejuegos* array de juegos
 * \param tamaño de juegos
 * \return  devuelve index del array donde el lugar esta libre, -1 si no hay mas lugar
 */
int lugarLibreJuegos(eJuegos* jueg, int lenJueg);

/** \brief Funcion para encontrar juego pidiendo y utilizando el id
 * \param lista puntero ejuegos* array de juegos
 * \param tamaño de juegos
* \return devuelve index del juego con esa id, -1 si no encuentra juego
 */
int encontrarJuegoxID(eJuegos* jueg, int lenJueg);

/** \brief Funcion para imprimir juego
 * \param array de juegos
 */
int imprimirJuego(eJuegos jueg);

/** \brief Funcion para imprimir juegos
 * \param lista puntero ejuegos* array de juegos
 * \param tamaño de juegos
 */
int imprimirJuegos(eJuegos* jueg, int lenJueg);

/** \brief Funcion para realizar un alta de juego con datos y generando id
 * \param lista puntero ejuegos* array de juegos
 * \param tamaño de juegos
* \return devuelve 0 si se ha dado de alta, -1 si no
 */
int altaJuego(eJuegos* jueg, int lenJueg);

/** \brief Funcion para realizar un alta de juego con datos y generando id
 * \param lista puntero ejuegos* array de juegos
 * \param tamaño de juegos
* \return devuelve 0 si se ha dado realizado la modificacion, -1 si no
 */
int modificarJuego(eJuegos* jueg, int lenJueg);

/** \brief Funcion para realizar un baja de juego
 * \param lista puntero ejuegos* array de juegos
 * \param tamaño de juegos
* \return devuelve 0 si se ha dado de baja, -1 si no
 */
int bajaJuego(eJuegos* jueg, int lenJueg);

/** \brief Funcion para ordenar juegos por nombre desc y descripcion asc
 * \param lista puntero ejuegos* array de juegos
 * \param tamaño de juegos
 */
int ordenarJuegos(eJuegos* jueg, int lenJueg);

/** \brief Funcion para ordenar juegos por importe desc usado metodo de burbujeo
 * \param lista puntero ejuegos* array de juegos
 * \param tamaño de juegos
 */
void ordenarJuegosXImporteBurb(eJuegos* jueg, int lenJueg);

/** \brief hardcodeo de valores de juegos
 * \param lista puntero ejuegos* array de juegos
 */
void hardcodeoJuegos(eJuegos* jueg);

#endif
