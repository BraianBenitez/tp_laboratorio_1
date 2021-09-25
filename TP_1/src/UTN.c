/*
 * UTN.c
 *
 *  Created on: 25 sep. 2021
 *      Author: Braian
 */


#include <stdio.h>
#include <stdlib.h>

int menu(int* a, int* b) // Menu de opciones que se encarga de sustiruir el valor en la 'x' y en la 'y' una vez se ingresan
{
    int opcion;
    int A;
    int B;
    A = *a; // se crean variables que toman como valor la direccion de memoria de los parametros utilizados
    B = *b;

    if(A > 1000000 || B > 1000000) // con dicho valor, se valida para cambiar los valores una vez ingresados (funciona solo en caso de que dichos valores de direccion sean mayores a un millon)
    {
        printf("Menu de opciones\n\n");
        printf("1. Ingresar 1er operando (A = x)\n");
        printf("2. Ingresar 2do operando (B = y)\n");
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    else
    {
        if(a != NULL && b != NULL)
        {
            fflush(stdin);
            printf("Menu de opciones\n\n");
            printf("1. Ingresar 1er operando (A = %d)\n", *a);
            printf("2. Ingresar 2do operando (B = %d)\n", *b);
            printf("3. Calcular todas las operaciones\n");
            printf("4. Informar resultados\n");
            printf("5. Salir\n\n");
            printf("Ingrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
    }

    return opcion;
}

int funcionSuma(int a, int b, int* pResultado) // Se obtienen dos valores, se suman y se asigna el resultado a un puntero que la asigna en la direccion de memoria asignada
{
    int retorno = 0;
    if(pResultado != NULL)
    {
        *pResultado = a + b;
        retorno = 1;
    }
    return retorno;
}

int funcionResta(int a, int b, int* pResultado) // Se obtienen dos valores, se restan y se asigna el resultado a un puntero que la asigna en la direccion de memoria asignada
{
    int retorno = 0;
    if(pResultado != NULL)
    {
        *pResultado = a - b;
        retorno = 1;
    }
    return retorno;
}

int funcionMultiplicacion(int a, int b, int* pResultado) // Se obtienen dos valores, se multiplican y se asigna el resultado a un puntero que la asigna en la direccion de memoria asignada
{
    int retorno = 0;
    if(pResultado != NULL)
    {
        *pResultado = a * b;
        retorno = 1;
    }
    return retorno;
}

int funcionDivision(int a, int b, float* pResultado) // Se obtienen dos valores, se dividen y se asigna el resultado a un puntero que la asigna en la direccion de memoria asignada
{
    int retorno = 0;
    if(b != 0 && pResultado != NULL) // se verifica que el valor puesto en el segundo parametro no sea cero
    {
        *pResultado = (float) a / b;
        retorno = 1;
    }
    return retorno;
}

int funcionFactorial(int n) // Se ingresa un numero y se lo multiplica por uno menor, hasta que se llega a multiplicarlo por 1
{
    int retorno = 0;
    int resultado;
    if(n >= 0) // Se verifica que sea mayor o igual a 0, ya que el factorial se calcula para enteros naturales
    {
        if(n == 1 || n == 0)
        {
            retorno = 1;
        }
        else
        {
            resultado = n * funcionFactorial(n - 1);
            retorno = resultado;
        }
    }
    return retorno;
}
