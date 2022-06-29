#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger) {
	int retorno = -1;
	int tamList;
	int i;
	Passenger *auxPassenger;
	if (pArrayListPassenger != NULL) {
		tamList = ll_len(pArrayListPassenger);
		for (i = 0; i < tamList; i++) {
			auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_mostrarUnPasajero(auxPassenger);
			retorno = 1;
		}
	}
	return retorno;
}



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;
	int retorno;
	if (path != NULL && pArrayListPassenger != NULL) {
		pFile = fopen(path, "r");
		//ll_clear(pArrayListPassenger);
		if (pFile != NULL) {
			if (parser_PassengerFromText(pFile, pArrayListPassenger) != -1) {
				retorno = 0;
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile;
	pFile=fopen(path,"rb");


	if( pArrayListPassenger!=NULL && path!=NULL)
	{

		if(pFile!= NULL)
		{

			if(parser_PassengerFromBinary(pFile, pArrayListPassenger)==0){
			retorno=0;
			}
		}
	fclose(pFile);
	}
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
		//int contId=0;

		int id;

		if (obtenerId("last_id.txt", &id) == 1) {
			printf("ID obtenido \n");
			printf("id %d \n", id);
			if (pArrayListPassenger != NULL) {

				if (addPassenger(pArrayListPassenger, &id) == 0) {
					autoIncremental(&id);
					retorno = 0;
				}
			}
		}
		return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int id;
		controller_ListPassenger(pArrayListPassenger);
	if (pArrayListPassenger != NULL) {
		id = getValidInt("\n Ingrese el ID del Pasajero a Modificar \n",
				"\n Error, intente nuevamente ingresando SOLO numeros. \n", 0,
				5000);

		if (modificar_Pasajero(pArrayListPassenger, &id) == 1) {
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger) {
	int retorno = -1;
	int id;
	int index;
	Passenger *auxPassenger = NULL;
	int tamList;
	char respuesta[4];
	if (pArrayListPassenger != NULL) {

		tamList = ll_len(pArrayListPassenger);
		controller_ListPassenger(pArrayListPassenger);
		id = getValidInt("Ingrese el ID del Pasajero a eliminar",
						 "ERROR. Intente Nuevamente", 0, tamList);
		index = buscar_PasajeroPorId(pArrayListPassenger, &id);
		if (index != -1) {
			auxPassenger = (Passenger*) ll_get(pArrayListPassenger, index);
			printf("%d index \n", index);
			Passenger_mostrarUnPasajero(auxPassenger);
			getStringSoloLetras("Está seguro que quiere eliminar este Pasajero? \n",
								"Respuesta invalida \n", respuesta, 4, 2);

			if (!(stricmp(respuesta, "si"))) {
				if (ll_remove(pArrayListPassenger, index) == 0) {
					printf("Pasajero Eliminado con exito \n");
				}else{
					printf("Baja cancelada \n");
				}
			}

			retorno = 1;
		}else{
			printf("No se encontro el ID\n");
		}

	}
	return retorno;
}


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
		int criterio;
		int opcion;
		char confirmar[4];
		strcpy(confirmar,"no");
		LinkedList* copia;
		if(pArrayListPassenger!=NULL)
		{
			copia = ll_clone(pArrayListPassenger);

			if(copia!=NULL)
			{
				do
				{
					opcion = Passenger_MenuOrden();
					if(opcion!=9)
					{
						criterio = Passenger_MenuCriterio();
					}
					switch(opcion)
					{
						case 1:
							if(!ll_sort(copia,Passenger_CompararId,criterio))
							{
								if(criterio)
								{
									puts("Se ha ordenado la lista por ID ascendente \n");
								}
								else
								{
									puts("Se ha ordenado la lista por ID descendente \n");

								}
							}
							break;
						case 2:
							ll_sort(copia,Passenger_CompararNombre,criterio);
							if(criterio)
							{
								puts("Se ha ordenado la lista por nombre de A-Z \n");
							}
							else
							{
								puts("Se ha ordenado la lista por nombre de Z-A \n");

							}
							break;
						case 3:
							ll_sort(copia, Passenger_CompararApellido, criterio);
							if (criterio)
							{
								puts("Se ha ordenado la lista por nombre de A-Z \n");
							} else
							{
								puts("Se ha ordenado la lista por nombre de Z-A \n");

							}
							break;
						case 4:
							ll_sort(copia,Passenger_CompararPrecio,criterio);
							if(criterio)
							{
								puts("Se ha ordenado la lista por Precio ascendente \n");
							}
							else
							{
								puts("Se ha ordenado la lista por Precio descendente \n");
							}
							break;
						case 5:
							ll_sort(copia, Passenger_CompararTipoPasajero, criterio);
							if(criterio)
							{
								puts("Se ha ordenado la lista por Tipo Pasajero Ascendente \n");
							}
							else
							{
								puts("Se ha ordenado la lista por Tipo Pasajero Descendente \n");
							}
							break;
						case 6:
							ll_sort(copia, Passenger_CompararCodigoVuelo, criterio);
							if(criterio)
							{
								puts("Se ha ordenado la lista por Codigo de Vuelo Ascendente \n");
							}
							else
							{
								puts("Se ha ordenado la lista por Codigo de Vuelo Descendente \n");
							}
							break;
						case 7:
							ll_sort(copia, Passenger_CompararEstadoDeVuelo, criterio);
							if (criterio)
							{
								puts("Se ha ordenado la lista por Estado de Vuelo Ascendente \n");
							} else
							{
								puts("Se ha ordenado la lista por Estado de Vuelo Descendente \n");
							}
							break;
						case 8:
							controller_ListPassenger(copia);
							break;
						case 9:
							getStringSoloLetras("Esta seguro de Salir? si/no \n", "Error. ingrese solo letras \n", confirmar, 4, 2);
							strlwr(confirmar);
							ll_deleteLinkedList(copia);
							break;
						}
				}while(stricmp(confirmar,"si"));
			}
		}

	    return retorno;
	}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	int i;
	int tamList;
	int auxId;
	char auxNombre[128];
	char auxApellido[128];
	float auxPrecio;
	char codigoVuelo[4];
	int tipoPasajero;
	int estadoVuelo;
	Passenger *auxPassenger;
	FILE *pFile;

	if (path != NULL && pArrayListPassenger != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			tamList = ll_len(pArrayListPassenger);
			fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight \n");
			for (i = 0; i < tamList; i++) {
				auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
				if(!(Passenger_getId(auxPassenger, &auxId)&&
				Passenger_getNombre(auxPassenger, auxNombre)&&
				Passenger_getApellido(auxPassenger, auxApellido)&&
				Passenger_getPrecio(auxPassenger, &auxPrecio)&&
				Passenger_getCodigoVuelo(auxPassenger, codigoVuelo)&&
				Passenger_getTipoPasajero(auxPassenger, &tipoPasajero)&&
				Passenger_getEstadoVuelo(auxPassenger, &estadoVuelo))){

				fscanf(pFile,"%d,%s,%s,%f,%s,%d,%d\n", &auxId, auxNombre, auxApellido, &auxPrecio, codigoVuelo,&tipoPasajero,&estadoVuelo);

				retorno = 1;
				}else{
					printf("No se pudo guardar como txt \n");
				}


			}
		}

	}
	fclose(pFile);
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno=-1;
	int i;
	int tamList;
	Passenger* auxPassenger;
	FILE* pFile;
	pFile=fopen(path,"wb");

	if(path!=NULL && pArrayListPassenger!=NULL){
	tamList=ll_len(pArrayListPassenger);
		for(i=0;i<tamList;i++){
			auxPassenger=(Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(auxPassenger,sizeof(Passenger),1,pFile);
			retorno=1;
		}
	}
	fclose(pFile);
    return retorno;
}

