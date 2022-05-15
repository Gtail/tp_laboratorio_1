/*
 * ArrayPassenger.c
 *
 *  Created on: 21 abr. 2022
 *      Author: Gian
 */

#include "ArrayPassenger.h"

int subMenu(){

	printf("\n Seleccione 1- Alta de Empleado 2- Modificar Empleado 3- Mostrar por Descipcion 4- Informar \n");
	int option;

	printf("\n Opcion 1 Alta de Pasajero \n");
	printf("\n Opcion 2 Modificar Pasajero \n");
	printf("\n Opcion 3 Baja de Pasajero \n");
	printf("\n Opcion 4 Informar \n");
	scanf("%d", &option);

	return option;

}

int subMenu2(){

	printf("\n Seleccione | 5- Listar empleados alfabeticamente Apellido y Sector | 6- Total y Promedio de los Salarios | 7- Listar pasajeros por Codigo de Vuelo Activos | 8- Salir \n");
	int option;

	printf("\n Opcion 5 Informar Listado de pasajeros Alfabeticamente Apellido y Tipo de Pasajero \n");
	printf("\n Opcion 6 Total y Promedio de los Pasajes. Cuantos lo superan \n");
	printf("\n Opcion 7 Informar Listado de pasajeros por Codigo de Vuelo Activos \n");
	printf("\n Opcion 8 Salir\n");
	scanf("%d", &option);

	return option;

}

int subMenu_Modify(){
	printf("\n Seleccione | 1- Modificar Nombre | 2- Modificar Apellido | 3- Salir \n");
		int option;

		printf("\n Opcion 1 Modificar Nombre del Pasajero \n");
		printf("\n Opcion 2 Modificar Apellido del Empleado \n");
		printf("\n Opcion 3 Modificar Precio \n");
		printf("\n Opcion 4 Modificar Tipo de Pasajero \n");
		printf("\n Opcion 5 Modificar Codigo de Vuelo \n");
		printf("\n Opcion 6 Salir \n");
		scanf("%d", &option);

		return option;
}



int initPassengers(Passenger list[], int len) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}

	return retorno;
}


int addPassenger(Passenger list[], int len, int* id, char name[],
		char lastName[], float price, int typePassenger, char flycode[]) {

	int retorno = -1;
	int index = -1;

	if (list != NULL && len > 0) {
		if (findEmptyPassenger(list, len, &index) != -1) {
			if (utn_getString("Ingrese el Nombre del pasajero\n", "Error Ingrese el Nombre del pasajero \n", 51, 2, name)==0) {

				strcpy(list[index].name, name);
				printf("Nombre ok \n");
			}else{
				printf("Ha reintentado demasiadas veces, intente nuevamente \n");
			}
			if (utn_getString("Ingrese el apellido del pasajero  \n", "ERROR, ingrese SOLO letras para el apellido del pasajero  \n", 51, 3, lastName)==0) {

				strcpy(list[index].lastName, lastName);

			}else{
				printf("Ha reintentado demasiadas veces, intente nuevamente \n");
			}
			if(chargeSalary(&price, "Ingrese el precio del vuelo \n",
					"Error, Ingrese SOLO numeros \n")!=-1){
				printf("Precio ok \n");
			}
			typePassenger =
					getValidInt(
							"Ingrese un tipo de pasajero 1- Primera Clase 2- Clase Ejecutiva 3- Clase Turista \n",
							"Error. Ingrese SOLO 1- Primera Clase 2- Clase Ejecutiva 3- Clase Turista \n",
							0, 4);
			if(getStringAlfaNumerico("Ingrese el codigo de vuelo \n", "ERROR solo letras y numeros \n", flycode, 10, 3)==0){
				printf("Ha reintentado demasiadas veces, intente nuevamente \n");
			}else{
				strcpy(list[index].flycode, flycode);
			}
			retorno=0;
		}
		list[index].id=*id;
		list[index].typePassenger=typePassenger;
		list[index].price=price;
		list[index].isEmpty=FULL;
		list[index].statusFlight=ACTIVO;
		(*id)++;
	}

	return retorno;
}

int findEmptyPassenger(Passenger list[], int len, int *index) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == EMPTY) {
				*index = i;
				retorno=0;
				break;
			}
		}

	}

	return retorno;
}



void printPassengers(Passenger lista[],int len, ePassage passages[], int top, int tams)
{

    if(lista !=NULL && len>0)
    {
        for (int i=0; i<len; i++)
        {
            if(lista[i].isEmpty ==FULL)
            {

                show_OneEmployee(lista[i], passages, top, tams);


            }
        }
    }
    else
    {
        printf("\n No hay empleados que listar\n");
    }
}

