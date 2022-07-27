/*
 * Viajes.c
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */

#include "Viajes.h"

int hardcodearVuelos(Vuelo vec[],int tamV, int cant, Avion* list, int tamAv, int* idVuelo, Destino*destinos, int tamD){
	int retorno;
	int index=-1;

	Vuelo vuelos[]={
			{0,0,20000,0,{12,03,2021}},
			{0,0,20002,0,{30,07,2021}},
			{0,0,20001,0,{15,10,2021}},
			{0,0,20003,0,{05,11,2021}},
			{0,0,20001,0,{15,02,2021}},
			{0,0,20002,0,{15,02,2021}},
	};


	if (vec != NULL && tamV > 0 && cant > 0 && idVuelo != NULL) {
		for (int i = 0; i < cant; i++)
		{
			vec[i] = vuelos[i];
			vec[i].idVuelo = *idVuelo;
			findAvionById(list, tamAv, i, &index);
			if(index!=-1){
			vec[i].idAvion = index;
			}else{
				vec[i].idAvion=-1;
			}

			(*idVuelo)++;
		}
		retorno = 1;
	}

	return retorno;
}



void HardcodeDestinos(Destino destinos[], int top) {
	int i;

	int typeDestino[] = { 20000, 20001, 20002, 20003 };
	char descripcion[][51] = { "Calafate ", "Miami ", "Madrid", "Amsterdam" };
	float precio[] = {22250.00, 103000.00,84400.00,95600.00};

	for (i = 0; i < top; i++) {
		destinos[i].idDestino = typeDestino[i];
		strcpy(destinos[i].descripcion, descripcion[i]);
		destinos[i].precio = precio[i];


	}
}

