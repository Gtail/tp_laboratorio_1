/*
 * Fecha.c
 *
 *  Created on: 24 jul. 2022
 *      Author: Gian
 */
#include "Fecha.h"

int main_Menu(){
		int option;

		printf("\n\t>-MENU PRINCIPAL-<\t\n");
		printf("-----------------------------------------\n");
		printf("Opcion 1 ALTA DE AUTO \n");
		printf("Opcion 2 MODIFICAR AUTO: \n");
		printf("Opcion 3 BAJA AUTO \n");
		printf("Opcion 4 LISTAR AUTOS \n");
		printf("Opcion 5 LISTAR MARCAS \n");
		printf("Opcion 6 LISTAR COLORES \n");
		printf("Opcion 7 LISTAR SERVICIOS \n");
		printf("Opcion 8 ALTA TRABAJO \n");
		printf("Opcion 9 LISTAR TRABAJOS \n");
		printf("Opcion 10 SALIR \n");

		scanf("%d", &option);

		return option;
}
