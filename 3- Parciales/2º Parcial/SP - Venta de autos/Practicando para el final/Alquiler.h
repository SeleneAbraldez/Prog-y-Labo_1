#ifndef Alquiler_H_INCLUDED
#define Alquiler_H_INCLUDED
typedef struct
{
    int id;
    char fecha[14];
    char nombre[128];
    int cantidad;
    float precio;
    float cuit;
}eAlquiler;

eAlquiler* alquiler_new();
eAlquiler* alquiler_newParametros(char* idStr, char* fechaStr, char* nombreStr, char* cantidadStr, char* precioStr, char* cuitStr);
void alquiler_delete();

int alquiler_setId(eAlquiler* this,int id);
int alquiler_getId(eAlquiler* this,int* id);

int alquiler_setFecha(eAlquiler* this,char* fecha);
int alquiler_getFecha(eAlquiler* this,char* fecha);

int alquiler_setNombre(eAlquiler* this,char* nombre);
int alquiler_getNombre(eAlquiler* this,char* nombre);

int alquiler_setCantidad(eAlquiler* this,int cantidad);
int alquiler_getCantidad(eAlquiler* this,int* cantidad);

int alquiler_setPrecio(eAlquiler* this,float precio);
int alquiler_getPrecio(eAlquiler* this,float* precio);

int alquiler_setCuit(eAlquiler* this,float cuit);
int alquiler_getCuit(eAlquiler* this,float* cuit);

/*
int alquilerSortById(void* empleadoA, void* empleadoB);
int alquilerSortByName(void* empleadoA, void* empleadoB);
int alquilerSortByHours(void* empleadoA, void* empleadoB);
int alquilerSortBySalary(void* empleadoA, void* empleadoB);

int alquilerFilterHours(void* p);
int alquilerFilterId(void* p);
int alquilerFilterName(void* p);

int alquilerMapSalary(void* p);
*/

int alquiler_VentasTotales(void* p);
int alquiler_VentasMayores100000(void* p);
int alquiler_VentasMayores300000(void* p);
int alquiler_VentasFords(void* p);
int alquiler_VentasFordsPrecio(void* p);

#endif // alquiler_H_INCLUDED
