#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entity.h"
#include "parser.h"
#include "utn.h"

int controller_menu(){    //menu inicial
    int option = -1;
        system("cls");
        printf("1. Cargar los datos desde el archivo data.csv (modo texto). \n");
        printf("2. Listar \n");
        printf("3. Realizar informes y guardar en 'informes.txt' \n");
        printf("10. Salir \n");
        option = getValidInt("\n\t*Seleccione  una opcion: ", "Opcion no valida, reintente", 0, 10);
    return option;
}


/** \brief Carga los datos de laa entidades desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEntity)
{
    int retorno = -1;
    char crear = 'n';
    FILE* listaFT;
    if((listaFT=fopen(path, "r+")) == NULL){               //lectura + si no se encuentra se crea
        printf("No se ha encontrado el archivo. ");
        crear = getValidYesNoChar("Desea crealo? y/n: ", "Opcion no valida. ");
        if(crear == 'y'){                                            //aceptar crear crea
            if ((listaFT=fopen(path,"w+"))==NULL){
                printf("!! - Error, no se ha podido abrir el archivo.\n");           //-1 si hay un error
                return retorno;
                exit(-1);
            }else{
                printf("Archivo creado. ");                           //1 si no se encontro y se creo
            }
        }else{
            printf("Saliendo...\n");
            return 0;                                                        //0 si no se encontro y no se creo
        }
    }else{
        printf("Archivo encontrado. ");
        parser_EntityFromText(listaFT, pArrayListEntity);
    }
    return 1;                                                       //1 si se encontro y cargo
}

/** \brief Listar entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_ListEntitys(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    eEntity* this;
    if((ll_len(pArrayListEntity))>0){
        printf("\n**Id\t  Tipo\t  Cantidad\tImporte**\n\n");
        for(int i=0; i<ll_len(pArrayListEntity); i++){
            this = ll_get(pArrayListEntity, i);

            if(this != NULL){
                printf("%-12d %-16s %-16d %-10.2f\n", this->id,this->tipo,this->cantidad,this->importe);
            }
        }
    }else{
        printf("Archivo cargado con 0 elementos, cargar nuevo archivo. ");
    }
    printf("\n");
    return retorno;
}

///** \brief Ordenar entidades
// *
// * \param path char*
// * \param pArrayListEntity LinkedList*
// * \return int
// *
// */
//int controller_sortEntity(LinkedList* pArrayListEntity)
//{
//    int retorno = -1;
//    int option;
//
//    printf("Seleeccionar ordenamiento por: \n");
//    printf("\t1- Id forma ascendente\n");
//    printf("\t2- Nombre forma ascendente\n");
//    printf("\t3- Horas trabajadas forma ascendente\n");
//    printf("\t4- Salario forma ascendente\n\n");
//    printf("\t5- Id forma descendente\n");
//    printf("\t6- Nombre forma descendente\n");
//    printf("\t7- Horas trabajadas forma descendente\n");
//    printf("\t8- Salario forma descendente\n");
//    scanf("%d", &option);
//
//    switch(option){         //sependiendo de la opcion ordena
//    case 1:
//        ll_sort(pArrayListEntity, entitySortById, 0);
//        printf("Ordenamiento ascendente por id realizado!\n");
//        break;
//    case 2:
//        ll_sort(pArrayListEntity, entitySortByName, 0);
//        printf("Ordenamiento ascendente por nombre realizado!\n");
//        break;
//    case 3:
//        ll_sort(pArrayListEntity, entitySortByHours, 0);
//        printf("Ordenamiento ascendente por horas trabajadas realizado!\n");
//        break;
//    case 4:
//        ll_sort(pArrayListEntity, entitySortBySalary, 0);
//        printf("Ordenamiento ascendente por salario realizado!\n");
//        break;
//    case 5:
//        ll_sort(pArrayListEntity, entitySortById, 1);
//        printf("Ordenamiento descendente por id realizado!\n");
//        break;
//    case 6:
//        ll_sort(pArrayListEntity, entitySortByName, 1);
//        printf("Ordenamiento descendente por nombre realizado!\n");
//        break;
//    case 7:
//        ll_sort(pArrayListEntity, entitySortByHours, 1);
//        printf("Ordenamiento descendente por horas trabajadas realizado!\n");
//        break;
//    case 8:
//        ll_sort(pArrayListEntity, entitySortBySalary, 1);
//        printf("Ordenamiento descendente por salario realizado!\n");
//        break;
//    default:
//        printf("Opcion no valida\n");
//        break;
//    }
//    return retorno;
//}
//
//
///** \brief Filtra empleados
// *
// * \param pArrayListEntity LinkedList*
// * \return int
// *
// */
//int controller_filterEntity(LinkedList* pArrayListEntity)
//{
//    int retorno = -1;
//    int option;
//    LinkedList* filterList;
//    int optionYN;
//
//
//    printf("Seleeccionar filtro por: \n");
//    printf("\t1- Horas trabajadas mayores a 150\n");
//    printf("\t2- Id mayor a 10\n");
//    printf("\t3- Nombre por debajo de H\n");
//    scanf("%d", &option);
//
//    switch(option){
//    case 1:
//        filterList = ll_filter(pArrayListEntity, entityFilterHours);
//        printf("Filtro: Horas trabajadas mayores a 150 ");
//        break;
//    case 2:
//        filterList = ll_filter(pArrayListEntity, entityFilterId);
//        printf("Filtro: Id mayor a 10 ");
//        break;
//    case 3:
//        filterList = ll_filter(pArrayListEntity, entityFilterName);
//        printf("Filtro: Nombre por debajo de H ");
//        break;
//    default:
//        printf("Opcion no valida\n");
//        break;
//    }
//    if(filterList != NULL){
//        retorno = 0;
//        if(ll_len(filterList)>0){
//            controller_ListEntitys(filterList);
//            optionYN = getValidYesNoChar("Desea guardar la lista filtrada en 'filteredData.csv?' y/n: ", "Caracter no valido. ");
//            if(optionYN == 'y'){
//                controller_saveAsText("filteredData.csv", filterList);
//            }else{
//                printf("Saliendo sin guardar. \n");
//            }
//        }else{
//            printf("ha resultado con 0 empleadxs. \n");
//        }
//    }else{
//        printf("no se ha podido realizar.\n");
//    }
//
//    return retorno;
//}
//
///** \brief Realiza un mapeo de entidades
// *
// * \param pArrayListEntity LinkedList*
// * \return int 0 si esta todo ok
// *
// */
//int controller_mapEntity(LinkedList* pArrayListEntity)
//{
//    int retorno = -1;
//
//   if(ll_map(pArrayListEntity, entityMapSalary) != 0){
//        printf("No se ha podido hacer el mapeo.");
//    }else{
//        printf("Sueldos actualizados con exito.\n");
//        retorno = 0;
//    }
//    return retorno;
//}


