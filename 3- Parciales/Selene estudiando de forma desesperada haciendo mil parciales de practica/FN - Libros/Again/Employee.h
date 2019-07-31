#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    float precio;
    int editorialId;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* editorialIdStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setTitulo(Employee* this,char* titulo);
int employee_getTitulo(Employee* this,char* titulo);

int employee_setAutor(Employee* this,char* autor);
int employee_getAutor(Employee* this,char* autor);

int employee_setPrecio(Employee* this,float precio);
int employee_getPrecio(Employee* this,float* precio);

int employee_setEditorialId(Employee* this,int editorialId);
int employee_getEditorialId(Employee* this,int* editorialId);

int employeeSortByEditorialId(void* empleadoA, void* empleadoB);

//
//int employeeSortById(void* empleadoA, void* empleadoB);
//int employeeSortByGenero(void* empleadoA, void* empleadoB);
////int employeeSortByHours(void* empleadoA, void* empleadoB);
////int employeeSortBySalary(void* empleadoA, void* empleadoB);
////
////int employeeFilterHours(void* p);
////int employeeFilterId(void* p);
//int employeeFilterGeneroAccion(void* p);
//int employeeFilterGeneroAnimacion(void* p);
//int employeeFilterGeneroAventura(void* p);
//int employeeFilterGeneroCienciaFiccion(void* p);
//int employeeFilterGeneroComedia(void* p);
//int employeeFilterGeneroDrama(void* p);
//int employeeFilterGeneroFamiliar(void* p);
//int employeeFilterGeneroFantasia(void* p);
//int employeeFilterGeneroInfantil(void* p);
//
//void depurarPeliculas (LinkedList* pArrayListPeliculas);
//
int employeeMapPrecios(void* p);

#endif // employee_H_INCLUDED
