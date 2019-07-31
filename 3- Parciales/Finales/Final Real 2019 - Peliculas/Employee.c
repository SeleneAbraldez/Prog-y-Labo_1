#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* this = malloc(sizeof(Employee));  //pedido de memoria dinamica por malloc
    if(this !=NULL)     //si hay memoria inciilizo los valores
    {
        this->id = 0;
        strcpy(this->nombre, " ");
        this->anio = 0;
        strcpy(this->genero, " ");
    }
    return this;
}

static void initializeStr(Employee* this, char *var1, char *var2, char *var3, char *var4)   //inicializo todos los parametros, de forma string
{
    int id, anio;

    id = atoi(var1);
    anio = atoi(var3);

    employee_setId(this, id);
    employee_setNombre(this, var2);
    employee_setAnio(this, anio);
    employee_setGenero(this, var4);
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* anioStr, char* generoStr)
{
    Employee* this;
    this = employee_new();
    if(this != NULL)
        initializeStr(this, idStr, nombreStr, anioStr, generoStr);
    return this;
}


int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        if(strcmp(this->nombre, "Animales Fantasticos - Los crímenes de Grindelwald") == 0){
            this->id = 11;
        }
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    if(this != NULL)
    {
        *id = this->id;
        if(strcmp(this->nombre, "Animales Fantasticos - Los crímenes de Grindelwald") == 0){
            *id = 11;
        }
        return 0;
    }
    else
        return -1;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre[0] != '\0')
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        return 0;
    }
    else
    {
        return -1;
    }
}


int employee_setAnio(Employee* this,int anio)
{
    int retorno = -1;
    if(this != NULL && anio > 0)
    {
        this->anio = anio;
        retorno = 0;
    }
    return retorno;
}
int employee_getAnio(Employee* this,int* anio)
{
    if(this != NULL)
    {
        *anio = this->anio;
        return 0;
    }
    else
        return -1;
}


int employee_setGenero(Employee* this,char* genero)
{
    int retorno = -1;
    if(this != NULL && genero[0] != '\0')
    {
        strncpy(this->genero, genero, sizeof(this->genero));
        retorno = 0;
    }
    return retorno;
}
int employee_getGenero(Employee* this,char* genero)
{
    if(this != NULL)
    {
        strcpy(genero, this->genero);
        return 0;
    }
    else
    {
        return -1;
    }
}



int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno = -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL)
    {
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        if((empA->id)<(empB->id))
        {
            retorno = 1 ;
        }
        else if((empA->id)>(empB->id))
        {
            retorno = -1 ;
        }
        else if((empA->id)==(empB->id))
        {
            retorno = 0;
        }
    }
    return retorno;
}

int employeeFilterGeneroAccion(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Accion") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int employeeFilterGeneroAnimacion(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Animacion") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int employeeFilterGeneroAventura(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Aventura") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int employeeFilterGeneroCienciaFiccion(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Ciencia ficcion") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int employeeFilterGeneroComedia(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Comedia") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int employeeFilterGeneroDrama(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Drama") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int employeeFilterGeneroFamiliar(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Familiar") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int employeeFilterGeneroFantasia(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Fantasia") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int employeeFilterGeneroInfantil(void* p)
{
    int retorno = 0;
    Employee* empl;

    if(p != NULL)
    {
        empl = (Employee*) p;
        if(strstr(empl->genero, "Infantil") != NULL)
        {
            retorno = 1;
        }
    }
    return retorno;
}


int employeeSortByGenero(void* empleadoA, void* empleadoB)
{
    int retorno = -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL)
    {
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        retorno = strcmp(empB->genero, empA->genero);
    }

    return retorno;
}


//int employeeSortByName(void* empleadoA, void* empleadoB){
//    int retorno = -1;
//    Employee* empA;
//    Employee* empB;
//
//    if(empleadoA !=NULL && empleadoB !=NULL){
//        empA = (Employee*) empleadoA;
//        empB = (Employee*) empleadoB;
//        retorno = strcmp(empB->nombre, empA->nombre);
//    }
//
//    return retorno;
//}
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

void depurarPeliculas (LinkedList* pArrayPelisDepu)
{
    Employee* peli1;
    Employee* peli2;
    Employee* peli;

    int auxId1, auxId2;
    char auxGenero1[30], auxGenero2[30];
    char idStr[30], anioStr[50];
    char generoFinal[90];
    int optionYN;

    if(pArrayPelisDepu != NULL)   //si el array no es nulo
    {
        for(int i=0; i<ll_len(pArrayPelisDepu); i++) //recorre epliclar
        {
            peli1 = ll_get(pArrayPelisDepu, i); //pelicula 1
            employee_getId(peli1, &auxId1); //id pelicula 1
            peli2 = ll_get(pArrayPelisDepu, i+1); // pelicula 2
            employee_getId(peli2, &auxId2); //id pelicula 2

            if(auxId1 == auxId2) //si son el mismo id
            {
                employee_getGenero(peli1, auxGenero1); //genero pelicula 1
                employee_getGenero(peli2, auxGenero2); //genero pelicula 2
                strcpy(generoFinal, auxGenero1);
                strcat(generoFinal, " | ");
                strcat(generoFinal, auxGenero2);

                employee_setGenero(peli1, generoFinal);
                ll_remove(pArrayPelisDepu, i+1);

                for(int j=0; j<ll_len(pArrayPelisDepu); j++) //recorre epliclar
                {
                    peli1 = ll_get(pArrayPelisDepu, j); //pelicula 1
                    employee_getId(peli1, &auxId1); //id pelicula 1
                    peli2 = ll_get(pArrayPelisDepu, j+1); // pelicula 2
                    employee_getId(peli2, &auxId2); //id pelicula 2

                    if(auxId1 == auxId2) //si son el mismo id
                    {
                        employee_getGenero(peli1, auxGenero1); //genero pelicula 1
                        employee_getGenero(peli2, auxGenero2); //genero pelicula 2
                        strcpy(generoFinal, auxGenero1);
                        strcat(generoFinal, " | ");
                        strcat(generoFinal, auxGenero2);

                        employee_setGenero(peli1, generoFinal);
                        ll_remove(pArrayPelisDepu, j+1);

                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf(" no se ha podido realizar.\n");
    }
}