void show_OneEmployee(Passenger onePassenger, ePassage passages[], int top, int tams) {
	char auxPassage[51];
	char auxStatus[51];

	getClass_byId(auxPassage, onePassenger.typePassenger, passages, top);
	getStatus_byId(auxStatus, onePassenger.statusFlight, passages, tams);

		printf(
				"\n |ID   | NOMBRE  | APELLIDO  | PRECIO	| CODIGO DE VUELO |   CLASE     |	ESTADO DE VUELO        ");
		printf(
				"\n |%d  |%10s  |%11s  |%.2f  |%10s  |%8s  |%10s  \n",
																										onePassenger.id,
																										onePassenger.name,
																										onePassenger.lastName,
																										onePassenger.price,
																										onePassenger.flycode,
																										auxPassage,
																										auxStatus);





}



int alta_Forzada(Passenger list[], int tam, ePassage passages[], int cant, int* idAuto, int top, int tams)
{

    int todoOk = 0;
    Passenger pasajeros[] =
    {
        {0, "Juan", "Franzoso", "C203",   100000 ,1,1,1},
        {0, "Daniela", "Gimenez", "C204", 120000 ,3,1,0},
        {0, "Lucia", "Camuzo", "C205",    40000  ,2,1,1},
        {0, "Mauro", "Gonzalez", "C206",  232000 ,1,1,0},
        {0, "Diego", "Torres", "C207",    12000  ,2,1,1},
        {0, "Juana", "Estebanez", "C208", 130000 ,3,1,1},
        {0, "Miguel", "Coccioli", "C209", 120000 ,2,1,0},
        {0, "Luciano", "Granero", "C210", 150000 ,1,1,1},
        {0, "Marina", "Armani", "C211",   120000 ,3,1,0},
        {0, "Dalma", "Maradona", "C212",  110000 ,2,1,1}
    	/*int id;
    	char name[51];
    	char lastName[51];
    	char flycode[10]; //PK
    	float price;
    	int typePassenger;
    	int isEmpty;
    	int statusFlight;*/
    };

    if(list != NULL && tam > 0 && idAuto != NULL )
    {

        for(int i=0; i < cant; i++)
        {
        	list[i] = pasajeros[i];

        	list[i].id = *idAuto;
            *idAuto = *idAuto +1;

        }
        todoOk = 1;
    }

    return todoOk;

}


int findPassengerById(Passenger* list, int len,int id, int* index)
{
	int retorno=-1;
	int i;

	if(list!=NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].id==id){
			*index=i;
			retorno=0;
			}
		}
	}
	return retorno;
}

int modifyPassenger(Passenger list[], int tam, ePassage passages[], int top,
		int tams) {
	int retorno = -1;
	int index;
	int id = -1;
	int opcion;
	Passenger auxPassenger;
	printPassengers(list, tam, passages, top, tams);
	id = getValidInt("Ingrese el ID de Pasajero a Modificar \n","Error, Ingrese un ID valido", 0, tam);
	if(findPassengerById(list, tam, id, &index)!=-1){
		printf("El id %d existe\n", id);
	}else{
		printf("El id %d es inexistente \n", id);
	}
	if (index != -1) {
		printf("\n Elija: 1- Modificar Nombre 2- Modificar Apellido. 3- Modificar Precio 4- Modificar Tipo de Pasajero 5- Modificar el codigo de vuelo 6- Salir  \n");
		do {
			opcion = subMenu_Modify();
			switch (opcion) {
			case 1:
				if(utn_getString("Ingrese el Nuevo Nombre del Pasajero \n", "Error. Ingrese SOLO letras \n", 51, 3, auxPassenger.name)==0){
					strcpy(list[index].name,auxPassenger.name);
				}
				break;
			case 2:
				if(utn_getString("Ingrese el nuevo apellido del Pasajero \n", "ERROR, Ingrese SOLO letras para el nuevo apellido del Pasajero \n", 51, 3, auxPassenger.lastName)==0){
					strcpy(list[index].lastName, auxPassenger.lastName);
				}
				break;
			case 3:
				if(chargeSalary(&auxPassenger.price, "Ingrese el nuevo precio \n", "Error, ingrese SOLO numeros")!=-1){
					list[index].price=auxPassenger.price;
				}
				break;
			case 4:
				auxPassenger.typePassenger= getValidInt("Ingrese el nuevo tipo de pasajero: 1- Primera Clase 2- Clase Ejecutiva 3- Clase Turista \n", "Error, ingrese SOLO: 1- Primera Clase 2- Clase Ejecutiva 3- Clase Turista \n", 0, 4);
				list[index].typePassenger=auxPassenger.typePassenger;
				break;
			case 5:
				if(getStringAlfaNumerico("Ingrese el nuevo codigo de vuelo \n", "Error, ingrese SOLO numeros y letras", auxPassenger.flycode, 10, 2)==0){
					printf("Demasiados reintentos. Intente nuevamente \n");
				}else{
					strcpy(list[index].flycode, auxPassenger.flycode);
				}
				break;
			case 6:
				printf("Menu principal \n");
				break;
			}
		} while (opcion != 6);

	}

	return retorno;
}

