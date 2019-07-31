#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entity.h"
#include "parser.h"
#include "utn.h"

int controller_menu(){    //menu inicial
    int option = -1;
        system("cls");
        printf("1. Alta ingrediente \n");
        printf("2. Modificar ingredientes\n");
        printf("3. Baja ingrediente\n");
        printf("4. Listar ingredientes \n");
        printf("5. Alta receta \n");
        printf("6. Listar recetas \n");
        printf("7. Informar valor de receta por Id \n");
        printf("8. Guardar 'ingredientes.csv' y 'recetas.csv' \n");
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
int controller_loadFromTextIngredientes(char* path , LinkedList* pArrayListEntity)
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
        parser_EntityFromTextIngredientes(listaFT, pArrayListEntity);
    }
    return 1;                                                       //1 si se encontro y cargo
}

int controller_loadFromTextReceta(char* path , LinkedList* pArrayListEntity)
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
        parser_EntityFromTextRecetas(listaFT, pArrayListEntity);
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
int controller_ListEntitysIngredientes(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    eIngredientes* this;
    if((ll_len(pArrayListEntity))>0){
        printf("\n**Id\t    Nombre\t  Calorias\t     Grasas\t     Sodio\t     Carbohidratos\t  Proteinas**\n\n");
        for(int i=0; i<ll_len(pArrayListEntity); i++){
            this = ll_get(pArrayListEntity, i);

            if(this != NULL){
                printf("%-12d %-16s %-16d %-16.1f %-16d %-16d %-16d \n", this->id,this->nombre,this->calorias,this->grasas,this->sodio,this->carbohidratos,this->proteinas);
            }
        }
    }else{
        printf("Archivo cargado con 0 elementos, cargar nuevo archivo. ");
    }
    printf("\n");
    return retorno;
}



int controller_ListEntitysRecetas(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    eRecetas* this;
    if((ll_len(pArrayListEntity))>0){
        printf("\n**Id\t    Nombre\t\t  id de Ingrediente\tCantidad\t **\n\n");
        for(int i=0; i<ll_len(pArrayListEntity); i++){
            this = ll_get(pArrayListEntity, i);

            if(this != NULL){
                printf("%-12d %-26s %-16d %-16d \n", this->id,this->nombre,this->idIngredientes,this->cantidad);
            }
        }
    }else{
        printf("Archivo cargado con 0 elementos, cargar nuevo archivo. ");
    }
    printf("\n");
    return retorno;
}

