#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){
    Employee* this = malloc(sizeof(Employee));
    if(this !=NULL){
        this->id = 0;
        strcpy(this->fecha, " / / ");
        strcpy(this->codigo, " ");
        this->cantidad = 0;
        this->precio = 0;
        strcpy(this->cuit, " ");
    }
    return this;
}

static void initializeStr(Employee* this, char *var1, char *var2, char *var3, char *var4, char *var5, char *var6)   //inicializo todos los parametros
{
    int idAux, cantidadAux;
    float precioAux;

    idAux = atoi(var1);
    cantidadAux = atoi(var4);
    precioAux = atof(var5);

    employee_setId(this, idAux);
    employee_setFecha(this, var2);
    employee_setCodigo(this, var3);
    employee_setCantidad(this, cantidadAux);
    employee_setPrecio(this, precioAux);
    employee_setCuit(this, var6);
}

Employee* employee_newParametros(char* idStr, char* fechaStr, char* codigoStr, char* cantidadStr, char* precioStr, char* cuitStr){
    Employee* this;
    this = employee_new();
    if(this != NULL)
        initializeStr(this, idStr, fechaStr, codigoStr, cantidadStr, precioStr, cuitStr);
    return this;
}


int employee_setId(Employee* this,int id){
    int retorno = -1;
    if(this != NULL && id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id){
    if(this != NULL){
        *id = this->id;
        return 0;
    }else
        return -1;
}

int employee_setFecha(Employee* this,char* fecha){
    int retorno = -1;
    if(this != NULL && fecha[0] != '\0'){
        strncpy(this->fecha, fecha, sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}
int employee_getFecha(Employee* this,char* fecha){
    if(this != NULL){
        strcpy(this->fecha, fecha);
        return 0;
    }else{
        return -1;
    }
}


int employee_setCodigo(Employee* this,char* codigo){
    int retorno = -1;
    if(this != NULL && codigo[0] != '\0'){
        strncpy(this->codigo, codigo, sizeof(this->codigo));
        retorno = 0;
    }
    return retorno;
}
int employee_getCodigo(Employee* this,char* codigo){
    if(this != NULL){
        strcpy(this->codigo, codigo);
        return 0;
    }else{
        return -1;
    }
}


int employee_setCantidad(Employee* this,int cantidad){
    int retorno = -1;
    if(this != NULL && cantidad > 0){
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int employee_getCantidad(Employee* this,int* cantidad){
    if(this != NULL){
        *cantidad = this->cantidad;
        return 0;
    }else
        return -1;
}


int employee_setPrecio(Employee* this, float precio){
    int retorno = -1;
    if(this != NULL && precio > 0){
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}

int employee_getPrecio(Employee* this, float* precio){
    if(this != NULL){
        *precio = this->precio;
        return  0;
    }else
        return -1;
}

int employee_setCuit(Employee* this,char* cuit){
    int retorno = -1;
    if(this != NULL && cuit[0] != '\0'){
        strncpy(this->cuit, cuit, sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}
int employee_getCuit(Employee* this,char* cuit){
    if(this != NULL){
        strcpy(this->cuit, cuit);
        return 0;
    }else{
        return -1;
    }
}

/*

int employeeSortById(void* empleadoA, void* empleadoB){
    int retorno = -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
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

int employeeSortByName(void* empleadoA, void* empleadoB){
    int retorno = -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        retorno = strcmp(empB->nombre, empA->nombre);
    }

    return retorno;
}

int employeeSortByHours(void* empleadoA, void* empleadoB){
    int retorno = -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
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

int employeeSortBySalary(void* empleadoA, void* empleadoB){
    int retorno = -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
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

int employeeFilterHours(void* p){
  int retorno = 0;
  Employee* empl;
  if(p != NULL){
    empl = (Employee*) p;
    if(empl->horasTrabajadas > 150){
      retorno = 1;
    }
  }
  return retorno;
}

int employeeFilterId(void* p){
  int retorno = 0;
  Employee* empl;
  if(p != NULL){
    empl = (Employee*) p;
    if(empl->id < 11){
      retorno = 1;
    }
  }
  return retorno;
}

int employeeFilterName(void* p){
  int retorno = 0;
  Employee* empl;
  if(p != NULL){
    empl = (Employee*) p;
    if(strcmp(empl->nombre,"H")>=0){
      retorno = 1;
    }
  }
  return retorno;
}



int employeeMapSalary(void* p)
{
  int retorno = -1;
  float sueldo;
  int horas;

  Employee* empl;

  if(p != NULL){
    empl = (Employee*) p;
    employee_getHorasTrabajadas(empl, &horas);
    if(horas <= 176){
      sueldo = (horas)*180;
    }else if(horas < 209){
      sueldo = (horas)*270;
    }else{
      sueldo = (horas)*360;
    }
    employee_setSueldo(empl, sueldo);
    retorno = 0;
  }
  return retorno;

}
*/

int employeeVentasTotales(void* p){
  int retorno = -1;
  Employee* empl;
  if(p != NULL){
    empl = (Employee*) p;
    if(ll_isEmpty(empl)==0){
        retorno = 1;
    }
  }
  return retorno;
}

int employeeMayores100000(void* p){
  int retorno = -1;
  Employee* empl;
  if(p != NULL){
    empl = (Employee*) p;
    if((empl->precio) > 100000){
        retorno = 1;
    }
  }
  return retorno;
}

int employeeMayores300000(void* p){
  int retorno = -1;
  Employee* empl;
  if(p != NULL){
    empl = (Employee*) p;
    if((empl->precio) > 300000){
        retorno = 1;
    }
  }
  return retorno;
}

int employeeVentasFord(void* p){
  int retorno = -1;
  Employee* empl;

  if(p != NULL){
    empl = (Employee*) p;
    if(strcmp(empl->codigo, "Ford") == 0){
        //printf("%s ", empl->codigo);
        retorno = 1;
    }
  }
  return retorno;
}

