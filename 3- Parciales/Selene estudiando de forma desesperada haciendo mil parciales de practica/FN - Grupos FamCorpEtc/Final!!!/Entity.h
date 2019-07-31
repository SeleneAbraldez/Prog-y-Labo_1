#ifndef entity_H_INCLUDED
#define entity_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char sexo[2];
    char numeroTelefono[21];
    int importe;
}eCliente;

eCliente* entity_new();
eCliente* entity_newParametros(char* idStr,char* nombreStr,char* sexoStr, char* numeroTelefono, char* importeStr);
void entity_delete();

int entity_setId(eCliente* this,int id);
int entity_getId(eCliente* this,int* id);

int entity_setNombre(eCliente* this,char* nombre);
int entity_getNombre(eCliente* this,char* nombre);

int entity_setSexo(eCliente* this,char* sexo);
int entity_getSexo(eCliente* this,char* sexo);

int entity_setNumeroTelefono(eCliente* this,char* numeroTelefono);
int entity_getNumeroTelefono(eCliente* this,char* numeroTelefono);

int entity_setImporte(eCliente* this,int importe);
int entity_getImporte(eCliente* this,int* importe);

int entitySortById(void* clienteA, void* clienteB);



typedef struct
{
    int id;
    int tipo;
    int idCliente;
    int importeFinal;
}eAbono;

eAbono* abono_new();
eAbono* abono_newParametros(char* idStr, char* tipoStr, char* idClienteStr, char* importeStr);

int abono_setId(eAbono* this,int id);
int abono_getId(eAbono* this,int* id);

int abono_setTipo(eAbono* this,int tipo);
int abono_getTipo(eAbono* this,int* tipo);

int abono_setIdCliente(eAbono* this,int idCliente);
int abono_getIdCliente(eAbono* this,int* idCliente);

int abono_setImporteFinal(eAbono* this,int importeFinal);
int abono_getImporteFinal(eAbono* this,int* importeFinal);














int entitySortById(void* entityA, void* entityB);
int entitySortByName(void* entityA, void* entityB);
int entitySortByHours(void* entityA, void* entityB);
int entitySortBySalary(void* entityA, void* entityB);

int entityFilterHours(void* p);
int entityFilterId(void* p);
int entityFilterName(void* p);

int entityMapSalary(void* p);

#endif // entity_H_INCLUDED
