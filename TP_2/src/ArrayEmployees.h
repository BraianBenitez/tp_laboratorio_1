/*
 * ArrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Braian
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[20];
    char lastName[20];
    float salary;
    int sector;
    int isEmpty;
}Employee;


#endif /* ARRAYEMPLOYEES_H_ */

int menu();
int menuInformar();

int initEmployees(Employee lista[], int len); // retorna -1 si hay error, 0 si no lo hay
int cargarEmpleado(Employee lista[], int len, int* pId, char name[], char lastname[], float* pSalary, int* pSector);
int addEmployee(Employee lista[], int len, int id, char name[], char lastname[], float salary, int sector);
int findEmployeeById(Employee lista[], int len, int id); // retorna la posicion de empleado, o -1
int removeEmployee(Employee lista[], int len);
void swap(Employee* xp, Employee* yp);
int sortEmployees(Employee lista[], int len, int order); // oredena de manera ascendente o descendente(apellido y sector) segun el orden (1 o 0)
void printEmployee(Employee lista);
int printEmployees(Employee lista[], int lenght);

int modifyEmployee(Employee* lista, int len);
int menuModificacion();

int totalSalarios(Employee lista[], int len);
float promedioSalarios(Employee lista[], int len);
int cantEmpleadosSupSalarioProm(Employee lista[], int len);
void informeSalarios(Employee lista[], int len);

int idEmpleado(int id);
int isNumber(char s[]);
int isString(char s[]);
