#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

static void initializeStr(Employee* this, char *var1, char *var2, char *var3, char *var4)
{
    int id, horasTrabajadas, sueldo;

    id = atoi(var1);
    horasTrabajadas = atoi(var3);
    sueldo = atoi(var4);

    employee_setId(this, id);
    employee_setNombre(this, var2);
    employee_setHorasTrabajadas(this, horasTrabajadas);
    employee_setSueldo(this, sueldo);
}

Employee* employee_new(){
    Employee* this = malloc(sizeof(Employee));
    if(this !=NULL){
        this->id = 0;
        this->horasTrabajadas = 0;

    }
    return this;

}

/* ePendrive* new_Pendrive(){
     ePendrive* nuevoPendrive;
     nuevoPendrive = (ePendrive*) malloc(sizeof(ePendrive));
     if(nuevoPendrive != NULL){
        nuevoPendrive->codigo = 0;
        strcpy(nuevoPendrive->marca, "");
       nuevoPendrive->capacidad = 0;
       nuevoPendrive->precio = 0;
     }
 return nuevoPendrive;

 }*/

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* this = malloc(sizeof(Employee));
    if(this != NULL)
        initializeStr(this, idStr, nombreStr, horasTrabajadasStr, sueldoStr);
    return this;
}

void employee_delete(){

}


int employee_setId(Employee* this,int id){
    int retorno = -1;
    if(id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id){
    return this->id;
}


int employee_setNombre(Employee* this,char* nombre){
    int retorno = -1;
    if(nombre[0] != '\0'){
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre){
    return this->nombre;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int retorno = -1;
    if(horasTrabajadas > 0){
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    return this->horasTrabajadas;
}


int employee_setSueldo(Employee* this,int sueldo){
    if(sueldo > 0)
        this->sueldo = sueldo;
}
int employee_getSueldo(Employee* this,int* sueldo){
    return this->sueldo;
}



int employeeSortById(void* empleadoA, void* empleadoB){
    int retorno = -1;

    if(empleadoA !=NULL && empleadoB !=NULL){

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
        retorno = strcmp(empA->nombre, empB->nombre);
    }

    return retorno;
}

int employeeSortByHours(void* empleadoA, void* empleadoB){
    int retorno = -1;

    if(empleadoA !=NULL && empleadoB !=NULL){

    }

    return retorno;
}

int employeeSortBySalary(void* empleadoA, void* empleadoB){
    int retorno = -1;

    if(empleadoA !=NULL && empleadoB !=NULL){

    }

    return retorno;
}

