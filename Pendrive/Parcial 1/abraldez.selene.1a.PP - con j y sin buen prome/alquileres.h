#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "juegos.h"
#include "clientes.h"

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha;

typedef struct{
    int idA;
    int idCliente;
    int idJuego;
    fecha diaDeAlquiler;
    int isEmpty;
}eAlquiler;

/** \brief Funcion para inicializar alquileres, todos los isEmpty en 1
 * \param lista puntero eAlquiler* array de alquiler
 * \param tamaño de alquiler
 */
void inicializAlquiler(eAlquiler* alqui, int lenAlqui);

/** \brief Funcion para encontrar el lugar libre en alquiler
 * \param lista puntero eAlquiler* array de alquiler
 * \param tamaño de alquiler
 * \return  devuelve index del array donde el lugar esta libre, -1 si no hay mas lugar
 */
int lugarLibreAlquiler(eAlquiler* alqui, int lenAlqui);

/** \brief Funcion para encontrar alquiler pidiendo y utilizando el id
 * \param lista puntero eAlquiler* array de alquileres
 * \param tamaño de alquileres
* \return devuelve index del alquiler con esa id, -1 si no encuentra alquiler
 */
int encontrAlquilerxID(eAlquiler* alqui, int lenAlqui);

/** \brief Funcion para imprimir alquiler
 * \param array de alquiler
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes

 */
int imprimirAlquiler(eAlquiler alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);

/** \brief Funcion para imprimir clientes
 * \param lista puntero eAlquiler* array de clientes
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes

 */
int imprimirAlquileres(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);

/** \brief Funcion para realizar un alta de alquiler con datos y generando id
 * \param lista puntero eAlquiler* array de clientes
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
* \return devuelve 0 si se ha dado de alta, -1 si no
 */
int altaAlquiler(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);


/** \brief funcion para encontrar con idJuegos descripcion con esa id
 * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
 * \param id referente en alquiler de juego
 * \param valor donde se guarda descripcion
 */
void cargarJuegos(eJuegos* jueg, int lenJueg, int idJuegos, char descripcion[]);

/** \brief funcion para mostrar juegos con sus ids para seleccionar juego
 * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
* \return devuelve el valor del juego, -1 si hay error
 */
int seleccionarJuego(eJuegos* jueg, int lenJueg);


/** \brief funcion para encontrar con idCliente descripcion con esa id
 * \param lista puntero eCliente* array de cliente
 * \param tamaño de cliente
 * \param id referente en alquiler de cliente
 * \param valor donde se guarda descripcion
 */
void cargarCliente(eClientes* clien, int lenClien, int idCliente, char apellido[], char nombre[]);

/** \brief funcion para mostrar clientes con sus ids para seleccionar cliente
 * \param lista puntero eCliente* array de clientes
 * \param tamaño de clientes
* \return devuelve el valor del cliente, -1 si hay error
 */
int seleccionarCliente(eClientes* clien, int lenClien);


/** \brief funcion para sacar la suma de los importes y el promedio
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 * \return promedio
 *
 */
float promedioImportes(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);



/** \brief Funcion para listar alquileres eligiendo juego
 * \param lista puntero eAlquiler* array de clientes
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
void listarClientesxJuego(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);

/** \brief Funcion para listar juegos eligiendo cleintes
 * \param lista puntero eAlquiler* array de clientes
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
void listarJuegosxCliente(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);

/** \brief Funcion para listarjuego o juegos menos alquilado/s
 * \param lista puntero eAlquiler* array de clientes
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
void listarJuegosMenosAlqui(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);
/** \brief Funcion para listar cliente o clientes con mayor numero de alquileres
 * \param lista puntero eAlquiler* array de clientes
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
void listarClienteMasAlqui(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);

/** \brief Funcion para listar juegos eligiendo fecha
 * \param lista puntero eAlquiler* array de clientes
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
void listarJuegosXFecha(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);


/** \brief Funcion para listar clientes eligiendo fecha
 * \param lista puntero eAlquiler* array de clientes
 * \param tamaño de alquiler
  * \param lista puntero eJuego* array de juegos
 * \param tamaño de juegos
  * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
void listarClientesXFecha(eAlquiler* alqui, int lenAlqui, eJuegos* jueg, int lenJueg, eClientes* clien, int lenClien);


/** \brief hardcodeo de valores de alquileres
 * \param lista puntero eClientes* array de alquileres
 */
void hardcodeoAlquiler(eAlquiler* alqui);

#endif
