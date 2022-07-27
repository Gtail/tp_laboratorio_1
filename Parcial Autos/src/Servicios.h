/*
 * Servicios.h
 *
 *  Created on: 24 jul. 2022
 *      Author: Gian
 *
 */

#include "Fecha.h"
#ifndef SERVICIOS_H_
#define SERVICIOS_H_
#include "Autos.h"
struct{
	int idServicio; // arranca en 20000
	char descServicio[25]; // Lavados (20000Lavado,20001 Pulido, 20002 Encerado,20003 Completo)
	float precio; //(Lavado: $450, Pulido: $500, Encerado: $600, Completo: $900)
}typedef Servicios;

struct{
	int idTrabajo; // autoincremental
	char patente[20];
	int idServicio; // validar que exista
	int isEmpty;
	Fecha fecha;
}typedef Trabajos;

struct{
	int idCliente;
	char nombre[51];
	char sexo;
}typedef Cliente;

void inicializarClientes(Cliente* clientes, int tamC);
int buscarTrabajoLibre(Trabajos* trabajos, int* index, int tamT);
void hardcodearServicios(Servicios *servicios, int tamSv);
int getServicio_byId(char* descServicio, int idServicio, Servicios* servicios, int tamSv);
int listarServicios(Servicios* servicios,int tamSv);
void inicializarTrabajos(Trabajos* trabajos, int tamT);
int validarServicio(Servicios* servicios, int tamSv, int auxId, int* index);
int altaDeTrabajo(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC, Servicios* servicios, int tamSv, Trabajos* trabajos, int tamT, int* idTrabajo);
int listarTrabajos(Trabajos* trabajos, int tamT, Servicios* servicios, int tamSv);
int hardcodearClientes(Cliente vec[], int tam, int cant, int* idCliente);
int mostrarClientes(Cliente* clientes, int tamCl);
void mostrarUnCliente(Cliente unCliente);
#endif /* SERVICIOS_H_ */
