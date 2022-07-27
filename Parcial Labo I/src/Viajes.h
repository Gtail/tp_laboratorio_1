/*
 * Viajes.h
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */


#ifndef VIAJES_H_
#define VIAJES_H_
#include "Aerolineas.h"
#include "fecha.h"
#include "Aviones.h"

/*
 * Destino:
• id(comienza en 20000)
• descripción (máximo 25 caracteres)
• precio
Vuelo:
• id (autoincremental)
• idAvion (debe existir) Validar
• idDestino (debe existir) Validar
• fecha (Validar día, mes y año)
 */

struct{
	int idDestino; //arranca en 20000: 20000 calafate / 20001 Miami / 20002Madrid / 20003 Amsterdam
	char descripcion[25]; //Calafate: $22250, Miami: $103000, Madrid: $84400, Amsterdam: $95600)
	float precio;
}typedef Destino;

struct{

	int idVuelo; //autoincremental
	int idAvion; //validar Existencia
	int idDestino; //Validar existencia
	int isEmpty;
	Fecha fecha; //validar dia mes y año
}typedef Vuelo;

int listarDestinos(Destino destinos[], int tam);


int validarViaje(Destino destinos[], int top, int* idDestino);
void HardcodeDestinos(Destino destinos[], int top);


int inicializarVuelos(Vuelo *vuelos, int tamV);
int buscarVueloLibre(Vuelo* vuelos, int tamV, int* index);

int hardcodearVuelos(Vuelo vec[],int tamV, int cant, Avion* list, int tamAv, int* idVuelo, Destino*destinos, int tamD);
int listarDestinos(Destino destinos[], int tam);
int altaDeVuelo(Avion* aviones, int tamAv, Vuelo* vuelos, int tamV, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA,  Destino* destinos, int tamD, Piloto* pilotos, int tamP, int* idVuelo);
int listarVuelos(Avion* aviones, int tamAv, Vuelo* vuelos, int tamV, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA, Destino* destinos, int tamD);
int getDestino_ById(char tipo[], int idDestino, Destino destinos[], int top);
void showVuelo(Vuelo vuelos, int tamV, Destino* destinos, Avion aviones[], int tamAv, Tipo tipos[], int tamT);
int getTipo_ByIdAvion(int* tipo, int idAvion, Avion aviones[], int top);
int inicializarVuelos(Vuelo *vuelos, int tamV);
int buscarVueloLibre(Vuelo* vuelos, int tamV, int* index);
int vuelosPorAvion(Vuelo* vuelos, int tamV, Avion* list, int tamAv, Tipo* tipos, int tamT, Aerolinea* aerolineas,int tamA, Piloto* pilotos,int tamP);
int precioTotalPorAvion(Vuelo* vuelos, int tamV, Avion* list, int tamAv, Tipo* tipos, int tamT, Aerolinea* aerolineas,int tamA, Piloto* pilotos,int tamP, Destino* destinos, int tamD);
int getPrecio_ById(float* precio, int idDestino, Destino destinos[], int top);

int findIndexDestino_ById(int* index, int idDestino, Destino destinos[], int tamD);

int mostrarVuelosPorFecha(Vuelo* vuelos, int tamV, Destino* destinos, int tamD, Avion* aviones, int tamAv, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA);

int mostrarAvionesPorDestino(Vuelo* vuelos, int tamV, Tipo* tipos, int tamT, Avion* aviones, int tamAv, Destino* destinos, int tamD);
#endif /* VIAJES_H_ */
