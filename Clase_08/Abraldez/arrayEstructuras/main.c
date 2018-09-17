#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 7

typedef struct{
int legajo;
char nombre[20];
char sexo;
float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);
void mostrarEmpleados(eEmpleado lista[], int tam);
void ordenarEmpleados(eEmpleado lista[], int tam);

int main()
{
  eEmpleado empleados[]={
  {1234, "Juan", 'm', 12300},
  {2321, "Luisa", 'f',14700},
  {2122, "Ariel", 'm', 11300},
  {3423, "Laura", 'f',15600},
  {6753, "Hugo", 'm', 10800},
  {8812, "Maria", 'f',12300},
  {9823, "Oscar", 'm', 16500}
  };
   /*for(int i=0; i < TAM; i++){

   printf("Ingrese legajo: ");
   scanf("%d",&empleados[i].legajo);

   printf("Ingrese nombre: ");
   fflush(stdin);
   gets(empleados[i].nombre);

   printf("Ingrese sexo: ");
   fflush(stdin);
   scanf("%c",&empleados[i].sexo);

   printf("Ingrese sueldo: ");
   scanf("%f",&empleados[i].sueldo);

  }*/

  mostrarEmpleados(empleados, TAM);

  ordenarEmpleados(empleados, TAM);

mostrarEmpleados(empleados, TAM);

    return 0;
}

void mostrarEmpleado(eEmpleado employee){

     printf("  %4d %10s   %2c   %5.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);

}

void mostrarEmpleados(eEmpleado lista[], int tam){


printf(" Legajo    Nombre  Sexo   Sueldo\n\n");
for(int i=0; i < tam; i++){
        mostrarEmpleado(lista[i]);
}

printf("\n\n");
}

void ordenarEmpleados(eEmpleado lista[], int tam){

    eEmpleado auxEmpleado;

    for(int i=0; i < tam-1; i++){
        for(int j= i+1; j< tam; j++){

            if( lista[i].sexo > lista[j].sexo){
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }else if( lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre, lista[j].nombre) > 0){
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }


}





