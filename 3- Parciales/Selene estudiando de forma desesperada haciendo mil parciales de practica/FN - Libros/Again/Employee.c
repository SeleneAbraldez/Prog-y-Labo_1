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
        strcpy(this->titulo, " ");
        strcpy(this->autor, " ");
        this->precio = 0;
        this->editorialId = 0;
    }
    return this;
}

static void initializeStr(Employee* this, char *var1, char *var2, char *var3, char *var4, char *var5)   //inicializo todos los parametros, de forma string
{
    int id, editorialId;
    float precio;

    id = atoi(var1);
    precio = atof(var4);
    editorialId = atoi(var5);

    employee_setId(this, id);
    employee_setTitulo(this, var2);
    employee_setAutor(this, var3);
    employee_setPrecio(this, precio);
    employee_setEditorialId(this, editorialId);
}

Employee* employee_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* editorialIdStr)
{
    Employee* this;
    this = employee_new();
    if(this != NULL)
        initializeStr(this, idStr, tituloStr, autorStr, precioStr, editorialIdStr);
    return this;
}


int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    if(this != NULL)
    {
        *id = this->id;
        return 0;
    }
    else
        return -1;
}


int employee_setTitulo(Employee* this,char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo[0] != '\0')
    {
        strncpy(this->titulo, titulo, sizeof(this->titulo));
        retorno = 0;
    }
    return retorno;
}
int employee_getTitulo(Employee* this,char* titulo)
{
    if(this != NULL)
    {
        strcpy(titulo, this->titulo);
        return 0;
    }
    else
    {
        return -1;
    }
}


int employee_setAutor(Employee* this,char* autor)
{
    int retorno = -1;
    if(this != NULL && autor[0] != '\0')
    {
        strncpy(this->autor, autor, sizeof(this->autor));
        retorno = 0;
    }
    return retorno;
}
int employee_getAutor(Employee* this,char* autor)
{
    if(this != NULL)
    {
        strcpy(autor, this->autor);
        return 0;
    }
    else
    {
        return -1;
    }
}


int employee_setPrecio(Employee* this,float precio)
{
    int retorno = -1;
    if(this != NULL && precio > 0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}
int employee_getPrecio(Employee* this,float* precio)
{
    if(this != NULL)
    {
        *precio = this->precio;
        return 0;
    }
    else
        return -1;
}


int employee_setEditorialId(Employee* this,int editorialId)
{
    int retorno = -1;
    if(this != NULL && editorialId > 0)
    {
        this->editorialId = editorialId;
        retorno = 0;
    }
    return retorno;
}
int employee_getEditorialId(Employee* this,int* editorialId)
{
    if(this != NULL)
    {
        *editorialId = this->editorialId;
        return 0;
    }
    else
        return -1;
}




int employeeSortByEditorialId(void* empleadoA, void* empleadoB)
{
    int retorno = -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL)
    {
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        if((empA->editorialId)<(empB->editorialId))
        {
            retorno = 1 ;
        }
        else if((empA->editorialId)>(empB->editorialId))
        {
            retorno = -1 ;
        }
        else if((empA->editorialId)==(empB->editorialId))
        {
            retorno = 0;
        }
    }
    return retorno;
}

//int employeeFilterGeneroAccion(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Accion") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//int employeeFilterGeneroAnimacion(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Animacion") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//int employeeFilterGeneroAventura(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Aventura") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//int employeeFilterGeneroCienciaFiccion(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Ciencia ficcion") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//int employeeFilterGeneroComedia(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Comedia") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//int employeeFilterGeneroDrama(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Drama") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//int employeeFilterGeneroFamiliar(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Familiar") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//int employeeFilterGeneroFantasia(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Fantasia") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//int employeeFilterGeneroInfantil(void* p)
//{
//    int retorno = 0;
//    Employee* empl;
//
//    if(p != NULL)
//    {
//        empl = (Employee*) p;
//        if(strcmp(empl->genero, "Infantil") == 0)
//        {
//            retorno = 1;
//        }
//    }
//    return retorno;
//}
//
//
//int employeeSortByGenero(void* empleadoA, void* empleadoB)
//{
//    int retorno = -1;
//    Employee* empA;
//    Employee* empB;
//
//    if(empleadoA !=NULL && empleadoB !=NULL)
//    {
//        empA = (Employee*) empleadoA;
//        empB = (Employee*) empleadoB;
//        retorno = strcmp(empB->genero, empA->genero);
//    }
//
//    return retorno;
//}
//
//
////int employeeSortByName(void* empleadoA, void* empleadoB){
////    int retorno = -1;
////    Employee* empA;
////    Employee* empB;
////
////    if(empleadoA !=NULL && empleadoB !=NULL){
////        empA = (Employee*) empleadoA;
////        empB = (Employee*) empleadoB;
////        retorno = strcmp(empB->nombre, empA->nombre);
////    }
////
////    return retorno;
////}
////
////int employeeSortByHours(void* empleadoA, void* empleadoB){
////    int retorno = -1;
////    Employee* empA;
////    Employee* empB;
////
////    if(empleadoA !=NULL && empleadoB !=NULL){
////        empA = (Employee*) empleadoA;
////        empB = (Employee*) empleadoB;
////                if((empA->horasTrabajadas)<(empB->horasTrabajadas)){
////            retorno = 1 ;
////        }else if((empA->horasTrabajadas)>(empB->horasTrabajadas)){
////            retorno = -1 ;
////        }else if((empA->horasTrabajadas)==(empB->horasTrabajadas)){
////            retorno = 0;
////        }
////    }
////    return retorno;
////}
////
////int employeeSortBySalary(void* empleadoA, void* empleadoB){
////    int retorno = -1;
////    Employee* empA;
////    Employee* empB;
////
////    if(empleadoA !=NULL && empleadoB !=NULL){
////        empA = (Employee*) empleadoA;
////        empB = (Employee*) empleadoB;
////        if((empA->sueldo)<(empB->sueldo)){
////            retorno = 1 ;
////        }else if((empA->sueldo)>(empB->sueldo)){
////            retorno = -1 ;
////        }else if((empA->sueldo)==(empB->sueldo)){
////            retorno = 0;
////        }
////    }
////    return retorno;
////}
////
////int employeeFilterHours(void* p){
////  int retorno = 0;
////  Employee* empl;
////  if(p != NULL){
////    empl = (Employee*) p;
////    if(empl->horasTrabajadas > 150){
////      retorno = 1;
////    }
////  }
////  return retorno;
////}
////
////int employeeFilterId(void* p){
////  int retorno = 0;
////  Employee* empl;
////  if(p != NULL){
////    empl = (Employee*) p;
////    if(empl->id < 11){
////      retorno = 1;
////    }
////  }
////  return retorno;
////}
////
////int employeeFilterName(void* p){
////  int retorno = 0;
////  Employee* empl;
////  if(p != NULL){
////    empl = (Employee*) p;
////    if(strcmp(empl->nombre,"H")>=0){
////      retorno = 1;
////    }
////  }
////  return retorno;
////}
////
////
////
int employeeMapPrecios(void* p)
{
  int retorno = -1;
  float precioDesc;
  float precio;
  int editorialId;

  Employee* empl;

  if(p != NULL){
    empl = (Employee*) p;
    employee_getEditorialId(empl, &editorialId);
    employee_getPrecio(empl, &precioDesc);
    employee_getPrecio(empl, &precio);
    if(editorialId == 1){
      precioDesc = (float)precio - (float)((precio)*0.20);
    }else if(editorialId == 2){
      precioDesc = (float)precio - (float)((precio)*0.10);
    }
    employee_setPrecio(empl, precioDesc);
    retorno = 0;
  }
  return retorno;

}

