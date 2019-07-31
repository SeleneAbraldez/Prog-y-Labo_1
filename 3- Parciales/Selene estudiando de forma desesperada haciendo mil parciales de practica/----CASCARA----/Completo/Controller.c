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
        printf("2. Cargar los datos desde el archivo data.bin (modo binario). \n");
        printf("3. Alta \n");
        printf("4. Modificar datos\n");
        printf("5. Baja \n");
        printf("6. Listar \n");
        printf("7. Ordenar \n");
        printf("8. Guardar los datos en el archivo data.csv (modo texto). \n");
        printf("9. Guardar los datos en el archivo data.bin (modo binario). \n");
        printf("10. Filtrar y guardar lista filtrada (modo texto) \n");
        printf("11. Mapear y guardar sueldo \n");
        printf("12. Salir \n");
        option = getValidInt("\n\t*Seleccione  una opcion: ", "Opcion no valida, reintente", 0, 12);
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

/** \brief Carga los datos de las entidades desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntity)
{
    int retorno = -1;
    char crear = 'n';
    FILE* listaFB;
    if((listaFB=fopen(path, "rb+")) == NULL){      //lectura binaria si no se encuentra se crea
        printf("No se ha encontrado el archivo. ");
        crear = getValidYesNoChar("Desea crealo? y/n: ", "Opcion no valida. ");
        if(crear == 'y'){                                  //respuesta si
            if ((listaFB=fopen(path,"wb+"))==NULL){
                printf("!! - Error, no se ha podido abrir el archivo.\n");           //-1 si hay un error
                return retorno;
                exit(-1);
            }else{
                printf("Archivo creado. ");        //1 si no se encontro y se creo
            }
        }else{
            printf("Saliendo...\n");
            return 0;                        //0 si no se encontro y no se creo
        }
    }else{
        printf("Archivo encontrado. ");
        parser_EntityFromBinary(listaFB, pArrayListEntity);
    }
    return 1;                                                                                   //1 si se encontro y cargo
}

/** \brief Alta de entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_addEntity(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    eEntity* this;     //nueva entidad this
    eEntity* aux;
    char idStr[5], nombreStr[128], horasStr[7], sueldoStr[15];
    int idAux, horasAux;
    int flagId = 0;

    if(pArrayListEntity != NULL){
        this = entity_new();
        do{
            idAux = getValidInt("Ingrese nueva ID: ", "Dato invalido. ", 0, 10000);
            if((ll_len(pArrayListEntity))>0){
                for(int j=0; j<ll_len(pArrayListEntity); j++){
                    aux = (eEntity*) ll_get(pArrayListEntity, j);
                    if(idAux == aux->id){
                        printf("La ID ingresada ya pertenece a una entidad. \n");
                        flagId = 0;
                        break;
                    }else{
                        flagId = 1;
                    }
                }
            }else{
                flagId = 1;
            }
        }while(flagId == 0);
        itoa(idAux, idStr, 10);
        getValidStringLen("Ingrese nombre: ", "Dato invalido. ", "El dato debe tener menos de 128 caracteres. ",nombreStr, 128);
        horasAux = getValidInt("Ingrese nuevas horas: ", "Dato invalido. ", 30, 350);
        itoa(horasAux, horasStr, 10);
        getStringNumerosFlotantes("Ingrese sueldo: ", sueldoStr);

        this = entity_newParametros(idStr, nombreStr, horasStr, sueldoStr);
        ll_add(pArrayListEntity, this);
        retorno = 0;
    }
    return retorno;
}

/** \brief Modificar datos de entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_editEntity(LinkedList* pArrayListEntity)
{
    int idM;        //id ingresado a modificar
    int option;
    char conM = 'n';
    eEntity* this;
    eEntity* aux;
    int idAux;
    char nombreAux[128];
    int horasAux;
    float sueldoAux;

    printf("Ingrese ID de empleadx a modificar: ");
    scanf("%d", &idM);
    for(int i=0; i<ll_len(pArrayListEntity); i++){
        this = (eEntity*) ll_get(pArrayListEntity, i);
        if(idM == this->id){
            printf("\n  Id\t    Nombre\t  Horas trabajadas\tSueldo\n");
            printf("%4d%14s\t\t%d\t\t%6.2f\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        do{
            printf("\nIngrese dato a modificar: \n");
            printf("\t1- Id\n");
            printf("\t2- Nombre\n");
            printf("\t3- Horas trabajadas\n");
            printf("\t4- Sueldo\n");
            printf("\t5- Cancelar\n");
            scanf("%d", &option);
            switch(option){
            case 1:
                idAux = getValidInt("Ingrese nueva ID: ", "Dato invalido. ", 0, 10000);
                for(int j=0; j<ll_len(pArrayListEntity); j++){
                    aux = (eEntity*) ll_get(pArrayListEntity, j);
                    if(idAux == aux->id){
                        printf("La ID ingresada ya pertenece a unx empleadx. Modifique el dato de otrx empleado o revise ID a ingresar. \n");
                    }
                }
                entity_setId(this, idAux);
                printf("Desea continuar modificando mismx empleadx? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 2:
                getValidStringLen("Ingrese nuevo nombre: ", "Dato invalido. ", "El dato debe tener menos de 128 caracteres. ", nombreAux, 128);
                entity_setNombre(this, nombreAux);
                printf("Desea continuar modificando mismx empleadx? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 3:
                horasAux = getValidInt("Ingrese nuevas horas: ", "Dato invalido. ", 30, 350);
                entity_setHorasTrabajadas(this, horasAux);
                printf("Desea continuar modificando mismx empleadx? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 4:
                sueldoAux = getValidFloat("Ingrese nuevo sueldo: ", "Dato invalido. ", 9000, 9999999);
                entity_setSueldo(this, sueldoAux);
                printf("Desea continuar modificando mismx empleadx? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 5:
                printf("Modificacion cancelada, volviendo al menu...\n");
                return 1;
                break;
            default:
                printf("Opcion no valida\n");
                break;
            }
        }while(conM == 'y');
        }
    }
    printf("No se ha encontrado empleadx %s. \n", idM);
    return -1;
}

/** \brief Baja de entidad
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_removeEntity(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    int idE;
    char conE = 'n';
    eEntity* this;

    printf("Ingrese ID de empeladx a eliminar: ");
    scanf("%d", &idE);
    for(int i=0; i<ll_len(pArrayListEntity); i++){
        this = (eEntity*) ll_get(pArrayListEntity, i);
        if(idE == this->id){
            printf("\n  Id\t    Nombre\t  Horas trabajadas\tSueldo\n");
            printf("%4d%14s\t\t%d\t\t%6.2f\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
            printf("\nDesea eliminar empleadx? ");
            conE = getValidYesNoChar("Ingrese y/n: ", "Dato invalido. ");
            if(conE != 'y'){
                printf("Eliminacion cancelada, volviendo al menu...\n");
                return 1;                                                   //1 se ecnuentra, no se realiza
            }else{
                ll_remove(pArrayListEntity, i);
                printf("Empleadx %d eliminadx. \n", idE);
                free(this);                     //sasumo que aqui es en donde se podria usar el entity detele, pero de vuelta, si no le paso el puintero como lo borra? lo dejo con un free
                return 0;                                               //o, se enceutnra, se realiza
            }
        }
    }
    printf("No se ha encontrado empleadx con ID %d. \n", idE);
    return retorno;                                                         //-1, no se encuentra
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
        printf("\n**Id\t    Nombre\t  Horas trabajadas\tSueldo**\n\n");
        for(int i=0; i<ll_len(pArrayListEntity); i++){
            this = ll_get(pArrayListEntity, i);

            if(this != NULL){
                printf("%4d%14s\t\t%d\t\t%6.2f\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
            }
        }
    }else{
        printf("Archivo cargado con 0 elementos, cargar nuevo archivo. ");
    }
    printf("\n");
    return retorno;
}

/** \brief Ordenar entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_sortEntity(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    int option;

    printf("Seleeccionar ordenamiento por: \n");
    printf("\t1- Id forma ascendente\n");
    printf("\t2- Nombre forma ascendente\n");
    printf("\t3- Horas trabajadas forma ascendente\n");
    printf("\t4- Salario forma ascendente\n\n");
    printf("\t5- Id forma descendente\n");
    printf("\t6- Nombre forma descendente\n");
    printf("\t7- Horas trabajadas forma descendente\n");
    printf("\t8- Salario forma descendente\n");
    scanf("%d", &option);

    switch(option){         //sependiendo de la opcion ordena
    case 1:
        ll_sort(pArrayListEntity, entitySortById, 0);
        printf("Ordenamiento ascendente por id realizado!\n");
        break;
    case 2:
        ll_sort(pArrayListEntity, entitySortByName, 0);
        printf("Ordenamiento ascendente por nombre realizado!\n");
        break;
    case 3:
        ll_sort(pArrayListEntity, entitySortByHours, 0);
        printf("Ordenamiento ascendente por horas trabajadas realizado!\n");
        break;
    case 4:
        ll_sort(pArrayListEntity, entitySortBySalary, 0);
        printf("Ordenamiento ascendente por salario realizado!\n");
        break;
    case 5:
        ll_sort(pArrayListEntity, entitySortById, 1);
        printf("Ordenamiento descendente por id realizado!\n");
        break;
    case 6:
        ll_sort(pArrayListEntity, entitySortByName, 1);
        printf("Ordenamiento descendente por nombre realizado!\n");
        break;
    case 7:
        ll_sort(pArrayListEntity, entitySortByHours, 1);
        printf("Ordenamiento descendente por horas trabajadas realizado!\n");
        break;
    case 8:
        ll_sort(pArrayListEntity, entitySortBySalary, 1);
        printf("Ordenamiento descendente por salario realizado!\n");
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
    return retorno;
}


/** \brief Filtra empleados
 *
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_filterEntity(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    int option;
    LinkedList* filterList;
    int optionYN;


    printf("Seleeccionar filtro por: \n");
    printf("\t1- Horas trabajadas mayores a 150\n");
    printf("\t2- Id mayor a 10\n");
    printf("\t3- Nombre por debajo de H\n");
    scanf("%d", &option);

    switch(option){
    case 1:
        filterList = ll_filter(pArrayListEntity, entityFilterHours);
        printf("Filtro: Horas trabajadas mayores a 150 ");
        break;
    case 2:
        filterList = ll_filter(pArrayListEntity, entityFilterId);
        printf("Filtro: Id mayor a 10 ");
        break;
    case 3:
        filterList = ll_filter(pArrayListEntity, entityFilterName);
        printf("Filtro: Nombre por debajo de H ");
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
    if(filterList != NULL){
        retorno = 0;
        if(ll_len(filterList)>0){
            controller_ListEntitys(filterList);
            optionYN = getValidYesNoChar("Desea guardar la lista filtrada en 'filteredData.csv?' y/n: ", "Caracter no valido. ");
            if(optionYN == 'y'){
                controller_saveAsText("filteredData.csv", filterList);
            }else{
                printf("Saliendo sin guardar. \n");
            }
        }else{
            printf("ha resultado con 0 empleadxs. \n");
        }
    }else{
        printf("no se ha podido realizar.\n");
    }

    return retorno;
}

/** \brief Realiza un mapeo de entidades
 *
 * \param pArrayListEntity LinkedList*
 * \return int 0 si esta todo ok
 *
 */
