#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entity.h"

/** \brief Parsea los datos de la entidad desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int parser_EntityFromTextCliente(FILE* pFile , LinkedList* pArrayListEntity){
    eCliente* pEntity;                                      //nueva entidad
    char varId[50], varNombre[51], varSexo[50], varNumeroTelefono[50], varImporte[50];
    int cant, i = 0;

    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre, varSexo, varNumeroTelefono, varImporte);     // revisa la lectura y asigna a cantidad
    while(!feof(pFile)){                                                     //mientras no se llegue al final
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre, varSexo, varNumeroTelefono, varImporte);      // revisa la lectura y asigna a cantidad
        if(cant == 5){                                                                     //si cantidad (la revision de lectura) es igual a x cantidad de variables
            pEntity = entity_newParametros(varId, varNombre, varSexo, varNumeroTelefono, varImporte);
            ll_add(pArrayListEntity,pEntity);                                     //se agrega lo leido al array
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

///** \brief Parsea los datos de la entidad desde el archivo data.csv (modo binario).
// *
// * \param path char*
// * \param pArrayListEntity LinkedList*
// * \return int
// *
// */
//int parser_EntityFromBinary(FILE* pFile , LinkedList* pArrayListEntity)
//{
//    eEntity entity;
//    int cant, i = 0;
//
//    cant = fread(&entity, sizeof(eEntity), 1, pFile);         //revisa lectura y se lo asigno a cantidad
//    while(!feof(pFile)){                       //mientras no se llega al final del archivo
//        eEntity* pEntity = entity_new();             //nueva entidad y le asigno lo leido
//        entity_setId(pEntity,entity.id);
//        entity_setHorasTrabajadas(pEntity,entity.horasTrabajadas);
//        entity_setNombre(pEntity,entity.nombre);
//        entity_setSueldo(pEntity,entity.sueldo);
//    if(cant == 1){                                       //si la cantidad es igual a uno
//            ll_add(pArrayListEntity, pEntity);               //la entidad se agrega al array
//            fread(&entity, sizeof(eEntity), 1, pFile);             //lectura
//            i++;                                     //incremento bytes leidos
//    }else{                         //posible error leyendo
//            if(!feof(pFile)){
//                printf("\n!!! - Se ha producido un error llegando al final del archivo.");
//                system("pause");
//                break;
//            }else{
//                printf("\nFinal del archivo. Bytes leidos %d", i);         //aviso de bytes leido
//            }
//        }
//    }
//    printf("Datos cargados correctamente.\n");
//    fclose(pFile);          //cierre del archivo
//    return i;
//}
