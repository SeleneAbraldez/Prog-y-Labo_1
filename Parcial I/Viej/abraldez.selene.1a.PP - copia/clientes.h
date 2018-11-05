#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{
    int idC;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int isEmpty;
}eClientes;

/** \brief Funcion para inicializar Clientes, todos los isEmpty en 1
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
void inicializarClientes(eClientes* clien, int lenClien);

/** \brief Funcion para encontrar el lugar libre en clientes
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 * \return  devuelve index del array donde el lugar esta libre, -1 si no hay mas lugar
 */
int lugarLibreClientes(eClientes* clien, int lenClien);

/** \brief Funcion para encontrar cliente pidiendo y utilizando el id
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
* \return devuelve index del cliente con esa id, -1 si no encuentra cliente
 */
int encontrarClientexID(eClientes* clien, int lenClien);

/** \brief Funcion para imprimir cliente
 * \param array de clientes
 */
int imprimirCliente(eClientes clien);

/** \brief Funcion para imprimir clientes
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
int imprimirClientes(eClientes* clien, int lenClien);

/** \brief Funcion para realizar un alta de cliente con datos y generando id
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
* \return devuelve 0 si se ha dado de alta, -1 si no
 */
int altaCliente(eClientes* clien, int lenClien);

/** \brief Funcion para realizar un alta de cliente con datos y generando id
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
* \return devuelve 0 si se ha dado realizado la modificacion, -1 si no
 */
int modificarCliente(eClientes* clien, int lenClien);

/** \brief Funcion para realizar un baja de cliente
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
* \return devuelve 0 si se ha dado de baja, -1 si no
 */
int bajaCliente(eClientes* clien, int lenClien);

/** \brief Funcion para ordenar clientes por nombre desc y descripcion asc
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
int ordenarClientes(eClientes* clien, int lenClien);

/** \brief Funcion para ordenar clientes por apellido asc insercion
 * \param lista puntero eClientes* array de clientes
 * \param tamaño de clientes
 */
void ordenarClientesInsercion(eClientes* clien, int lenClien);


/** \brief hardcodeo de valores de clientes
 * \param lista puntero eClientes* array de clientes
 */
void hardcodeoClientes(eClientes* clien);

#endif