int controller_mapEntity(LinkedList* pArrayListEntity)
{
    int retorno = -1;

   if(ll_map(pArrayListEntity, entityMapSalary) != 0){
        printf("No se ha podido hacer el mapeo.");
    }else{
        printf("Sueldos actualizados con exito.\n");
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEntity)
{
    int retorno = -1;
    eEntity* this;
    FILE* lista = fopen(path, "w");

    if(lista==NULL){        //error del fopen
        printf("Error para guardar\n");
        return retorno;
    }
    fprintf(lista, "id,nombre,horasTrabajadas,sueldo\n");       //primera linea
    if(pArrayListEntity!=NULL){
        for(int i=0; i<ll_len(pArrayListEntity); i++){
            this = (eEntity*)ll_get(pArrayListEntity, i);    //consigue entidad
            fprintf(lista, "%d,%s,%d,%f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);   //y lo guarda
        }
        printf("Archivo Guardado.\n");
        retorno = 1;
    }
    fclose(lista);      //cierro lista
    return retorno;
}

/** \brief Guarda los datos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntity)
{
    int retorno = -1;
    int len = ll_len(pArrayListEntity);
    eEntity* this;
    FILE* lista = fopen(path, "wb");

    if(lista==NULL){        //si hay error en el fopen
        printf("Error para guardar\n");
        return retorno;     //cxorto
    }
    if(pArrayListEntity!=NULL){
        for(int i=0; i<len; i++){
            this = (eEntity*)ll_get(pArrayListEntity, i);
            fwrite(this,sizeof(eEntity),1,lista);      //si no hay errorres guardo entidades del array rn rl archivo
        }
        printf("Archivo Guardado.\n");
        retorno = 1;
    }
    fclose(lista);          //cierro lista
    return retorno;
}
