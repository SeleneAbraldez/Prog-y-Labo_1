#ifndef entity_H_INCLUDED
#define entity_H_INCLUDED
typedef struct
{
    int id;
    char fecha[12];
    char codigo[128];
    int cantidad;
    float precio;
    char cuit[128];
}eEntity;

eEntity* entity_new();
eEntity* entity_newParametros(char* idStr,char* fechaStr,char* codigoStr, char* cantidadStr, char* precioStr, char* cuitStr);
void entity_delete();

int entity_setId(eEntity* this,int id);
int entity_getId(eEntity* this,int* id);

int entity_setFecha(eEntity* this,char* fecha);
int entity_getFecha(eEntity* this,char* fecha);

int entity_setCodigo(eEntity* this,char* codigo);
int entity_getCodigo(eEntity* this,char* codigo);

int entity_setCantidad(eEntity* this,int cantidad);
int entity_getCantidad(eEntity* this,int* cantidad);

int entity_setPrecio(eEntity* this,float precio);
int entity_getPrecio(eEntity* this,float* precio);

int entity_setCuit(eEntity* this,char* cuit);
int entity_getCuit(eEntity* this,char* cuit);


//int entitySortById(void* entityA, void* entityB);
//int entitySortByName(void* entityA, void* entityB);
//int entitySortByHours(void* entityA, void* entityB);
//int entitySortBySalary(void* entityA, void* entityB);
//
//int entityFilterHours(void* p);
//int entityFilterId(void* p);
//int entityFilterName(void* p);

int entityVentasTotales(void* p);
int entityMayores100000(void* p);
int entityMayores300000(void* p);
int entityVentasFord(void* p);


//int entityMapSalary(void* p);

#endif // entity_H_INCLUDED
