#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entity.h"

/****************************************************
    Menu:
    1. Cargar los datos de la entidad desde el archivo data.csv (modo texto).
    2. Cargar los datos de la entidad desde el archivo data.bin (modo binario).
    3. Alta de entidad
    4. Modificar datos de empleado
    5. Baja de entidad
    6. Listar las entidades
    7. Ordenar las entidades
    8. Guardar los datos de la entidad en el archivo data.csv (modo texto).
    9. Guardar los datos de la entidad en el archivo data.bin (modo binario).
    10. Filtrar las entidades y guardar lista filtrada (modo texto)
    11. Mapear las entidades y guardar sueldo
    12. Salir
*****************************************************/


int main()
{
    char seguir = 'y';
    int flagFile = 0;
    LinkedList* listaEntidad = ll_newLinkedList();
    char archivoTxt[20] = "data.csv";
    char archivoBin[20] = "data.bin";

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
                //printf("Que archivo desea cargar? Ingrese el nombre junto con '.bin': ");
                //gets(archivoBin);
                if(controller_loadFromBinary(archivoBin, listaEntidad) == 1){
                    flagFile = 1;                                                   //bandera para realizar resto
                }
                break;
            case 3:
                if(controller_addEntity(listaEntidad) == 0){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 4:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_editEntity(listaEntidad);
                }
                break;
            case 5:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_removeEntity(listaEntidad);
                }
                break;
            case 6:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_ListEntitys(listaEntidad);
                }
                break;
            case 7:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_sortEntity(listaEntidad);
                }
                break;
            case 8:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_saveAsText("data.csv",listaEntidad);
                }
                break;
            case 9:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_saveAsBinary("data.bin",listaEntidad);
                }
                break;
            case 10:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_filterEntity(listaEntidad);
                }
                break;
            case 11:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_mapEntity(listaEntidad);
                }
                break;
            case 12:
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
