#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"



static void initialize(Person* this, int age, int something);

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Person* person_new (int id, char *name, char *lastName, int age)
{
    Person* this = malloc(sizeof(Person));
    if(this != NULL)
        initialize(this, id, age);

    return this;
}

/*
Person* person_new (int age, int something)
{
    Person* this = malloc(sizeof(Person));
    if(this != NULL)
        initialize(this,age,something);

    return this;
}
*/

/** \brief  Inicializa a una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return void
 *
 */


static void initialize(Person* this, int age, int something)
{
    this->age = age;
    this->id = something;
}


/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Person* this, int age)
{
    if(age > 0)
        this->age = age;
}

void person_setId(Person* this, int id)
{
    if(id > 0)
        this->id = id;
}

void person_setName(Person* this, char *name)
{
    if(name[0] != '\0')
        strncpy(this->name, name, sizeof(this->name));
}

void person_setLastName(Person* this, char *lastName)
{
    if(lastName[0] != '\0')
        strncpy(this->lastName, lastName, sizeof(this->lastName));
}

/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Person* this)
{
    return this->age;
}


/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Person * this) {
    // Do any other freeing required here.
    free(this);
}

int parseData( char* fileName, Person* arrayPersonas ){
    FILE *pFile;
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    int ageAux;
    int idAux;
    char nameAux[50];
    char lastNameAux[50];

    //Person arrayPersonas[10];

    pFile = fopen(fileName,"r");

    if(pFile == NULL){
        return -1;
    }
    //leo los titulos
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do{
            //printf("LLEGA2");
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            //initialize(&arrayPersonas[i], int, int);

            arrayPersonas[i].id = atoi(var1);
            strncpy(arrayPersonas[i].name,var2,sizeof(arrayPersonas[i].name));
            strncpy(arrayPersonas[i].lastName,var3,sizeof(arrayPersonas[i].lastName));
            arrayPersonas[i].age = atoi(var4);

            /* idAux = atoi(var1);
            person_setId(&arrayPersonas[i], idAux);

            person_setName(&arrayPersonas[i], var2);

            person_setLastName(&arrayPersonas[i], var3);

            ageAux = atoi(var4);
            person_setAge(&arrayPersonas[i], ageAux); */

            i++;
        }
        else
            break;
    }while( !feof(pFile) && i< 10 );

    fclose(pFile);

    return i;
}

/*
int parseData( char* fileName, Persona* arrayPersonas ){
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
    }while( !feof(pFile) );

    fclose(pFile);

    return i;
}
*/
