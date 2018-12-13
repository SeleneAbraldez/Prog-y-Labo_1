#ifndef Abono_H_INCLUDED
#define Abotno_H_INCLUDED
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

#endif
