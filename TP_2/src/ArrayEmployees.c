/*
 * ArrayEmployees.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Braian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int menu()
{
    int opcion;

    system("cls");
    printf("   *** ABM Empleados ***   \n");
    printf("----------------------------\n");
    printf("    1- ALTAS\n");
    printf("    2- MODIFICAR\n");
    printf("    3- BAJA\n");
    printf("    4- INFORMAR\n");
    printf("    5- SALIR\n\n");

    printf("Seleccione la operacion que desea realizar: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformar()
{
    int opcion;

    system("cls");
    printf("                         ******** Menu De Informes ********                                   \n");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("    1- Informe de empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("    2- Total y promedio de los salarios, ademas de la cantidad de empleados que superan el salario promedio\n\n");

    printf("Seleccione la operacion que desea realizar: ");
    scanf("%d", &opcion);
    return opcion;
}


int initEmployees(Employee lista[], int len)
{
    int retorno = 0;

    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            lista[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int buscarLibre(Employee lista[], int len)
{
    int indice = -1;

    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int idEmpleado(int id)
{
    return id - 1;
}

int cargarEmpleado(Employee lista[], int len, int* pId, char name[], char lastname[], float* pSalary, int* pSector)
{
    int retorno = 0;
    int indice;
    char salaryC[20];
    char sectorC[20];
    float salary;
    int sector;
    int id;

    if(lista != NULL && len > 0 && name != NULL && lastname != NULL)
    {
        system("cls");
        printf("   *** Alta Empleado ***   \n");
        printf("----------------------------\n");
        indice = buscarLibre(lista, len);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("Nombre: ");
            fflush(stdin);
            gets(name);
            while(!isString(name) || strlen(name) > 19 || name[0] == '\0')
            {
                printf("Dato ingresado no valido. Intente nuevamente\n");
                printf("Debe ingresar texto, sin numeros y que no sea demasiado largo\n\n");
                printf("Nombre: ");
                fflush(stdin);
                gets(name);
            }
            name[0] = toupper(name[0]);

            printf("Apellido: ");
            fflush(stdin);
            gets(lastname);
            while(!isString(lastname) || strlen(lastname) > 19 || lastname[0] == '\0')
            {
                printf("Dato ingresado no valido. Intente nuevamente\n");
                printf("Debe ingresar texto, sin numeros y que no sea demasiado largo\n\n");
                printf("Apellido: ");
                fflush(stdin);
                gets(lastname);
            }
            lastname[0] = toupper(lastname[0]);

            printf("Salario: ");
            gets(salaryC);
            while(!isNumber(salaryC) || salaryC[0] == '\0')
            {
                printf("Error. Debe ingresar un numero\n\n");
                printf("Salario: ");
                gets(salaryC);
            }
            salary = atof(salaryC);
            *pSalary = salary;

            printf("Sector: ");
            gets(sectorC);
            while(!isNumber(sectorC) || sectorC[0] == '\0')
            {
                printf("Error. Debe ingresar un numero\n\n");
                printf("Sector: ");
                gets(sectorC);
            }
            sector = atoi(sectorC);
            *pSector = sector;

            id = *pId;
            idEmpleado(id);
            (*pId)++;
            retorno = 1;
        }

    }
    return retorno;
}

int addEmployee(Employee lista[], int len, int id, char name[], char lastname[], float salary, int sector)
{
    int retorno = -1;
    Employee auxPersona;

    if(lista != NULL && len > 0 && name != NULL && lastname != NULL)
    {

        auxPersona.id = idEmpleado(id);

        strcpy(auxPersona.name, name);

        strcpy(auxPersona.lastName, lastname);

        auxPersona.salary = salary;

        auxPersona.sector = sector;

       //auxPersona.isEmpty = 0;

        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty)
            {
                auxPersona.isEmpty = 0;
                lista[i] = auxPersona;
                break;
            }
        }
        retorno = 0;
    }

    return retorno;
}
int findEmployeeById(Employee lista[], int len, int id)
{
    int posicion = -1;

    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty == 0 && id == lista[i].id)
            {
                posicion = i;
            }
        }
    }

    return posicion;
}

int removeEmployee(Employee lista[], int len)
{
    int retorno = -1;
    int posicionEmpleado;
    int id;
    char confirmacion;

    if(lista != NULL && len > 0)
    {
        printf("Ingrese ID del empleado que desea remover: ");
        scanf("%d", &id);
        posicionEmpleado = findEmployeeById(lista, len, id);
        if(posicionEmpleado == -1)
        {
            printf("No existe ningun empleado con ese ID");
        }
        else
        {
            system("cls");
            printf("   *** Informe De Empleados ***   \n");
            printf("    ID                 Nombre                  Apellido        Salario      Sector\n");
            printf("-----------------------------------------------------------------------------------\n");
            printEmployee(lista[posicionEmpleado]);
            printf("Desea eliminar a este empleado del sistema? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);

            if(confirmacion == 's')
            {
                lista[posicionEmpleado].isEmpty = 1;
                retorno = 0;
            }
            else
            {
                printf("Se ha cancelado la operacion\n");
            }
        }
    }
    return retorno;
}

void swap(Employee* xp, Employee* yp)
{
    Employee aux;

    aux = *xp;
    *xp = *yp;
    *yp = aux;
}

int sortEmployees(Employee lista[], int len, int order)
{
    int retorno = -1;


    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(order == 0) // Descendente
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName) < 0 ||
                       (strcmp(lista[i].lastName,lista[j].lastName) == 0 && lista[i].sector < lista[j].sector))
                    {
                        swap(&lista[i], &lista[j]);

                    }
                }
                else if(order == 1)  // Ascendente
                {
                    if(strcmp(lista[i].lastName, lista[j].lastName) > 0 ||
                        (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].sector > lista[j].sector))
                    {
                        swap(&lista[i], &lista[j]);
                    }
                }
            }
        }
        if(order == 0 || order == 1)
        {
            retorno = 0;
        }
    }
    return retorno;
}

void printEmployee(Employee lista)
{
    printf("  %3d    %20s     %20s      $%10.2f        %d\n",
           lista.id,
           lista.name,
           lista.lastName,
           lista.salary,
           lista.sector
           );
}

int printEmployees(Employee lista[], int lenght)
{
   int retorno = 0;
   int flag = 0;

   if(lista != NULL && lenght > 0)
   {
       system("cls");
       printf("   *** Informe De Empleados ***   \n");
       printf("    ID                 Nombre                  Apellido        Salario      Sector\n");
       printf("-----------------------------------------------------------------------------------\n");
       for(int i = 0; i < lenght; i++)
       {
           if(!lista[i].isEmpty)
           {
               printEmployee(lista[i]);
               flag = 1;
           }
       }
       if(!flag)
       {
           printf("No hay personas para mostrar\n");
       }
       retorno = 1;
   }

   return retorno;
}

int menuModificacion()
{
    int opcion;

    printf("    1- Nombre\n");
    printf("    2- Apellido\n");
    printf("    3- Salario\n");
    printf("    4- Sector\n\n");
    printf("Seleccione el campo que desea modificar segun el numero correspondiente: ");
    scanf("%d", &opcion);

    return opcion;
}

int modifyEmployee(Employee* lista, int len)
{
    int retorno = 0;
    int posicionEmpleado;
    char confirmacion;
    int id;

    if(lista != NULL && len > 0)
    {
        printf("Ingrese el ID del empleado que desea modificar: ");
        scanf("%d", &id);
        posicionEmpleado = findEmployeeById(lista, len, id);
        if(posicionEmpleado == -1)
        {
            printf("No existe ningun empleado con ese ID\n");
        }
        else
        {
            system("cls");
            printf("   *** Informe De Empleados ***   \n");
            printf("    ID                 Nombre                  Apellido        Salario      Sector\n");
            printf("-----------------------------------------------------------------------------------\n");
            printEmployee(lista[posicionEmpleado]);
            printf("Desea modificar algun campo de este empleado? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);

            if(confirmacion == 's')
            {
                switch(menuModificacion())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(lista->name);
                    retorno = 1;
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(lista->lastName);
                    retorno = 1;
                    break;
                case 3:
                    printf("Ingrese nuevo salario: ");
                    scanf("%f", &lista->salary);
                    retorno = 1;
                    break;
                case 4:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &lista->sector);
                    retorno = 1;
                    break;
                default:
                    printf("Opcion no valida. Se ha cancelado la operacion\n");
                    break;
                }
            }
            else
            {
                printf("Se ha cancelado la operacion\n");
            }
        }
    }
    return retorno;
}

int totalSalarios(Employee lista[], int len)
{
    int acumSalarios = 0;

    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(!lista[i].isEmpty)
            {
                acumSalarios += lista[i].salary;
            }
        }
    }
    return acumSalarios;
}

float promedioSalarios(Employee lista[], int len)
{
    int totSalarios;
    int contador = 0;
    float promSalarios;

    totSalarios = totalSalarios(lista, len);

    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(!lista[i].isEmpty)
            {
                contador++;
            }
        }
    }
    promSalarios = (float) totSalarios / contador;

    return promSalarios;
}
int cantEmpleadosSupSalarioProm(Employee lista[], int len)
{
    int contEmpleados = 0;
    float salarioPromedio;

    salarioPromedio = promedioSalarios(lista, len);

    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(!lista[i].isEmpty && lista[i].salary > salarioPromedio)
            {
                contEmpleados++;
            }
        }
    }
    return contEmpleados;
}

void informeSalarios(Employee lista[], int len)
{
    int total;
    float promedio;
    int supProm;

    total = totalSalarios(lista, len);
    promedio = promedioSalarios(lista, len);
    supProm = cantEmpleadosSupSalarioProm(lista, len);

    system("cls");
    printf("  *** Informe De Salarios ***   \n");
    printf("    Total        Promedio       Cant. Empleados que superan el salario promedio\n");
    printf("----------------------------------------------------------------------------\n");
    printf("   10%d      %10.2f                    %3d\n", total, promedio, supProm);
}

int isNumber(char s[])
{
    int retorno = 1;

    if(s != NULL)
    {
        for(int i = 0; s[i] != '\0'; i++)
        {
            if(!isdigit(s[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int isString(char s[])
{
    int retorno = 1;

    if(s != NULL)
    {
        for(int i = 0; i < strlen(s); i++)
        {
            if(!isalpha(s[i]))
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}
