/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */


#ifndef PASSENGER_H
#define PASSENGER_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "inputUtn.h"


typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoDeVuelo;
	int isEmpty;

}Passenger;

//Constructores y destructores
Passenger* Passenger_new();
Passenger* Passenger_newParametros(char *idStr, char *nombreStr, char *apellidoStr, char *precioStr,
		char *codigoVueloStr, char *tipoPasajeroStr, char *estadoVueloStr);
void Passenger_delete();

//SETTERS
int Passenger_setId(Passenger* this,int id);
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_setFields(Passenger* aPassenger, int auxId, char* auxNombre, char* auxApellido, float auxPrecio, char* auxCodigoVuelo, int auxTipo, int auxEstadoVuelo);
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
//GETTERS
int Passenger_getId(Passenger* this,int* id);
int Passenger_getNombre(Passenger* this,char* nombre);
int Passenger_getApellido(Passenger* this,char* apellido);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);
//Herramientas
void Passenger_mostrarUnPasajero(Passenger* pasajero);
int obtenerId(char* path, int* id);
void autoIncremental(int* id);

int buscar_PasajeroPorId(LinkedList *pArrayListPassenger, int *id);

// ABM
int addPassenger(LinkedList* pArrayListPassenger,int* id);
int modificar_Pasajero(LinkedList *pArrayListPassenger, int *id);

//Menus
int subMenu_Dos();
int menuTen();
int subMenu_One();
int Passenger_MenuOrden();
int Passenger_MenuCriterio();

//Comparadores
int Passenger_CompararId(void* passenger1, void* passenger2);
int Passenger_CompararNombre(void* passenger1, void* passenger2);
int Passenger_CompararApellido(void *passenger1, void *passenger2);
int Passenger_CompararPrecio(void *passenger1, void *passenger2);
int Passenger_CompararTipoPasajero(void *passenger1, void *passenger2);
int Passenger_CompararCodigoVuelo(void *passenger1, void *passenger2);
int Passenger_CompararEstadoDeVuelo(void *passenger1, void *passenger2);


#endif /* PASSENGER_H_ */
