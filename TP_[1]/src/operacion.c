/*
 * operation.c
 *
 *  Created on: 19 sep. 2021
 *      Author: Gian
 */
#include "operacion.h"
#include <stdio.h>
#include <stdlib.h>

int menuFive (){
int opcion;

	printf("\n Opcion 1 Ingrese Primer Operando \n\n");
	printf("\n Opcion 2 Ingrese Primer Operando \n\n");
	printf("\n Opcion 3 Calcular Operaciones \n\n");
	printf("\n Opcion 4 Mostrar Resultados \n\n");
	printf("\n Opcion 5 Salir \n\n");
	scanf("%d", &opcion);

	return opcion;
}


int operando1(int num1){
	printf("\n Ingrese el primer numero \n\n");
	scanf("%d", &num1);
	printf("\n El numero ingresado es %d \n\n",num1);

	return num1;
}

int operando2(int num2){
	printf("\n Ingrese el segundo numero \n\n");
	scanf("%d", &num2);
	printf("\n El numero ingresado es %d \n\n",num2);

	return num2;
}

int sumar(int num1, int num2){

	int operacion;
	operacion= num1 + num2;

	return operacion;
}

int restar(int num1, int num2){

	int operacion= num1 - num2;

	return operacion;
}

float dividir(int num1, int num2){
	int operacion;
	if(num2==0){
		operacion=0;
	}else{
	operacion= (float)num1/num2;
	}
	return operacion;
}

int multiplicar(int num1, int num2){
	int operacion;
	operacion = num1*num2;
	return operacion;
}

int factoreo(int num1){

	int f=1;

		for (int i = 1; num1 >= i; i++) {
		f*= i;
		}
	return f;
}

void operar(int num1, int num2, int *sumatoria, int *resta, float *division, int *multiplicacion, int *factorizar, int *factorizar2){
	*sumatoria = sumar(num1,num2);
	*resta=restar(num1,num2);
	*division=dividir(num1,num2);
	*multiplicacion=multiplicar(num1,num2);
	*factorizar=factoreo(num1);
	*factorizar2=factoreo(num2);
}

void mostrar(int num1, int num2,int sumatoria, int resta, float division, int multiplicacion, int factorizar, int factorizar2){

	printf("\n El resultado de la suma es %d\n\n", sumatoria);
	printf("\n El resultado de la resta es %d\n\n", resta);
	if(division==0){
		printf("\n La division no se pudo realizar\n\n");
	}else{
	printf("\n El resultado de la division es %.2f\n\n", division);
	}
	printf("\n El resultado de la multiplicacion es %d\n\n", multiplicacion);
	if(num1<0 || num2<0){
		printf("\n No se puede factorizar");
	}else{
	printf("\n El resultado del factoreo del primer numero es %d\n\n", factorizar);
	printf("\n El resultado del factoreo del segundo numero es %d\n\n", factorizar2);
	}
}
