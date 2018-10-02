#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ // debe estar antes proque esta anidado
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
    eFecha fechaIngreso; //anidado y definido
}eEmpleado;



int main()
{
    eEmpleado unEmpleado;
    eEmpleado otroEmpleado;
    // si se quiere hardcodear, al definir la fecha de unEmpleado fecha de deberia poner entre llaves {32/576/567}

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 10000.5;
    unEmpleado.fechaIngreso.dia = 23;
    unEmpleado.fechaIngreso.mes = 7;
    unEmpleado.fechaIngreso.anio = 1967;

    //se podria haber cargafo unaFecha y luego igualas dentro de unEmpleado como
        //unEmpleado fechaIngreso = unaFecha;

    mostrarEmpelado(unEmpleado);
    mostrarFecha(unEmpleado);

    return 0;
}

void mostrarEmpelado (eEmpleado empleado){
    printf("%d  %s  %c  %.2f \t", empleado.legajo, empleado.nombre, empleado.sexo, empleado.sueldo);
}

void mostrarFecha (eEmpleado empleado){
    printf(" %02d/%0d/%4d \n", empleado.fechaIngreso.dia, empleado.fechaIngreso.mes, empleado.fechaIngreso.anio);
}
