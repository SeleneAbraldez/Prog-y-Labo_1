#ifndef reglasNegocio_H_INCLUDED
#define reglasNegocio_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char sexo[2];
    char numeroTelefono[21];
    float importe;
}Employee;

typedef struct
{
    int id;
    char tipo[15];
    int idCliente;
    float importeFinal;
}eAbono;


eAbono* abono_new();
eAbono* abono_newParametros(char* idStr,char* tipoStr,char* idClienteStr ,char* importeFStr);
void abono_delete();

int abono_setId(eAbono* this,int id);
int abono_getId(eAbono* this,int* id);

int abono_setTipo(eAbono* this,char* tipo);
int abono_getTipo(eAbono* this,char* tipo);

int abono_setIdCliente(eAbono* this,int idCliente);
int abono_getIdCliente(eAbono* this,int* idCliente);

int abono_setImporteFinal(eAbono* this,float importeF);
int abono_getImporteFinal(eAbono* this,float* importeF);



Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* sexoStr ,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();



int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setSexo(Employee* this,char* sexo);
int employee_getSexo(Employee* this,char* sexo);

int employee_setNumeroTelefono(Employee* this,char* numeroTelefono);
int employee_getNumeroTelefono(Employee* this,char* numeroTelefono);

int employee_setImporte(Employee* this,float importe);
int employee_getImporte(Employee* this,float* importe);


int employeeSortById(void* empleadoA, void* empleadoB);
int employeeSortByName(void* empleadoA, void* empleadoB);
int employeeSortByHours(void* empleadoA, void* empleadoB);
int employeeSortBySalary(void* empleadoA, void* empleadoB);

int employeeFilterHours(void* p);
int employeeFilterId(void* p);
int employeeFilterName(void* p);

int employeeMapSalary(void* p);



#endif

