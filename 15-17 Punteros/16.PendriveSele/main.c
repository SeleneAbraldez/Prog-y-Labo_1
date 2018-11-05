#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
}ePendrive;

int cargarPendrive(ePendrive* pen);
void mostrarPendrive(ePendrive* pen);
int cargarPendriveParam(ePendrive* pen, int cod, char marc[], int cap, float prec);

int main()
{
    ePendrive usb;
    ePendrive usb2;
    ePendrive usb3;

    printf("\t Por puntero: \n\n");
    if(cargarPendrive(&usb) == 0){
        mostrarPendrive(&usb);
    }else{
        printf("\n!! - Error. ");
    }

    printf("\n\n\t Por parametro, por si es necesario hardcodear o para datos almacenados: ");
    if(cargarPendriveParam(&usb2, 222, "Peg", 16, 550) == 0){
        mostrarPendrive(&usb2);
    }else{
        printf("\n!! - Error. ");
    }
    if(cargarPendriveParam(&usb3, 333, "KNG", 8, 200) == 0){
        mostrarPendrive(&usb3);
    }else{
        printf("\n!! - Error. ");
    }

    return 0;
}

int cargarPendriveParam(ePendrive* pen, int cod, char marc[], int cap, float prec){
    int ret = 0;

    if(pen != NULL){
        pen->codigo = cod;
        strcpy(pen->marca, marc);
        pen->capacidad = cap;
        pen->precio = prec;
    }

    return ret;
}

int cargarPendrive(ePendrive* pen){
    int ret = -1;

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

        ret = 0;
    }
    return ret;
}

void mostrarPendrive(ePendrive* pen){
    if(pen != NULL){
        printf("\nCodigo: %d - Marca: %s - Capacidad: %d - Precio: %.2f \n", pen->codigo, pen->marca, pen->capacidad, pen->precio);
    }else{
        printf("\n!!- Datos vacios. ");
    }
}
