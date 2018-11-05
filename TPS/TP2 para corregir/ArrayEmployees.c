#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

int menu(void){
    int option;
    system("cls");
    printf("---Menu de Opciones---\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Salir\n\n");
    printf("0- Hardcodeo\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}

int initEmployees(eEmployee* listi, int len){
    int ret = -1;
    if(listi!=NULL && len > 0){
        for(int i=0; i < len; i++){
            listi[i].isEmpty = 1;
        }
        ret = 0;
    }
    return ret;
}

int freeSpace(eEmployee* listi, int len){
    int index = -1;
    for(int i=0; i< len; i++){
        if( listi[i].isEmpty == 1){
            index = i;
            break;
        }
    }
    return index;
}

void printSector(void){
    printf("\n-----Sectores-----\n");
    printf("  1 Sistemas\n");
    printf("  2 Ventas\n");
    printf("  3 Mantenimiento\n");
    printf("  4 Atencion\n");
    printf("  5 RRHH\n");
}

int findEmployeeById(eEmployee* listi, int len, int id){
    int ret;
    for(int i=0; i < len; i++){
        if(listi[i].id == id && listi[i].isEmpty == 0){
            ret = i;
        }
    }
    return ret;
}

int printEmployee(eEmployee* listi, int index){
    printf("-ID: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n\n", listi[index].id, listi[index].name, listi[index].lastName, listi[index].salary, listi[index].sector);
    return 0;
}

int addEmployee(eEmployee* listi, int len, int id, char name[],char lastName[], float salary, int sector){
    eEmployee emplAdd;
    int index = freeSpace(listi, len);
    int ret = -1;
    if(index == -1){
        printf("!! - No hay lugar disponible. \n\n");
    } else {
        if (listi != NULL && len > 0){
            emplAdd.id = id;
            strcpy(emplAdd.name, name);
            strcpy(emplAdd.lastName, lastName);
            emplAdd.salary = salary;
            emplAdd.sector = sector;

            emplAdd.isEmpty = 0;
            listi[index] = emplAdd;
            ret = 0;
        }
    }
    return ret;
}

int editEmployeeById(eEmployee* listi, int len, int id){
    int index;
    int subMenu;
    eEmployee emplAux;
    int ret = -1;

    index = findEmployeeById(listi, len, id);
    char cont = 's';

    if(index != -1){
        if (listi != NULL && len > 0){
            do{
                printf("ID\tNombre\tApellido\tSalario\t\tSector\n");
                printEmployee(listi, index);
                printf("Que desea modificar?\n");
                printf("\t1- Nombre\n");
                printf("\t2- Apellido\n");
                printf("\t3- Salario\n");
                printf("\t4- Sector\n");
                printf("\t5- Salir\n");
                scanf("%d", &subMenu);
                switch(subMenu){
                    case 1:
                        getValidString("Ingrese nombre: ", "Valor no valido.", emplAux.name);
                        strcpy(listi[index].name, emplAux.name);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 2:
                        getValidString("Ingrese apellido: ", "Valor no valido.", emplAux.lastName);
                        strcpy(listi[index].lastName, emplAux.lastName);
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 3:
                        emplAux.salary =getValidFloat("Ingrese salario: ","Valor no valido", 10000, 1000000);
                        listi[index].salary=emplAux.salary;
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 4:
                        printSector();
                        emplAux.sector =getValidInt("Ingrese sector: ","Valor no valido", 0, 5);
                        listi[index].sector= emplAux.sector;
                        printf("Se ha modificado el dato con exito.\n\n");
                        break;
                    case 5:
                        break;
                    default :
                        printf("Error, ingrese numero entre 1 y 5.\n");
                        break;
                }
                printf("Desea editar otro dato? Presione 's' para aceptar, aprete cualquier otra tecla para salir.\n");
                fflush(stdin);
                scanf("%c", &cont);
            }while (cont == 's');
            printf("Saliendo al Menu...\n");
            ret = 0;
        }
    } else {
        printf("!! - No se ha encontrado empleadx con esa ID. \n");
    }
    return ret;
}

int removeEmployee(eEmployee* listi, int len, int id){
    int index;
    char del;
    int ret = -1;

    index = findEmployeeById(listi, len, id);
    if(index != -1){
        if (listi != NULL && len > 0){
            printf("ID\tNombre\tApellido\tSalario\t\tSector\n");
            printEmployee(listi, index);
            printf("Confirmar eliminado? 's' para confirmar: ");
            fflush(stdin);
            scanf("%c", &del);
            if(del != 's'){
                printf("Eliminado cancelado\n\n");
            }else {
                listi[index].isEmpty = 1;
                printf("Se ha eliminado empleadx\n\n");
            }
            ret = 0;
        }
    }else {
        printf("!! - No se ha encontrado empleadx con esa ID.\n");
    }
    return ret;
}

int printEmployees(eEmployee* listi, int len){
    for(int i=0; i< len; i++){
        if(listi[i].isEmpty == 0){
            printEmployee(listi, i);
        }
    }
    return 0;
}

int sortEmployees(eEmployee* listi, int len, int order){
    int ret = -1;
    eEmployee auxEmployees;
    if (listi != NULL && len > 0){
        if(order == 1){
            for(int i =0 ; i<len-1 ; i ++){
                for(int j= i+1 ; j<len; j++){
                    if(strcmp(listi[j].lastName,listi[i].lastName)<0 && listi[j].isEmpty==0 && listi[i].isEmpty==0){
                        auxEmployees = listi[i];
                        listi[i] = listi[j];
                        listi[j] = auxEmployees;
                    }else if(strcmp(listi[j].lastName,listi[i].lastName) ==0 && listi[j].sector<listi[i].sector && listi[j].isEmpty==0 && listi[i].isEmpty==0){
                        auxEmployees = listi[i];
                        listi[i] = listi[j];
                        listi[j] = auxEmployees;
                    }
                }
            }
            printf("\t1--Listado de empleadxs Apellido y Sector - Ascendente\n\n");
            printEmployees(listi, len);
        }else if(order == 2){
            for(int i =0 ; i<len-1 ; i ++){
                for(int j= i+1 ; j<len; j++){
                    if(strcmp(listi[j].lastName,listi[i].lastName)>0 && listi[j].sector<listi[i].sector && listi[j].isEmpty==0 && listi[i].isEmpty==0){
                        auxEmployees = listi[i];
                        listi[i] = listi[j];
                        listi[j] = auxEmployees;
                    }else if(strcmp(listi[j].lastName,listi[i].lastName) ==0 && listi[j].sector>listi[i].sector && listi[j].sector<listi[i].sector && listi[j].isEmpty==0 && listi[i].isEmpty==0){
                        auxEmployees = listi[i];
                        listi[i] = listi[j];
                        listi[j] = auxEmployees;
                    }
                }
            }
            printf("\t1--Listado de empleadxs Apellido y Sector - Descendente\n\n");
            printEmployees(listi, len);
        } else {
                printf("Opcion no valida\n");
        }
        ret = 0;
    }
    return ret;
}

int averageSalary(eEmployee* listi, int len){
    float empl=0;
    float salaryTotal=0;
    float average = -1;
    for (int i = 0; i<len; i++){
        if(listi[i].isEmpty==0){
            empl++;
            salaryTotal = salaryTotal + listi[i].salary;
        }
    }
    average = salaryTotal / empl;
    printf("\t2--Total y promedio de los salarios \n\n");
    printf("Total: %.2f\t", salaryTotal);
    printf("Promedio: %.2f\n", average);
    return average;
}

int aboveAverageSalary(eEmployee* listi, int len){
    int average;
    int aboveA = 0;
    average = averageSalary(listi, len);
    for(int i = 0; i<len; i++){
        if(listi[i].salary > average){
            aboveA++;
        }
    }
    printf("\n\t2--Cuantxs empleadxs superan el salario promedio? \n");
    printf("%d \n", aboveA);
    return 0;
}



void hardcodeo(eEmployee* listi){
    eEmployee y[]={
        {1, "Ana", "Giga", 15000, 5, 0},
        {2, "Luis", "Alberto", 25000, 4, 0},
        {3, "Juli", "Puertas", 10000, 5, 0},
        {4, "Julia", "Giga", 30000, 1, 0},
        {5, "Mile", "Rovida", 23000, 2, 0},
        {6, "Vero", "Zantos", 31000, 5, 0},
        {7, "Mauro", "Felo", 27000, 5, 0},
    };

    for(int i=0; i<7; i++){
        listi[i] = y[i];
    }
    printf("\tHardcodeo hecho!\n");
}
