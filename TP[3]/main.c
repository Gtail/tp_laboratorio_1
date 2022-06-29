#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/





int main() {
	setbuf(stdout, NULL);
	int option;
	int flagSaveTxt=0;
	int flagSaveBin=0;
	int flagCarga=0;
	LinkedList *listaPasajeros = ll_newLinkedList(); //me crea una linked list de pasajeros
	// me consigue memoria para un ll y me devuelve el puntero a esa linkedlist, es un constructor normal
	//
	if (listaPasajeros == NULL) {
		printf("No se consiguio memoria \n");
	} else {

		do {
			option = menuTen();
			switch (option) {
			case 1:
				if(ll_isEmpty(listaPasajeros) && flagCarga==0){
				printf(
						"\n Usted ha seleccionado 1: Cargar Pasajeros Modo Texto \n");
				if(controller_loadFromText("data.csv", listaPasajeros)==0){
					printf(" Carga txt exitosa \n");
				}
				}else{
					printf("No se puede cargar la lista dos veces \n");
				}
				break;
			case 2:
				printf(
						"\n Usted ha seleccionado 2: Cargar Pasajeros Modo Binario \n");
				if(controller_loadFromBinary("data.csv", listaPasajeros)==0){
					printf("Todo ok\n");
				}
				break;
			case 3:
				printf("\n Usted ha seleccionado 3: Alta de Pasajeros \n");
				controller_addPassenger(listaPasajeros);
				break;
			case 4:
				printf("\n Usted ha seleccionado 4: Modificacion Pasajeros \n");
				controller_editPassenger(listaPasajeros);
				break;
			case 5:
				printf("\n Usted ha seleccionado 5: Baja de Pasajeros \n");
				controller_removePassenger(listaPasajeros);
				break;
			case 6:
				printf("\n Usted ha seleccionado 6: Listar Pasajeros \n");
				controller_ListPassenger(listaPasajeros);
				break;
			case 7:
				printf("\n Usted ha seleccionado 7: Ordenar Pasajeros \n");
				controller_sortPassenger(listaPasajeros);
				break;
			case 8:
				printf(
						"\n Usted ha seleccionado 8: Guardar Pasajeros en Modo Texto \n");
				if(controller_saveAsText("data.csv", listaPasajeros)==1){
					printf("Informacion guardada correctamente \n");
				}else{
					printf("No se guardo la informacion \n");
				}
				break;
			case 9:
				printf(
						"\n Usted ha seleccionado 9: Guardar Pasajeros en Modo Binario \n");
				if(controller_saveAsBinary("data.csv", listaPasajeros)==1){
					printf("Informacion guardada correctamente \n");
				}else{
					printf("No se guardo la informacion \n");
				}
				break;
			case 10:
				printf("Hasta Luego \n");
				break;
			}
		} while (option != 10);
	}
	return 0;
}

