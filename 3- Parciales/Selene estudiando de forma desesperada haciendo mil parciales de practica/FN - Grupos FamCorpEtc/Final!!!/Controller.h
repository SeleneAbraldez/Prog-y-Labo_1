int controller_loadFromText(char* path , LinkedList* pArrayListEntity);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntity);
int controller_addEntity(LinkedList* pArrayListEntity);
int controller_editEntity(LinkedList* pArrayListEntity);
int controller_removeEntity(LinkedList* pArrayListEntity);
int controller_ListEntitysclientes(LinkedList* pArrayListEntity);
int controller_sortEntity(LinkedList* pArrayListEntity);
int controller_filterEntity(LinkedList* pArrayListEntity);
int controller_mapEntity(LinkedList* pArrayListEntity);
int controller_saveAsText(char* path , LinkedList* pArrayListEntity);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntity);
int controller_menu();

int controller_ListEntitysAbono(LinkedList* pArrayListAbono, LinkedList* pArrayListClientes);


