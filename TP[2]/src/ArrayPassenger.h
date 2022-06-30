/*
 * ArrayPassenger.h
 *
 *  Created on: 21 abr. 2022
 *      Author: Gian
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "Passage.h"
#include "inputUtn.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


#define EMPTY 1
#define FULL 0
#define ACTIVO 1
#define INACTIVO 0

struct{
	int id;
	char name[51];
	char lastName[51];
	char flycode[10]; //PK
	float price;
	int typePassenger;
	int isEmpty;
	int statusFlight;
}typedef Passenger;

//Menus
int subMenu();
int subMenu2();
int subMenu_Modify();

/**
 * @brief Busca un lugar libre
 *
 * @param list array de lista de pasajeros
 * @param len tamaño
 * @param index indice devuelto por parametro
 * @return -1 en caso de error// 0 en caso de exito
 */
int findEmptyPassenger(Passenger list[], int len, int *index);
/**
 * @brief Agrega un pasajero a la lista
 *
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 * @param id
 * @param name
 * @param lastName
 * @param price
 * @param typePassenger
 * @param flycode
 * @return -1 en caso de error// 0 en caso de exito
 */
int addPassenger(Passenger list[], int len, int* id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/**
 * @brief Inicializa la lista en EMPTY o 1
 *
 * @param list array de lista de pasajeros
 * @param len  tamaño de esa lista
 * @return -1 en caso de error// 0 en caso de exito
 */
int initPassengers(Passenger list[], int len);
/**
 * @brief Muestra un pasajero
 *
 * @param onePassenger variable auxiliar donde paso el pasajero que quiera
 * @param passages pasajes
 * @param top tamaño
 * @param tams tamaño
 */
void show_OnePassenger(Passenger onePassenger, ePassage passages[], int top, int tams);
/**
 * @brief Muestra la lista de pasajeros
 *
 * @param lista array de lista de pasajeros
 * @param len tamaño de esa lista
 * @param passages pasajes
 * @param top tamaño
 * @param tams tamaño
 */
void printPassengers(Passenger lista[],int len, ePassage passages[], int top, int tams);
/**
 * @brief Busca un pasajero por id
 *
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 * @param id que quiera buscar
 * @param index devuelve el indice si lo encontro
 * @return -1 en caso de error// 0 en caso de exito
 */
int findPassengerById(Passenger* list, int len,int id, int* index);
/**
 * @brief Modifica un pasajero de la lista
 *
 * @param list array de lista de pasajeros
 * @param tam tamaño de esa lista
 * @param passages  pasajes
 * @param top tamaño
 * @param tams tamaño
 * @return -1 en caso de error// 0 en caso de exito
 */
int modifyPassenger(Passenger list[], int tam, ePassage passages[], int top,int tams);
/**
 * @brief Elimina un pasajero de la lista
 *
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 * @param id
 * @param passages
 * @param top tamaño
 * @param tams tamaño
 * @return -1 en caso de error// 0 en caso de exito
 */
int removePassenger(Passenger *list, int len, int id, ePassage passages[], int top, int tams);
/**
 * @brief Ordena la lista de pasajeros
 *  de forma ascendente o descendente por Apellido y Tipo de Pasajero
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 * @param order 0 descendente - 1 ascendente
 * @return -1 en caso de error// 0 en caso de exito
 */
int sortPassengers(Passenger *list, int len, int order);
/**
 * @brief Muestra todos los informes
 * 	solicitados
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 */
void informes(Passenger list[], int len);
/**
 * @brief Calcula los precios totales
 *
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 * @return el total en caso de exito// -1 en caso de fallar
 */
float calculate_Prices(Passenger list[], int len);
/**
 * @brief Calcula el promedio de precios de los
 * pasajes
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 * @return el promedio en caso de exito// -1 en caso de fallar
 */
float calculate_AveragePassengers(Passenger list[], int len);
/**
 * @brief Calcula la cantidad de pasajeros
 *  que exceden el promedio de precios
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 * @return la cantidad en caso de exito// -1 en caso de fallar
 */
int calculate_ExceedPassengers(Passenger list[], int len);
/**
 * @brief Calcula la cantidad de pasajeros
 * activos
 * @param list array de lista de pasajeros
 * @param len tamaño de esa lista
 * @return la cantidad en caso de exito// -1 en caso de fallar
 */
int calculate_Passengers(Passenger list[], int len);
/**
 * @brief Muestra la lista de pasajeros activos
 *
 * @param lista array de lista de pasajeros
 * @param len tamaño de esa lista
 * @param passages pasajes
 * @param top tamaño
 * @param tams tamaño
 */
void print_ActivePassengers(Passenger lista[],int len, ePassage passages[], int top, int tams);
/**
 * @brief Ordena la lista de Pasajeros por codigo de vuelo y en estado de vuelo
 * activo
 *
 * @param list array de lista de pasajeros
 * @param passages tamaño de esa lista
 * @param len tamaño de esa lista
 * @param top pasajes
 * @param tams tamaño
 * @param order order 0 descendente - 1 ascendente
 * @return -1 en caso de error// 0 en caso de exito
 */
int sortPassengers_ByCode(Passenger *list, ePassage passages[], int len, int top, int tams, int order);
/**
 * @brief Carga forzada de pasajeros
 *
 * @param lista array de lista de pasajeros
 * @param len tamaño de esa lista
 * @param cant cantidad de pasajeros a generar
 * @param pId puntero a id
 * @return -1 en caso de error// 0 en caso de exito
 */
int Alta_Forzada(Passenger lista[], int len , int cant, int* pId);

#endif /* ARRAYPASSENGER_H_ */
