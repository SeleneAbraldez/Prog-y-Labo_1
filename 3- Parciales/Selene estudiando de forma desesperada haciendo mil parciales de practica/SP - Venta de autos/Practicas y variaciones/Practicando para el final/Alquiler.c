#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Alquiler.h"

eAlquiler* alquiler_new(){
    eAlquiler* this = malloc(sizeof(eAlquiler));  //pedido de memoria dinamica por malloc
    if(this !=NULL){    //si hay memoria inciilizo los valores
        this->id = 0;
        strcpy(this->fecha, " ");
        strcpy(this->nombre, " ");
        this->cantidad = 0;
        this->precio = 0;
        this->cuit = 0;
    }
    return this;
}

static void initializeStr(eAlquiler* this, char *var1, char *var2, char *var3, char *var4, char *var5, char *var6)   //inicializo todos los parametros, de forma string
{
    int id, cantidad;
    float precio, cuit;

    id = atoi(var1);
    cantidad = atoi(var4);
    precio = atof(var5);
    cuit = atof(var6);

    alquiler_setId(this, id);
    alquiler_setFecha(this, var2);
    alquiler_setNombre(this, var3);
    alquiler_setCantidad(this, cantidad);
    alquiler_setPrecio(this, precio);
    alquiler_setCuit(this, cuit);
}

eAlquiler* alquiler_newParametros(char* idStr, char* fechaStr, char* nombreStr, char* cantidadStr, char* precioStr, char* cuitStr){
    eAlquiler* this;
    this = alquiler_new();
    if(this != NULL)
        initializeStr(this, idStr, fechaStr, nombreStr, cantidadStr, precioStr, cuitStr);
    return this;
}


