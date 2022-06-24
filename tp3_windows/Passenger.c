/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

int menuTen()
{
	int opcion;
	printf("\n\t>-MENU PRINCIPAL-<\t\n");
	printf("-----------------------------------------\n");
	printf(" Opcion 1 Cargar los datos de los empleados en Modo Texto \n");
	printf(" Opcion 2 Cargar los datos de los empleados en Modo Binario\n");
	printf(" Opcion 3 Dar de Alta un empleado \n");
	printf(" Opcion 4 Modificar un empleado \n");
	printf(" Opcion 5 Dar de Baja un empleado  \n");
	printf(" Opcion 6 Listar empleados \n");
	printf(" Opcion 7 Ordenar empleados \n");
	printf(" Opcion 8 Guardar los datos de los empleados en Modo Texto \n");
	printf(" Opcion 9 Guardar los datos de los empleados en Modo Binario \n");
	printf(" Opcion 10 Salir \n\n");

	scanf("%d", &opcion);
	opcion=getValidInt("Ingrese una Opcion 1 - 10", "Error Ingrese una opcion 1 - 10", 1, 10);
	return opcion;
}

int subMenu_One()
{
	int opcion;
	printf("\n\t>-MENU MODIFICACION-<\t\n");
	printf("-----------------------------------------\n");
	printf("\n Opcion 1 Modificar el Nombre \n");
	printf("\n Opcion 2 Modificar el Apellido \n");
	printf("\n Opcion 3 Modificar el Precio \n");
	printf("\n Opcion 4 Modificar el Tipo de Pasajero \n");
	printf("\n Opcion 5 Modificar el Codigo de Vuelo \n");
	printf("\n Opcion 6 Modificar el Estado de Vuelo \n");
	printf("\n Opcion 7  Salir \n");

	scanf("%d", &opcion);
	opcion=getValidInt("Ingrese una Opcion 1 - 7", "Error Ingrese una opcion 1 - 7", 1, 7);
	return opcion;
}

int Passenger_MenuOrden()
{
	int opcion;

	printf("\n\t>-MENU ORDENAMIENTO-<\t\n");
	printf("-----------------------------------------\n");
	printf("1. Ordenar por ID\n");
	printf("2. Ordenar por Nombre\n");
	printf("3. Ordenar por Apellido \n");
	printf("4. Ordenar por Precio\n");
	printf("5. Ordenar por Tipo de Pasajero \n");
	printf("6. Ordenar por Codigo de Vuelo \n");
	printf("7. Ordenar por Estado de Vuelo \n");
	printf("8. Mostrar Listado \n");
	printf("9. Salir\n");

	opcion=getValidInt("Ingrese una Opcion 1 - 9", "Error Ingrese una opcion 1 - 9", 1, 9);

	return opcion;
}

int Passenger_MenuCriterio()
{
	int opcion;

	printf("\n\t>-CRITERIO DE ORDENAMIENTO-<\t\n");
	printf("-----------------------------------------\n");
	printf("0. Descendente\n");
	printf("1. Ascendente\n");

	opcion=getValidInt("Ingrese una Opcion 0 - 1", "Error Ingrese una opcion 0 - 1", 0, 1);

	return opcion;
}

Passenger* Passenger_new(){
	Passenger* auxPassenger;

	auxPassenger = (Passenger*) malloc(sizeof(Passenger));

	Passenger_setFields(auxPassenger, 0, " sin asignar ", " sin asignar ", 0, " no code ", 2, 2);
	return auxPassenger;

}
Passenger* Passenger_newParametros(char *idStr, char *nombreStr, char *apellidoStr, char *precioStr,
		char *codigoVueloStr, char *tipoPasajeroStr, char *estadoVueloStr) {
	Passenger *pPassenger = Passenger_new();
	int auxId;
	int auxTipo;
	float auxPrecio;
	int auxStatus;

	auxId = atoi(idStr);
	auxTipo = atoi(tipoPasajeroStr);
	auxPrecio = atof(precioStr);
	auxStatus = atoi(estadoVueloStr);

	if (pPassenger != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL
			&& codigoVueloStr != NULL && tipoPasajeroStr != NULL && estadoVueloStr != NULL) {
		if (Passenger_setFields(pPassenger, auxId, nombreStr, apellidoStr,auxPrecio, codigoVueloStr,
				auxTipo, auxStatus) != -1) {

		}else{
			Passenger_delete(pPassenger);
		}
	}

	return pPassenger;
}

