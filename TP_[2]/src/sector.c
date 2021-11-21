/*
 * sector.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Gian
 */
#include "sector.h"

int chargeSector(eSector Sector[], int top)
{
	int idReturnSector;

	showSectors(Sector, top);
	idReturnSector=getValidInt("Ingrese un ID de sector 1 - 3","Error, intente nuevamente", 0, 4);

	return idReturnSector;
}

// mostrar la lista de sectores tengo que cear una funcion que reciba
// le pido que ingrese el sector y me aseguro que exista. Si exite, lo devuelvo con un return 1


void showSectors(eSector Sector[], int top){
	printf("||||||||||||||||LISTA DE SECTORES||||||||||||||||||");
	printf("||||||||| ID SECTOR ||||||||||| SECTOR ||||||||||||");
	for(int i=0; i<top;i++){
		printf("\n%d %s", Sector[i].idSector, Sector[i].typeSector);
	}
}

