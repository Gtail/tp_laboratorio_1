/*
 ============================================================================
 Name        : Parcial.c
 Author      : Gian Franzoso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "fecha.h"
#include "Viajes.h"
#include "Aviones.h"


#define TAMF 5
#define TAMA 5
#define TAMT 4
#define TAMD 4



int main(void) {
	setbuf(stdout, NULL);
	int option;
	int idAvion=0;
	int idVuelo=19999;
	Avion list[TOP];
	Aerolinea aerolineas[TAMA];
	Tipo tipos[TAMT];
	Destino destinos[TAMD];
	Vuelo vuelos[TAMV];
	Piloto pilotos[TAMP];
	//fecha fechas[TAMF];
	initAviones(list, TOP);
	HardcodeAerolinea(aerolineas, TAMA);
	HardcodeDestinos(destinos, TAMD);
	HardcodeTipo(tipos, TAMT);
	inicializarVuelos(vuelos, TAMV);
	HardcodePilotos(pilotos, TAMP);
	hardcodearAviones(list, TOP, 5, &idAvion);

	hardcodearVuelos(vuelos, TAMV, 6, list, TOP, &idVuelo, destinos,TAMD);
	do {

		option = main_Menu();
		switch (option) {
		case 1:

			printf("\n Usted ha elegido la opcion Nº1: Alta de Avion \n");
			if (altaAvion(list, TOP, &idAvion, aerolineas, TAMA, tipos, TAMT, pilotos, TAMP) == 0) {
				printf("Todo ok \n");
				//flag=1;
			}
			break;
		case 2:
			/*if(flag!=1){
			 printf("\n No hay empleados disponibles \n ");
			 }else{
			 }*/
			printf("\n Usted ha elegido la opcion Nº2: Modificacion de Avion \n");
			modifyAvion(list, tipos, aerolineas,pilotos, TOP, TAMT, TAMA, TAMP);
			break;
		case 3:
			/*if(flag==0){
			 printf("\n No hay empleados disponibles \n ");
			 }else{

			 }*/
			printf("\n Usted ha elegido la opcion Nº3: Baja de Avion \n");
			if(removeAvion(list, TOP, idAvion, tipos, aerolineas, pilotos, TAMT, TAMA, TAMP)==0){
				printf("Baja realizada\n");
			}
			break;
		case 4:
			/*	if(flag==0){
			 printf("\n No hay empleados disponibles \n ");
			 }else{*/
			printf("\n Usted ha elegido la opcion Nº4: Listado de Aviones ordenados por aerolínea y capacidad. \n");
			sortAviones(list, tipos, aerolineas, pilotos, TOP, TOP, TAMT, TAMA, TAMP);
			break;
		case 5:
			printf("\n Usted ha elegido la opcion Nº5: Listado de AEROLINEAS \n");
			listarAerolineas(list, aerolineas, TOP, TAMA);
			break;
		case 6:
			printf("\n Usted ha elegido la opcion Nº6: Listar TIPOS \n");
			listarTipos(list, tipos, TAMT, TOP);
			break;
		case 7:
			printf("\n Usted ha elegido la opcion Nº7: LISTAR DESTINOS \n");
			listarDestinos(destinos, TAMD);
			break;
		case 8:
			printf("\n Usted ha elegido la opcion Nº8: ALTA DE VUELOS \n");
			altaDeVuelo(list, TOP, vuelos, TAMV, tipos, TAMT, aerolineas, TAMA, destinos, TAMD, pilotos, TAMP, &idVuelo);
			break;
		case 9:
			printf("\n Usted ha elegido la opcion Nº9: LISTAR VUELOS \n");
			listarVuelos(list, TOP, vuelos, TAMV, tipos, TAMT, aerolineas, TAMA, destinos, TAMD);
			break;
		case 10:
			printf("\n Usted ha elegido la opcion Nº10: MOSTRAR AVIONES DE LA AEROLINEA SELECCIONADA \n");
			mostrarAvionesPorAerolinea(list, TOP, aerolineas, TAMA, tipos, TAMT, pilotos, TAMP);
			break;
		case 11:
			printf("\n Usted ha elegido la opcion Nº11: PROMEDIO DE JETS POR AEROLINEA \n");
			promedioDe_JetsPorAerolinea(list, TOP, tipos, TAMT, aerolineas, TAMA);
			break;
		case 12:
			printf("\n Usted ha elegido la opcion Nº12: MOSTRAR AVIONES POR TIPO SELECCIONADO \n");
			mostrarAvionesPorTipo(list, TAMA, aerolineas, TAMA, tipos, TAMT, pilotos, TAMP);
			break;
		case 13:
			printf("\n Usted ha elegido la opcion Nº13: LISTADO DE AVIONES SEPARADOS POR AEROLINEA \n");
			mostrarAviones_PorAerolineas(list, TOP, aerolineas, TAMA, tipos, TAMT, pilotos, TAMP);
			break;
		case 14:
			printf("\n Usted ha elegido la opcion Nº14: LISTADO DE AEROLINEAS CON MAYOR CAPACIDAD DE TRANSPORTE \n");
			mayorCapacidadPorAerolinea(list, TOP, aerolineas, TAMA);
			break;
		case 15:
			printf("\n Usted ha elegido la opcion Nº15: LISTADO DE AEROLINEA/S CON MENOR CANTIDAD DE AVIONES \n");
			aerolineaConMenosAviones(list, TOP, aerolineas, TAMA);
			break;
		case 16:
			printf("\n Usted ha elegido la opcion Nº16: VUELOS REALIZADOS POR AVION SELECCIONADO \n");
			vuelosPorAvion(vuelos, TAMV, list, TOP, tipos, TAMT, aerolineas, TAMA, pilotos,TAMP);
			break;
		case 17:
			printf("\n Usted ha elegido la opcion Nº17: PRECIO TOTAL DE VUELOS REALIZADO POR AVION SELECCIONADO \n");
			precioTotalPorAvion(vuelos, TAMV, list, TOP, tipos, TAMT, aerolineas, TAMA, pilotos, TAMP, destinos, TAMD);
			break;
		case 18:
			printf("\n Usted ha elegido la opcion Nº18: AVIONES QUE VOLARON A DESTINO SELECCIONADO \n");
			mostrarAvionesPorDestino(vuelos, TAMV, tipos, TAMT, list, TOP, destinos, TAMD);
			break;
		case 19:
			printf("\n Usted ha elegido la opcion Nº19: VUELOS REALIZADOS EN FECHA SELECCIONADA \n");
			mostrarVuelosPorFecha(vuelos, TAMV, destinos, TAMD, list, TOP, tipos, TAMT, aerolineas, TAMA);
			break;
		case 20:
			printf("\n Salir \n");
			break;

		}
	} while (option != 20);

	return 0;
}
