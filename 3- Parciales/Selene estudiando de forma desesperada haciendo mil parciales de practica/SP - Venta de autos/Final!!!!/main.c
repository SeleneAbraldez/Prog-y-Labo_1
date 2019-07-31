#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entity.h"

/****************************************************
    Final:
    1. Cargar los datos desde el archivo data.csv (modo texto).
    2. Listar las entidades
    3. Realizar informes:
        -Cantidad de unidades vendidas totales:
        -Cantidad de unidades con precio mayor a 100000:
        -Cantidad de unidades con precio mayor a 300000:
        -Cantidad de Fords vendidos:
    y guardarlo en el archivo informes.txt
    10. Salir
*****************************************************/


int main()
{
    char seguir = 'y';
    int flagFile = 0;
    LinkedList* listaEntidad = ll_newLinkedList();
    char archivoTxt[20] = "data.csv";

    do{
        switch(controller_menu())
        {
            case 1:
                //printf("Que archivo desea cargar? Ingrese el nombre junto con '.csv': ");
                //gets(archivoTxt);
                if(controller_loadFromText(archivoTxt, listaEntidad) == 1){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 2:
                if(flagFile == 0){
                    printf("No hay datos cargados para realizar esta accion. \n");
                }else{
                    controller_ListEntitys(listaEntidad);
                }
                break;
            case 3:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_makeInfo(listaEntidad);
                }
                break;
            case 10:
                seguir = 'n';
                printf("\nSaliendo... \n");
                break;
            default:
                printf("Opcion invalida, reintente. \n");
                break;
        }
      system("pause");
    }while(seguir != 'n');
    ll_deleteLinkedList(listaEntidad);
    return 0;
}
