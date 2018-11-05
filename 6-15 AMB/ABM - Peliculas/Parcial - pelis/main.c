#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "peliculas.h"

int main()
{
    char seguir = 's';

    ePeliculas peliculas;
    eDirectorx directores;
    eFecha fecha;

    do{
        switch(menu()){
        case 1:
            printf("Alta");
            //agregarEmpleado(lista, 10, sectores, 5);
            break;
        case 2:
             printf("Eliminar");
            //eliminarEmpleado(lista, 10, sectores, 5);
            break;
        case 3:
             printf("Baja");
            //modificarEmpleado(lista, 10, sectores, 5);
            break;
        case 4:
             printf("Alta dire");
            //mostrarEmpleados(lista, 10, sectores, 5);
            break;
        case 5:
            printf("baja dire");
            //listarEmpleadosXSector(lista, 10, sectores, 5);
            break;
        case 6:
            printf("listar");
            //ordenarEmpleadosXSector(lista, 10, sectores, 5);
            break;
        case 10:
            seguir = 'n';
            break;
        }
        system("pause");
    }while(seguir == 's');




    return 0;
}
