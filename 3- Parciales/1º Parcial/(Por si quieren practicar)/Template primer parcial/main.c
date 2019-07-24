#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"
#define QTY 10

int main()
{
    Fantasma array[QTY];
    int i;
    int menu;
    int auxiliarId;

    fantasma_init(array,QTY);
    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                fantasma_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                fantasma_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                fantasma_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                fantasma_mostrar(array,QTY);
                break;
            case 5:
                fantasma_ordenar(array,QTY,0);
                break;
            case 6:
                fantasma_mostrarDebug(array,QTY);
                break;
        }

    }while(menu != 9);

    return 0;
}
