#ifndef entity_H_INCLUDED
#define entity_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int km;
    int tipo;
    int costoEnvio;
}eEntity;

eEntity* entity_new();
eEntity* entity_newParametros(char* idStr,char* nombreStr,char* kmStr, char* tipoStr, char* costoEnvioStr);
void entity_delete();

int entity_setId(eEntity* this,int id);
int entity_getId(eEntity* this,int* id);

int entity_setNombre(eEntity* this,char* nombre);
int entity_getNombre(eEntity* this,char* nombre);

int entity_setKm(eEntity* this,int km);
int entity_getKm(eEntity* this,int* km);

int entity_setTipo(eEntity* this,int tipo);
int entity_getTipo(eEntity* this,int* tipo);

int entity_setCostoEnvio(eEntity* this,int costoEnvio);
int entity_getCostoEnvio(eEntity* this,int* costoEnvio);

int entityMapCosto(void* p);


int entitySortById(void* entityA, void* entityB);
int entitySortByName(void* entityA, void* entityB);
int entitySortByHours(void* entityA, void* entityB);
int entitySortBySalary(void* entityA, void* entityB);

int entityFilterHours(void* p);
int entityFilterId(void* p);
int entityFilterName(void* p);

int entityMapSalary(void* p);

#endif // entity_H_INCLUDED
