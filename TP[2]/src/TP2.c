/*
 ============================================================================
 Name        : TP2.c
 Author      : Gian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "ArrayPassenger.h"
#define LEN 50
#define TAM 3
#define TAMS 2


int main(void) {
	setbuf(stdout,NULL);
	int option;
	int option_Informe;
	int orden;
	int orden_Dos;
	int idAuto=0;
	int flag=0;
	char name[51];
	char lastName[51];
	float price=0;
	int typePassenger=0;
	char flycode[10];
	Passenger list[LEN];
	ePassage passages[TAM];
	initPassengers(list, LEN);
	HardcodePassage(passages, TAM);
	HardcodeStatus(passages, TAMS);

	do{
		option = subMenu();
		switch(option)
		{
		case 1:

			printf("\n Usted ha elegido la opcion N.1: Alta de Pasajero \n");
			if(addPassenger(list, LEN, &idAuto, name, lastName, price, typePassenger, flycode)==0){
				printf("Alta ejecutada \n");
			flag=1;
			}
			break;
		case 2:
			if(!flag){
				printf("\n No hay empleados disponibles \n ");
			}else{
			printf("\n Usted ha elegido la opcion N.2: Modificacion de Pasajero \n");
			modifyPassenger(list, LEN, passages, TAM, TAMS);
			}
			break;
		case 3:
			if(!flag){
				printf("\n No hay empleados disponibles \n ");
			}else{
			printf("\n Usted ha elegido la opcion N.3: Eliminar Pasajero \n");
			if(removePassenger(list, LEN, idAuto, passages, TAM, TAMS)!=-1){
				printf("Eliminacion exitosa \n");
			}else{
				printf("Error al eliminar el pasajero \n");
			}
			}
			break;
		case 4:
			if(!flag){
				printf("\n No hay empleados disponibles \n ");
			}else{
			do{
				option_Informe=subMenu2();
				switch(option_Informe){
				case 5:
					printf("\n Usted ha elegido la opcion N.5: Listado de Pasajeros Alfabeticamente Apellido y Sector \n");
					orden=getValidInt("Ingrese 0 para ordenar descendente || Ingrese 1 para ordenar Ascendente \n", "Error, Ingrese solo 0 descendente || 1 ascendente \n", 0, 1);
					if(sortEmployees(list, LEN, orden)!=-1){
						printPassengers(list, LEN, passages, TAM, TAMS);
					}else{
						printf("Error al realizar el ordenamiento. Intente nuevamente \n");
					}
					break;
				case 6:
					printf("\n Usted ha elegido la opcion N.6: Total y Promedio de los Pasajes. Cuantos lo superan \n");
					informes(list, LEN);
					break;
				case 7:
					printf("\n Usted ha elegido la opcion N.7: Informar Listado de pasajeros por Codigo de Vuelo Activos \n");
					orden_Dos=getValidInt("Ingrese 0 para ordenar descendente || Ingrese 1 para ordenar Ascendente \n", "Error, Ingrese solo 0 descendente || 1 ascendente \n", 0, 1);
					if(sortPassengers_ByCode(list, passages, LEN, TAM, TAMS, orden_Dos)!=-1){

						printf("Ordenamiento ok \n");
					}
					break;
				case 8:
					printf("\n Menu Principal \n");
					break;
				}
			}while(option_Informe!=8);
			}
			break;
		case 9:
			printf("\n Usted ha elegido la opcion N.9: Carga Forzada de Pasajeros \n");
			if(Alta_Forzada(list, LEN, 10, &idAuto)!=-1){
				printPassengers(list, LEN, passages, TAM, TAMS);
				flag=1;
			}
			break;
		case 10:
			printf("\n Salir \n");
			break;
		}
	}while(option != 10);


	return 0;
}
