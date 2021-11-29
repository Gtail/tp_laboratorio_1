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

/**
 * @fn int getSector_byId(char[], int, eSector[], int)
 * @brief obtiene un sector por id
 *
 * @param unSector auxiliar que devuelve el sector
 * @param idSector donde pasamos el id a matchear
 * @param sector lista de sectores
 * @param top tamaño
 * @return
 */
int getSector_byId(char unSector[], int idSector, eSector sector[], int top);
/**
 * @fn void HardcodeSector(eSector[], int)
 * @brief harcodeo de sectores
 *
 * @param sector
 * @param top
 */
void HardcodeSector(eSector sector[], int top);

#endif /* SECTOR_H_ */
