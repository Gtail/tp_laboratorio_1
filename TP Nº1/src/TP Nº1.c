/*
 ============================================================================
 Name        : TP.c
 Author      : Gian Franzoso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operation.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int num1;
	int num2;
	int sumatoria;
	int resta;
	float division;
	int multiplicacion;
	int factorizar;
	int factorizar2;

	printf("Bienvenido, elija una opcion \n\n");
	do{
		opcion = menuFive();

	switch(opcion){
				case 1:
					printf("\n Usted ha seleccionado 1 Ingrese el Primer Operando\n\n");
					num1 = operando1(num1);
					break;
				case 2:
					printf("\n Usted ha seleccionado 2	Ingrese el Segundo Operando \n\n");
					num2 = operando2(num2);
					break;
				case 3:
					printf("\n Usted ha seleccionado 3 Calcular Operaciones \n\n");
					operar(num1,num2, &sumatoria, &resta, &division, &multiplicacion, &factorizar, &factorizar2);
					break;
				case 4:
					printf("\n Usted ha seleccionado 4 Mostrar Resultados \n\n");
					mostrar(num1,num2,sumatoria,resta,division,multiplicacion,factorizar, factorizar2);
					break;
				case 5:
					printf("\n Hasta Luego \n");
					break;
				default:
					printf("\n Error. Opcion incorrecta, intente nuevamente. \n");
				}
		}while(opcion!=5);
		return 0;
	}