/** \brief Realiza un informe con lo pedido
 *
 * \param pArrayListEntity LinkedList*
 * \return int 0 si esta todo ok
 *
 */
int controller_makeInfo(LinkedList* pArrayListEntity)
{
    int retorno = 0;
    int ventasTotales, conteoGold, conteoRegular, conteoPlus, bultosTotales, promedioBultoEntrega;
    float promedioImporte;

    printf("\n*************************\n  Informe de ventas\n*************************\n");
    ventasTotales = ll_count(pArrayListEntity, entityVentasTotales);
    if(ventasTotales == -1){
        printf("No se ha podido hacer total.");
        retorno = -1;
    }else{
        printf("-Cantidad total de entregas: %d\n", ventasTotales);
    }

    conteoGold = ll_count(pArrayListEntity, entityGold);
    conteoRegular = ll_count(pArrayListEntity, entityRegular);
    conteoPlus = ll_count(pArrayListEntity, entityPlus);
    if(conteoGold == -1 || conteoRegular == -1 || conteoPlus == -1){
        printf("No se ha podido hacer el conteo de entregas por tipo.");
        retorno = -1;
    }else{
        printf("-Cantidad de entregas por tipo: %d (GOLD) - %d  (REGULAR) - %d (PLUS)\n", conteoGold, conteoRegular, conteoPlus);
    }

    bultosTotales = ll_sumInt(pArrayListEntity, entityBultosTotales);
    if(bultosTotales == -1){
        printf("No se ha podido hacer total de bultos.");
        retorno = -1;
    }else{
        printf("-Cantidad total de bultos entregados: %d\n", bultosTotales);
    }

    promedioBultoEntrega = bultosTotales / ventasTotales;
    if(bultosTotales == -1 || ventasTotales == -1){
        printf("No se ha podido promedio bultos.");
        retorno = -1;
    }else{
        printf("-Promedio de bultos por entrega: %d\n", promedioBultoEntrega);
    }

    promedioImporte = ll_sumFloat(pArrayListEntity, entityImportesTotales);
    promedioImporte = promedioImporte / ventasTotales;
    if(promedioImporte == -1 || ventasTotales == -1){
        printf("No se ha podido hacer el promedio.");
        retorno = -1;
    }else{
        printf("-Importe promedio por entrega: %.2f\n", promedioImporte);
    }


    printf("*************************\n");

    if(retorno != -1){
        FILE* lista = fopen("informes.txt", "w");

        if(lista==NULL){        //error del fopen
            printf("Error para guardar\n");
            return retorno;
        }

        fprintf(lista,"*************************\n  Informe de ventas\n*************************\n-Cantidad total de entregas: %d\n--Cantidad de entregas por tipo: %d (GOLD) - %d  (REGULAR) - %d (PLUS)\n-Cantidad total de bultos entregados: %d\n-Promedio de bultos por entrega: %d\n-Importe promedio por entrega: %.2f\n*************************\n", ventasTotales,  conteoGold, conteoRegular, conteoPlus, bultosTotales, promedioBultoEntrega, promedioImporte);   //y lo guarda
        printf("Archivo guardado en 'informes.txt' con el informe de ventas.\n\n");

        fclose(lista);
    }else{
        printf("Debido a errores no se ha guardado el informe.\n");
    }
    return retorno;
}

///** \brief Guarda los datos en el archivo data.csv (modo texto).
// *
// * \param path char*
// * \param pArrayListEntity LinkedList*
// * \return int
// *
// */
//int controller_saveAsText(char* path , LinkedList* pArrayListEntity)
//{
//    int retorno = -1;
//    eEntity* this;
//    FILE* lista = fopen(path, "w");
//
//    if(lista==NULL){        //error del fopen
//        printf("Error para guardar\n");
//        return retorno;
//    }
//    fprintf(lista, "id,nombre,horasTrabajadas,sueldo\n");       //primera linea
//    if(pArrayListEntity!=NULL){
//        for(int i=0; i<ll_len(pArrayListEntity); i++){
//            this = (eEntity*)ll_get(pArrayListEntity, i);    //consigue entidad
//            fprintf(lista, "%d,%s,%d,%f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);   //y lo guarda
//        }
//        printf("Archivo Guardado.\n");
//        retorno = 1;
//    }
//    fclose(lista);      //cierro lista
//    return retorno;
//}
