#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Alquiler.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_AlquilerFromText(FILE* pFile , LinkedList* pArrayListAlquiler){
    eAlquiler* pAlquiler;                                      //nuevo empleado
    char varId[50], varFecha[50], varNombre[50], varCantidad[50], varPrecio[50], varCuit[50];
    int cant, i = 0;
    cant = fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", varId, varFecha, varNombre, varCantidad, varPrecio, varCuit);     // revisa la lectura y asigna a cantidad
    while(!feof(pFile)){                                                     //mientras no se llegue al final
        cant = fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", varId, varFecha, varNombre, varCantidad, varPrecio, varCuit);      // revisa la lectura y asigna a cantidad
        if(cant == 6){                                                                     //si cantidad (la revision de lectura) es igual a 4
            pAlquiler = alquiler_newParametros(varId, varFecha, varNombre, varCantidad, varPrecio, varCuit);
            ll_add(pArrayListAlquiler, pAlquiler);                                     //se agrega lo leido al array
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
int parser_AlquilerFromBinary(FILE* pFile , LinkedList* pArrayListAlquiler)
{
    eAlquiler alquiler;
    int cant, i = 0;

    cant = fread(&alquiler, sizeof(eAlquiler), 1, pFile);         //revisa lectura y se lo asigno a cantidad
    while(!feof(pFile)){                       //mientras no se llega al final del archuvo
        eAlquiler* pAlquiler = alquiler_new();             //nuevo empleado y lle asigno lo leido
        alquiler_setId(pAlquiler, alquiler.id);
        alquiler_setFecha(pAlquiler, alquiler.fecha);
        alquiler_setNombre(pAlquiler, alquiler.nombre);
        alquiler_setCantidad(pAlquiler, alquiler.cantidad);
        alquiler_setPrecio(pAlquiler, alquiler.precio);
        alquiler_setCuit(pAlquiler, alquiler.cuit);
    if(cant == 1){                                       //si la cantidad es igual a uno
            ll_add(pArrayListAlquiler, pAlquiler);               //el empleado se agrega al array
            fread(&alquiler, sizeof(eAlquiler), 1, pFile);             //lectura
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
