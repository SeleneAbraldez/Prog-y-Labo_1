#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    char seguir = 'y';
    int flagFile = 0;
    LinkedList* eEmpleado = ll_newLinkedList();
    char archivoTxt[20] = "data.csv";

    do{
        switch(controller_menu())
        {
            case 1:
                //printf("Que archivo desea cargar? Ingrese el nombre junto con '.csv': ");
                //gets(archivoTxt);
                if(controller_loadFromText(archivoTxt, eEmpleado) == 1){
                    flagFile = 1;
                }
                break;
            case 2:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_ListEmployee(eEmpleado);
                }
                break;
            case 3:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_mapEmployee(eEmpleado);
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
    ll_deleteLinkedList(eEmpleado);
    return 0;
}
