#ifndef entity_H_INCLUDED
#define entity_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int calorias;
    float grasas;
    int sodio;
    int carbohidratos;
    int proteinas;
}eIngredientes;

eIngredientes* entity_new();
eIngredientes* entity_newParametros(char* idStr, char* nombreStr, char* caloriasStr, char* grasasStr, char* sodioStr, char* carbohidratosStr, char* proteinasStr);
void entity_delete();

int entity_setId(eIngredientes* this,int id);
int entity_getId(eIngredientes* this,int* id);

int entity_setNombre(eIngredientes* this,char* nombre);
int entity_getNombre(eIngredientes* this,char* nombre);

int entity_setCalorias(eIngredientes* this,int calorias);
int entity_getCalorias(eIngredientes* this,int* calorias);

int entity_setGrasas(eIngredientes* this,float grasas);
int entity_getGrasas(eIngredientes* this,float* grasas);

int entity_setSodio(eIngredientes* this,int sodio);
int entity_getSodio(eIngredientes* this,int* sodio);

int entity_setCarbohidratos(eIngredientes* this,int carbohidratos);
int entity_getCarbohidratos(eIngredientes* this,int* carbohidratos);

int entity_setProteinas(eIngredientes* this,int proteinas);
int entity_getProteinas(eIngredientes* this,int* proteinas);




typedef struct
{
    int id;
    char nombre[128];
    int idIngredientes;
    int cantidad;
}eRecetas;

eRecetas* receta_new();
eRecetas* receta_newParametros(char* idStr, char* nombreStr, char* idIngredientesStr, char* cantidadStr);
void receta_delete();

int receta_setId(eRecetas* this,int id);
int receta_getId(eRecetas* this,int* id);

int receta_setNombre(eRecetas* this,char* nombre);
int receta_getNombre(eRecetas* this,char* nombre);

int receta_setidIngredientes(eRecetas* this,int idIngredientes);
int receta_getidIngredientes(eRecetas* this,int* idIngredientes);

int receta_setCantidad(eRecetas* this,int cantidad);
int receta_getCantidad(eRecetas* this,int* cantidad);







int entitySortById(void* entityA, void* entityB);
int entitySortByName(void* entityA, void* entityB);
int entitySortByHours(void* entityA, void* entityB);
int entitySortBySalary(void* entityA, void* entityB);

int entityFilterHours(void* p);
int entityFilterId(void* p);
int entityFilterName(void* p);

int entityMapSalary(void* p);

#endif // entity_H_INCLUDED
