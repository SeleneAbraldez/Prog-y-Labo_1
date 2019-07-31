#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entity.h"

/****************************************************
    Final:
        printf("1. Alta ingrediente \n");
        printf("2. Modificar ingredientes\n");
        printf("3. Baja ingrediente\n");
        printf("4. Listar ingredientes \n");
        printf("5. Alta receta \n");
        printf("6. Informar valor de receta por Id con sus ingredientes y los valores totales\n");
        guardar archivos
        printf("10. Salir \n");
*****************************************************/


int main()
{
    char seguir = 'y';
    int flagFile = 0;
    int flagFileR = 0;
    LinkedList* listaIngredientes = ll_newLinkedList();
    LinkedList* listaRecetas = ll_newLinkedList();
    char archivoTxt[20] = "ingrediente.csv";

    if(controller_loadFromTextIngredientes(archivoTxt, listaIngredientes) == 1){
        flagFile = 1;                                               //bandera para realizar resto
    }
    if(controller_loadFromTextReceta("receta.csv", listaRecetas) == 1){
        flagFileR = 1;                                               //bandera para realizar resto
    }
    do{
        switch(controller_menu())
        {
            case 1:
                if(controller_addEntity(listaIngredientes) == 0){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 2:
                if(flagFile == 0){
                    printf("No hay datos para realizar esta accion. \n");
                }else{
                    controller_editEntity(listaIngredientes);
                }
                break;
            case 3:
                 if(flagFile == 0){
                    printf("No hay datos para realizar esta accion. \n");
                }else{
                    controller_removeEntity(listaIngredientes);
                }
                break;
            case 4:
                if(flagFileR == 0){
                    printf("No hay datos para realizar esta accion. \n");
                }else{
                    controller_ListEntitysIngredientes(listaIngredientes);
                }
                break;
            case 5:
                if(flagFileR == 0){
                    printf("No hay datos para realizar esta accion. \n");
                }else{
                    controller_addReceta(listaRecetas);
                }
                break;
            case 6:
                if(flagFileR == 0){
                    printf("No hay datos para realizar esta accion. \n");
                }else{
                    controller_ListEntitysRecetas(listaRecetas);
                }
                break;
            case 7:
                if(flagFileR == 0){
                    printf("No hay datos para realizar esta accion. \n");
                }else{
                    controller_ListReceta(listaRecetas, listaIngredientes);
                }
                break;
            case 8:
                if(flagFileR == 0 || flagFile == 0){
                    printf("No hay datos para realizar esta accion. \n");
                }else{
                    controller_saveAsTextIngredientes("ingredientes.csv",listaIngredientes);
                    controller_saveAsTextRecetas("recetas.csv",listaRecetas);
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
    ll_deleteLinkedList(listaIngredientes);
    return 0;
}
