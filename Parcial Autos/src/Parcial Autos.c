/*
 ============================================================================
 Name        : Parcial.c
 Author      : Gian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Fecha.h"
#include "Autos.h"
#include "Servicios.h"

#define TAMA 10
#define TAMAR 5
#define TAMC 5
#define TAMSV 4
#define TAMT 5
#define TAMCL 5


int main(void) {
	setbuf(stdout,NULL);
	int idAutos=0;
	int idTrabajos=0;
	int idCliente=0;
	Marca marcas[TAMAR];
	Color colores[TAMC];
	Auto autos[TAMA];
	Servicios servicios[TAMSV];
	Trabajos trabajos[TAMT];
	Cliente clientes[TAMCL];
	int opcion;
	inicializarTrabajos(trabajos, TAMT);
	inicializarAutos(autos, TAMA);
	hardcodearMarcas(marcas, TAMAR);
	hardcodearColores(colores, TAMC);
	hardcodearClientes(clientes, TAMCL, 5, &idCliente);
	hardcodearAutos(autos, TAMA, 5, &idAutos);
	hardcodearServicios(servicios, TAMSV);

	do{
		opcion=main_Menu();
		switch(opcion){
		case 1:
			puts("Usted a elegido la opcion 1: Alta de Auto \n");
			altaDeAuto(autos, TAMA, marcas, TAMAR, colores, TAMC, &idAutos, clientes, TAMCL);
			break;
		case 2:
			puts("Usted a elegido la opcion 2: Modificar Auto \n");
			modificarAuto(autos, TAMA, marcas, TAMAR, colores, TAMC);
			break;
		case 3:
			puts("Usted a elegido la opcion 2: Eliminar Auto \n");
			eliminarAuto(autos, TAMA, marcas, TAMAR, colores, TAMC);
			break;
		case 4:
			puts("Usted a elegido la opcion 4: Listar Autos \n");
			mostrarAutos(autos, TAMA, marcas, TAMAR, colores, TAMC);
			break;
		case 5:
			puts("Usted a elegido la opcion 5: Listar Marcas \n");
			listarMarcas(marcas, TAMAR);
			break;
		case 6:
			puts("Usted a elegido la opcion 6: Listar Colores \n");
			listarColores(colores, TAMC);
			break;
		case 7:
			puts("Usted a elegido la opcion 7: Listar Servicios \n");
			listarServicios(servicios, TAMSV);
			break;
		case 8:
			puts("Usted a elegido la opcion 8: Alta de Trabajo \n");
			altaDeTrabajo(autos, TAMA, marcas, TAMAR, colores, TAMC, servicios, TAMSV, trabajos, TAMT, &idTrabajos);
			break;
		case 9:
			puts("Usted a elegido la opcion 9: Listar Trabajos \n");
			listarTrabajos(trabajos, TAMT, servicios, TAMSV);
			break;
		case 10:
			break;
		}

	}while(opcion!=10);


	return 0;
}
