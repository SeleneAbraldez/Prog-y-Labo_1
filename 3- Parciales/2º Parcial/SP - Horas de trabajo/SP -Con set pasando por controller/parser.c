#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    Employee* pEmployee;
    char varId[50], varNombre[50], varHoras[50], varSueldo[50] = "0";
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", varId, varNombre, varHoras);
    while(!feof(pFile)){
        cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", varId, varNombre, varHoras);
        if(cant == 3){
            pEmployee = employee_newParametros(varId, varNombre, varHoras, varSueldo);
            ll_add(pArrayListEmployee,pEmployee);
            i++;
        }else{
            if(feof(pFile)){
                printf("\nFinal del archivo. Bytes leidos %d \n", i);
                system("pause");
                break;
            }
        }
    }
    printf("Datos cargados.\n");
    fclose(pFile);
    return i;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee employee;
    int cant, i = 0;

    cant = fread(&employee, sizeof(Employee), 1, pFile);
    while(!feof(pFile)){
        Employee* pEmployee = employee_new();
        employee_setId(pEmployee,employee.id);
        employee_setHorasTrabajadas(pEmployee,employee.horasTrabajadas);
        employee_setNombre(pEmployee,employee.nombre);
        employee_setSueldo(pEmployee,employee.sueldo);
    if(cant == 1){
            ll_add(pArrayListEmployee, pEmployee);
            fread(&employee, sizeof(Employee), 1, pFile);
            i++;
    }else{
            if(!feof(pFile)){
                printf("\n!!! - Se ha producido un error llegando al final del archivo.");
                system("pause");
                break;
            }else{
                printf("\nFinal del archivo. Bytes leidos %d", i);
            }
        }
    }
    printf("Datos cargados correctamente.\n");
    fclose(pFile);
    return i;
}
