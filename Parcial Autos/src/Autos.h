/*
 * Autos.h
 *
 *  Created on: 24 jul. 2022
 *      Author: Gian
 */

#include "Fecha.h"
#include "Fecha.h"
#include "Servicios.h"
#ifndef AUTOS_H_
#define AUTOS_H_

struct{
	int idMarca; // comienza en 1000
	char descripcion[20]; //Marcas (1000 Renault,1001 Ford,1002 Fiat, 1003Chevrolet,1004 Peugeot)
}typedef Marca;

struct{
	int idColor; // comienza en 5000
	char nombreColor[20]; //Colores (5000 Negro,5001 Blanco,5002 Rojo,5003 Gris,5004 Azul)
}typedef Color;

struct{
	int idAuto; //validar
	int idMarca; // validar
	int idColor; //Validar todo
	int idCliente;
	char caja; //m manual o a automatica
	char patente[20];
	int isEmpty;
}typedef Auto;

int inicializarAutos(Auto* autos, int tamA);
int subMenu_Modify();
//hardcodeos
void hardcodearMarcas(Marca *marcas, int tamM);
void hardcodearColores(Color *colores, int tamC);
int hardcodearAutos(Auto vec[], int tam, int cant, int* idAuto);
//validaciones
int validarMarca(Marca* marcas, int tamM, int* idMarca);
int validarColor(Color* colores, int tamC, int* idColor);
int validarAuto(Auto* autos, int tamA, int auxId, int* index);
//getters
int getMarca_byId(char* descMarca, int idAerolinea, Marca* marcas, int tamM);
int getColor_byId(char* color, int idColor, Color* colores, int top);

//herramientas
int inicializarAutos(Auto* autos, int tamA);
int findEmptyAuto(Auto* autos, int tamA, int* index);
void mostrarUnAuto(Auto unAuto, Marca* marcas, int tamM, Color* colores, int tamC);
int mostrarAutos(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC);
int listarMarcas(Marca* marcas,int tamM);
int listarColores(Color* colores,int tamC);

//ABM
int altaDeAuto(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC, int* idAuto, Cliente* clientes, int tamCl);
int modificarAuto(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC);
int eliminarAuto(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC);
#endif /* AUTOS_H_ */
