#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entity.h"

/****************************************************
    Final:
        printf("1. Cargar lista clientes \n");
        printf("2. Listar clientes \n");
        printf("3. Crear y completar lista abono\n");
        printf("4. Listar abono con clientes\n");
        printf("5. Generar archivos de salida (texto y binario)\n");
        printf("10. Salir \n");
*****************************************************/


int main()
{
    char seguir = 'y';
    int flagFile = 0;
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaAbono = ll_newLinkedList();
    char archivoTxt[20] = "clientes.csv";

    do{
        switch(controller_menu())
        {
            case 1:
                //printf("Que archivo desea cargar? Ingrese el nombre junto con '.csv': ");
                //gets(archivoTxt);
                if(controller_loadFromTextClientes(archivoTxt, listaClientes) == 1){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 2:
                if(flagFile == 0){
                    printf("No hay datos cargados para realizar esta accion. \n");
                }else{
                    controller_ListEntitysClientes(listaClientes);
                }
                break;
            case 3:
                 if(flagFile == 0){
                    printf("No hay datos cargados para realizar esta accion. \n");
                }else{
                    listaAbono = controller_makeAndComple(listaClientes);
                }
                break;
            case 4:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_ListEntitysAbono(listaAbono, listaClientes);
                }
                break;
            case 5:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_saveAsTextAbono("abono.csv" ,listaAbono);
                    controller_saveAsBinaryAbono("abono.bin", listaAbono);
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
    ll_deleteLinkedList(listaClientes);
    return 0;
}
