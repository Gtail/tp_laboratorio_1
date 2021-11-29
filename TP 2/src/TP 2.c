/*
 ============================================================================
 Name        : TP.c
 Author      : Gian Franzoso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "ArrayEmployees.h"
#define LEN 5
#define TOP 3


int main(void){

	setbuf(stdout,NULL);

	int option;
	int optionSub;
	int sort_Order=0;
	int idAuto=99;
	int flag=0;
	Employee list[LEN];
	eSector sector[TOP];
	initEmployees(list, LEN);
	HardcodeSector(sector, TOP);
	do{
		idAuto+=1;
		option = subMenu();
		switch(option)
		{
		case 1:

			printf("\n Usted ha elegido la opcion Nº1: Alta de Empleado \n");
			if(registerEmployee(list, LEN, idAuto)!=1){

				printf("\n Alta ok \n");
				flag=1;
			}
			break;
		case 2:
			if(flag==0){
				printf("\n No hay empleados disponibles \n ");
			}else{
			printf("\n Usted ha elegido la opcion Nº2: Modificacion de Empleado");
			if(modifyEmployee(list, LEN, idAuto)==1){
			printf("\n OK \n");
			}
			}
			break;
		case 3:
			if(flag==0){
				printf("\n No hay empleados disponibles \n ");
			}else{
			if(removeEmployee(list, LEN, idAuto)==0)
			{
				printf("\n Eliminacion exitosa \n");
			}
			}
			break;

		case 4:
			if(flag==0){
				printf("\n No hay empleados disponibles \n ");
			}else{
			do{
				optionSub=subMenu2();
				switch(optionSub){
				case 5:
					printf("\n Usted ha elegido la opcion Nº5: Listado de empleados Alfabeticamente Apellido y Sector");
					sort_Order=getValidInt("\n Ingrese 0 para ordenar de forma descendente o 1 para ordenar de forma Ascendente \n", "\n Error SOLO 0 o 1 \n", 0, 1);
					sortEmployees(list, LEN, sort_Order);
					if(sortEmployees(list, LEN, sort_Order)==-1)
					{
						printf("\n No se logró el ordenamiento \n");
					}else{
						printEmployees(list,LEN, sector, TOP);
						printf("\n Ordenamiento Exitoso \n");
					}
					break;
				case 6:
					informes(list, LEN);
					break;
				case 7:
					printf("\n Hasta Luego \n");
					break;
				}
			}while(option!=7);
			}
			break;
		case 8:
			printf("\n Salir.");
			break;
		}
	}while(option != 8);


return 0;
}
