#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
Menu:
    1. Cargar los datos de lxs empleadxs desde el archivo data.csv (modo texto).
    2. Calcular sueldo
    3. Guardar los datos de lxs empleadxs con SUELDO en 'info.csv'
    4. Salir
    5. Listar empleadxs

*****************************************************/


int main()
{
    char seguir = 'y';
    int flagFile = 0;
    int flagSueldo = 0;
    char guardarSueldo = 'n';
    LinkedList* eEmpleadx = ll_newLinkedList();
    char archivoTxt[20] = "data.csv";

    do{
        switch(controller_menu())
        {
            case 1:
                //printf("Que archivo desea cargar? Ingrese el nombre junto con '.csv': ");
                //gets(archivoTxt);
                if(controller_loadFromText(archivoTxt, eEmpleadx) == 1){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 2:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_mapEmployee(eEmpleadx);
                    flagSueldo = 1;
                }
                break;
            case 3:
                 if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    if(flagSueldo == 0){
                        printf("No ha realizado el calculo de sueldo (2). \n");
                        guardarSueldo = getValidYesNoChar("Desea guardar de todas maneras? y/n: ", "Opcion no valida. ");
                        if(guardarSueldo == 'n'){
                            printf("Saliendo... \n");
                        }else{
                            controller_saveAsText("info.csv", eEmpleadx);
                        }
                    }else{
                        controller_saveAsText("info.csv", eEmpleadx);
                    }
                }
                break;
            case 4:
                seguir = 'n';
                printf("\nSaliendo... \n");
                break;
            case 5:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_ListEmployee(eEmpleadx);
                }
                break;
            default:
                printf("Opcion invalida, reintente. \n");
                break;
        }
      system("pause");
    }while(seguir != 'n');
    ll_deleteLinkedList(eEmpleadx);
    return 0;
}
