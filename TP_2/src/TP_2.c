/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "dataWarehouse.h"

#define TAM 1000


int main(void) {

	setbuf(stdout, NULL);

    char seguir = 's';
    int nextID = 0;
    char nombre[20];
    char apellido[20];
    float salario;
    int sector;
    int orden;

    Employee lista[TAM];

    if(!initEmployees(lista, TAM))
    {
        printf("Hubo un problema al inicializar empleados");
    }

    //harcodearPersonas(lista, TAM, 10, &nextID); // Permite hacer pruebas con diez personas precargadas

    do
    {
        switch(menu())
        {
        case 1:

            if(cargarEmpleado(lista, TAM, &nextID, nombre, apellido, &salario, &sector) && !addEmployee(lista, TAM, nextID, nombre, apellido, salario, sector))
            {
                printf("Alta realizada con exito\n");
            }
            break;
        case 2:
            if(modifyEmployee(lista, TAM))
            {
                printf("Se ha modificado el campo del empleado con exito\n");
            }
            break;
        case 3:
            if(!removeEmployee(lista, TAM))
            {
                printf("Se ha eliminado al empleado del sistema\n");
            }
            break;
        case 4:
            switch(menuInformar())
            {
            case 1:
                printf("Elija criterio de ordenamiento: \n1- Ascendente \n0- Descentente: ");
                scanf("%d", &orden);

                if(sortEmployees(lista, TAM, orden) == -1)
                {
                    printf("Numero de orden no valido. No se pudieron ordenar los empleados\n");
                }
                else
                {
                    printEmployees(lista, TAM);
                }
                break;
            case 2:
                informeSalarios(lista, TAM);
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }while(seguir == 's');

	return EXIT_SUCCESS;
}
