#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entity.h"

eEntity* entity_new(){
    eEntity* this = malloc(sizeof(eEntity));  //pedido de memoria dinamica por malloc
    if(this !=NULL){    //si hay memoria inciilizo los valores
        this->id = 0;
        strcpy(this->fecha, " / / ");
        strcpy(this->codigo, " ");
        this->cantidad = 0;
        this->precio = 0;
        strcpy(this->cuit, " ");
    }
    return this;
}

static void initializeStr(eEntity* this, char *var1, char *var2, char *var3, char *var4, char *var5, char *var6)   //inicializo todos los parametros de forma string
{
    int id, cantidad;
    float precio;

    id = atoi(var1);
    cantidad = atoi(var4);
    precio = atof(var5);

    entity_setId(this, id);
    entity_setFecha(this, var2);
    entity_setCodigo(this, var3);
    entity_setCantidad(this, cantidad);
    entity_setPrecio(this, precio);
    entity_setCuit(this, var6);
}

eEntity* entity_newParametros(char* idStr,char* fechaStr,char* codigoStr, char* cantidadStr, char* sueldoStr, char* cuitStr){
    eEntity* this;
    this = entity_new();
    if(this != NULL)
        initializeStr(this, idStr, fechaStr, codigoStr, cantidadStr, sueldoStr, cuitStr);
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

int entity_setFecha(eEntity* this,char* fecha){
    int retorno = -1;
    if(this != NULL && fecha[0] != '\0'){
        strncpy(this->fecha, fecha, sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}
int entity_getFecha(eEntity* this,char* fecha){
    if(this != NULL){
        strcpy(this->fecha, fecha);
        return 0;
    }else{
        return -1;
    }
}

int entity_setCodigo(eEntity* this,char* codigo){
    int retorno = -1;
    if(this != NULL && codigo[0] != '\0'){
        strncpy(this->codigo, codigo, sizeof(this->codigo));
        retorno = 0;
    }
    return retorno;
}
int entity_getCodigo(eEntity* this,char* codigo){
    if(this != NULL){
        strcpy(this->codigo, codigo);
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

int entity_setPrecio(eEntity* this,float precio){
    int retorno = -1;
    if(this != NULL && precio > 0){
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}
int entity_getPrecio(eEntity* this,float* precio){
    if(this != NULL){
        *precio = this->precio;
        return  0;
    }else
        return -1;
}

int entity_setCuit(eEntity* this,char* cuit){
    int retorno = -1;
    if(this != NULL && cuit[0] != '\0'){
        strncpy(this->cuit, cuit, sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}
int entity_getCuit(eEntity* this,char* cuit){
    if(this != NULL){
        strcpy(this->cuit, cuit);
        return 0;
    }else{
        return -1;
    }
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

int entityMayores100000(void* p){
  int retorno = -1;
  eEntity* ent;
  if(p != NULL){
    ent = (eEntity*) p;
    if((ent->precio) > 100000){
        retorno = 1;
    }
  }
  return retorno;
}

int entityMayores300000(void* p){
  int retorno = -1;
  eEntity* ent;
  if(p != NULL){
    ent = (eEntity*) p;
    if((ent->precio) > 300000){
        retorno = 1;
    }
  }
  return retorno;
}

int entityVentasFord(void* p){
  int retorno = -1;
  eEntity* ent;

  if(p != NULL){
    ent = (eEntity*) p;
    if(strcmp(ent->codigo, "Ford") == 0){
        //printf("%s ", ent->codigo);
        retorno = 1;
    }
  }
  return retorno;
}


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
