#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Abono.h"
#include "Employee.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL){
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
            returnAux=this->size;       //retorna el tamaño de la ll pasada
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this != NULL && nodeIndex>=0 && nodeIndex<ll_len(this)){
        LinkedList listAux = *this;
        pNode = listAux.pFirstNode;
        for(int i = 0; i<nodeIndex; i++){
           pNode = pNode->pNextNode;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    if((this !=NULL) /*&& (pElement!=NULL)*/ && (nodeIndex>=0) && (nodeIndex<=ll_len(this))){
        Node* aNodo= malloc(sizeof(Node));
        LinkedList listAux = *this;
        if(aNodo != NULL){ //se fija si hay memoria del malloc
            aNodo->pElement = pElement;
            if(ll_len(this)==0){    //locom
                aNodo->pNextNode = NULL;
                this->pFirstNode = aNodo;
            }else{                  //ll_len(this)!=0
                if(nodeIndex == 0){ //prim
                    aNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = aNodo;
                }else{              //inter
                    for(int i=0;i+1<nodeIndex;i++){
                        listAux.pFirstNode = listAux.pFirstNode->pNextNode;
                    }
                    aNodo->pNextNode = listAux.pFirstNode->pNextNode;
                    listAux.pFirstNode->pNextNode = aNodo;
                }
            }
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;

}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) //necesita addnode
{
    int returnAux = -1;

    if(this !=NULL /*&& pElement!=NULL*/){
        if(addNode(this, ll_len(this), pElement) != -1){
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* gNode;
    if(this!=NULL && index>= 0 && index<=ll_len(this)){
        gNode = getNode(this, index);
        if(gNode!=NULL){
            returnAux = gNode->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* gNode;

    if((this !=NULL) /*&& (pElement!=NULL)*/ && (index>=0) && (index<=(this->size)) ){
        gNode = getNode(this, index);
        if(gNode!=NULL){
             gNode->pElement = pElement;
             returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* rNode=NULL;
    Node* rNodeAux=NULL;

    if(this!=NULL && index>=0 && index<(this->size)){
        if(index == 0){                             //si esta en locomoto
            rNode = getNode(this, index);
            this->pFirstNode = rNode->pNextNode;
            free(rNode);
        }else if(index == (ll_len(this))){          //si esta en la ultima
            free(rNode);
        }else{                                      //si esta entremedio
            rNodeAux = getNode(this,(index-1));
            rNode = getNode(this,index);
            rNodeAux->pNextNode = rNode->pNextNode;
            free(rNode);
        }
        this->size--;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        for(int i= ll_len(this); i>=0; i--){        //TIENE QUE IR DE aTrAS PARA ADELANTE 40 minutos apra darme cuenta d esto una funcion de 6 lineas dios
            ll_remove(this, i);         //va removiendo de atras para adelante para no perder el registro uno a uno
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        ll_clear(this); //aun si es funcional, de forma logica hacer la baja en sentido de this->size 0, no estaria liberando espacio, por eso es necesario el clear
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{

    int returnAux = -1;
    Node* iNode;

    if(this!=NULL /*&& pElement !=NULL*/){
        for(int i=0; i<ll_len(this); i++){                  //recorre this
            iNode = getNode(this, i);                   //consigue el nodo para comparar
            if(iNode->pElement == pElement){                //si encuentra el elemento
                returnAux = i;                          //devuelve el indice del elemento
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        if((this->size)>0){         //se fija si es  tamño es mayor a 0, deliitando si esta vacio o no
            returnAux=0;
        }else{
            returnAux=1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if((this!=NULL) /*&& (pElement!=NULL)*/ && (index>=0) && (index<=this->size) ){
        if(addNode(this, index, pElement)==0){
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if((this!=NULL) && (index>=0) && (index<=this->size) ){
        returnAux = ll_get(this, index);
        if(returnAux != NULL){
            ll_remove(this, index);
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* cNode;
    int flagC = 0;          //media innecesaria la bandera porque podria defnirlo antes del for como 0 y si no lo encuentra nunca se cambia, peor queria dejarlo ams explicito

    if(this!=NULL /*&& pElement!=NUL*/){
        for(int i=0; i<ll_len(this); i++){      //recorre this
            cNode = getNode(this, i);           //agarra nodo para comparar
            if(cNode->pElement == pElement){            //esta
                returnAux=1;
                flagC = 1;                      //bandera si el elemento se encuentra
                break;                      //sale porque ya lo encontr
            }
        }
        if(flagC == 0){
            returnAux = 0;          //si nunca se encentra la bandera nunca se cambia
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElemAux;
    int contCA = 0;     //soy conciente de que hacerlo con un contador es complicarme la vida cuando lo puedo definir antes como uno y si es cdero que haga break, pero lo entendia mas asi

    if((this!=NULL) && (this2!=NULL)){
        for(int i=0; i<ll_len(this2); i++){
            pElemAux = ll_get(this2, i);
            if((ll_contains(this, pElemAux)) == 1){
                contCA++;                               //agrego al contador si se encuentra y cumple el contains
            }
        }
        if(contCA == (ll_len(this2))){                  //si la cantidad de this2 es igual a la vantidad del contador, qiuere decir que todos estan incluidos
            returnAux = 1;
        }else{
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElemAux;

    if(this!=NULL){
        if((from>=0) && (from<ll_len(this)) && (to>from) && (to<=ll_len(this))){
            cloneArray = ll_newLinkedList();
            for(int i = from; i < to ; i++){
                pElemAux = ll_get(this, i);
                ll_add(cloneArray, pElemAux);
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL){
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElemAux;

    if(this!=NULL && pFunc!=NULL && (order == 0 || order == 1) ){
        for(int i=0;i<((ll_len(this))-1);i++){
            for(int j=i+1; j<(ll_len(this)); j++){
                if(order == 0 && pFunc(ll_get(this, i), ll_get(this, j))<0){
                    pElemAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this,j));
                    ll_set(this, j, pElemAux);
                }else if(order == 1 && pFunc(ll_get(this, i), ll_get(this, j))>0){
                    pElemAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this,j));
                    ll_set(this, j, pElemAux);
                }
            }
        }
        returnAux=0;
    }

    return returnAux;
}


/** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (filterList) la lista filtrada
 */

LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*)){
  LinkedList* filterList = ll_newLinkedList();
  if(this != NULL && pFunc != NULL){
    if(filterList != NULL){
      for(int i = 0; i<ll_len(this); i++){
        if(pFunc(ll_get(this, i))){
          ll_add(filterList, ll_get(this, i));
        }
      }
    }
  }
  return filterList;
}


/** \brief Mapea los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna

 */

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
  int retorno = -1;
  LinkedList* mapList;

  if(this != NULL && pFunc != NULL){
      for(int i = 0; i<ll_len(this); i++){
        mapList = ll_get(this, i);
        if(pFunc(mapList)!= -1){
          pFunc(mapList);
          retorno = 0;
        }
      }
  }
  return retorno;
}

int ll_count(LinkedList* this, int (*fn)(void* element))
{
  int retorno = -1;
  LinkedList* conteoLL;

  if(this != NULL && fn!= NULL){
      retorno = 0;
      for(int i = 0; i<ll_len(this); i++){
        conteoLL = ll_get(this, i);
        if(fn(conteoLL)!= -1){
            retorno++;
        }
      }
  }
  return retorno;
}




LinkedList* ll_makeCreate(LinkedList* this)
{
  LinkedList* abonoList = ll_newLinkedList();   //nueva linkedlist que sea la de abono
  eAbono* abono;    //puntero a estr abono
  Employee* empl;   //puntero a estr emplo
  Employee* conteoEmpl;

  int conteoId;     //conteo para sacar tipo de cuenta
  float conteoImporteFinal; //conteo para importe final
  int conteoIdAbono=0;

  LinkedList* empleado;
  LinkedList* conteo;

  int idAuxiolio=0;          //valores para agregar
  char idStr[20], tipoStr[20] = "0", idClienteStr[20], importeFinalStr[20];      //valores para agregar a la lista abono string, los inicilizo para hacer pruebas


  if(this != NULL){     //se fija que el valor pasano no sea NULL
    if(abonoList != NULL){
      for(int i = 0; i<ll_len(this); i++){
///conteo
        empleado = ll_get(this, i);
        empl = (Employee*) empleado;
        if((empl->id) > idAuxiolio){  //se fija si es mayor a la ultima leida para no leer dos veces la misma, funciona con un sort antes O si estan "mas o menos" ordenados,
                                        //o sea que nunca hay una id mas grande como 1321, pero funciona con 121313, no es necesario que esten en 111233, pero puedo hacer un sort antes para asegurarme
            conteoIdAbono++;
            abono = abono_new();
            idAuxiolio = empl->id;
            conteoId = 0;
            conteoImporteFinal = 0;
            for(int j=0; j<ll_len(this); j++){
                conteo = ll_get(this, j);
                conteoEmpl = (Employee*) conteo;
                if(empl->id == conteoEmpl->id){
                   conteoId++;
//suma importe final
                   conteoImporteFinal = conteoImporteFinal + conteoEmpl->importe;
                }
            }
//tipo de cuenta
            if(conteoId<2){     //asigna dependiendo
                strcpy(tipoStr, "PERSONAL");
            }else{
                if(conteoId<5){
                    strcpy(tipoStr, "FAMILIAR");
                    conteoImporteFinal = conteoImporteFinal * 1.1;
                }else{
                    if(conteoId>4)
                    strcpy(tipoStr, "CORPORATIVO");
                    conteoImporteFinal = conteoImporteFinal * 1.2;
                }
            }
            itoa(conteoIdAbono, idStr, 10);
            itoa(idAuxiolio, idClienteStr, 10);
            snprintf(importeFinalStr, sizeof(importeFinalStr), "%.3f", conteoImporteFinal);
            abono = abono_newParametros(idStr, tipoStr, idClienteStr, importeFinalStr);
            ll_add(abonoList, abono);
        }
      }
    }else{
        printf("No se ha podido reservar memoria.\n");  //aviso que no se puede reservar memoria para la nueva lista
    }
  }
  return abonoList;
}
