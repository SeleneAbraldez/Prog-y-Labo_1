#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleadxs.h"
#include "menu.h"
#include "almuerzo.h"

#define CANTEMPL 10
#define CANTMENU 6
#define CANTALMUER 15


int main(){
    char seguir = 's';
    eEmpleadx lista[CANTEMPL];
    eSector sectores[]={
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"},
    };
    eMenu comidas[CANTMENU];
    eAlmuerzo almuerzos[CANTALMUER];

    inicializarEmpleadxs(lista, CANTEMPL);
    inicializarMenu(comidas, CANTMENU);
    inicializarAlmuerzo(almuerzos, CANTALMUER);

    do{
        switch(menu()){
        case 1:
            altaEmpleadx(lista, CANTEMPL, sectores, 5);
            break;
        case 2:
            bajaEmpleadxs(lista, CANTEMPL, sectores, 5);
            break;
        case 3:
            modificarEmpleadx(lista, CANTEMPL, sectores, 5);
            break;
        case 4:
            imprimirEmpleadxs(lista, CANTEMPL, sectores, 5);
            break;
        case 5:
            altaMenu(comidas, CANTMENU);
            break;
        case 6:
            bajaMenu(comidas, CANTMENU);
            break;
        case 7:
            imprimirMenus(comidas, CANTMENU);
            break;
        case 8:
            altaAlmuerzo(almuerzos, CANTALMUER, lista, CANTEMPL, comidas, 5);
            break;
        case 9:
            bajaAlmuerzo(almuerzos, CANTALMUER, lista, CANTEMPL, comidas, 5);
            break;
        case 10:
            imprimirAlmuerzos(almuerzos, CANTALMUER, lista, CANTEMPL, comidas, 5);
            break;
        case 0:
            hardcodeoEmpleadxs(lista);
            hardcodeoMenu(comidas);
            hardcodeoAlmuerzo(almuerzos);
            break;
        case 100:
            seguir = 'n';
            break;
        }
    system("pause");
    }while(seguir == 's');

    return 0;
}