int validarViaje(Destino destinos[], int top, int* idDestino) {
	int retorno = -1;
	int i;

	if (destinos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (*idDestino == destinos[i].idDestino) {
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}

int listarDestinos(Destino destinos[], int tam){
int todoOk = 0;

    if(destinos != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Destinos  ***\n");
        printf("  Id    Descripcion    Precio\n");
        printf("--------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s  %5.2f\n", destinos[i].idDestino, destinos[i].descripcion, destinos[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}


int altaDeVuelo(Avion* aviones, int tamAv, Vuelo* vuelos, int tamV, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA,  Destino* destinos, int tamD, Piloto* pilotos, int tamP, int* idVuelo){
	int retorno=-1;
	int index=-1;
	int indexA;
	Vuelo auxVuelo;

	if(aviones!=NULL && vuelos!=NULL && tipos!=NULL && aerolineas!=NULL && destinos !=NULL && tamA>0 && tamV>0 && tamT>0 && tamA>0 && tamD>0 && idVuelo!=NULL){
		buscarVueloLibre(vuelos, tamV, &index);
		if(index!=-1){
			auxVuelo.idVuelo=*idVuelo;
			(*idVuelo)++;
			printAviones(aviones, tipos, aerolineas, pilotos, tamAv, tamT, tamA, tamP);
			auxVuelo.idAvion=getValidInt("Ingrese un id de Avion \n", "Error, Ingrese SOLO numeros \n", 0, tamAv);
			while(findAvionById(aviones, tamAv, auxVuelo.idAvion, &indexA)!=0){
				printAviones(aviones, tipos, aerolineas, pilotos, tamAv, tamT, tamA, tamP);
				auxVuelo.idAvion=getValidInt("Ingrese un id de Avion \n", "Error, Ingrese SOLO numeros \n", 0, tamAv);
		}
				listarDestinos(destinos, tamD);
				auxVuelo.idDestino=getValidInt("Ingrese un id de Destino 20000 - 20003 \n", "Error, Ingrese SOLO numeros 20000 - 20003 \n", 20000, 20003);
				while(validarViaje(destinos, tamD, &auxVuelo.idDestino)!=0){
				auxVuelo.idDestino=getValidInt("Ingrese un id de Destino 20000 - 20003 \n", "Error, Ingrese SOLO numeros 20000 - 20003 \n", 20000, 20003);
				}
				printf("INGRESE LA FECHA \n");
			 printf("-------------..----------");
			 auxVuelo.fecha.dia=getValidInt("Ingrese el dia \n", "Error, ingrese SOLO numeros \n", 1, 31);
			 auxVuelo.fecha.mes=getValidInt("Ingrese el Mes \n", "Error, ingrese SOLO numeros \n",  1, 12);
			 auxVuelo.fecha.anio=getValidInt("Ingres el año \n", "Error, ingrese SOLO numeros \n",  2020, 2030);

			 vuelos[index]=auxVuelo;
			 retorno=0;
		}
	}

	return retorno;
}

int listarVuelos(Avion* aviones, int tamAv, Vuelo* vuelos, int tamV, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA, Destino* destinos, int tamD)
{
	int retorno=-1;
	int i;
	if(aviones!=NULL && vuelos!=NULL && tipos!=NULL && aerolineas!=NULL && destinos !=NULL && tamA>0 && tamV>0 && tamT>0 && tamA>0 && tamD>0)
	{
        system("cls");
        printf("          *** Listado de Vuelos ***\n\n");
        printf("  IdVuelo        Avion      Destino     Fecha\n");
        printf("--------------------------------------------------------------------------------\n");

        for(i=0;i<tamV;i++){
        	if(vuelos[i].isEmpty==0){
        		showVuelo(vuelos[i], tamV, destinos, aviones, tamAv, tipos, tamT);
        	}else{
        		break;
        	}
        }


	}


	return retorno;
}

int getDestino_ById(char tipo[], int idDestino, Destino destinos[], int top) {

	int retorno = -1;
	int i;

	if (destinos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idDestino == destinos[i].idDestino) {
				strcpy(tipo, destinos[i].descripcion);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int findIndexDestino_ById(int* index, int idDestino, Destino destinos[], int tamD) {

	int retorno = -1;
	int i;

	if (destinos != NULL && tamD > 0 && index!=NULL) {
		for (i = 0; i < tamD; i++) {
			if (idDestino == destinos[i].idDestino) {
				i=*index;
				break;
			}
		}
		retorno = 0;
	}

	return retorno;
}

int getPrecio_ById(float* precio, int idDestino, Destino destinos[], int top) {

	int retorno = -1;
	int i;

	if (destinos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idDestino == destinos[i].idDestino) {
				*precio=destinos[i].precio;
				printf("precio %f \n", destinos[i].precio);
				break;
			}
		}
		retorno = 0;
	}

	return retorno;
}


void showVuelo(Vuelo vuelos, int tamV, Destino* destinos, Avion aviones[], int tamAv, Tipo tipos[], int tamT)
{
	char auxDestino[25];
	int tipo;
	char auxTipo[25];
	getDestino_ById(auxDestino, vuelos.idDestino, destinos, tamV);
	if(getTipo_ByIdAvion(&tipo, vuelos.idAvion, aviones, tamAv)!=-1){

		getTipo_ById(auxTipo, &tipo, tipos, tamT);
	}
    system("cls");
    printf("          *** Listado de Vuelos ***\n\n");
    printf("  IdVuelo        Avion      Destino     Fecha\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("  %d             %s          %s         %02d/%02d/%02d\n", vuelos.idVuelo, auxTipo, auxDestino, vuelos.fecha.dia, vuelos.fecha.mes, vuelos.fecha.anio);

}

int getTipo_ByIdAvion(int* tipo, int idAvion, Avion aviones[], int top)
{

	int retorno = -1;
	int i;

	if (aviones != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idAvion == aviones[i].idAvion) {
				*tipo=aviones[i].idTipo;
				break;
			}
		}
		retorno = 0;
	}

	return retorno;
}


int inicializarVuelos(Vuelo *vuelos, int tamV)
{
	int i;
	int retorno = -1;

	if (vuelos != NULL && tamV > 0) {
		for (i = 0; i < tamV; i++) {
			vuelos[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}


int buscarVueloLibre(Vuelo* vuelos, int tamV, int* index)
{
int i;
int retorno=-1;

if(vuelos!=NULL && tamV>0){
	for(i=0;i<tamV;i++){
		if(vuelos[i].isEmpty==1){
			*index=i;
			break;
		}
	}
	retorno=0;
}

return retorno;
}

int vuelosPorAvion(Vuelo* vuelos, int tamV, Avion* list, int tamAv, Tipo* tipos, int tamT, Aerolinea* aerolineas,int tamA, Piloto* pilotos,int tamP){
	int retorno=-1;
	int idAvion;
	int index=-1;
	int contVuelos=0;
	char aerolinea[51];
	char tipo[51];

	if(vuelos!=NULL && list!=NULL && tamV>0 && tamAv>0)
	{
		printAviones(list, tipos, aerolineas, pilotos, tamAv, tamT, tamA, tamP);
		idAvion=getValidInt("Ingrese un ID de Avion \n", "Error, ingrese un ID valido", 0, tamAv);
		findAvionById(list, tamA, idAvion, &index);
		if(index!=-1){
			for(int i=0; i<tamV; i++){
				if(vuelos[i].idAvion==idAvion){
					contVuelos++;
				}
			}
			retorno=0;
		}
		printf("\n\t>-LA CANTIAD DE VUELOS REALIZADA POR EL AVION SELECTO ES-<\t\n");
		printf("ID AVION   AEROLINEA    CANTIDAD");
		printf("-----------------------------------------\n");

		for(int j=0; j<tamAv; j++){
			if(list[j].idAvion==idAvion){
				if(getAerolinea_byId(aerolinea, list[j].idAerolinea, aerolineas, tamA) && getTipo_ById(tipo, &list[j].idTipo, tipos, tamT)){
					printf("| %-5d |  %-4s | %-4s | %-5d \n", idAvion, tipo, aerolinea, contVuelos);
				}
			}
		}


	}
	return retorno;
}

int precioTotalPorAvion(Vuelo* vuelos, int tamV, Avion* list, int tamAv, Tipo* tipos, int tamT, Aerolinea* aerolineas,int tamA, Piloto* pilotos,int tamP, Destino* destinos, int tamD){
	int retorno=-1;
	int idAvion;
	int index=-1;

	float precio;
	float acumPrecio=0;
	int contVuelos=0;
	char aerolinea[51];
	char tipo[51];


	if (vuelos != NULL && list != NULL && tamV > 0 && tamAv > 0) {
		printAviones(list, tipos, aerolineas, pilotos, tamAv, tamT, tamA, tamP);
		idAvion = getValidInt("Ingrese un ID de Avion \n", "Error, ingrese un ID valido", 0, tamAv);
		findAvionById(list, tamA, idAvion, &index);
		if (index != -1) {
			for (int i = 0; i < tamV; i++) {
					if (vuelos[i].isEmpty == list[index].isEmpty && vuelos[index].idAvion == vuelos[i].idAvion) {
						getPrecio_ById(&precio, vuelos[i].idDestino, destinos, tamD);
						acumPrecio+=precio;
						printf("%.2f acumprecio \n", acumPrecio);
						contVuelos++;

				}
			}
		}
	}
	printf("\n\t>-LA SUMATORIA DE PRECIOS DE LOS VUELOS REALIZADOS POR EL AVION SELECTO ES-<\t\n");
			printf("ID AVION  CANTIDAD DE VUELOS TIPO  AEROLINEA   PRECIO TOTAL");
			printf("-----------------------------------------\n");

			for(int j=0; j<tamAv; j++){
				if(list[j].idAvion==idAvion){
					if(getAerolinea_byId(aerolinea, list[j].idAerolinea, aerolineas, tamA) && getTipo_ById(tipo, &list[j].idTipo, tipos, tamT)){
						printf("| %-7d | %-14d | %-2s | %-8s | %.2f \n", idAvion, contVuelos, tipo, aerolinea, acumPrecio);
					}
				}
			}
	return retorno;
}

//Pedir un destino y mostrar los aviones que volaron a ese destino y en qué fecha.

int mostrarAvionesPorDestino(Vuelo* vuelos, int tamV, Tipo* tipos, int tamT, Avion* aviones, int tamAv, Destino* destinos, int tamD)
{
	int retorno=-1;
	int idDestino;
	int indexAvion=-1;
	char destino[51];
	char tipoAvion[51];
	if(vuelos!=NULL && tipos !=NULL && aviones!=NULL && destinos!=NULL && tamD>0 && tamV>0 && tamT>0 && tamAv>0){

	listarDestinos(destinos, tamD);
	idDestino=getValidInt("Ingrese un id de Destino 20000 - 20003 \n", "Error, Ingrese SOLO numeros 20000 - 20003 \n", 20000, 20003);
	while(validarViaje(destinos, tamD, &idDestino)!=0){
	idDestino=getValidInt("Ingrese un id de Destino 20000 - 20003 \n", "Error, Ingrese SOLO numeros 20000 - 20003 \n", 20000, 20003);
	}

	getDestino_ById(destino, idDestino, destinos, tamD);
	printf("\n\t>-LOS AVIONES QUE VOLARON AL DESTINO %s -<\t\n", destino);
	printf("FECHA            AVIONES \n");
	printf("-----------------------------------------\n");
	for(int i=0; i<tamV; i++){
		if(vuelos[i].idDestino == idDestino){
			findAvionById(aviones, tamAv, vuelos[i].idAvion, &indexAvion);
			if(indexAvion!=-1){
				if(!aviones[indexAvion].isEmpty && !vuelos[i].isEmpty){
					getTipo_ById(tipoAvion, &aviones[indexAvion].idTipo, tipos, tamT);
					printf("%02d/%02d/%02d   %-5s", vuelos[i].fecha.dia, vuelos[i].fecha.mes, vuelos[i].fecha.anio, tipoAvion);
				retorno=0;
				}
			}else{
				printf("No se hallo el avion \n");
			}
		}
	}

	}

	return retorno;
}


// Pedir una fecha y mostrar todos los vuelos realizados en la misma.


int mostrarVuelosPorFecha(Vuelo* vuelos, int tamV, Destino* destinos, int tamD, Avion* aviones, int tamAv, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA){
	int retorno=-1;
	Fecha auxfechas;
	int flag=0;
	if(vuelos!=NULL  && tamV>0 ){
		listarVuelos(aviones, tamAv, vuelos, tamV, tipos, tamT, aerolineas, tamA, destinos, tamD);
		auxfechas.dia=getValidInt("Ingrese el dia \n", "ERROR. Ingrese solo numeros del 1 al 31 \n", 1, 31);
		auxfechas.mes=getValidInt("Ingrese el mes \n", "Error. Ingrese solo numeros del 1 al 12 \n", 1	, 12);
		auxfechas.anio=getValidInt("Ingrese el año (2020 - 2022) \n", "Error. Solo ingrese el año (2020 - 2022) \n",2020, 2022);
		for(int i=0; i<tamV; i++){
			if(vuelos[i].fecha.dia== auxfechas.dia && vuelos[i].fecha.mes == auxfechas.mes && vuelos[i].fecha.anio == auxfechas.anio){
				if(!vuelos[i].isEmpty){
					showVuelo(vuelos[i], tamV, destinos, aviones, tamAv, tipos, tamT);
					flag=1;
					retorno=0;
				}

			}
		}
		if(flag==1){
			printf("No hay mas vuelos en esa fecha \n");
		}else{
			printf("No hubo vuelos en esa fecha \n");
		}
	}

	return retorno;
}


