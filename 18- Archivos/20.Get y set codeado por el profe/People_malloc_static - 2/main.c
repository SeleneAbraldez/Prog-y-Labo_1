#include <stdio.h>
#include <stdlib.h>
#include "Person.h"


int main()
{
    /**/
    Person personas[10];
    int r,i;
    //Person* personArray[50];
    //printf("LLEGA1");
    r = parseData("datos.csv", personas);
    //printf("LLEGA2");
    for(i=0; i<r; i++)
        printf("id:%d nombre:%s apellido:%s edad:%d\n", personas[i].id, personas[i].name, personas[i].lastName, personas[i].age);

    exit(EXIT_SUCCESS);
    /**/

    //Person* personArray[50];
    //int i;

    /*for(i = 0; i < 10; i++)
    {
        personArray[i] = person_new(i,i);
    }

    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i-4);
    }
    for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
    }*/
    scanf(" ");
    return 0;
}


/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S_Persona
{
    int id;
    char nombre[32];
    char apellido[32];
    int edad;
};

typedef struct S_Persona Persona;




int main(void){
    Persona personas[8];
    int r,i;

    r = parseData("datos.csv",personas,8);

    for(i=0; i<r; i++)
        printf("id:%d nombre:%s apellido:%s edad:%d\n", personas[i].id, personas[i].nombre, personas[i].apellido, personas[i].edad);

    exit(EXIT_SUCCESS);
}

int parseData(char* fileName,Persona* arrayPersonas, int len){
    FILE *pFile;
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    pFile = fopen(fileName,"r");

    if(pFile == NULL){
        return -1;
    }

    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            arrayPersonas[i].id = atoi(var1);
            strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
            strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
            arrayPersonas[i].edad = atoi(var4);
            i++;
        }
        else
            break;
    }while(!feof(pFile) && i<len);

    fclose(pFile);

    return i;
}


*/
