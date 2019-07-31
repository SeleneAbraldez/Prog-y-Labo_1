#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entity.h"

eEntity* entity_new(){
    eEntity* this = malloc(sizeof(eEntity));  //pedido de memoria dinamica por malloc
    if(this !=NULL){    //si hay memoria inciilizo los valores
        this->id = 0;
        strcpy(this->nombre, " ");
        this->km = 0;
        this->tipo = 0;
        this->costoEnvio;
    }
    return this;
}

static void initializeStr(eEntity* this, char *var1, char *var2, char *var3, char *var4, char *var5)   //inicializo todos los parametros de forma string
{
    int id, km, tipo, costoEnvio;

    id = atoi(var1);
    km = atoi(var3);
    tipo = atoi(var4);
    costoEnvio = atoi(var5);

    entity_setId(this, id);
    entity_setNombre(this, var2);
    entity_setKm(this, km);
    entity_setTipo(this, tipo);
    entity_setCostoEnvio(this, costoEnvio);
}

eEntity* entity_newParametros(char* idStr,char* nombreStr,char* kmStr, char* tipoStr, char* costoEnvioStr){
    eEntity* this;
    this = entity_new();
    if(this != NULL)
        initializeStr(this, idStr, nombreStr, kmStr, tipoStr, costoEnvioStr);
    return this;
}


int entity_setId(eEntity* this,int id){
    int retorno = -1;
    if(this != NULL && id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int entity_getId(eEntity* this,int* id){
    if(this != NULL){
        *id = this->id;
        return 0;
    }else
        return -1;
}

int entity_setNombre(eEntity* this,char* nombre){
    int retorno = -1;
    if(this != NULL && nombre[0] != '\0'){
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int entity_getNombre(eEntity* this,char* nombre){
    if(this != NULL){
        strcpy(this->nombre, nombre);
        return 0;
    }else{
        return -1;
    }
}

int entity_setKm(eEntity* this,int km){
    int retorno = -1;
    if(this != NULL && km > 0){
        this->km = km;
        retorno = 0;
    }
    return retorno;
}
int entity_getKm(eEntity* this,int* km){
    if(this != NULL){
        *km = this->km;
        return 0;
    }else
        return -1;
}

int entity_setTipo(eEntity* this,int tipo){
    int retorno = -1;
    if(this != NULL && tipo > 0){
        this->tipo = tipo;
        retorno = 0;
    }
    return retorno;
}
int entity_getTipo(eEntity* this,int* tipo){
    if(this != NULL){
        *tipo = this->tipo;
        return  0;
    }else
        return -1;
}


int entity_setCostoEnvio(eEntity* this,int costoEnvio){
    int retorno = -1;
    if(this != NULL && costoEnvio > 0){
        this->costoEnvio = costoEnvio;
        retorno = 0;
    }
    return retorno;
}
int entity_getCostoEnvio(eEntity* this,int* costoEnvio){
    if(this != NULL){
        *costoEnvio = this->costoEnvio;
        return 0;
    }else
        return -1;
}


//int entitySortById(void* empleadoA, void* empleadoB){
//    int retorno = -1;
//    eEntity* empA;
//    eEntity* empB;
//
//    if(empleadoA !=NULL && empleadoB !=NULL){
//        empA = (eEntity*) empleadoA;
//        empB = (eEntity*) empleadoB;
//        if((empA->id)<(empB->id)){
//            retorno = 1 ;
//        }else if((empA->id)>(empB->id)){
//            retorno = -1 ;
//        }else if((empA->id)==(empB->id)){
//            retorno = 0;
//        }
//    }
//    return retorno;
//}
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


int entityMapCosto(void* p)
{
  int retorno = -1;
  int costoAux, kmAux, tipoAux;

  eEntity* empl;

  if(p != NULL){
    empl = (eEntity*) p;
    entity_getKm(empl, &kmAux);
    entity_getTipo(empl, &tipoAux);

    if(kmAux < 50){
      costoAux = (kmAux)*67;
    }else if(kmAux >= 50){
      costoAux = (kmAux)*80;
    }

    if(tipoAux == 1){
        costoAux = costoAux + 330;
    }else if(tipoAux == 2){
        costoAux += 560;
    }else if(tipoAux == 3){
        costoAux += 80;
    }

    entity_setCostoEnvio(empl, costoAux);
    retorno = 0;
  }
  return retorno;
}
