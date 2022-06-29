#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
		int retorno=-1;
		int contPassenger=0;
		FILE* fid;

		char* id=(char*)malloc(sizeof (char)*10);
		char* nombre=(char*)malloc(sizeof (char)*256);
		char* apellido=(char*)malloc(sizeof (char)*256);
		char* precio=(char*)malloc(sizeof (char)*20);
		char* codigoDeVuelo=(char*)malloc(sizeof (char)*20);
		char* tipoPasajero=(char*)malloc(sizeof (char)*20);
		char* statusFlight=(char*)malloc(sizeof (char)*256);

		fid=fopen("last_id.txt","w");

		Passenger* auxPassenger;

		if (pFile != NULL && pArrayListPassenger != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoDeVuelo,tipoPasajero,statusFlight);

				while (!feof(pFile))
				{

						auxPassenger=Passenger_new();
						if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoDeVuelo,tipoPasajero,statusFlight)==7)
						{
							auxPassenger=Passenger_newParametros(id, nombre, apellido, precio, codigoDeVuelo, tipoPasajero, statusFlight);

								if(auxPassenger != NULL)
								{
									ll_add(pArrayListPassenger, auxPassenger);
									Passenger_mostrarUnPasajero(auxPassenger);
									//free(auxEmpleado);
									contPassenger+=1;
									retorno=0;

								}
								else{
									Passenger_delete(auxPassenger);
								}
						}


				}
						fprintf(fid,"%d",contPassenger);
						fclose(fid);
		}
		fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno = -1;
		Passenger *auxPasajero;

		if (pFile != NULL && pArrayListPassenger != NULL)
		{

			while (!feof(pFile)) {
				auxPasajero = Passenger_new();

				if (auxPasajero != NULL) {
					if (fread(auxPasajero, sizeof(Passenger), 1, pFile)==1) {
						ll_add(pArrayListPassenger, auxPasajero);
						//printf("ID %d", auxPasajero->id);
						retorno=0;
					}else{
						Passenger_delete(auxPasajero);
					}
				}
			}
		}
		return retorno;

}
