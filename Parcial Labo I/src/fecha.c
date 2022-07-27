/*
 * fecha.c
 *
 *  Created on: 11 may. 2022
 *      Author: Gian Franzoso
 */


#include "fecha.h"

int main_Menu(){
		int option;

		printf("\n\t>-MENU PRINCIPAL-<\t\n");
		printf("-----------------------------------------\n");
		printf("Opcion 1 ALTA DE AVION \n");
		printf("Opcion 2 MODIFICAR AVION: \n");
		printf("Opcion 3 BAJA AVION \n");
		printf("Opcion 4 LISTAR AVIONES \n");
		printf("Opcion 5 LISTAR AEROLINEAS \n");
		printf("Opcion 6 LISTAR TIPOS \n");
		printf("Opcion 7 LISTAR DESTINOS \n");
		printf("Opcion 8 ALTA VUELO: \n");
		printf("Opcion 9 LISTAR VUELOS \n");
		printf("Opcion 10 MOSTRAR AVIONES DE LA AEROLINEA SELECCIONADA \n");
		printf("Opcion 11 PROMEDIO DE JETS POR AEROLINEA \n");
		printf("Opcion 12 MOSTRAR AVIONES POR TIPO SELECCIONADO \n");
		printf("Opcion 13 LISTADO DE AVIONES SEPARADOS POR AEROLINEA \n");
		printf("Opcion 14 AEROLINEAS QUE PUEDEN TRANSPORTAR MAS PASAJEROS \n");
		printf("Opcion 15 AEROLINEA CON MENOR CANTIDAD DE AVIONES \n");
		printf("Opcion 16 MOSTRAR VUELOS POR AVION SELECCIONADO \n");
		printf("Opcion 17 COSTO TOTAL DE VUELOS REALIZADOS POR AVION SELECCIONADO \n");
		printf("Opcion 18 AVIONES QUE VOLARON A DESTINO SELECCIONADO \n");
		printf("Opcion 19 VUELOS REALIZADOS POR FECHA SELECCIONADA\n");
		printf("Opcion 20 SALIR \n");

		scanf("%d", &option);

		return option;
}

int validarFecha(Fecha fechas[], int top, int index) {
	int retorno = -1;
	int i;
	Fecha auxFecha[top];


		for (i = 0; i < top; i++) {
			if (fechas[index].dia == auxFecha[i].dia && fechas[index].mes == auxFecha[i].mes && fechas[index].anio == auxFecha[i].anio) {
				retorno = 0;
				break;
			}


	}

	return retorno;

}

