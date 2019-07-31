#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Alquiler.h"


/****************************************************
Menu:
    1. Cargar los datos de ventas desde el archivo data.csv (modo texto).
    2. Listar ventas.
    3. Generar 'informe.txt.
    4. Salir

*****************************************************/


int main()
{
    char seguir = 'y';
    int flagFile = 0;
    char guardarSueldo = 'n';
    LinkedList* eAlquileres = ll_newLinkedList();
    char archivoTxt[20] = "data.csv";

    do{
        switch(controller_menu())
        {
            case 1:
                //printf("Que archivo desea cargar? Ingrese el nombre junto con '.csv': ");
                //gets(archivoTxt);
                if(controller_loadFromText(archivoTxt, eAlquileres) == 1){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 2:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_ListAlquiler(eAlquileres);
                }
                break;
            case 3:
                if(flagFile == 0){
                        printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_makeInfo(eAlquileres);
                }
                break;
            case 4:
                seguir = 'n';
                printf("\nSaliendo... \n");
                break;
            default:
                printf("Opcion invalida, reintente. \n");
                break;
        }
      system("pause");
    }while(seguir != 'n');
    ll_deleteLinkedList(eAlquileres);
    return 0;
}
