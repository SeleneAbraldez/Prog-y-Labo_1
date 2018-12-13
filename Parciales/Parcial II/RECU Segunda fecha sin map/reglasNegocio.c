#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "reglasNegocio.h"

eAbono* abono_new(){
    eAbono* this = malloc(sizeof(eAbono));
    if(this != NULL){
        this->id = 0;
        strcpy(this->tipo, "0");
        this->idCliente = 0;
        this->importeFinal = 0;
    }
    return this;
}

Employee* employee_new(){
    Employee* this = malloc(sizeof(Employee));
    if(this !=NULL){
        this->id = 0;
        strcpy(this->nombre, " ");
        strcpy(this->sexo, " ");
        strcpy(this->numeroTelefono, " - ");
        this->importe = 0;
    }
    return this;
}

static void initializeAbonoStr(eAbono* this, char *var1, char *var2, char *var3, char *var4)   //inicializo todos los parametros
{
    int id, idCliente;
    float importeFinal;

    id = atoi(var1);
    idCliente = atoi(var3);
    importeFinal = atof(var4);

    abono_setId(this, id);
    abono_setTipo(this, var2);
    abono_setIdCliente(this, idCliente);
    abono_setImporteFinal(this, importeFinal);
}

eAbono* abono_newParametros(char* idStr,char* tipoStr,char* idClienteStr ,char* importeFinalStr){
    eAbono* this;
    this = abono_new();
    if(this != NULL){
       initializeAbonoStr(this, idStr, tipoStr, idClienteStr, importeFinalStr);
    }
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

int abono_setTipo(eAbono* this,char* tipo){
    int retorno = -1;
    if(this != NULL && tipo[0] != '\0'){
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}
int abono_getTipo(eAbono* this,char* tipo){
    if(this != NULL){
        strcpy(this->tipo, tipo);
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


int abono_setImporteFinal(eAbono* this,float importeFinal){
    int retorno = -1;
    if(this != NULL && importeFinal > 0){
        this->importeFinal = importeFinal;
        retorno = 0;
    }
    return retorno;
}

int abono_getImporteFinal(eAbono* this,float* importeFinal){
    if(this != NULL){
        *importeFinal = this->importeFinal;
        return  0;
    }else
        return -1;
}

static void initializeStr(Employee* this, char *var1, char *var2, char *var3, char *var4, char *var5)   //inicializo todos los parametros
{
    int id;
    float importe;

    id = atoi(var1);
    importe = atof(var5);

    employee_setId(this, id);
    employee_setNombre(this, var2);
    employee_setSexo(this, var3);
    employee_setNumeroTelefono(this, var4);
    employee_setImporte(this, importe);
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* sexoStr ,char* horasTrabajadasStr, char* sueldoStr){
    Employee* this;
    this = employee_new();
    if(this != NULL){
       initializeStr(this, idStr, nombreStr, sexoStr, horasTrabajadasStr, sueldoStr);
    }
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

int employee_setSexo(Employee* this,char* sexo){
    int retorno = -1;
    if(this != NULL && sexo[0] != '\0'){
        strncpy(this->sexo, sexo, sizeof(this->sexo));
        retorno = 0;
    }
    return retorno;
}
int employee_getSexo(Employee* this,char* sexo){
    if(this != NULL){
        strcpy(this->sexo, sexo);
        return 0;
    }else{
        return -1;
    }
}


int employee_setNumeroTelefono(Employee* this,char* numeroTelefono){
    int retorno = -1;
    if(this != NULL && numeroTelefono[0] != '\0'){
        strncpy(this->numeroTelefono, numeroTelefono, sizeof(this->numeroTelefono));
        retorno = 0;
    }
    return retorno;
}
int employee_getNumeroTelefono(Employee* this,char* numeroTelefono){
    if(this != NULL){
        strcpy(this->numeroTelefono, numeroTelefono);
        return 0;
    }else{
        return -1;
    }
}


int employee_setImporte(Employee* this,float importe){
    int retorno = -1;
    if(this != NULL && importe > 0){
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}

int employee_getImporte(Employee* this,float* importe){
    if(this != NULL){
        *importe = this->importe;
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
//
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
//
//int employeeSortByHours(void* empleadoA, void* empleadoB){
//    int retorno = -1;
//    Employee* empA;
//    Employee* empB;
//
//    if(empleadoA !=NULL && empleadoB !=NULL){
//        empA = (Employee*) empleadoA;
//        empB = (Employee*) empleadoB;
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
//int employeeSortBySalary(void* empleadoA, void* empleadoB){
//    int retorno = -1;
//    Employee* empA;
//    Employee* empB;
//
//    if(empleadoA !=NULL && empleadoB !=NULL){
//        empA = (Employee*) empleadoA;
//        empB = (Employee*) empleadoB;
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
//int employeeFilterHours(void* p){
//  int retorno = 0;
//  Employee* empl;
//  if(p != NULL){
//    empl = (Employee*) p;
//    if(empl->horasTrabajadas > 150){
//      retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int employeeFilterId(void* p){
//  int retorno = 0;
//  Employee* empl;
//  if(p != NULL){
//    empl = (Employee*) p;
//    if(empl->id < 11){
//      retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//int employeeFilterName(void* p){
//  int retorno = 0;
//  Employee* empl;
//  if(p != NULL){
//    empl = (Employee*) p;
//    if(strcmp(empl->nombre,"H")>=0){
//      retorno = 1;
//    }
//  }
//  return retorno;
//}
//
//
//
//int employeeMapSalary(void* p)
//{
//  int retorno = -1;
//  float sueldo;
//  int horas;
//
//  Employee* empl;
//
//  if(p != NULL){
//    empl = (Employee*) p;
//    employee_getHorasTrabajadas(empl, &horas);
//    if(horas <= 176){
//      sueldo = (horas)*180;
//    }else if(horas < 209){
//      sueldo = (horas)*270;
//    }else{
//      sueldo = (horas)*360;
//    }
//    employee_setSueldo(empl, sueldo);
//    retorno = 0;
//  }
//  return retorno;
//
//}
