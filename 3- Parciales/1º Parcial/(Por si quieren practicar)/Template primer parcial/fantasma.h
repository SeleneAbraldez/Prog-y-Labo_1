#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED
typedef struct
{
    char nombre[50];
    //------------
    int idFantasma;
    int isEmpty;
}Fantasma;
#endif // FANTASMA_H_INCLUDED


int fantasma_init(Fantasma* array,int limite);
int fantasma_mostrar(Fantasma* array,int limite);
int fantasma_mostrarDebug(Fantasma* array,int limite);
int fantasma_alta(Fantasma* array,int limite);
int fantasma_baja(Fantasma* array,int limite, int id);
int fantasma_modificacion(Fantasma* array,int limite, int id);
int fantasma_ordenar(Fantasma* array,int limite, int orden);
int buscarLugarLibre(Fantasma* array,int limite);
int proximoId();


