#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_menu(){
    int option = -1;
        system("cls");
        printf("\n\t -Trabajo Practico Nro 3: LinkedList- \n\t\tSelene Abraldez 1 A \n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). \n");
        printf("3. Alta de empleado \n");
        printf("4. Modificar datos de empleado \n");
        printf("5. Baja de empleado \n");
        printf("6. Listar empleados \n");
        printf("7. Ordenar empleados \n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario). \n");
        printf("10. Salir \n");
        option = getValidInt("\n\t*Seleccione  una opcion: ", "Opcion no valida, reintente", 0, 10);
    return option;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char crear = 'n';
    FILE* lista;
    if((lista=fopen(path, "rb+")) == NULL){
        printf("No se ha encontrado el archivo. Desea crealo? 's' para aceptar: ");
        scanf("%c", &crear);
        if(crear == 's'){
            if ((lista=fopen(path,"wb+"))==NULL){
                printf("!! - Error, no se ha podido abrir el archivo.\n");
                return retorno;
                exit(-1);
            }
        }else{
            printf("Saliendo...");
        }
    }else{
        printf("Archivo encontrado. ");
    }
    parser_EmployeeFromText(lista, pArrayListEmployee);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char crear = 'n';
    FILE* lista;
    if((lista=fopen(path, "rb+")) == NULL){
        printf("No se ha encontrado el archivo. Desea crealo? 's' para aceptar: ");
        scanf("%c", &crear);
        if(crear == 's'){
            if ((lista=fopen(path,"wb+"))==NULL){
                printf("!! - Error, no se ha podido abrir el archivo.\n");
                return retorno;
                exit(-1);
            }
        }else{
            printf("Saliendo...");
        }
    }else{
        printf("Archivo encontrado. ");
    }
    parser_EmployeeFromBinary(lista, pArrayListEmployee);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* this;
    char idAux[5];
    char nombreAux[128];
    char horasAux[7];
    char sueldoAux[15];

    if(pArrayListEmployee != NULL){
        this = employee_new();
        getValidStringNumberLen("Ingrese ID: ","Dato invalido. ", "El dato debe tener menos de 5 caracteres. ", idAux, 5);
        getValidStringLen("Ingrese nombre: ", "Dato invalido. ", "El dato debe tener menos de 128 caracteres. ",nombreAux, 128);
        getValidStringNumberLen("Ingrese horas trabajadas: ",  "Dato invalido. ", "El dato debe tener menos de 7 caracteres. ", horasAux, 7);
        getValidStringNumberLen("Ingrese sueldo: ", "Dato invalido. ", "El dato debe tener menos de 7 caracteres. ", sueldoAux, 15);
        this = employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
        ll_add(pArrayListEmployee, this);
        retorno = 0;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int option;
    char idM[5];
    int index=1;
    Employee* this;
    char idAux[5];
    char nombreAux[128];
    char horasAux[7];
    char sueldoAux[15];

    printf("Ingrese ID de empleadx a modificar: ");
    scanf("%s", &idM);
    if(1){
        printf("\n  Id\t    Nombre\t  Horas trabajadas\tSueldo**\n");
        this = ll_get(pArrayListEmployee, index);
        if(this != NULL){
            printf("%4d%14s\t\t%d\t\t%6d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
            printf("\nIngrese dato a modificar: \n");
            printf("\t1- Id\n");
            printf("\t2- Nombre\n");
            printf("\t3- Horas trabajadas\n");
            printf("\t4- Salario\n");
            scanf("%d", &option);

            switch(option){
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            default:
                printf("Opcion no valida\n");
                break;
            }
            retorno = 0;
        }
    }else{
        printf("No se ha encontrado empleadx %s", idM);
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char idAux[5];


    printf("Ingrese ID de empeladx a eliminar: ");
    scanf("%s", idAux);


    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* this;
    printf("\n**Id\t    Nombre\t  Horas trabajadas\tSueldo**\n\n");
    for(int i=0; i<ll_len(pArrayListEmployee); i++){
        this = ll_get(pArrayListEmployee, i);
        if(this != NULL){
            printf("%4d%14s\t\t%d\t\t%6d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        }
    }
    printf("\n");
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int option;

    printf("Seleeccionar ordenamiento por: \n");
    printf("\t1- Id\n");
    printf("\t2- Nombre\n");
    printf("\t3- Horas trabajadas\n");
    printf("\t4- Salario\n");
    scanf("%d", &option);

    switch(option){
    case 1:
        ll_sort(pArrayListEmployee, employeeSortById, 0);
        printf("Ordenamiento por id realizado!\n");
        break;
    case 2:
        ll_sort(pArrayListEmployee, employeeSortByName, 0);
        printf("Ordenamiento por nombre realizado!\n");
        break;
    case 3:
        ll_sort(pArrayListEmployee, employeeSortByHours, 0);
        printf("Ordenamiento por horas trabajadas realizado!\n");
        break;
    case 4:
        ll_sort(pArrayListEmployee, employeeSortBySalary, 0);
        printf("Ordenamiento por salario realizado!\n");
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int len = ll_len(pArrayListEmployee);
    Employee* this;
    FILE* lista = fopen(path, "w");

    if(lista==NULL){
        printf("Error para guardar\n");
        return retorno;
    }
    fprintf(lista, "id,nombre,horasTrabajadas,sueldo\n");
    if(pArrayListEmployee!=NULL){
        for(int i=0; i<len; i++){
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(lista, "%d,%s,%d,%d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        printf("Archivo Guardado.\n");
        retorno = 1;
    }
    fclose(lista);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int len = ll_len(pArrayListEmployee);
    Employee* this;
    FILE* lista = fopen(path, "wb");

    if(lista==NULL){
        printf("Error para guardar\n");
        return retorno;
    }
    fprintf(lista, "id,nombre,horasTrabajadas,sueldo\n");
    if(pArrayListEmployee!=NULL){
        for(int i=0; i<len; i++){
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(lista, "%d,%s,%d,%d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        printf("Archivo Guardado.\n");
        retorno = 1;
    }
    fclose(lista);
    return retorno;
}

