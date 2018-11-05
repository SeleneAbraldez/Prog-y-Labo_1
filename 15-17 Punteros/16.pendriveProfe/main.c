#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
}ePendrive;


int cargarPendrive(ePendrive* pen);
void mostrarPendrive(ePendrive* pen);
int cargarPendriveParam(ePendrive* pen, int codigo, char marca[], int cap, float precio);
 ePendrive* new_Pendrive();


int main()
{

  //  ePendrive pendrive;
   // ePendrive pen2;
  // ePendrive pen3;

  //  cargarPendriveParam(&pen2, 1122, "PNY", 16, 430);
  //  cargarPendriveParam(&pen3, 1134, "Sorny", 32, 150);

  //  mostrarPendrive(&pen2);
  //  mostrarPendrive(&pen3);


    ePendrive* miPendrive = new_PendriveParam(1111, "Kingston", 32, 560);

    mostrarPendrive(miPendrive);





    return 0;

}

int cargarPendrive(ePendrive* pen){

    int todoOk = 0;

    if(pen != NULL){

        printf("Ingrese codigo: ");
        scanf("%d", &pen->codigo);

        printf("Ingrese marca: ");
        fflush(stdin);
        gets(pen->marca);

        printf("Ingrese capacidad: ");
        scanf("%d", &pen->capacidad);

        printf("Ingrese precio: ");
        scanf("%f", &pen->precio);

        todoOk = 1;
    }
    return todoOk;
}


int cargarPendriveParam(ePendrive* pen, int codigo, char marca[], int cap, float precio){

 int todoOk = 0;

    if(pen != NULL){

            pen->codigo = codigo;
            strcpy(pen->marca, marca);
            pen->capacidad = cap;
            pen->precio = precio;

            todoOk = 1;
    }

    return todoOk;
}

void mostrarPendrive(ePendrive* pen){

 if( pen != NULL){
    printf("%d  %s  %d  %.2f\n", pen->codigo, pen->marca, pen->capacidad, pen->precio);

  }
 }


 ePendrive* new_Pendrive(){

     ePendrive* nuevoPendrive;

     nuevoPendrive = (ePendrive*) malloc(sizeof(ePendrive));

     if(nuevoPendrive != NULL){
        nuevoPendrive->codigo = 0;
        strcpy(nuevoPendrive->marca, "");
       nuevoPendrive->capacidad = 0;
       nuevoPendrive->precio = 0;
     }

 return nuevoPendrive;

 }
