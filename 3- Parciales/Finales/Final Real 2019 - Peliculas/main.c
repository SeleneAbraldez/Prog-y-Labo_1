#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Final:
        1. Cargar los datos de las peliculas (modo texto)
        2. Listar peliculas
        3. Ordenar peliculas por id
        4. Depurar peliculas y listarlas
        5. Filtrar peliculas por genero y opcion de guardar lista
        10. Salir
*****************************************************/


int main()
{
    char seguir = 'y';
    char optionYN = 'n';
    int flagFile = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char archivoTxt[20] = "datosMF1.csv";

    do{
        switch(controller_menu())
        {
            case 1:
                printf("Que archivo desea cargar? Ingrese el nombre junto con '.csv': ");
                gets(archivoTxt);
                if(controller_loadFromText(archivoTxt, listaEmpleados) == 1){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 2:
                if(flagFile == 0){
                    printf("No hay peliculas cargadas para realizar esta accion. \n");
                }else{
                    controller_ListPeliculas(listaEmpleados);
                }
                break;
            case 3:
                 if(flagFile == 0){
                    printf("No hay peliculas cargadas para realizar esta accion. \n");
                }else{
                    controller_sortEmployee(listaEmpleados);
                    controller_ListPeliculas(listaEmpleados);
                }
                break;
            case 4:
                if(flagFile == 0){
                    printf("No hay peliculas cargadas para realizar esta accion. \n");
                }else{
                    controller_sortEmployeeDepu(listaEmpleados);
                    depurarPeliculas(listaEmpleados);
                    controller_ListPeliculas(listaEmpleados);
                    optionYN = getValidYesNoChar("Desea guardar la lista filtrada en 'depurado.csv?' y/n: ", "Caracter no valido. ");
                    if(optionYN == 'y'){
                        controller_saveAsText("depurado.csv", listaEmpleados);
                    }else{
                        printf("Saliendo sin guardar. \n");
                    }
                }
                break;
            case 5:
                if(flagFile == 0){
                    printf("No hay peliculas cargadas para realizar esta accion. \n");
                }else{
                    controller_filterEmployee(listaEmpleados);
                }
                break;
            case 8:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_saveAsText("data.csv",listaEmpleados);
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
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
