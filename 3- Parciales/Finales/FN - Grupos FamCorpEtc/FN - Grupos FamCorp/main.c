#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
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
                if(controller_loadFromText(archivoTxt, listaClientes) == 1){
                    flagFile = 1;                                               //bandera para realizar resto
                }
                break;
            case 2:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                     listaAbono = controller_makeAndComple(listaClientes);
                }
                break;
            case 3:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_ListAbono(listaAbono, listaClientes);
                }
                break;
            case 4:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_abonoSaveAsText("abono.csv",listaAbono);
                    controller_abonoSaveAsBinary("abono.bin",listaAbono);
                }
                break;
            case 5:
                seguir = 'n';
                printf("\nSaliendo... \n");
                break;
            case 6:
                if(flagFile == 0){
                    printf("No hay empleadxs cargadxs para realizar esta accion. \n");
                }else{
                    controller_ListEmployee(listaClientes);
                }
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