int controller_ListReceta(LinkedList* pArrayListEntityReceta, LinkedList* pArrayListEntityIngredientes)
{
    int retorno = -1;
    eRecetas* receta;
    eIngredientes* ingrediente;
    int idAux;
    char nombreAux[128];
    int caloriasAux = 0, sodioAux = 0, carbohidratosAux = 0, proteinasAux = 0;
    float grasasAux;

    if((ll_len(pArrayListEntityIngredientes))>0 && (ll_len(pArrayListEntityReceta))>0){
        printf("Ingrese ID de receta: ");
        scanf("%d", &idAux);
        for(int i=0; i<ll_len(pArrayListEntityReceta); i++)
        {
            receta = (eRecetas*) ll_get(pArrayListEntityReceta, i);
            strcpy(nombreAux, receta->nombre);
            if(idAux == receta->id)
            {
                for(int j=0; j<ll_len(pArrayListEntityIngredientes); j++)
                {
                    ingrediente = (eIngredientes*) ll_get(pArrayListEntityIngredientes, j);
                    if(receta->idIngredientes == ingrediente->id){
                        caloriasAux = caloriasAux + ingrediente->calorias;
                        grasasAux = grasasAux +ingrediente->grasas;
                        sodioAux = sodioAux + ingrediente->sodio;
                        carbohidratosAux = carbohidratosAux + ingrediente->carbohidratos;
                        proteinasAux = proteinasAux + ingrediente->proteinas;
                    }
                }
            }
        }
        printf("*%s:\nCalorias totales: %d, Grasas totales: %.2f, Sodio total: %d, Carbohidratos totales: %d, Proteinas totales: %d.", nombreAux, caloriasAux, grasasAux, sodioAux, carbohidratosAux, proteinasAux);
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


///** \brief Realiza un informe con lo pedido
// *
// * \param pArrayListEntity LinkedList*
// * \return int 0 si esta todo ok
// *
// */
//int controller_makeInfo(LinkedList* pArrayListEntity)
//{
//    int retorno = 0;
//    int ventasTotales, mayoresA100000, mayoresA300000, ventasFord;
//
//    printf("\n*************************\n  Informe de ventas\n*************************\n");
//    ventasTotales = ll_count(pArrayListEntity, entityVentasTotales);
//    if(ventasTotales == -1){
//        printf("No se ha podido hacer el conteo Total.");
//        retorno = -1;
//    }else{
//        printf("-Cantidad de unidades vendidas totales: %d\n", ventasTotales);
//    }
//
//    mayoresA100000 = ll_count(pArrayListEntity, entityMayores100000);
//    if(mayoresA100000 == -1){el
//        printf("No se ha podido hacer el conteo mayor a 100000.");
//        retorno = -1;
//    }else{
//        printf("-Cantidad de unidades con precio mayor a 100000: %d\n", mayoresA100000);
//    }
//
//    mayoresA300000 = ll_count(pArrayListEntity, entityMayores300000);
//    if(mayoresA300000 == -1){
//        printf("No se ha podido hacer el conteo mayoor a 300000.");
//        retorno = -1;
//    }else{
//        printf("-Cantidad de unidades con precio mayor a 300000: %d\n", mayoresA300000);
//    }
//
//    ventasFord = ll_count(pArrayListEntity, entityVentasFord);
//    if(ventasFord == -1){
//        printf("No se ha podido hacer el conteo de venta de Fords.");
//        retorno = -1;
//    }else{
//        printf("-Cantidad de Fords vendidos: %d\n", ventasFord);
//    }
//    printf("*************************\n");
//
//    if(retorno != -1){
//        FILE* lista = fopen("informes.txt", "w");
//
//        if(lista==NULL){        //error del fopen
//            printf("Error para guardar\n");
//            return retorno;
//        }
//
//        fprintf(lista,"*************************\n  Informe de ventas\n*************************\n-Cantidad de unidades vendidas totales: %d\n-Cantidad de unidades con precio mayor a 100000: %d\n-Cantidad de unidades con precio mayor a 300000: %d\n-Cantidad de Fords vendidos: %d\n*************************\n", ventasTotales, mayoresA100000, mayoresA300000, ventasFord);   //y lo guarda
//        printf("Archivo guardado en 'informes.txt' con el informe de ventas.\n\n");
//
//        fclose(lista);
//    }else{
//        printf("Debido a errores no se ha guardado el informe.\n");
//    }
//    return retorno;
//}

/** \brief Guarda los datos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */
int controller_saveAsTextIngredientes(char* path , LinkedList* pArrayListEntity)
{
    int retorno = -1;
    eIngredientes* this;
    FILE* lista = fopen(path, "w");

    if(lista==NULL){        //error del fopen
        printf("Error para guardar\n");
        return retorno;
    }
    fprintf(lista, "id,nombre,calorias,grasas,sodio,carbohidratos,proteinas\n");       //primera linea
    if(pArrayListEntity!=NULL){
        for(int i=0; i<ll_len(pArrayListEntity); i++){
            this = (eIngredientes*)ll_get(pArrayListEntity, i);    //consigue entidad
            fprintf(lista, "%d,%s,%d,%f,%d,%d,%d\n", this->id, this->nombre, this->calorias, this->grasas, this->sodio, this->carbohidratos, this->proteinas);   //y lo guarda
        }
        printf("Archivo Guardado.\n");
        retorno = 1;
    }
    fclose(lista);      //cierro lista
    return retorno;
}

int controller_saveAsTextRecetas(char* path , LinkedList* pArrayListEntity)
{
    int retorno = -1;
    eRecetas* this;
    FILE* lista = fopen(path, "w");

    if(lista==NULL){        //error del fopen
        printf("Error para guardar\n");
        return retorno;
    }
    fprintf(lista, "id,nombre,idIngredientes,cantidad\n");       //primera linea
    if(pArrayListEntity!=NULL){
        for(int i=0; i<ll_len(pArrayListEntity); i++){
            this = (eRecetas*)ll_get(pArrayListEntity, i);    //consigue entidad
            fprintf(lista, "%d,%s,%d,%d\n", this->id, this->nombre, this->idIngredientes, this->cantidad);   //y lo guarda
        }
        printf("Archivo Guardado.\n");
        retorno = 1;
    }
    fclose(lista);      //cierro lista
    return retorno;
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
    eIngredientes* this;     //nueva entidad this
    eIngredientes* aux;
    char idStr[5], nombreStr[128], caloriasStr[7], grasasStr[7] = "0", sodioStr[7], carbohidratosStr[7], proteinasStr[7];
    int idAux, caloriasAux, sodioAux, carbohidratosAux, proteinasAux;
    float grasasAux;
    int flagId = 0;

    if(pArrayListEntity != NULL){
        this = entity_new();
        if((ll_len(pArrayListEntity))>0){
            for(int j=0; j<ll_len(pArrayListEntity); j++){
                aux = (eIngredientes*) ll_get(pArrayListEntity, j);
            }
        }else{
            flagId = 1;
        }
        idAux = aux->id;
        idAux++;
        itoa(idAux, idStr, 10);
        getValidStringLen("Ingrese nombre: ", "Dato invalido. ", "El dato debe tener menos de 128 caracteres. ",nombreStr, 128);
        caloriasAux = getValidInt("Ingrese calorias: ", "Dato invalido. ", 0, 1000);
        itoa(caloriasAux, caloriasStr, 10);
        grasasAux = getValidFloat("Ingrese grasas: ", "Dato invalido. ", 0, 1000);
        //ftoa(grasasAux, grasasStr, 10);
        sodioAux = getValidInt("Ingrese sodio: ", "Dato invalido. ", 0, 1000);
        itoa(sodioAux, sodioStr, 10);
        carbohidratosAux = getValidInt("Ingrese carbohidratos: ", "Dato invalido. ", 0, 1000);
        itoa(carbohidratosAux, carbohidratosStr, 10);
        proteinasAux = getValidInt("Ingrese proteinas: ", "Dato invalido. ", 0, 1000);
        itoa(proteinasAux, proteinasStr, 10);

        this = entity_newParametros(idStr, nombreStr, caloriasStr, grasasStr, sodioStr, carbohidratosStr, proteinasStr);
        entity_setGrasas(this, grasasAux);
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
    eIngredientes* this;
    eIngredientes* aux;
    int idAux, caloriasAux, sodioAux, carbohidratosAux, proteinasAux;
    char nombreAux[128];
    float grasasAux;

    printf("Ingrese ID de ingrediente a modificar: ");
    scanf("%d", &idM);
    for(int i=0; i<ll_len(pArrayListEntity); i++){
        this = (eIngredientes*) ll_get(pArrayListEntity, i);
        if(idM == this->id){
            printf("\n**Id\t    Nombre\t  Calorias\t     Grasas\t     Sodio\t     Carbohidratos\t  Proteinas**\n\n");
            printf("%-12d %-16s %-16d %-16.1f %-16d %-16d %-16d \n", this->id,this->nombre,this->calorias,this->grasas,this->sodio,this->carbohidratos,this->proteinas);
        do{
            printf("\nIngrese dato a modificar: \n");
            printf("\t1- Id\n");
            printf("\t2- Nombre\n");
            printf("\t3- Calorias\n");
            printf("\t4- Grasas\n");
            printf("\t5- Sodio\n");
            printf("\t6- Carbohidratos\n");
            printf("\t7- Proteinas\n");
            printf("\t8- Cancelar\n");
            scanf("%d", &option);
            switch(option){
            case 1:
                idAux = getValidInt("Ingrese nueva ID: ", "Dato invalido. ", 0, 10000);
                for(int j=0; j<ll_len(pArrayListEntity); j++){
                    aux = (eIngredientes*) ll_get(pArrayListEntity, j);
                    if(idAux == aux->id){
                        printf("La ID ingresada ya pertenece a un ingrediente. Modifique el dato de otro ingrediente o revise ID a ingresar. \n");
                    }
                }
                entity_setId(this, idAux);
                printf("Desea continuar modificando mismo ingrediente? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 2:
                getValidStringLen("Ingrese nuevo nombre: ", "Dato invalido. ", "El dato debe tener menos de 128 caracteres. ", nombreAux, 128);
                entity_setNombre(this, nombreAux);
                printf("Desea continuar modificando mismo ingrediente? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 3:
                caloriasAux = getValidInt("Ingrese nuevas calorias: ", "Dato invalido. ", 0, 1000);
                entity_setCalorias(this, caloriasAux);
                printf("Desea continuar modificando mismo ingrediente? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 4:
                grasasAux = getValidFloat("Ingrese nueva grasa: ", "Dato invalido. ", 0, 1000000000);
                entity_setGrasas(this, grasasAux);
                printf("Desea continuar modificando mismo ingrediente? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 5:
                sodioAux = getValidInt("Ingrese nuevas calorias: ", "Dato invalido. ", 0, 1000);
                entity_setSodio(this, sodioAux);
                printf("Desea continuar modificando mismo ingrediente? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 6:
                carbohidratosAux = getValidInt("Ingrese nuevos carbohidratos: ", "Dato invalido. ", 0, 1000);
                entity_setCarbohidratos(this, carbohidratosAux);
                printf("Desea continuar modificando mismo ingrediente? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 7:
                proteinasAux = getValidInt("Ingrese nuevas proteinas: ", "Dato invalido. ", 0, 1000);
                entity_setProteinas(this, proteinasAux);
                printf("Desea continuar modificando mismo ingrediente? ");
                conM = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
                if(conM == 'n'){
                    return 0;
                }
                break;
            case 8:
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
    eIngredientes* this;

    printf("Ingrese ID de ingrediente a eliminar: ");
    scanf("%d", &idE);
    for(int i=0; i<ll_len(pArrayListEntity); i++){
        this = (eIngredientes*) ll_get(pArrayListEntity, i);
        if(idE == this->id){
            printf("\n**Id\t    Nombre\t  Calorias\t     Grasas\t     Sodio\t     Carbohidratos\t  Proteinas**\n\n");
            printf("%-12d %-16s %-16d %-16.1f %-16d %-16d %-16d \n", this->id,this->nombre,this->calorias,this->grasas,this->sodio,this->carbohidratos,this->proteinas);
            printf("\nDesea eliminar ingrediente? ");
            conE = getValidYesNoChar("Ingrese y/n: ", "Dato invalido. ");
            if(conE != 'y'){
                printf("Eliminacion cancelada, volviendo al menu...\n");
                return 1;                                                   //1 se ecnuentra, no se realiza
            }else{
                ll_remove(pArrayListEntity, i);
                printf("Ingrediente %d eliminada. \n", idE);
                free(this);                     //sasumo que aqui es en donde se podria usar el entity detele, pero de vuelta, si no le paso el puintero como lo borra? lo dejo con un free
                return 0;                                               //o, se enceutnra, se realiza
            }
        }
    }
    printf("No se ha encontrado empleadx con ID %d. \n", idE);
    return retorno;                                                         //-1, no se encuentra
}








int controller_addReceta(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    eRecetas* this;     //nueva entidad this
    eRecetas* aux;
    char idStr[5], nombreStr[128], idIngredientesStr[7], cantidadStr[7];
    char nombreIngredienteStr[128];
    int idAux, idIngredientesAux, cantidadAux;
    char continuar = 'n';

    if(pArrayListEntity != NULL){
        this = entity_new();
        if((ll_len(pArrayListEntity))>0){
            for(int j=0; j<ll_len(pArrayListEntity); j++){
                aux = (eRecetas*) ll_get(pArrayListEntity, j);
            }
        }
        idAux = aux->id;
        idAux++;
        itoa(idAux, idStr, 10);
        getValidStringLen("Ingrese nombre de receta: ", "Dato invalido. ", "El dato debe tener menos de 128 caracteres. ",nombreStr, 128);
        do{
            idIngredientesAux = getValidInt("Ingrese id del ingrediente: ", "Dato invalido. ", 0, 1000);
            itoa(idIngredientesAux, idIngredientesStr, 10);
            cantidadAux = getValidInt("Ingrese cantidad del ingrediente: ", "Dato invalido. ", 0, 1000);
            itoa(cantidadAux, cantidadStr, 10);

            this = receta_newParametros(idStr, nombreStr, idIngredientesStr, cantidadStr);
            ll_add(pArrayListEntity, this);
            retorno = 0;

            printf("Desea agregar otro ingrediente a %s?", nombreStr);
            continuar = getValidYesNoChar("Ingrese y/n: ", "Opcion no valida");
        }while(continuar == 'y');
    }
    return retorno;
}