int alquiler_setId(eAlquiler* this,int id){
    int retorno = -1;
    if(this != NULL && id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int alquiler_getId(eAlquiler* this,int* id){
    if(this != NULL){
        *id = this->id;
        return 0;
    }else
        return -1;
}

int alquiler_setFecha(eAlquiler* this,char* fecha){
    int retorno = -1;
    if(this != NULL && fecha[0] != '\0'){
        strncpy(this->fecha, fecha, sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}
int alquiler_getFecha(eAlquiler* this,char* fecha){
    if(this != NULL){
        strcpy(this->fecha, fecha);
        return 0;
    }else{
        return -1;
    }
}


int alquiler_setNombre(eAlquiler* this,char* nombre){
    int retorno = -1;
    if(this != NULL && nombre[0] != '\0'){
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int alquiler_getNombre(eAlquiler* this,char* nombre){
    if(this != NULL){
        strcpy(this->nombre, nombre);
        return 0;
    }else{
        return -1;
    }
}


int alquiler_setCantidad(eAlquiler* this,int cantidad){
    int retorno = -1;
    if(this != NULL && cantidad > 0){
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int alquiler_getCantidad(eAlquiler* this,int* cantidad){
    if(this != NULL){
        *cantidad = this->cantidad;
        return 0;
    }else
        return -1;
}


int alquiler_setPrecio(eAlquiler* this,float precio){
    int retorno = -1;
    if(this != NULL && precio > 0){
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}

int alquiler_getPrecio(eAlquiler* this,float* precio){
    if(this != NULL){
        *precio = this->precio;
        return  0;
    }else
        return -1;
}


int alquiler_setCuit(eAlquiler* this,float cuit){
    int retorno = -1;
    if(this != NULL && cuit > 0){
        this->cuit = cuit;
        retorno = 0;
    }
    return retorno;
}

int alquiler_getCuit(eAlquiler* this,float* cuit){
    if(this != NULL){
        *cuit = this->cuit;
        return  0;
    }else
        return -1;
}


/*
int alquilerSortById(void* empleadoA, void* empleadoB){
    int retorno = -1;
    eAlquiler* empA;
    eAlquiler* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (eAlquiler*) empleadoA;
        empB = (eAlquiler*) empleadoB;
        if((empA->id)<(empB->id)){
            retorno = 1 ;
        }else if((empA->id)>(empB->id)){
            retorno = -1 ;
        }else if((empA->id)==(empB->id)){
            retorno = 0;
        }
    }
    return retorno;
}

int alquilerSortByName(void* empleadoA, void* empleadoB){
    int retorno = -1;
    eAlquiler* empA;
    eAlquiler* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (eAlquiler*) empleadoA;
        empB = (eAlquiler*) empleadoB;
        retorno = strcmp(empB->nombre, empA->nombre);
    }

    return retorno;
}

int alquilerSortByHours(void* empleadoA, void* empleadoB){
    int retorno = -1;
    eAlquiler* empA;
    eAlquiler* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (eAlquiler*) empleadoA;
        empB = (eAlquiler*) empleadoB;
                if((empA->horasTrabajadas)<(empB->horasTrabajadas)){
            retorno = 1 ;
        }else if((empA->horasTrabajadas)>(empB->horasTrabajadas)){
            retorno = -1 ;
        }else if((empA->horasTrabajadas)==(empB->horasTrabajadas)){
            retorno = 0;
        }
    }
    return retorno;
}

int alquilerSortBySalary(void* empleadoA, void* empleadoB){
    int retorno = -1;
    eAlquiler* empA;
    eAlquiler* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (eAlquiler*) empleadoA;
        empB = (eAlquiler*) empleadoB;
        if((empA->sueldo)<(empB->sueldo)){
            retorno = 1 ;
        }else if((empA->sueldo)>(empB->sueldo)){
            retorno = -1 ;
        }else if((empA->sueldo)==(empB->sueldo)){
            retorno = 0;
        }
    }
    return retorno;
}

int alquilerFilterHours(void* p){
  int retorno = 0;
  eAlquiler* empl;
  if(p != NULL){
    empl = (eAlquiler*) p;
    if(empl->horasTrabajadas > 150){
      retorno = 1;
    }
  }
  return retorno;
}

int alquilerFilterId(void* p){
  int retorno = 0;
  eAlquiler* empl;
  if(p != NULL){
    empl = (eAlquiler*) p;
    if(empl->id < 11){
      retorno = 1;
    }
  }
  return retorno;
}

int alquilerFilterName(void* p){
  int retorno = 0;
  eAlquiler* empl;
  if(p != NULL){
    empl = (eAlquiler*) p;
    if(strcmp(empl->nombre,"H")>=0){
      retorno = 1;
    }
  }
  return retorno;
}

int alquilerMapSalary(void* p)
{
  int retorno = -1;
  float sueldo;
  int horas;

  eAlquiler* empl;

  if(p != NULL){
    empl = (eAlquiler*) p;
    alquiler_getHorasTrabajadas(empl, &horas);
    if(horas <= 176){
      sueldo = (horas)*180;
    }else if(horas < 209){
      sueldo = (horas)*270;
    }else{
      sueldo = (horas)*360;
    }
    alquiler_setSueldo(empl, sueldo);
    retorno = 0;
  }
  return retorno;
}

*/


int alquiler_VentasTotales(void* p){
    int retorno =-1;
    eAlquiler* alqui;
    if(p != NULL){
        alqui = (eAlquiler*) p;
        if(ll_isEmpty(alqui)==0){
            retorno = 1;
        }
    }
    return retorno;
}


int alquiler_VentasMayores100000(void* p){
    int retorno =-1;
    eAlquiler* alqui;
    if(p != NULL){
        alqui = (eAlquiler*) p;
        if((alqui->precio) > 100000){
            retorno = 1;
        }
    }
    return retorno;
}

int alquiler_VentasMayores300000(void* p){
    int retorno =-1;
    eAlquiler* alqui;
    if(p != NULL){
        alqui = (eAlquiler*) p;
        if((alqui->precio) > 300000){
            retorno = 1;
        }
    }
    return retorno;
}

int alquiler_VentasFords(void* p){
    int retorno =-1;
    eAlquiler* alqui;
    if(p != NULL){
        alqui = (eAlquiler*) p;
        if(strcmp(alqui->nombre, "Ford") == 0){
            retorno = 1;
        }
    }
    return retorno;
}


int alquiler_VentasFordsPrecio(void* p){
    int retorno =-1;
    eAlquiler* alqui;
    if(p != NULL){
        alqui = (eAlquiler*) p;
        if(strcmp(alqui->nombre, "Ford") == 0){
            retorno = alqui->precio;
        }
    }
    return retorno;
}









