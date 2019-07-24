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
    Employee* pEmployee;                                      //nuevo empleado
    char varId[50], varNombre[50], varHoras[50], varSueldo[50] = "0" ;
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", varId, varNombre, varHoras);     // revisa la lectura y asigna a cantidad
    while(!feof(pFile)){                                                     //mientras no se llegue al final
        cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", varId, varNombre, varHoras);      // revisa la lectura y asigna a cantidad
        if(cant == 3){                                                                     //si cantidad (la revision de lectura) es igual a 4
            pEmployee = employee_newParametros(varId, varNombre, varHoras, varSueldo);
            ll_add(pArrayListEmployee,pEmployee);                                     //se agrega lo leido al array
            i++;                                                           //bytes leidos por si hay algun error
        }else{                                                  //hay algun error en la lectura
            if(feof(pFile)){                                             //si se llega al final del archivo
                printf("\nFinal del archivo. Bytes leidos %d", i);          //comunica que se ha llegado al final y la cantidad de bytes leidos
                system("pause");
                break;
            }
        }
    }
    printf("Datos cargados correctamente.\n");
    fclose(pFile);          //cierre del archivo
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

    cant = fread(&employee, sizeof(Employee), 1, pFile);         //revisa lectura y se lo asigno a cantidad
    while(!feof(pFile)){                       //mientras no se llega al final del archuvo
        Employee* pEmployee = employee_new();             //nuevo empleado y lle asigno lo leido
        employee_setId(pEmployee,employee.id);
        employee_setHorasTrabajadas(pEmployee,employee.horasTrabajadas);
        employee_setNombre(pEmployee,employee.nombre);
        employee_setSueldo(pEmployee,employee.sueldo);
    if(cant == 1){                                       //si la cantidad es igual a uno
            ll_add(pArrayListEmployee, pEmployee);               //el empleado se agrega al array
            fread(&employee, sizeof(Employee), 1, pFile);             //lectura
            i++;                                     //incremento bytes leidos
    }else{                         //posible error leyendo
            if(!feof(pFile)){
                printf("\n!!! - Se ha producido un error llegando al final del archivo.");
                system("pause");
                break;
            }else{
                printf("\nFinal del archivo. Bytes leidos %d", i);         //aviso de bytes leido
            }
        }
    }
    printf("Datos cargados correctamente.\n");
    fclose(pFile);          //cierre del archivo
    return i;
}
