#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entity.h"

eIngredientes* entity_new(){
    eIngredientes* this = malloc(sizeof(eIngredientes));  //pedido de memoria dinamica por malloc
    if(this !=NULL){    //si hay memoria inciilizo los valores
        this->id = 0;
        strcpy(this->nombre, " ");
        this->calorias = 0;
        this->grasas = 0;
        this->sodio = 0;
        this->carbohidratos = 0;
        this->proteinas = 0;
    }
    return this;
}

static void initializeStr(eIngredientes* this, char *var1, char *var2, char *var3, char *var4, char *var5, char *var6, char *var7)   //inicializo todos los parametros de forma string
{
    int id, calorias, sodio, carbohidratos, proteinas;
    float grasas;

    id = atoi(var1);
    calorias = atoi(var3);
    grasas = atof(var4);
    sodio = atoi(var5);
    carbohidratos = atoi(var6);
    proteinas = atoi(var7);

    entity_setId(this, id);
    entity_setNombre(this, var2);
    entity_setCalorias(this, calorias);
    entity_setGrasas(this, grasas);
    entity_setSodio(this, sodio);
    entity_setCarbohidratos(this, carbohidratos);
    entity_setProteinas(this, proteinas);
}

eIngredientes* entity_newParametros(char* idStr,char* nombreStr, char* caloriasStr, char* grasasStr, char* sodioStr, char* carbohidratosStr, char* proteinasStr){
    eIngredientes* this;
    this = entity_new();
    if(this != NULL)
        initializeStr(this, idStr, nombreStr, caloriasStr, grasasStr, sodioStr, carbohidratosStr, proteinasStr);
    return this;
}


int entity_setId(eIngredientes* this,int id){
    int retorno = -1;
    if(this != NULL && id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int entity_getId(eIngredientes* this,int* id){
    if(this != NULL){
        *id = this->id;
        return 0;
    }else
        return -1;
}

int entity_setNombre(eIngredientes* this,char* nombre){
    int retorno = -1;
    if(this != NULL && nombre[0] != '\0'){
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int entity_getNombre(eIngredientes* this,char* nombre){
    if(this != NULL){
        strcpy(this->nombre, nombre);
        return 0;
    }else{
        return -1;
    }
}

int entity_setCalorias(eIngredientes* this,int calorias){
    int retorno = -1;
    if(this != NULL && calorias > 0){
        this->calorias = calorias;
        retorno = 0;
    }
    return retorno;
}
int entity_getCalorias(eIngredientes* this,int* calorias){
    if(this != NULL){
        *calorias = this->calorias;
        return 0;
    }else
        return -1;
}

int entity_setGrasas(eIngredientes* this,float grasas){
    int retorno = -1;
    if(this != NULL && grasas > 0){
        this->grasas = grasas;
        retorno = 0;
    }
    return retorno;
}
int entity_getGrasas(eIngredientes* this,float* grasas){
    if(this != NULL){
        *grasas = this->grasas;
        return  0;
    }else
        return -1;
}

int entity_setSodio(eIngredientes* this,int sodio){
    int retorno = -1;
    if(this != NULL && sodio > 0){
        this->sodio = sodio;
        retorno = 0;
    }
    return retorno;
}
int entity_getSodio(eIngredientes* this,int* sodio){
    if(this != NULL){
        *sodio = this->sodio;
        return 0;
    }else
        return -1;
}

int entity_setCarbohidratos(eIngredientes* this,int carbohidratos){
    int retorno = -1;
    if(this != NULL && carbohidratos > 0){
        this->carbohidratos = carbohidratos;
        retorno = 0;
    }
    return retorno;
}
int entity_getCarbohidratos(eIngredientes* this,int* carbohidratos){
    if(this != NULL){
        *carbohidratos = this->carbohidratos;
        return 0;
    }else
        return -1;
}

int entity_setProteinas(eIngredientes* this,int proteinas){
    int retorno = -1;
    if(this != NULL && proteinas > 0){
        this->proteinas = proteinas;
        retorno = 0;
    }
    return retorno;
}
int entity_getProteinas(eIngredientes* this,int* proteinas){
    if(this != NULL){
        *proteinas = this->proteinas;
        return 0;
    }else
        return -1;
}




eRecetas* receta_new(){
    eRecetas* this = malloc(sizeof(eRecetas));  //pedido de memoria dinamica por malloc
    if(this !=NULL){    //si hay memoria inciilizo los valores
        this->id = 0;
        strcpy(this->nombre, " ");
        this->idIngredientes = 0;
        this->cantidad = 0;
    }
    return this;
}

static void initializeStrReceta(eRecetas* this, char *var1, char *var2, char *var3, char *var4)   //inicializo todos los parametros de forma string
{
    int id, idIngredientes, cantidad;

    id = atoi(var1);
    idIngredientes = atoi(var3);
    cantidad = atoi(var4);

    receta_setId(this, id);
    receta_setNombre(this, var2);
    receta_setidIngredientes(this, idIngredientes);
    receta_setCantidad(this, cantidad);
}

eRecetas* receta_newParametros(char* idStr, char* nombreStr, char* idIngredientesStr, char* cantidadStr){
    eRecetas* this;
    this = receta_new();
    if(this != NULL)
        initializeStrReceta(this, idStr, nombreStr, idIngredientesStr, cantidadStr);
    return this;
}


int receta_setId(eRecetas* this,int id){
    int retorno = -1;
    if(this != NULL && id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int receta_getId(eRecetas* this,int* id){
    if(this != NULL){
        *id = this->id;
        return 0;
    }else
        return -1;
}

int receta_setNombre(eRecetas* this,char* nombre){
    int retorno = -1;
    if(this != NULL && nombre[0] != '\0'){
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int receta_getNombre(eRecetas* this,char* nombre){
    if(this != NULL){
        strcpy(this->nombre, nombre);
        return 0;
    }else{
        return -1;
    }
}

int receta_setidIngredientes(eRecetas* this,int idIngredientes){
    int retorno = -1;
    if(this != NULL && idIngredientes > 0){
        this->idIngredientes = idIngredientes;
        retorno = 0;
    }
    return retorno;
}
int receta_getidIngredientes(eRecetas* this,int* idIngredientes){
    if(this != NULL){
        *idIngredientes = this->idIngredientes;
        return 0;
    }else
        return -1;
}

int receta_setCantidad(eRecetas* this,int cantidad){
    int retorno = -1;
    if(this != NULL && cantidad > 0){
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int receta_getCantidad(eRecetas* this,int* cantidad){
    if(this != NULL){
        *cantidad = this->cantidad;
        return 0;
    }else
        return -1;
}








//int entitySortById(void* empleadoA, void* empleadoB){
//    int retorno = -1;
//    eRecetas* empA;
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
