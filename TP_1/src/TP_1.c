/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);

	int A;
	    int B;
	    int banderaNumA = 0;
	    int banderaNumB = 0;
	    int banderaOperaciones = 0;

	    int suma;
	    int resta;
	    float division;
	    int multiplicacion;
	    int factorialA;
	    int factorialB;
	    char salir;

	    do
	    {
	        switch(menu(&A, &B))
	        {
	        case 1:
	            printf("Bienvenido. Ingrese el 1er numero: ");
	            scanf("%d", &A);
	            banderaNumA = 1;
	            break;
	        case 2:
	            printf("Bienvenido. Ingrese el 2do numero: ");
	            scanf("%d", &B);
	            banderaNumB = 1;
	            break;
	        case 3:
	            if(banderaNumA == 0 || banderaNumB == 0)
	            {
	                printf("No se ingresaron los valores suficientes para calcular las operaciones\n");
	            }
	            else
	            {
	                funcionSuma(A, B, &suma);
	                funcionResta(A, B, &resta);
	                funcionMultiplicacion(A, B, &multiplicacion);
	                funcionDivision(A, B, &division);
	                factorialA = funcionFactorial(A);
	                factorialB = funcionFactorial(B);
	                banderaOperaciones = 1;
	            }
	            break;
	        case 4:
	            if(banderaNumA == 0 || banderaNumB == 0)
	            {
	                printf("No se ingresaron los valores suficientes\n");
	            }
	            else
	            {
	                if(banderaOperaciones == 0)
	                {
	                    printf("No se calcularon las operaciones\n");
	                }
	                else
	                {
	                    printf("El resultado de %d + %d es %d\n", A, B, suma);
	                    printf("El resultado de %d - %d es %d\n", A, B, resta);
	                    printf("El resultado de %d * %d es %d\n", A, B, multiplicacion);
	                    if(!funcionDivision(A, B, &division))
	                        printf("No es posible dividir por cero\n");
	                    else
	                        printf("El resultado entre %d / %d es %.2f\n", A, B, division);
	                    printf("El factorial de %d es: %d y el factorial de %d es: %d\n\n",A, factorialA, B, factorialB);
	                }
	            }
	            break;
	        case 5:
	            printf("\nAdios!\n");
	            salir = 's';
	            break;
	        default:
	            printf("No pertenece a alguna de las opciones. Intente nuevamente\n");
	            break;
	        }
	    }while(salir != 's');

	return EXIT_SUCCESS;
}
