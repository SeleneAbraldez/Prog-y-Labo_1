#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleadxs.h"
#include "menu.h"
#include "almuerzo.h"
#include "utn.h"

int main(){
    char seguir = 's';
    eEmpleado lista[10]={
        {1111, "Juan", 'm', 15000, 3, 1},
        {2222, "Juana", 'f', 19000, 2, 1},
        {3333, "Ana", 'f', 17000, 2, 1},
        {4444, "Pepe", 'm', 1000, 5, 1},
        {5555, "Ari", 'f', 25000, 4, 1},
    };

    eSector sectores[]={
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"},
    };

    eComida comidas[]={
        {1, "Ensalada"},
        {2, "Tortilla"},
        {3, "Mila de Soja"},
        {4, "Revuelto"},
        {5, "Tarta"},
    };

    eAlmuerzo almuerzos[]={
        {100, 1111, 4},
        {101, 3333, 2},
        {102, 2222, 4},
        {103, 1111, 5},
        {104, 4444, 3},
        {105, 1111, 1},
        {106, 5555, 3},
        {107, 3333, 4},
        {108, 2222, 5},
        {109, 4444, 4},
        {110, 1111, 2},
    };

    inicializarEmpleados(lista, 10);

    do{
        switch(menu()){
        case 1:
            agregarEmpleado(lista, 10, sectores, 5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, 10, sectores, 5);
            break;
        case 3:
            modificarEmpleado(lista, 10, sectores, 5);
            break;
        case 4:
            mostrarEmpleados(lista, 10, sectores, 5);
            system("pause");
            break;
        case 5:
            listarEmpleadosXSector(lista, 10, sectores, 5);
            system("pause");
            break;
        case 6:
            ordenarEmpleadosXSector(lista, 10, sectores, 5);
            system("pause");
            break;
        case 7:
            printf("7\n");
            break;
        case 8:
            mostrarAlmuerzos(lista, comidas, almuerzos, 11, 5, 10);
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }while(seguir == 's');

    return 0;
}
