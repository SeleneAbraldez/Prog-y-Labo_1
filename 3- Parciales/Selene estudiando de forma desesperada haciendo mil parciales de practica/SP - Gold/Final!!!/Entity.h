#ifndef entity_H_INCLUDED
#define entity_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float importe;
}eEntity;

eEntity* entity_new();
eEntity* entity_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr);
void entity_delete();

int entity_setId(eEntity* this,int id);
int entity_getId(eEntity* this,int* id);

int entity_setTipo(eEntity* this,char* tipo);
int entity_getTipo(eEntity* this,char* tipo);

int entity_setCantidad(eEntity* this,int cantidad);
int entity_getCantidad(eEntity* this,int* cantidad);

int entity_setImporte(eEntity* this,float importe);
int entity_getImporte(eEntity* this,float* importe);

int entityVentasTotales(void* p);
int entityGold(void* p);
int entityRegular(void* p);
int entityPlus(void* p);
int entityBultosTotales(void* p);
float entityImportesTotales(void* p);

int entitySortById(void* entityA, void* entityB);
int entitySortByName(void* entityA, void* entityB);
int entitySortByHours(void* entityA, void* entityB);
int entitySortBySalary(void* entityA, void* entityB);

int entityFilterHours(void* p);
int entityFilterId(void* p);
int entityFilterName(void* p);

int entityMapSalary(void* p);

#endif // entity_H_INCLUDED
