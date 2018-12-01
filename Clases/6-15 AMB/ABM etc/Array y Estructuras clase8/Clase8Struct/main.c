#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct empleado { // e para saber que es una estructura
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
}; */

typedef struct{ // nuevo tipo de dato
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
}eEmpleado; //nombint legaj, e ti`po de dato, e para estructura



int main()
{
   // struct empleado unEmpleado; //forma a
    eEmpleado otroEmpleado; //forma b, la de la cursada
    eEmpleado otroOtroEmpleado;
    eEmpleado empl3 = {2222, "Pani", 'm', 3223.6};
    eEmpleado emp4 = empl3; //se pude igualar `porque empl3 esta hardcodeado, no se podria de otra forma quedaria basura
    eEmpleado emp5;

    otroEmpleado.legajo = 1234;
    strcpy(otroEmpleado.nombre, "Juan");
    otroEmpleado.sexo = 'm';
    otroEmpleado.sueldo = 10000.5;

    otroOtroEmpleado.legajo = 1235;
    strcpy(otroOtroEmpleado.nombre, "Pepa");
    otroOtroEmpleado.sexo = 'f';
    otroOtroEmpleado.sueldo = 2000;

    printf("Ingrese legajo: ");
    scanf("%d", &emp5.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(emp5.nombre);
    printf("Ingrese sexo: ");
    scanf("%c", &emp5.sexo);
    printf("Ingrese sueldo: ");
    scanf("%f", &emp5.sueldo); //OJO! error era que en scan NO SE USA EL .2f SOLO en printf



    mostrarEmpelado(otroEmpleado);
    mostrarEmpelado(otroOtroEmpleado);
    mostrarEmpelado(empl3);
    mostrarEmpelado(emp4);
    mostrarEmpelado(emp5);

    return 0;
}

void mostrarEmpelado (eEmpleado empleado){
    printf("%d  %s  %c  %.2f \n", empleado.legajo, empleado.nombre, empleado.sexo, empleado.sueldo);
}
