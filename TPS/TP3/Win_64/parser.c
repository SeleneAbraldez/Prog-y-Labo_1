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
    Employee* pEmployee = employee_new();
    char varId[50], varNombre[50], varHoras[50], varSueldo[50];
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre, varHoras, varSueldo);
    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre, varHoras, varSueldo);
        if(cant == 4)
        {
            pEmployee = employee_newParametros(varId, varNombre, varHoras, varSueldo);
            ll_add(pArrayListEmployee,pEmployee);
            i++;
        }
        else{
            if(!feof(pFile)){ ///preguntar
                printf("\n!!! - Se ha producido un error llegando al final del archivo.");
                system("pause");
                break;
            }else{
                printf("\nFinal del archivo.");
            }
        }
    }
    printf("Datos cargados correctamente.\n");
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
    Employee* pEmployee = employee_new();
    char varId[50], varNombre[50], varHoras[50], varSueldo[50];
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre, varHoras, varSueldo); ///fread
    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre, varHoras, varSueldo);
        if(cant == 4)
        {
            pEmployee = employee_newParametros(varId, varNombre, varHoras, varSueldo);
            ll_add(pArrayListEmployee,pEmployee);
            i++;
        }
        else{if(!feof(pFile)){
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
    return 1;
}
