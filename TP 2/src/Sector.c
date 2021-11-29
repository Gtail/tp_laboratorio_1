/*
 * Sector.c
 *
 *  Created on: 29 nov. 2021
 *      Author: Gian
 */


#include "sector.h"



int getSector_byId(char unSector[], int idSector, eSector sector[], int top){

	int retorno=-1;
	int i;

	if(sector!=NULL && top>0)
	{
		for(i=0;i<top;i++){
			if(idSector==sector[i].idSector){
				strcpy(unSector,sector[i].typeSector);
			}
		}
		retorno=1;
	}

	return retorno;
}

void HardcodeSector(eSector sector[], int top) {
	int i;

	int idSector[] = { 1, 2, 3 };
	char typeSector[][51] = { "Sistemas", "Administracion", "Produccion" };

	for (i = 0; i < top; i++) {
		sector[i].idSector = idSector[i];
		strcpy(sector[i].typeSector, typeSector[i]);
	}
}

