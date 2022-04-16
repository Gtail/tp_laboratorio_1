/*
 ============================================================================
 Name        : TP.c
 Author      : Gian Franzoso
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"
int main(void) {
	setbuf(stdout, NULL);
	float km;
	float precioAerolineas;
	float precioLatam;
	float precio_DebitoL;
	float precio_DebitoA;
	float precio_CreditoL;
	float precio_CreditoA;
	float precio_BtcL;
	float precio_BtcA;
	float unitarioL; //PRECIO X KM
	float unitarioA;
	float diferencia; //LATAM - AEROLINEAS*/
	int opcion;
	int opcionP;
	int flagKm=0;
	int flagLatam=0;
	int flagA=0;

		printf("Bienvenido al simulador de pasajes \n");
	do {
		opcion = menuSix();
		system("cls");
		switch (opcion) {

		case 1:
			chargeSalary(&km, "Usted ha seleccionado opcion 1) Ingresar Km's \n", "Error, solo ingrese numeros \n");
			flagKm=1;
			break;
		case 2:
			if(flagKm!=1){
				printf("Ingrese los KM en opcion 1 previamente \n");
			}else{
			printf("Usted ha seleccionado opcion 2) Ingrese Precios (3)LATAM - (4)Aerolineas \n");
			do {
				opcionP = subMenu();
				switch (opcionP) {
				case 3:
					chargeSalary(&precioLatam, "Ingrese precio LATAM \n", "Error, solo ingrese numeros \n");
					flagLatam=1;
					break;
				case 4:
					chargeSalary(&precioAerolineas, "Ingrese precio Aerolineas \n", "Error, solo ingrese numeros \n");
					flagA=1;
					break;
				case 5:
					printf("Salir \n");
					break;
				}
			} while (opcionP!= 5);
			}
			break;
		case 6:
			if(flagLatam&&flagA){
			printf("Usted ha seleccionado opcion 6) Calcular Costos \n");
			calcularCostos(km, precioLatam, precioAerolineas, &precio_DebitoL, &precio_DebitoA, &precio_CreditoL, &precio_CreditoA, &precio_BtcL, &precio_BtcA, &unitarioL, &unitarioA, &diferencia);
			}else{
				printf("Cargue ambos precios ,LATAM y Aerolineas, para poder calcular los costos \n");
			}
			break;
		case 7:
			if(flagLatam!=1&&flagA!=1){
				printf("Ingrese los KM y precios previamente para poder informar resultados \n");
			}else{
			printf("Usted ha seleccionado opcion 7) Informar Resultados \n");
			mostrarResultadosTotales(km,precio_DebitoL, precio_CreditoL, precio_BtcL, unitarioL, precio_DebitoA, precio_CreditoA, precio_BtcA, unitarioA, diferencia);
			flagKm=1;
			flagLatam=1;
			flagA=1;
			}
			break;
		case 8:
			printf("Usted ha selecccionado opcion 8) Carga Forzada de datos \n");
			cargaForzada( precioLatam,  precioAerolineas, precio_DebitoL, precio_DebitoA, precio_CreditoL, precio_CreditoA, precio_BtcL, precio_BtcA, unitarioL, unitarioA, diferencia);
			system("pause");
			break;
		case 9:
			printf("Hasta Luego \n");
			break;
		default:
			printf("Opcion incorrecta \n");
			system("pause");
		}

	} while (opcion != 9);

	return 0;
}
