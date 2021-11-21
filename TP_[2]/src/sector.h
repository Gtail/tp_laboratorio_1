/*
 * sector.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Gian
 */

#ifndef SECTOR_H_
#define SECTOR_H_
#include "ArrayEmployees.h"

typedef struct{
	int idSector; //PK
	char typeSector[51];
}eSector;

int chargeSector(eSector Sector[], int top);
void showSectors(eSector Sector[], int top);
#endif /* SECTOR_H_ */
