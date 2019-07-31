#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entity.h"

eCliente* entity_new(){
    eCliente* this = malloc(sizeof(eCliente));  //pedido de memoria dinamica por malloc
    if(this !=NULL){    //si hay memoria inciilizo los valores
        this->id = 0;
        strcpy(this->nombre, " ");
        strcpy(this->sexo, " ");
        strcpy(this->numeroTelefono, " - ");
        this->importe = 0;
    }
    return this;
}

static void initializeStr(eCliente* this, char *var1, char *var2, char *var3, char *var4, char *var5)   //inicializo todos los parametros de forma string
{
    int id, importe;

    id = atoi(var1);
    importe = atoi(var5);

    entity_setId(this, id);
    entity_setNombre(this, var2);
    entity_setSexo(this, var3);
    entity_setNumeroTelefono(this, var4);
    entity_setImporte(this, importe);
}

eCliente* entity_newParametros(char* idStr,char* nombreStr,char* sexoStr, char* numeroTelefonoStr, char* importeStr){
    eCliente* this;
    this = entity_new();
    if(this != NULL)
        initializeStr(this, idStr, nombreStr, sexoStr, numeroTelefonoStr, importeStr);
    return this;
}


int entity_setId(eCliente* this,int id){
    int retorno = -1;
    if(this != NULL && id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int entity_getId(eCliente* this,int* id){
    if(this != NULL){
        *id = this->id;
        return 0;
    }else
        return -1;
}

int entity_setNombre(eCliente* this,char* nombre){
    int retorno = -1;
    if(this != NULL && nombre[0] != '\0'){
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int entity_getNombre(eCliente* this,char* nombre){
    if(this != NULL){
        strcpy(this->nombre, nombre);
        return 0;
    }else{
        return -1;
    }
}

int entity_setSexo(eCliente* this,char* sexo){
    int retorno = -1;
    if(this != NULL && sexo[0] != '\0' && sexo[0] == 'F' || sexo[0] == 'M'){
        strncpy(this->sexo, sexo, sizeof(this->sexo));
        retorno = 0;
    }
    return retorno;
}
int entity_getSexo(eCliente* this,char* sexo){
    if(this != NULL){
        strcpy(this->sexo, sexo);
        return 0;
    }else{
        return -1;
    }
}

int entity_setNumeroTelefono(eCliente* this,char* numeroTelefono){
    int retorno = -1;
    if(this != NULL && numeroTelefono[0] != '\0'){
        strncpy(this->numeroTelefono, numeroTelefono, sizeof(this->numeroTelefono));
        retorno = 0;
    }
    return retorno;
}
int entity_getNumeroTelefono(eCliente* this,char* numeroTelefono){
    if(this != NULL){
        strcpy(this->numeroTelefono, numeroTelefono);
        return 0;
    }else{
        return -1;
    }
}

int entity_setImporte(eCliente* this,int importe){
    int retorno = -1;
    if(this != NULL && importe > 0){
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}
int entity_getImporte(eCliente* this,int* importe){
    if(this != NULL){
        *importe = this->importe;
        return 0;
    }else
        return -1;
}






eAbono* abono_new(){
    eAbono* this = malloc(sizeof(eAbono));  //pedido de memoria dinamica por malloc
    if(this !=NULL){    //si hay memoria inciilizo los valores
        this->id = 0;
        this->tipo = 0;
        this->idCliente = 0;
        this->importeFinal = 0;
    }
    return this;
}

static void initializeStrAbono(eAbono* this, char *var1, char *var2, char *var3, char *var4)   //inicializo todos los parametros de forma string
{
    int id, tipo, idCliente, importeFinal;

    id = atoi(var1);
    tipo = atoi(var2);
    idCliente = atoi(var3);
    importeFinal = atoi(var4);

    abono_setId(this, id);
    abono_setTipo(this, tipo);
    abono_setIdCliente(this, idCliente);
    abono_setImporteFinal(this, importeFinal);
}

eAbono* abono_newParametros(char* idStr, char* tipoStr, char* idClienteStr, char* importeStr){
    eAbono* this;
    this = abono_new();
    if(this != NULL)
        initializeStrAbono(this, idStr, tipoStr, idClienteStr, importeStr);
    return this;
}


int abono_setId(eAbono* this,int id){
    int retorno = -1;
    if(this != NULL && id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int abono_getId(eAbono* this,int* id){
    if(this != NULL){
        *id = this->id;
        return 0;
    }else
        return -1;
}

int abono_setTipo(eAbono* this,int tipo){
    int retorno = -1;
    if(this != NULL && tipo > 0){
        this->tipo = tipo;
        retorno = 0;
    }
    return retorno;
}
int abono_getTipo(eAbono* this,int* tipo){
    if(this != NULL){
        *tipo = this->tipo;
        return 0;
    }else
        return -1;
}

int abono_setIdCliente(eAbono* this,int idCliente){
    int retorno = -1;
    if(this != NULL && idCliente > 0){
        this->idCliente = idCliente;
        retorno = 0;
    }
    return retorno;
}
int abono_getIdCliente(eAbono* this,int* idCliente){
    if(this != NULL){
        *idCliente = this->idCliente;
        return 0;
    }else
        return -1;
}

int abono_setImporteFinal(eAbono* this,int importeFinal){
    int retorno = -1;
    if(this != NULL && importeFinal > 0){
        this->importeFinal = importeFinal;
        retorno = 0;
    }
    return retorno;
}
int abono_getImporteFinal(eAbono* this,int* importeFinal){
    if(this != NULL){
        *importeFinal = this->importeFinal;
        return 0;
    }else
        return -1;
}

int entitySortById(void* clienteA, void* clienteB){
    int retorno = -1;
    eCliente* clieA;
    eCliente* clieB;

    if(clienteA !=NULL && clienteB !=NULL){
        clieA = (eCliente*) clienteA;
        clieB = (eCliente*) clienteB;
        if((clieA->id)<(clieB->id)){
            retorno = 1 ;
        }else if((clieA->id)>(clieB->id)){
            retorno = -1 ;
        }else if((clieA->id)==(clieB->id)){
            retorno = 0;
        }
    }
    return retorno;
}
//
//int entitySortByName(void* empleadoA, void* empleadoB){
//    int retorno = -1;
//    eEntity* empA;
//    eEntity* empB;
//
//    if(empleadoA !=NULL && empleadoB !=NULL){
//        empA = (eEntity*) empleadoA;
//        empB = (eEntity*) empleadoB;
//        retorno = strcmp(empB->nombre, empA->nombre);
//    }
//
//    return retorno;
//}
//
//int entitySortByHours(void* empleadoA, void* empleadoB){
//    int retorno = -1;
//    eEntity* empA;
//    eEntity* empB;
//
//    if(empleadoA !=NULL && empleadoB !=NULL){
//        empA = (eEntity*) empleadoA;
//        empB = (eEntity*) empleadoB;
//                if((empA->horasTrabajadas)<(empB->horasTrabajadas)){
//            retorno = 1 ;
//        }else if((empA->horasTrabajadas)>(empB->horasTrabajadas)){
//            retorno = -1 ;
//        }else if((empA->horasTrabajadas)==(empB->horasTrabajadas)){
//            retorno = 0;
//        }
//    }
//    return retorno;
//}
//
//int entitySortBySalary(void* empleadoA, void* empleadoB){
//    int retorno = -1;
//    eEntity* empA;
//    eEntity* empB;
//
//    if(empleadoA !=NULL && empleadoB !=NULL){
//        empA = (eEntity*) empleadoA;
//        empB = (eEntity*) empleadoB;
//        if((empA->sueldo)<(empB->sueldo)){
//            retorno = 1 ;
//        }else if((empA->sueldo)>(empB->sueldo)){
//            retorno = -1 ;
//        }else if((empA->sueldo)==(empB->sueldo)){
//            retorno = 0;
//        }
//    }
//    return retorno;
//}
//
//
//
//int entityFilterHours(void* p){
//  int retorno = 0;
//  eEntity* empl;
//  if(p != NULL){
//    empl = (eEntity*) p;
//    if(empl->horasTrabajadas > 150){
//      retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityFilterId(void* p){
//  int retorno = 0;
//  eEntity* empl;
//  if(p != NULL){
//    empl = (eEntity*) p;
//    if(empl->id < 11){
//      retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityFilterName(void* p){
//  int retorno = 0;
//  eEntity* empl;
//  if(p != NULL){
//    empl = (eEntity*) p;
//    if(strcmp(empl->nombre,"H")>=0){
//      retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//

//int entityVentasTotales(void* p){
//  int retorno = -1;
//  eEntity* ent;
//  if(p != NULL){
//    ent = (eEntity*) p;
//    if(ll_isEmpty(ent)==0){
//        retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityMayores100000(void* p){
//  int retorno = -1;
//  eEntity* ent;
//  if(p != NULL){
//    ent = (eEntity*) p;
//    if((ent->precio) > 100000){
//        retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityMayores300000(void* p){
//  int retorno = -1;
//  eEntity* ent;
//  if(p != NULL){
//    ent = (eEntity*) p;
//    if((ent->precio) > 300000){
//        retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityVentasFord(void* p){
//  int retorno = -1;
//  eEntity* ent;
//
//  if(p != NULL){
//    ent = (eEntity*) p;
//    if(strcmp(ent->codigo, "Ford") == 0){
//        //printf("%s ", ent->codigo);
//        retorno = 1;
//    }
//  }
//  return retorno;
//}

//
//int entityVentasTotales(void* p){
//  int retorno = -1;
//  eEntity* ent;
//  if(p != NULL){
//    ent = (eEntity*) p;
//    if(ll_isEmpty(ent)==0){
//        retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityGold(void* p){
//  int retorno = -1;
//  eEntity* ent;
//
//  if(p != NULL){
//    ent = (eEntity*) p;
//    if(strcmp(ent->tipo, "GOLD") == 0){
//        //printf("%s ", ent->codigo);
//        retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityRegular(void* p){
//  int retorno = -1;
//  eEntity* ent;
//
//  if(p != NULL){
//    ent = (eEntity*) p;
//    if(strcmp(ent->tipo, "REGULAR") == 0){
//        //printf("%s ", ent->codigo);
//        retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityPlus(void* p){
//  int retorno = -1;
//  eEntity* ent;
//
//  if(p != NULL){
//    ent = (eEntity*) p;
//    if(strcmp(ent->tipo, "PLUS") == 0){
//        //printf("%s ", ent->codigo);
//        retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int entityBultosTotales(void* p){
//  int retorno = -1;
//  eEntity* ent;
//
//  if(p != NULL){
//    ent = (eEntity*) p;
//    retorno = ent->cantidad;
//  }
//  return retorno;
//}
//
//float entityImportesTotales(void* p){
//  float retorno = -1;
//  eEntity* ent;
//
//  if(p != NULL){
//    ent = (eEntity*) p;
//    retorno = ent->importe;
//  }
//  return retorno;
//}

//
//int entityMapSalary(void* p)
//{
//  int retorno = -1;
//  float sueldo;
//  int horas;
//
//  eEntity* empl;
//
//  if(p != NULL){
//    empl = (eEntity*) p;
//    entity_getHorasTrabajadas(empl, &horas);
//    if(horas <= 176){
//      sueldo = (horas)*180;
//    }else if(horas < 209){
//      sueldo = (horas)*270;
//    }else{
//      sueldo = (horas)*360;
//    }
//    entity_setSueldo(empl, sueldo);
//    retorno = 0;
//  }
//  return retorno;
//}
