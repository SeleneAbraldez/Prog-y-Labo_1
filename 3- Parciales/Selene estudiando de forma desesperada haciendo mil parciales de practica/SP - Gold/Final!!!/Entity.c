#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entity.h"

eEntity* entity_new(){
    eEntity* this = malloc(sizeof(eEntity));  //pedido de memoria dinamica por malloc
    if(this !=NULL){    //si hay memoria inciilizo los valores
        this->id = 0;
        strcpy(this->tipo, " ");
        this->cantidad = 0;
        this->importe = 0;
    }
    return this;
}

static void initializeStr(eEntity* this, char *var1, char *var2, char *var3, char *var4)   //inicializo todos los parametros de forma string
{
    int id, cantidad;
    float importe;

    id = atoi(var1);
    cantidad = atoi(var3);
    importe = atof(var4);

    entity_setId(this, id);
    entity_setTipo(this, var2);
    entity_setCantidad(this, cantidad);
    entity_setImporte(this, importe);
}

eEntity* entity_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr){
    eEntity* this;
    this = entity_new();
    if(this != NULL)
        initializeStr(this, idStr, tipoStr, cantidadStr, importeStr);
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

int entity_setTipo(eEntity* this,char* tipo){
    int retorno = -1;
    if(this != NULL && tipo[0] != '\0'){
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}
int entity_getTipo(eEntity* this,char* tipo){
    if(this != NULL){
        strcpy(this->tipo, tipo);
        return 0;
    }else{
        return -1;
    }
}

int entity_setCantidad(eEntity* this,int cantidad){
    int retorno = -1;
    if(this != NULL && cantidad > 0){
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int entity_getCantidad(eEntity* this,int* cantidad){
    if(this != NULL){
        *cantidad = this->cantidad;
        return 0;
    }else
        return -1;
}

int entity_setImporte(eEntity* this,float importe){
    int retorno = -1;
    if(this != NULL && importe > 0){
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}
int entity_getImporte(eEntity* this,float* importe){
    if(this != NULL){
        *importe = this->importe;
        return  0;
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

int entityVentasTotales(void* p){
  int retorno = -1;
  eEntity* ent;
  if(p != NULL){
    ent = (eEntity*) p;
    if(ll_isEmpty(ent)==0){
        retorno = 1;
    }
  }
  return retorno;
}

int entityGold(void* p){
  int retorno = -1;
  eEntity* ent;

  if(p != NULL){
    ent = (eEntity*) p;
    if(strcmp(ent->tipo, "GOLD") == 0){
        //printf("%s ", ent->codigo);
        retorno = 1;
    }
  }
  return retorno;
}

int entityRegular(void* p){
  int retorno = -1;
  eEntity* ent;

  if(p != NULL){
    ent = (eEntity*) p;
    if(strcmp(ent->tipo, "REGULAR") == 0){
        //printf("%s ", ent->codigo);
        retorno = 1;
    }
  }
  return retorno;
}

int entityPlus(void* p){
  int retorno = -1;
  eEntity* ent;

  if(p != NULL){
    ent = (eEntity*) p;
    if(strcmp(ent->tipo, "PLUS") == 0){
        //printf("%s ", ent->codigo);
        retorno = 1;
    }
  }
  return retorno;
}

int entityBultosTotales(void* p){
  int retorno = -1;
  eEntity* ent;

  if(p != NULL){
    ent = (eEntity*) p;
    retorno = ent->cantidad;
  }
  return retorno;
}

float entityImportesTotales(void* p){
  float retorno = -1;
  eEntity* ent;

  if(p != NULL){
    ent = (eEntity*) p;
    retorno = ent->importe;
  }
  return retorno;
}


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
