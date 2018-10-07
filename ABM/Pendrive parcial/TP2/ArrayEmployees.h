#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;


/** \brief To print the menu
 * \return Option
 *
 */
int menu(void);

/** \brief To indicate that all position in the array are empty,
*           this function put the flag (isEmpty) in TRUE in all
*           position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee* listi, int len);


/** \brief To get what index is free
 * \param list employee*
 * \param int len
 * \return free index
 *
 */
int freeSpace(eEmployee* listi, int len);

/** \brief  Prints sectors
 */
void printSector(void); ///esto es con la interpretacion de que sector NO es una estructura, debido a que sector en eEmpleyee no es idSector

/** \brief Prints a single employee
 * \param list employee*
 * \param int index
 * \return -1 if error 0 if ok
 *
 */
int printEmployee(eEmployee* listi, int index);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(eEmployee* listi, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee* listi, int len,int id);

/** \brief Edits a Employee by Id (has submenus)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int editEmployeeById(eEmployee* listi, int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee* listi, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee* listi, int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int Return (-1) if Error [] - (0) if Ok
*
*/
int printEmployees(eEmployee* listi, int length);


/** \brief gets the total and the average salary
 *
* \param list Employee*
* \param length int
* \return int Return (-1) if Error - (0) if Ok
 *
 */
int averageSalary(eEmployee* listi, int len);

/** \brief gets employees with salary above average (got in averageSalary)
 *
* \param list Employee*
* \param length int
* \return int Return (-1) if Error [] - (0) if Ok
 *
 */
int aboveAverageSalary(eEmployee* listi, int len);



void hardcodeo(eEmployee* listi);

#endif // ARRAYEMPLOYEE_H_INCLUDED