//void depurarPeliculas (LinkedList* pArrayPelisDepu)
//{
//    LinkedList* pArrayPelisDepuNew = ll_newLinkedList();
//
//    Employee* peli1;
//    Employee* peli2;
//    Employee* peli;
//
//    int auxId1, auxId2;
//    char auxGenero1[30], auxGenero2[30];
//    char idStr[30], anioStr[50];
//    char generoFinal[90];
//    int optionYN;
//
//    if(pArrayPelisDepu != NULL)   //si el array no es nulo
//    {
//        for(int i=0; i<ll_len(pArrayPelisDepu); i++) //recorre epliclar
//        {
//            peli1 = ll_get(pArrayPelisDepu, i); //pelicula 1
//            employee_getId(peli1, &auxId1); //id pelicula 1
//            peli2 = ll_get(pArrayPelisDepu, i+1); // pelicula 2
//            employee_getId(peli2, &auxId2); //id pelicula 2
//
//            if(auxId1 == auxId2) //si son el mismo id
//            {
//                employee_getGenero(peli1, auxGenero1); //genero pelicula 1
//                employee_getGenero(peli2, auxGenero2); //genero pelicula 2
//                strcpy(generoFinal, auxGenero1);
//                strcat(generoFinal, " | ");
//                strcat(generoFinal, auxGenero2);
//
//                employee_setGenero(peli1, generoFinal);
//                ll_remove(pArrayPelisDepu, i+1);
//
////                itoa(peli1->id, idStr, 10);
////                itoa(peli1->anio, anioStr, 10);
////                peli = employee_newParametros(idStr, peli1->nombre, anioStr, generoFinal);
////                ll_add(pArrayPelisDepuNew, peli);
//
//                for(int j=0; j<ll_len(pArrayPelisDepu); j++) //recorre epliclar
//                {
//                    peli1 = ll_get(pArrayPelisDepu, j); //pelicula 1
//                    employee_getId(peli1, &auxId1); //id pelicula 1
//                    peli2 = ll_get(pArrayPelisDepu, j+1); // pelicula 2
//                    employee_getId(peli2, &auxId2); //id pelicula 2
//
//                    if(auxId1 == auxId2) //si son el mismo id
//                    {
//                        employee_getGenero(peli1, auxGenero1); //genero pelicula 1
//                        employee_getGenero(peli2, auxGenero2); //genero pelicula 2
//                        strcpy(generoFinal, auxGenero1);
//                        strcat(generoFinal, " | ");
//                        strcat(generoFinal, auxGenero2);
//
//                        employee_setGenero(peli1, generoFinal);
//                        ll_remove(pArrayPelisDepu, j+1);
////
////                        itoa(peli1->id, idStr, 10);
////                        itoa(peli1->anio, anioStr, 10);
////                        peli = employee_newParametros(idStr, peli1->nombre, anioStr, generoFinal);
////                        ll_add(pArrayPelisDepuNew, peli);
////                        ll_remove(pArrayPelisDepuNew, j);
//                        break;
//                    }
//                }
//            }
//        }
//
//
//        if(ll_len(pArrayPelisDepuNew)>0)
//        {
//            controller_ListEmployee(pArrayPelisDepuNew);
//            optionYN = getValidYesNoChar("Desea guardar la lista depurada en 'depurada.csv?' y/n: ", "Caracter no valido. ");
//            if(optionYN == 'y')
//            {
//                controller_saveAsText("depurada.csv", pArrayPelisDepuNew);
//            }
//            else
//            {
//                printf("Saliendo sin guardar. \n");
//            }
//        }
//        else
//        {
//            printf(" ha resultado con 0 peliculas. \n");
//        }
//    }
//    else
//    {
//        printf(" no se ha podido realizar.\n");
//    }
//}
//
//