int Passenger_setFields(Passenger* aPassenger, int auxId, char* auxNombre, char* auxApellido, float auxPrecio, char* auxCodigoVuelo, int auxTipo, int auxEstadoVuelo)
{
	int retorno=-1;
	int id=Passenger_setId(aPassenger, auxId);
	int nombre=Passenger_setNombre(aPassenger, auxNombre);
	int apellido=Passenger_setApellido(aPassenger, auxApellido);
	int precio=Passenger_setPrecio(aPassenger, auxPrecio);
	int codigoV=Passenger_setCodigoVuelo(aPassenger, auxCodigoVuelo);
	int tipo=Passenger_setTipoPasajero(aPassenger, auxTipo);
	int estVuelo=Passenger_setEstadoVuelo(aPassenger, auxEstadoVuelo);

	if(aPassenger != NULL)
	{
		if(id==0&& nombre==0&& apellido==0&& precio==0&& codigoV==0&& tipo==0&& estVuelo==0)
		{
			retorno=0;
		}else{
			printf("Error al asignar los datos \n");
		}
	}
	return retorno;
}


void Passenger_delete(Passenger *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

int Passenger_setId(Passenger *this, int id) {
	int retorno = -1;

	if (this != NULL && id >= 0) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setNombre(Passenger *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		if (strlen(nombre) < 50 && strlen(nombre) > 1) {

			strcpy(this->nombre, nombre);
			retorno = 0;
		}
	}
	return retorno;
}
int Passenger_setApellido(Passenger *this, char *apellido) {
	int retorno = -1;

	if (this != NULL && apellido != NULL) {
		if (strlen(apellido) < 50 && strlen(apellido) > 2) {

			strcpy(this->apellido, apellido);
			retorno = 0;
		}
	}
	return retorno;
}
int Passenger_setPrecio(Passenger* this, float precio){
	int retorno=-1;
	if(this!=NULL)
	{
		if((precio>9999 && precio <60000) || precio==0)
		{
			this->precio=precio;
			retorno=0;
		}
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {
	int retorno = -1;
	if (this != NULL) {
		if (tipoPasajero < 4 && tipoPasajero > 0) {
			this->tipoPasajero = tipoPasajero;
			retorno = 0;
		}
	}
	return retorno;
}
int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int retorno = -1;

	if (this != NULL && codigoVuelo != NULL) {
		if (strlen(codigoVuelo) < 10 && strlen(codigoVuelo) > 3) {

			strcpy(this->codigoVuelo, codigoVuelo);
			retorno = 0;
		}
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int retorno=-1;
	if(this!=NULL)
	{
		if(estadoVuelo<5 || estadoVuelo>0)
		{
			this->estadoDeVuelo=estadoVuelo;
			retorno=0;
		}

	}
	return retorno;
}


int Passenger_getId(Passenger *this, int *id) {
	int retorno = -1;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}


int Passenger_getApellido(Passenger *this, char *apellido) {
	int retorno = -1;

	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int retorno = -1;

	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {
	int retorno = -1;

	if (this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}


int Passenger_getPrecio(Passenger *this, float *precio) {
	int retorno = -1;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int retorno=-1;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		*estadoVuelo=this->estadoDeVuelo;
		retorno=0;
	}
	return retorno;
}

int Passenger_getdescripcionTipoPasajero(int tipoPasajero , char* descripcionTipo)
{
	int retorno=-1;

	if(tipoPasajero<4 &&  tipoPasajero>0 && descripcionTipo!=NULL)
	{
		if(tipoPasajero==1)
		{
			strcpy(descripcionTipo, "First Class");
		}
		else if(tipoPasajero==2)
		{
			strcpy(descripcionTipo, "Executive Class");
		}
		else
		{
			strcpy(descripcionTipo, "Economy Class");
		}
		retorno=0;
	}

	return retorno;
}

int Passenger_getdescripcionEstadoVuelo(int estadoVuelo , char* descripcionE_Vuelo)
{
	int retorno=-1;

		if(estadoVuelo<5 &&  estadoVuelo>0 && descripcionE_Vuelo!=NULL)
		{
			switch(estadoVuelo){
			case 1:
				strcpy(descripcionE_Vuelo, "Aterrizado");
				break;
			case 2:
				strcpy(descripcionE_Vuelo, "En Horario");
				break;
			case 3:
				strcpy(descripcionE_Vuelo, "En Vuelo");
				break;
			case 4:
				strcpy(descripcionE_Vuelo, "Demorado");
				break;
			}
			retorno=0;
		}

		return retorno;
}
void Passenger_mostrarUnPasajero(Passenger* pasajero) {
	int id;
	int tipoPasajero;
	int estadoVuelo;
	float precio;
	char nombre[50];
	char apellido[50];
	char codigoDeVuelo[10];
	char descripcion_TipoPasajero[50];
	char descripcion_EstadoVuelo[50];



	if (Passenger_getId(pasajero, &id)==0
			&& Passenger_getNombre(pasajero, nombre)==0
			&& Passenger_getApellido(pasajero, apellido)==0
			&& Passenger_getPrecio(pasajero, &precio)==0
			&& Passenger_getCodigoVuelo(pasajero, codigoDeVuelo)==0
			&& Passenger_getTipoPasajero(pasajero, &tipoPasajero)==0
			&& Passenger_getdescripcionTipoPasajero(tipoPasajero,
					descripcion_TipoPasajero)==0
			&& Passenger_getEstadoVuelo(pasajero, &estadoVuelo)==0
			&& Passenger_getdescripcionEstadoVuelo(estadoVuelo,
					descripcion_EstadoVuelo)==0) {
		printf(
				"| %-5d |  %-12s|  %-12s|  $%-8.2f |       %-10s    |    %-15s   |      %-13s  |\n",
				id, nombre, apellido, precio, codigoDeVuelo,
				descripcion_TipoPasajero, descripcion_EstadoVuelo);
	} else {
		printf("Error al bontener los datos del pasajero a mostrar \n");

	}

}

int obtenerId(char* path, int* id)
{
	int retorno=-1;
	FILE* pFile;

	if(path!=NULL && id!=NULL)
	{
		pFile=fopen(path,"r");
		fscanf(pFile,"%d",id);
		retorno=1;
	}
	fclose(pFile);
	return retorno;
}

void autoIncremental(char* path)
{
	FILE* pFile;
	int id=0;

		if(path!=NULL)
		{
			pFile=fopen(path,"w");
			id+=1;
			fprintf(pFile,"%n",&id);
		}
		fclose(pFile);
}

int addPassenger(Passenger* pPassenger,int id) {

	int retorno =-1;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero=0;
	char codigoVuelo[10];
	int estadoDeVuelo=2;


			if (getStringSoloLetras("\n Ingrese el nombre del Pasajero \n","\n Error, intente nuevamente ingresando SOLO letras. \n",nombre,50,2) != 1) {
				printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
			}
			if (getStringSoloLetras("\n Ingrese el Apellido del Pasajero \n","\n Error, intente nuevamente ingresando SOLO letras. \n",apellido,50,2) != 1) {
						printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
					}
			if(getStringAlfaNumerico("\n Ingrese el Codigo de Vuelo del Pasajero \n","\n Error, intente nuevamente ingresando SOLO letras y numeros. \n" , codigoVuelo, 10, 2)!=1) {
				printf("\n Error, intente nuevamente ingresando SOLO letras y Numeros. \n");
			}

			chargeSalary(&precio, "\n Inrese el Precio \n", "\n Error, cargue el Precio nuevamente \n");

			getValidInt("Ingrese el Tipo de Pasajero: 1- First Class 2- Executive Class 3- Economy Class \n", "Error Ingrese SOLO: 1- First Class 2- Executive Class 3- Economy Class\n", 1, 4);



			if(Passenger_setFields(pPassenger, id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoDeVuelo)!=-1)
			{
				Passenger_mostrarUnPasajero(pPassenger);
				retorno=0;
			}else{
				Passenger_mostrarUnPasajero(pPassenger);
				printf(" Error en el set \n");
			}


	return retorno;
	}

int buscar_PasajeroPorId(LinkedList *pArrayListPassenger, int *id) {
	int retorno = -1;
	int i;
	int tamList;
	 Passenger *auxPassenger;

	if (pArrayListPassenger != NULL && id != NULL) {
		tamList = ll_len(pArrayListPassenger);

		for (i = 0; i <= tamList; i++) {
			auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);

			if (auxPassenger != NULL) {
				if (*id == auxPassenger->id) {

					retorno = i;
					break;
				}
			}
		}
	}

	return retorno;
}

int modificar_Pasajero(LinkedList *pArrayListPassenger, int *id) {
	int retorno = -1;
	int i;
	Passenger *auxPassenger=NULL;
	int tamList;
	int opcion;
	int index;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero=0;
	char codigoVuelo[10];
	int estadoDeVuelo=0;


	if (pArrayListPassenger != NULL && id != NULL) {
		tamList = ll_len(pArrayListPassenger);
		for (i = 0; i < tamList; i++) {
			index=buscar_PasajeroPorId(pArrayListPassenger, id);
				if (index != -1) {
					auxPassenger= (Passenger*) ll_get(pArrayListPassenger, index);
					do {
						opcion = subMenu_One();
						switch (opcion) {
						case 1:
							printf(
									"\n Usted ha seleccionado 1: Modificar el Nombre \n");
							if (getStringSoloLetras(
									"\n Ingrese el Nuevo Nombre \n",
									"\n ERROR. Ingrese el Nuevo Nombre \n",
									nombre, 50, 2) != 1) {
								printf("\n Error. Reinicie el proceso \n");
							} else {
								printf(
										"\n La carga del NUEVO nombre ha sido un exito \n");
								Passenger_setNombre(auxPassenger, nombre);
								Passenger_mostrarUnPasajero(auxPassenger);
								retorno = 1;

							}
							break;
						case 2:
						printf(
								"\n Usted ha seleccionado 1: Modificar el Apellido \n");
						if (getStringSoloLetras("\n Ingrese el Nuevo Apellido \n",
								"\n ERROR. Ingrese el Nuevo Nombre \n", apellido,
								50, 2) != 1) {
							printf("\n Error. Reinicie el proceso \n");
						} else {
							printf(
									"\n La carga del NUEVO Apellido ha sido un exito \n");
							Passenger_setApellido(auxPassenger, nombre);
							Passenger_mostrarUnPasajero(auxPassenger);
							retorno = 1;

						}

							break;
						case 3:
							printf(
									"\n Usted ha seleccionado 3: Modificar el Precio \n");
							chargeSalary(&precio,
									"\n Ingrese el Nuevo Precio \n",
									"\n ERROR. Ingrese el Nuevo Precio \n");
							if (precio > 0) {
								Passenger_setPrecio(auxPassenger, precio);
								Passenger_mostrarUnPasajero(auxPassenger);
								retorno = 1;
							}
							break;
						case 4:
						printf(
								"\n Usted ha seleccionado 2: Modificar el Tipo de Pasajero \n");
						tipoPasajero =
								getValidInt(
										"\n Ingrese el Nuevo Tipo de Pasajero:  1- First Class 2- Executive Class 3- Economy Class\n",
										"\n ERROR. Ingrese el Nuevo Tipo de Pasajero:  1- First Class 2- Executive Class 3- Economy Class \n",
										1, 3);
						if (tipoPasajero >= 0) {
							Passenger_setTipoPasajero(auxPassenger, tipoPasajero);
							Passenger_mostrarUnPasajero(auxPassenger);
							retorno = 1;
						}
							break;
						case 5:
						printf(
								"\n Usted ha seleccionado 1: Modificar el Codigo de Vuelo \n");
						if (getStringSoloLetras("\n Ingrese el Codigo de Vuelo \n",
								"\n ERROR. Ingrese el Codigo de Vuelo \n", codigoVuelo,
								10, 2) != 1) {
							printf("\n Error. Reinicie el proceso \n");
						} else {
							printf(
									"\n La carga del NUEVO Codigo de Vuelo ha sido un exito \n");
							Passenger_setCodigoVuelo(auxPassenger, codigoVuelo);
							Passenger_mostrarUnPasajero(auxPassenger);
							retorno = 1;

						}
							break;
						case 6:
						printf(
								"\n Usted ha seleccionado 2: Modificar el Estado de Vuelo \n");
						estadoDeVuelo =
								getValidInt(
										"\n Ingrese el Nuevo Estado de Vuelo : 1- Aterrizado 2- En Horario 3- En Vuelo 4- Demorado\n",
										"\n ERROR. Ingrese el Nuevo Estado de Vuelo :  1- Aterrizado 2- En Horario 3- En Vuelo 4- Demorado \n",
										1, 4);
						if (estadoDeVuelo > 0) {
						Passenger_setEstadoVuelo(auxPassenger, estadoDeVuelo);
						Passenger_mostrarUnPasajero(auxPassenger);
							retorno = 1;
						}
							break;
						case 7:
							printf("Menu Principal \n");
							break;

						}
					} while (opcion != 7);
				}

			}
		}
	return retorno;
	}




int Passenger_CompararId(void* passenger1, void* passenger2)
{
	int resultado = 0;
	Passenger* passenger = NULL;
	Passenger* passengerDos = NULL;
	int id1;
	int id2;

	if(passenger1!=NULL && passenger2!=NULL)
	{
		passenger = (Passenger*) passenger1;
		passengerDos = (Passenger*) passenger2;

		if((!Passenger_getId(passenger, &id1)) && (!Passenger_getId(passengerDos, &id2)))
		{
			//0 -> si son iguales
			//1 -> mayor
			//-1 -> menor
			if(id1 > id2)
			{
				resultado = 1;
			}
			else
			{
				if(id1 < id2)
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}

int Passenger_CompararNombre(void* passenger1, void* passenger2)
{
	int resultado = -1;
	Passenger* passenger = NULL;
	Passenger* passengerDos = NULL;
	char nombre1[128];
	char nombre2[128];

	if(passenger1!=NULL && passenger2!=NULL)
	{
		passenger = (Passenger*) passenger1;
		passengerDos = (Passenger*) passenger2;

		if((!Passenger_getNombre(passenger, nombre1)) && (!Passenger_getNombre(passengerDos, nombre2)))
		{
			resultado = strcmp(nombre1,nombre2);
		}
	}

	return resultado;
}

int Passenger_CompararApellido(void *passenger1, void *passenger2) {
	int resultado = -1;
	Passenger *passenger = NULL;
	Passenger *passengerDos = NULL;
	char apellido1[128];
	char apellido2[128];

	if (passenger1 != NULL && passenger2 != NULL) {
		passenger = (Passenger*) passenger1;
		passengerDos = (Passenger*) passenger2;

		if ((!Passenger_getApellido(passenger, apellido1)) && (!Passenger_getApellido(passengerDos, apellido2))) {
			resultado = strcmp(apellido1, apellido2);
		}
	}

	return resultado;
}

int Passenger_CompararPrecio(void *passenger1, void *passenger2) {
	int resultado = 0;
	Passenger *passenger = NULL;
	Passenger *passengerDos = NULL;
	float precio;
	float precio2;

	if (passenger1 != NULL && passenger2 != NULL) {
		passenger = (Passenger*) passenger1;
		passengerDos = (Passenger*) passenger2;

		if ((!Passenger_getPrecio(passenger, &precio)) && (!Passenger_getPrecio(passengerDos, &precio2))) {
			//0 -> si son iguales
			//1 -> mayor
			//-1 -> menor
			if (precio > precio2) {
				resultado = 1;
			} else {
				if (precio < precio2) {
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}

int Passenger_CompararTipoPasajero(void *passenger1, void *passenger2) {
	int resultado = -1;
	int tipo1;
	int tipo2;
	Passenger *passenger = NULL;
	Passenger *passengerDos = NULL;
	char descripcionTipo[128];
	char descripcionTipo2[128];

	if (passenger1 != NULL && passenger2 != NULL) {
		passenger = (Passenger*) passenger1;
		passengerDos = (Passenger*) passenger2;

		if ((!Passenger_getTipoPasajero(passenger, &tipo1)) && (!Passenger_getTipoPasajero(passengerDos, &tipo2))) {
			if ((!Passenger_getdescripcionTipoPasajero(tipo1,
					descripcionTipo)) && (!Passenger_getdescripcionTipoPasajero(tipo2,
																				descripcionTipo2))) {
				resultado = strcmp(descripcionTipo, descripcionTipo2);

			}
		}
	}

	return resultado;
}

int Passenger_CompararCodigoVuelo(void *passenger1, void *passenger2) {
	int resultado = -1;
	Passenger *passenger = NULL;
	Passenger *passengerDos = NULL;
	char codigoVuelo[10];
	char codigoVuelo2[10];

	if (passenger1 != NULL && passenger2 != NULL) {
		passenger = (Passenger*) passenger1;
		passengerDos = (Passenger*) passenger2;

		if ((!Passenger_getCodigoVuelo(passenger, codigoVuelo)) && (!Passenger_getCodigoVuelo(passengerDos, codigoVuelo2))) {
			resultado = strcmp(codigoVuelo, codigoVuelo2);
		}
	}

	return resultado;
}

int Passenger_CompararEstadoDeVuelo(void *passenger1, void *passenger2) {
	int resultado = -1;
	int estado1;
	int estado2;
	Passenger *passenger = NULL;
	Passenger *passengerDos = NULL;
	char descripcionEstado[128];
	char descripcionEstado2[128];

	if (passenger1 != NULL && passenger2 != NULL) {
		passenger = (Passenger*) passenger1;
		passengerDos = (Passenger*) passenger2;

		if ((!Passenger_getEstadoVuelo(passenger, &estado1)) && (!Passenger_getEstadoVuelo(passengerDos, &estado2))) {
			if ((!Passenger_getdescripcionEstadoVuelo(estado1, descripcionEstado)) &&
					(!Passenger_getdescripcionEstadoVuelo(estado2, descripcionEstado2))) {
				resultado = strcmp(descripcionEstado, descripcionEstado2);

			}
		}
	}

	return resultado;
}