int removePassenger(Passenger *list, int len, int id, ePassage passages[], int top, int tams) {
	int retorno = -1;
	int index;

	if (list != NULL && passages != NULL && top > 0 && len > 0 && tams > 0) {
		printPassengers(list, len, passages, top, tams);
		id = getValidInt("Ingrese el ID del Pasajero a eliminar \n", "ERROR, ingrese SOLO numeros", 0, len);
		if (findPassengerById(list, len, id, &index) != -1) {
			printf("El id %d existe \n", id);
		} else {
			printf("El id %d no existe \n", id);
		}
		if (index != -1) {
			list[index].isEmpty = EMPTY;
			list[index].statusFlight=INACTIVO;
			retorno=0;
		}
	}

	return retorno;
}

int sortEmployees(Passenger *list, int len, int order) {

	int retorno = -1;
	Passenger auxEmployee;

	if (list != NULL && len > 0 && order >= 0 && order <= 1) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (list[i].isEmpty==FULL && list[j].isEmpty==FULL) {
					if ((strcmp(list[i].lastName, list[j].lastName) > 0 && order == 1)
							|| (strcmp(list[i].lastName, list[j].lastName) < 0 && order == 0)) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					} else if (list[i].lastName == list[j].lastName
							&& list[i].typePassenger > list[j].typePassenger) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					} else if (list[i].lastName == list[j].lastName
							&& list[i].typePassenger < list[j].typePassenger) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}

void informes(Passenger list[], int len)
{
	float precios_Total;
	float promedio_Pasajes;
	int pasajeros_MejorPagan;
	precios_Total=0;
	promedio_Pasajes=0;
	pasajeros_MejorPagan=0;

	precios_Total=calculate_Prices(list, len);
	promedio_Pasajes=calculate_AveragePassengers(list, len);
	pasajeros_MejorPagan=calculate_ExceedPassengers(list, len);

	printf("\n  TOTAL PASAJES | PROMEDIO PASAJES  | CANT QUE SUPERA EL PASAJE PROMEDIO \n");
    printf("\n   %.2f       |    %.2f         |   %d       \n  ",precios_Total
															        ,promedio_Pasajes
															        ,pasajeros_MejorPagan);

}

float calculate_Prices(Passenger list[], int len){
	float retorno=-1;
	int i;
	float precios;
	precios=0;

	if(list!=NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty==FULL){
				precios+=list[i].price;
			}
		}
		retorno=precios;
	}


	return retorno;
}

float calculate_AveragePassengers(Passenger list[], int len){
	int Passengers;
	float Prices;
	float promedio;
	Prices=calculate_Prices(list, len);
	Passengers=calculate_Passengers(list, len);
	if(Prices>0 && Passengers>0){
		promedio=Prices/Passengers;
	}else{
		printf("\n No se pudo realizar el promedio\n");
	}
	return promedio;
}

int calculate_ExceedPassengers(Passenger list[], int len){
	int retorno=-1;
	int contPassenger=0;
	float promedio;
	int i;

	if(list!=NULL && len>0){
		promedio=calculate_AveragePassengers(list, len);
		for(i=0; i<len ;i++){
			if(promedio<list[i].price)
			{
				contPassenger++;
			}
		}
		retorno=contPassenger;
	}

	return retorno;
}

int calculate_Passengers(Passenger list[], int len) {
	int retorno=-1;
	int i;
	int passengers;
	passengers=0;
	i=0;

	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++){
			if(list[i].isEmpty==FULL){
				passengers++;
			}
		}
		retorno=passengers;
	}

	return retorno;
}


void print_ActivePassengers(Passenger lista[],int len, ePassage passages[], int top, int tams)
{

    if(lista !=NULL && len>0)
    {
        for (int i=0; i<len; i++)
        {
            if(lista[i].isEmpty ==FULL && lista[i].statusFlight==ACTIVO)
            {

                show_OneEmployee(lista[i], passages, top, tams);


            }
        }
    }
    else
    {
        printf("\n No hay empleados que listar\n");
    }
}


//3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�

int sortPassengers_ByCode(Passenger *list, ePassage passages[], int len, int top, int tams, int order) {
	int retorno = -1;
	Passenger auxPassenger;
	int i;
	int j;
	int k;

	if (list != NULL && len > 0) {
		for (i = 0; i < len - 1; i++) {

				for (j = i + 1; j < len; j++) {

					if ((strcmp(list[i].flycode, list[j].flycode) > 0
							&& order == 1)
							|| (strcmp(list[i].flycode, list[j].flycode) < 0
									&& order == 0)) {
						auxPassenger = list[i];
						list[i] = list[j];
						list[j]=auxPassenger;


				}
			}
		}
		for(k=0;k<len;k++){
			if(list[k].statusFlight==ACTIVO){
				show_OneEmployee(list[k], passages, top, tams);
			}
		}
			retorno=0;
	}
	return retorno;
}





