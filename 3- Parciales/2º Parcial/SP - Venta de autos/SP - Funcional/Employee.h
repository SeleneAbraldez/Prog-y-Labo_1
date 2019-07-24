#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char fecha[15];
    char codigo[128];
    int cantidad;
    float precio;
    char cuit[128];
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* fechaStr, char* codigoStr, char* cantidadStr, char* precioStr, char* cuitStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setFecha(Employee* this, char* fecha);
int employee_getFecha(Employee* this,char* fecha);

int employee_setCodigo(Employee* this,char* codigo);
int employee_getCodigo(Employee* this,char* codigo);

int employee_setCantidad(Employee* this,int cantidad);
int employee_getCantidad(Employee* this,int* cantidad);

int employee_setPrecio(Employee* this, float precio);
int employee_getPrecio(Employee* this, float* precio);

int employee_setCuit(Employee* this,char* cuit);
int employee_getCuit(Employee* this,char* cuit);




int employeeSortById(void* empleadoA, void* empleadoB);
int employeeSortByName(void* empleadoA, void* empleadoB);
int employeeSortByHours(void* empleadoA, void* empleadoB);
int employeeSortBySalary(void* empleadoA, void* empleadoB);

int employeeFilterHours(void* p);
int employeeFilterId(void* p);
int employeeFilterName(void* p);

int employeeMapSalary(void* p);


int employeeVentasTotales(void* p);
int employeeMayores100000(void* p);
int employeeMayores300000(void* p);
int employeeVentasFord(void* p);

#endif // employee_H_INCLUDED
