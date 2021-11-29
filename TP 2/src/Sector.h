/*
 * Sector.h
 *
 *  Created on: 29 nov. 2021
 *      Author: Gian
 */
#include "ArrayEmployees.h"

#ifndef SECTOR_H_
#define SECTOR_H_

typedef struct{
	int idSector; //PK
	char typeSector[51];
}eSector;


int getSector_byId(char unSector[], int idSector, eSector sector[], int top);
void HardcodeSector(eSector sector[], int top);

#endif /* SECTOR_H_ */
