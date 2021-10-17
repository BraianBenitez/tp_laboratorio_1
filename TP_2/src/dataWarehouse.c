/*
 * dataWarehouse.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Braian
 */


#include <string.h>

#include "dataWarehouse.h"
#include "ArrayEmployees.h"

char nombres[10][20] =
{
    "Juan",
    "Pedro",
    "Carla",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia"
};

/*
char apellidos[10][20] =
{
    "Perez",
    "Benitez", //Ex Robertaza
    "Matanze",
    "Songa",
    "Benitez",
    "Garcia",
    "Fernandez",
    "Messi",
    "Benitez", // Ex Aguero
    "Salvador"
};*/

char apellidos[10][20] =
{
    "Benitez",
    "Benitez",
    "Cenitez",
    "Benitez",
    "Benitez",
    "Aenitez",
    "Benitez",
    "Fenitez",
    "Benitez",
    "Benitez"
};

float salarios[10] = {1000.5,10000.8,12000,4000,8000,11000,15000,4500,12000,18000};

int sectores[10] = {3,2,1,2,1,3,2,3,3,1};

char sexos[10] = {'m','m','f','m','f','f','f','m','m','f'};

int edades[10] = {23,21,28,32,45,29,39,23,28,27,};

float alturas[10] = {1.65,1.67,1.9,1.78,1.75,1.7,1.65,1.73,1.69,1.68};

int idLocalidades[10] = {1001,1002,1000,1001,1001,1003,1004,1002,1004,1001};


int harcodearPersonas(Employee lista[], int tam, int cant, int* pId)
{
    int contador = -1;

    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam)
    {
        contador = 0;
        for(int i = 0; i < cant; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].name, nombres[i]);
            strcpy(lista[i].lastName, apellidos[i]);
            lista[i].salary = salarios[i];
            lista[i].sector = sectores[i];
            lista[i].isEmpty = 0;
        }
    }
    return contador;
}
