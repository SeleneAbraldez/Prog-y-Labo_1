#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int anio;
    char genero[128];
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* anioStr, char* generoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setAnio(Employee* this,int anio);
int employee_getAnio(Employee* this,int* anio);

int employee_setGenero(Employee* this,char* genero);
int employee_getGenero(Employee* this,char* genero);

//
int employeeSortById(void* empleadoA, void* empleadoB);
int employeeSortByGenero(void* empleadoA, void* empleadoB);
//int employeeSortByHours(void* empleadoA, void* empleadoB);
//int employeeSortBySalary(void* empleadoA, void* empleadoB);
//
//int employeeFilterHours(void* p);
//int employeeFilterId(void* p);
int employeeFilterGeneroAccion(void* p);
int employeeFilterGeneroAnimacion(void* p);
int employeeFilterGeneroAventura(void* p);
int employeeFilterGeneroCienciaFiccion(void* p);
int employeeFilterGeneroComedia(void* p);
int employeeFilterGeneroDrama(void* p);
int employeeFilterGeneroFamiliar(void* p);
int employeeFilterGeneroFantasia(void* p);
int employeeFilterGeneroInfantil(void* p);

void depurarPeliculas (LinkedList* pArrayListPeliculas);
//
//int employeeMapSalary(void* p);

#endif // employee_H_INCLUDED
