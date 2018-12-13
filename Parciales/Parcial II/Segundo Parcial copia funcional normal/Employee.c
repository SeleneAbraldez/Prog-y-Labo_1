#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){
    Employee* this = malloc(sizeof(Employee));
    if(this !=NULL){
        this->id = 0;
        strcpy(this->nombre, " ");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

static void initializeStr(Employee* this, char *var1, char *var2, char *var3, char *var4)
{
    int id, horasTrabajadas, sueldo;

    id = atoi(var1);
    horasTrabajadas = atoi(var3);
    sueldo = atof(var4);

    employee_setId(this, id);
    employee_setNombre(this, var2);
    employee_setHorasTrabajadas(this, horasTrabajadas);
    employee_setSueldo(this, sueldo);
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* this;
    this = employee_new();
    if(this != NULL)
        initializeStr(this, idStr, nombreStr, horasTrabajadasStr, sueldoStr);
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


int employee_setNombre(Employee* this,char* nombre){
    int retorno = -1;
    if(this != NULL && nombre[0] != '\0'){
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre){
    if(this != NULL){
        strcpy(this->nombre, nombre);
        return 0;
    }else{
        return -1;
    }
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int retorno = -1;
    if(this != NULL && horasTrabajadas > 0){
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    if(this != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        return 0;
    }else{
        return -1;
    }
}


int employee_setSueldo(Employee* this, float sueldo){
    int retorno = -1;
    if(this != NULL && sueldo > 0){
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this, float* sueldo){
    if(this != NULL){
        *sueldo = this->sueldo;
        return  0;
    }else
        return -1;
}



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
    if(empl->id > 10){
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
