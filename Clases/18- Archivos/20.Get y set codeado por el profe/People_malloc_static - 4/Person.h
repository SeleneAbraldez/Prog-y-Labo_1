#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED
/* typedef struct
{
    int age;
    int something;
}Person; */

typedef struct{
    int id;
    char name[32];
    char lastName[32];
    int age;
}Person;
#endif //PEOPLE_H_INCLUDED

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
/*
Person* person_new (int age, int something);
*/

Person* person_new (int id, char *name, char *lastName, int age);

/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Person* this, int age) ;

/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Person* this);

/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Person * this);

int parseData(char* fileName, Person* arrayPersonas);

char * person_getName(Person* this);

char * person_getLastName(Person* this);

int person_getId(Person* this);
