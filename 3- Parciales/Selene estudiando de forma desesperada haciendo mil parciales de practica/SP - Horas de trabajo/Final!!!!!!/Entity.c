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
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

static void initializeStr(eEntity* this, char *var1, char *var2, char *var3, char *var4)   //inicializo todos los parametros de forma string
{
    int id, horasTrabajadas;
    float sueldo;

    id = atoi(var1);
    horasTrabajadas = atoi(var3);
    sueldo = atof(var4);

    entity_setId(this, id);
    entity_setNombre(this, var2);
    entity_setHorasTrabajadas(this, horasTrabajadas);
    entity_setSueldo(this, sueldo);
}

eEntity* entity_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    eEntity* this;
    this = entity_new();
    if(this != NULL)
        initializeStr(this, idStr, nombreStr, horasTrabajadasStr, sueldoStr);
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

int entity_setHorasTrabajadas(eEntity* this,int horasTrabajadas){
    int retorno = -1;
    if(this != NULL && horasTrabajadas > 0){
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int entity_getHorasTrabajadas(eEntity* this,int* horasTrabajadas){
    if(this != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        return 0;
    }else
        return -1;
}

int entity_setSueldo(eEntity* this,float sueldo){
    int retorno = -1;
    if(this != NULL && sueldo > 0){
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
int entity_getSueldo(eEntity* this,float* sueldo){
    if(this != NULL){
        *sueldo = this->sueldo;
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



int entityMapSalary(void* p)
{
  int retorno = -1;
  float sueldo;
  int horas;

  eEntity* empl;

  if(p != NULL){
    empl = (eEntity*) p;
    entity_getHorasTrabajadas(empl, &horas);
    if(horas <= 176){
      sueldo = (horas)*180;
    }else if(horas < 209){
      sueldo = (horas)*270;
    }else{
      sueldo = (horas)*360;
    }
    entity_setSueldo(empl, sueldo);
    retorno = 0;
  }
  return retorno;
}
