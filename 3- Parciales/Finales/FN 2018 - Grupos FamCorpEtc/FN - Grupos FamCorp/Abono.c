#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Abono.h"

eAbono* abono_new(){
    eAbono* this = malloc(sizeof(eAbono));
    if(this != NULL){
        this->id = 0;
        strcpy(this->tipo, "0");
        this->idCliente = 0;
        this->importeFinal = 0;
    }
    return this;
}

static void initializeAbonoStr(eAbono* this, char *var1, char *var2, char *var3, char *var4)   //inicializo todos los parametros
{
    int id, idCliente;
    float importeFinal;

    id = atoi(var1);
    idCliente = atoi(var3);
    importeFinal = atof(var4);

    abono_setId(this, id);
    abono_setTipo(this, var2);
    abono_setIdCliente(this, idCliente);
    abono_setImporteFinal(this, importeFinal);
}

eAbono* abono_newParametros(char* idStr,char* tipoStr,char* idClienteStr ,char* importeFinalStr){
    eAbono* this;
    this = abono_new();
    if(this != NULL){
       initializeAbonoStr(this, idStr, tipoStr, idClienteStr, importeFinalStr);
    }
    return this;
}


int abono_setId(eAbono* this,int id){
    int retorno = -1;
    if(this != NULL && id > 0){
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int abono_getId(eAbono* this,int* id){
    if(this != NULL){
        *id = this->id;
        return 0;
    }else
        return -1;
}

int abono_setTipo(eAbono* this,char* tipo){
    int retorno = -1;
    if(this != NULL && tipo[0] != '\0'){
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}
int abono_getTipo(eAbono* this,char* tipo){
    if(this != NULL){
        strcpy(this->tipo, tipo);
        return 0;
    }else
        return -1;
}

int abono_setIdCliente(eAbono* this,int idCliente){
    int retorno = -1;
    if(this != NULL && idCliente > 0){
        this->idCliente = idCliente;
        retorno = 0;
    }
    return retorno;
}
int abono_getIdCliente(eAbono* this,int* idCliente){
    if(this != NULL){
        *idCliente = this->idCliente;
        return 0;
    }else
        return -1;
}


int abono_setImporteFinal(eAbono* this,float importeFinal){
    int retorno = -1;
    if(this != NULL && importeFinal > 0){
        this->importeFinal = importeFinal;
        retorno = 0;
    }
    return retorno;
}

int abono_getImporteFinal(eAbono* this,float* importeFinal){
    if(this != NULL){
        *importeFinal = this->importeFinal;
        return  0;
    }else
        return -1;
}

