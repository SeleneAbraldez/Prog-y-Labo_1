#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define CANT 1000 // 1000 empleadxs

int main(){
    char seguir = 's';
    int orderer;
    eEmployee employees[CANT];

    int index;
    int idAux;
    char nameAux[51];
    char lastnameAux[51];
    float salaryAux;
    int sectorAux;

    int emplCount = 0;

    initEmployees(employees, CANT);

    do{
        switch(menu()){
        case 1:
            index = freeSpace(employees, CANT);
            if(index == -1){
                printf("!! - No hay lugar disponible. \n\n");
            } else {
                idAux = index + 1;
                printf("-- Empleadx ID %d --\n", idAux);

                getValidString("Ingrese nombre: ", "Valor no valido.", nameAux);
                getValidString("Ingrese apellido: ", "Valor no valido.", lastnameAux);
                salaryAux =getValidFloat("Ingrese salario: ","Valor no valido", 10000, 1000000);
                printSector();
                sectorAux =getValidInt("Ingrese sector: ","Valor no valido", 0, 5);

                if(addEmployee(employees, CANT, idAux, nameAux, lastnameAux, salaryAux, sectorAux) == -1){
                    printf("!!! - Se ha producido un error.\n");
                }else{
                    emplCount++;
                }
            }
            break;
        case 2:
            if(emplCount < 1){
                printf("No hay empleadxs que editar.\n");
            } else {
                idAux= getValidInt("Ingrese ID: ", "ID no valido.", 0, 1000);
                if(editEmployeeById(employees, CANT, idAux)==-1){
                    printf("!!! - Se ha producido un error.\n");
                }
            }
            break;
        case 3:
            if(emplCount < 1){
                printf("No hay empleadxs que borrar.\n");
            } else {
                idAux= getValidInt("Ingrese ID: ", "ID no valido.", 0, 1000);
                if(removeEmployee(employees, CANT, idAux)==-1){
                    printf("!!! - Se ha producido un error.\n");
                }else{
                    emplCount--;
                }
            }
            break;
        case 4:
            if(emplCount < 1){
                printf("No hay empleadxs que mostrar.\n");
            } else {
                orderer = getValidInt("De que forma desea ordenar a lxs empleadxs?\n 1 para Ascendente, 2 para Descendente: ", "Valor no valido.", 1, 2);
                if(sortEmployees(employees, CANT, orderer)==-1){
                    printf("!!! - Se ha producido un error.\n");
                }else{
                    if(aboveAverageSalary(employees, CANT)==-1){
                    printf("!!! - Se ha producido un error.\n");
                    }
                }
            }
            break;
        case 5:
            seguir = 'n';
            printf("\nSaliendo... \n");
            break;
        case 0:
            hardcodeo(employees);
            emplCount = emplCount + 7;
            break;
        default:
            printf("Opcion no valida, ingrese numero entre 0 y 5. \n\n");
            break;
        }
    system("pause");
    }while(seguir == 's');
    return 0;
}
