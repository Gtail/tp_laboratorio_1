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
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define LEN 5
#define TOP 5


int main(void){
	setbuf(stdout,NULL);
	int initialize;
	int option;
	int optionSub;
	int id=0;
	Employee list[LEN];
	eSector sectorList[TOP]={{1,"sistemas"},{2,"administracion"},{3,"produccion"}};

	initialize=initEmployees(list, LEN);
	if(initialize==0){
	do{
		option = subMenu();
		switch(option){
		case 1:
			printf("\n Usted ha elegido la opcion Nº1: Alta de Empleado \n");
			if(registerEmployee(list, LEN)!=1){
				printf("\n Alta ok \n");
			}
			break;
		case 2:
			printf("\n Usted ha elegido la opcion Nº2: Modificacion de Empleado");
			if(modifyEmployee(list, LEN)==1){
			printf("\n Modificacion exitosa \n");
			}
			break;
		case 3:
			if(removeEmployee(list, LEN, id)==0)
			{
				printf("\n Eliminacion exitosa \n");
			}
			break;
		case 4:
			do{
				optionSub=subMenu2();
				switch(optionSub){
				case 5:
					break;
				case 6:
					break;
				}
			}while(option!=6);
			break;
		case 7:
			printf("\n Salir.");
			break;
		}
	}while(option != 8);
	}else{
		printf("Error al inicializar");
	}

return 0;
}

