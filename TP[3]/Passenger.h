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
/**
 * @brief
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_setId(Passenger* this,int id);
/**
 * @brief
 *
 * @param this
 * @param nombre
 * @return
 */
int Passenger_setNombre(Passenger* this,char* nombre);
/**
 * @brief
 *
 * @param this
 * @param apellido
 * @return
 */
int Passenger_setApellido(Passenger* this,char* apellido);
/**
 * @brief
 *
 * @param this
 * @param codigoVuelo
 * @return
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * @brief
 *
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
/**
 * @brief
 *
 * @param this
 * @param precio
 * @return
 */
int Passenger_setPrecio(Passenger* this,float precio);
/**
 * @brief
 *
 * @param aPassenger
 * @param auxId
 * @param auxNombre
 * @param auxApellido
 * @param auxPrecio
 * @param auxCodigoVuelo
 * @param auxTipo
 * @param auxEstadoVuelo
 * @return
 */
int Passenger_setFields(Passenger* aPassenger, int auxId, char* auxNombre, char* auxApellido, float auxPrecio, char* auxCodigoVuelo, int auxTipo, int auxEstadoVuelo);
/**
 * @brief
 *
 * @param this
 * @param estadoVuelo
 * @return
 */
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
//GETTERS
/**
 * @brief
 *
 * @param this
 * @param id
 * @return
 */
int Passenger_getId(Passenger* this,int* id);
/**
 * @brief
 *
 * @param this
 * @param nombre
 * @return
 */
int Passenger_getNombre(Passenger* this,char* nombre);
/**
 * @brief
 *
 * @param this
 * @param apellido
 * @return
 */
int Passenger_getApellido(Passenger* this,char* apellido);
/**
 * @brief
 *
 * @param this
 * @param tipoPasajero
 * @return
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
/**
 * @brief
 *
 * @param this
 * @param codigoVuelo
 * @return
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * @brief
 *
 * @param this
 * @param precio
 * @return
 */
int Passenger_getPrecio(Passenger* this,float* precio);
/**
 * @brief
 *
 * @param this
 * @param estadoVuelo
 * @return
 */
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);
//Herramientas
/**
 * @brief
 *
 * @param pasajero
 */
void Passenger_mostrarUnPasajero(Passenger* pasajero);
/**
 * @brief
 *
 * @param path
 * @param id
 * @return
 */
int obtenerId(char* path, int* id);
/**
 * @brief
 *
 * @param id
 */
void autoIncremental(int* id);
/**
 * @brief
 *
 * @param pArrayListPassenger
 * @param id
 * @return
 */
int buscar_PasajeroPorId(LinkedList *pArrayListPassenger, int *id);

// ABM
/**
 * @brief
 *
 * @param pArrayListPassenger
 * @param id
 * @return
 */
int addPassenger(LinkedList* pArrayListPassenger,int* id);
/**
 * @brief
 *
 * @param pArrayListPassenger
 * @param id
 * @return
 */
int modificar_Pasajero(LinkedList *pArrayListPassenger, int *id);

//Menus
int subMenu_Dos();
int menuTen();
int subMenu_One();
int Passenger_MenuOrden();
int Passenger_MenuCriterio();

//Comparadores
/**
 * @brief
 *
 * @param passenger1
 * @param passenger2
 * @return
 */
int Passenger_CompararId(void* passenger1, void* passenger2);
/**
 * @brief
 *
 * @param passenger1
 * @param passenger2
 * @return
 */
int Passenger_CompararNombre(void* passenger1, void* passenger2);
/**
 * @brief
 *
 * @param passenger1
 * @param passenger2
 * @return
 */
int Passenger_CompararApellido(void *passenger1, void *passenger2);
/**
 * @brief
 *
 * @param passenger1
 * @param passenger2
 * @return
 */
int Passenger_CompararPrecio(void *passenger1, void *passenger2);
/**
 * @brief
 *
 * @param passenger1
 * @param passenger2
 * @return
 */
int Passenger_CompararTipoPasajero(void *passenger1, void *passenger2);
/**
 * @brief
 *
 * @param passenger1
 * @param passenger2
 * @return
 */
int Passenger_CompararCodigoVuelo(void *passenger1, void *passenger2);
/**
 * @brief
 *
 * @param passenger1
 * @param passenger2
 * @return
 */
int Passenger_CompararEstadoDeVuelo(void *passenger1, void *passenger2);


#endif /* PASSENGER_H_ */
