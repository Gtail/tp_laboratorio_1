/*
 * Aviones.c
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */


#include "Aviones.h"

int subMenu_Modify(){
	printf("----------------------------MENU MODIFICAR------------------------------");
	printf("\n Seleccione | 1- Modificar TIPO | 2- Modificar CAPACIDAD | 3- Salir \n");
		int option;

		printf("\n Opcion 1 Modificar TIPO \n");
		printf("\n Opcion 2 Modificar CAPACIDAD \n");
		printf("\n Opcion 3 Salir \n");

		scanf("%d", &option);

		return option;
}

void HardcodeTipo(Tipo tipos[], int top) {
	int i;


	int typeAvion[] = { 5000, 5001, 5002, 5003 };
	char descripcion[][51] = { "Jet ", "Helice ", "Planeador" ,"Carga"};

	for (i = 0; i < top; i++) {
		tipos[i].idTipo = typeAvion[i];
		strcpy(tipos[i].descripcion, descripcion[i]);

	}
}

int validarTipo(Tipo tipos[], int top, int* idTipo) {
	int retorno = -1;
	int i;

	if (tipos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (*idTipo == tipos[i].idTipo) {
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}

int initAviones(Avion list[], int len) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}

	return retorno;
}



int altaAvion(Avion list[], int tamAvion, int* idAvion, Aerolinea aerolineas[], int tamAero, Tipo tipos[], int tamT, Piloto pilotos[], int tamP ){
	int idAerolinea;
	int idTipo;
	int capacidad;
	int idPiloto;
	int index=-1;
	int retorno=-1;

	if(list!=NULL && tamAvion>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0){

		findEmptyAvion(list, tamAvion, &index);
		 printf("-------------------------------------------------------------------------------\n");
        printf("***************************** ALTA DE AVION ************************************\n");
        printf("--------------------------------------------------------------------------------\n");

		if(index!=-1){


			idAerolinea=getValidInt("Ingrese la Aerolinea 1000 Lan - 1001 Iberia - 1002 Norwegian - 1003 American - 1004 Austral \n", "Error Ingrese SOLO numeros de 1000 - 1004 \n", 1000	, 1004);

			if(validarColor(aerolineas, tamAero, &idAerolinea)==0){
				list[index].idAerolinea=idAerolinea;

			}else{
				printf("el id %d de Aerolinea NO existe \n	", idAerolinea);
			}

			idPiloto=getValidInt("Seleccione un Piloto  1- Max Verstappen 2- Esteban Tuero 3- Danica Patrick \n", "Error, ingrese SOLO numeros 1 - 3", 1, 3);
			if(validarPiloto(pilotos, tamP, &idPiloto)==0){
				list[index].idPiloto=idPiloto;
			}else{
				printf("El ID %d de Piloto NO existe \n", idPiloto);
			}

			idTipo=getValidInt("Ingrese el tipo de Avion 5000 Jet - 5001 Helice - 5002 Planeador - 5003 Carga \n", "ERROR. Ingrese SOLO numeros del 5000 al 5003\n", 5000, 5003);

			if(validarTipo(tipos, tamT, &idTipo)==0){
				list[index].idTipo=idTipo;
				printf("%d", list[index].idTipo);
			}else{
				printf("el id %d de Tipo NO existe \n	", idTipo);
			}

			capacidad=getValidInt("Ingrese la Capacidad del Avion 10 - 300 \n", "Error Ingrese SOLO numeros de 10 a 300 \n", 10, 300);
			if(capacidad>9 && capacidad<301){
				list[index].capacidad=capacidad;
				printf("%d capacidad \n", capacidad);
			}else{
				printf("La capacidad %d es INVALIDA \n", capacidad);
			}

			list[index].idAvion=*idAvion;
			(*idAvion)++;
			list[index].isEmpty=FULL;

		}
	}

	return retorno;
}

int findEmptyAvion(Avion list[], int len, int *index) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == EMPTY) {
				*index = i;
				retorno=0;
				break;
			}
		}

	}

	return retorno;
}




int modifyAvion(Avion list[], Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int top, int tamt, int tama, int tamP) {
	int retorno = -1;
	int index;
	int id = -1;
	int opcion;
	Avion auxAvion;
	printAviones(list, tipos, aerolineas, pilotos, top, tamt, tama, tamP);
	id = getValidInt("Ingrese el ID de Avion a Modificar \n",
			"Error, Ingrese un ID valido", 0, 5);
	if (findAvionById(list, top, id, &index) != -1) {
		printf("El id %d existe\n", id);
	} else {
		printf("El id %d es inexistente \n", id);
	}
	if (index != -1) {
		do {
			opcion = subMenu_Modify();
			switch (opcion) {
			case 1:
				auxAvion.idTipo =
						getValidInt("Ingrese el tipo de Avion 5000 Jet - 5001 Helice - 5002 Planeador - 5003 Carga \n",
						            "ERROR. Ingrese SOLO numeros del 5000 al 5003\n",
								    5000, 5003);

				if (validarTipo(tipos, tamt, &auxAvion.idTipo) == 0) {
					auxAvion.idTipo = list[index].idTipo;
				} else {
					printf("el id %d de Tipo NO existe \n	", auxAvion.idTipo);
				}
				break;
			case 2:
				auxAvion.capacidad =
						getValidInt("Ingrese la Capacidad del Avion 10 - 300 \n",
						"Error Ingrese SOLO numeros de 10 a 300 \n", 10, 300);
				if (auxAvion.capacidad > 9 && auxAvion.capacidad < 301) {
					auxAvion.capacidad = list[index].capacidad;
				} else {
					printf("La capacidad %d es INVALIDA \n",
							auxAvion.capacidad);
				}
				break;
			case 3:
				printf("Menu principal \n");
				break;
			}
		} while (opcion != 3);

	}

	return retorno;
}




int getTipo_ById(char tipo[], int* idTipo, Tipo tipos[], int top) {

	int retorno = -1;
	int i;

	if (tipos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (*idTipo == tipos[i].idTipo) {
				strcpy(tipo, tipos[i].descripcion);
			}
		}
		retorno = 1;
	}

	return retorno;
}

void printAviones(Avion lista[], Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int top, int tamt, int tama, int tamP)
{

    if(lista !=NULL && top>0)
    {
        for (int i=0; i<top; i++)
        {

            if(lista[i].isEmpty == FULL)
            {

                show_OneAvion(lista[i], tipos, aerolineas, pilotos, top, tamt, tama, tamP);


            }
        }
    }
    else
    {
        printf("\n No hay Aviones que listar\n");
    }
}

void show_OneAvion(Avion oneAvion, Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int top, int tamt, int tama, int tamP) {
	char auxAerolinea[25];
	char auxTipos[20];
	char auxNombre[70];

	getAerolinea_byId(auxAerolinea, oneAvion.idAerolinea, aerolineas, tama);
	getTipo_ById(auxTipos, &oneAvion.idTipo, tipos, tamt);
	getPiloto_ById(auxNombre, &oneAvion.idPiloto, pilotos, tamP);


    printf("          *** Listado de Aviones ***\n\n");
    printf("  ID PILOTO   NOMBRE PILOTO      ID Avion     ID Tipo      Tipo     Aerolinea    Capacidad \n");
    printf("-------------------------------------------------------------------------------------------------");
	printf("\n  %d      %s              %d          %d          %s        %s              %d        \n",

																					oneAvion.idPiloto,
																					auxNombre,
																					oneAvion.idAvion,
																					oneAvion.idTipo,
																					auxTipos,
																					auxAerolinea,
																					oneAvion.capacidad);

}


int findAvionById(Avion* list, int len,int id, int* index)
{
	int retorno=-1;
	int i;

	if(list!=NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].idAvion==id){
			*index=i;
			retorno=0;
			break;
			}
		}
	}
	return retorno;
}

int removeAvion(Avion *list, int top, int id, Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int tamt, int tama, int tamP) {
	int retorno = -1;
	int index;

	if (list != NULL && tipos != NULL && aerolineas !=NULL && tamt > 0 && top > 0 && tama > 0) {
		printAviones(list, tipos, aerolineas, pilotos, top, tamt, tama, tamP);
		id = getValidInt("Ingrese el ID del Avion a eliminar \n", "ERROR, ingrese SOLO numeros", 0, top);
		if (findAvionById(list, top, id, &index) != -1) {
			printf("El id %d existe \n", id);
		} else {
			printf("El id %d no existe \n", id);
		}
		if (index != -1) {
			list[index].isEmpty = EMPTY;
			retorno=0;
		}
	}

	return retorno;
}

int sortAviones(Avion *list, Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[],
		int len, int top, int tamt, int tama, int tamP) {
	int retorno = -1;
	Avion auxAvion;
	int i;
	int j;
	int p;
// Hacer un �nico listado de todos los aviones ordenados por aerol�nea y capacidad.
	if (list != NULL && len > 0) {
		for (i = 0; i < len - 1; i++) {

			for (j = i + 1; j < len; j++) {

				if (list[i].idAerolinea == list[j].idAerolinea
						&& list[i].capacidad > list[j].capacidad) {
					auxAvion = list[i];
					list[i] = list[j];
					list[j] = auxAvion;

				}
			}
		}
		for (p = 0; p < len; p++) {
			if(list[p].isEmpty==FULL){
			show_OneAvion(list[p], tipos, aerolineas, pilotos, top, tamt, tama, tamP);

			}
		}
		retorno = 0;
	}
	return retorno;
}


void listarAerolineas(Avion oneAvion[], Aerolinea aerolineas[],int top,  int tama){
	int i;

	if(aerolineas!=NULL && top>0){
		for(i=0;i<top;i++){
			if(!oneAvion[i].isEmpty){
				show_Aerolineas(oneAvion[i], aerolineas,tama);
			}
		}
	}


}


void show_Aerolineas(Avion oneAvion, Aerolinea aerolineas[], int tama) {
	char auxAerolinea[25];

	getAerolinea_byId(auxAerolinea, oneAvion.idAerolinea, aerolineas, tama);


		  printf("\n | |ID AEROLINEA     LISTA DE AEROLINEAS | |      \n");
		  printf("\n-----------------------------------------------\n");
		  printf("\n      %d              %s               \n", oneAvion.idAerolinea,
												               auxAerolinea);

}


void listarTipos(Avion oneAvion[], Tipo tipos[], int tamt, int top){
	int i;

	if(oneAvion!=NULL && top>0){
		for(i=0;i<top;i++){
			if(!oneAvion[i].isEmpty){
				show_Tipos(oneAvion[i], tipos, tamt);
			}
		}
	}
}

void show_Tipos(Avion oneAvion, Tipo tipos[], int tamt) {
	char auxTipos[25];

	getTipo_ById(auxTipos, &oneAvion.idTipo, tipos, tamt);


		printf(
				"\n | |   ID TIPO             LISTA DE TIPOS | |      \n");
		printf("\n-----------------------------------------------\n");
		printf(
				"\n        %d                     %s                \n", oneAvion.idTipo,
																			auxTipos);

}
/*
1- Mostrar aviones de la aerol�nea seleccionada por el usuario.
2- Mostrar aviones de un tipo seleccionado.
*/

int mostrarAvionesPorAerolinea(Avion aviones[], int tamAv, Aerolinea aerolineas[], int tamA, Tipo tipos[], int tamT, Piloto* pilotos, int tamP){
	int retorno=-1;
	int i;
	int auxId;
	if(aviones!=NULL && aerolineas!=NULL && tamAv>0 && tamA>0){
		listarAerolineas(aviones, aerolineas, tamAv, tamA);
		auxId=getValidInt("Ingrese un ID de Aerolinea \n", "Error, ingrese SOLO numeros \n", 1000, 1004);
		if(validarColor(aerolineas, tamAv, &auxId)!=-1)
		{
			for(i=0;i<tamA;i++){
				if(auxId==aviones[i].idAerolinea && !aviones[i].isEmpty){
					show_OneAvion(aviones[i], tipos, aerolineas, pilotos, tamAv, tamT, tamA, tamP);
				}
			}
			retorno=0;
		}


	}

	return retorno;
}

int mostrarAvionesPorTipo(Avion aviones[], int tamAv, Aerolinea aerolineas[], int tamA, Tipo tipos[], int tamT, Piloto pilotos[], int tamP)
{
	int retorno=-1;
	int i;
	int auxTipo;

	if(aviones!=NULL && aerolineas!=NULL && tamAv>0 && tamA>0){
		listarTipos(aviones, tipos, tamT, tamAv);
		auxTipo=getValidInt("Ingrese el tipo de Avion \n", "Error ingrese SOLO numeros \n", 5000, 5003);
		if(validarTipo(tipos, tamT, &auxTipo)!=-1){
			for(i=0;i<tamAv;i++){
				if(auxTipo==aviones[i].idTipo && !aviones[i].isEmpty){
					show_OneAvion(aviones[i], tipos, aerolineas,pilotos, tamAv, tamT, tamA, tamP);
				}
			}
		}
	}

	return retorno;
}


/*3- Informar Promedio de aviones jet sobre el total de aviones de una aerol�nea
4- Mostrar un listado de los aviones separados por aerol�nea.*/

int mostrarAviones_PorAerolineas(Avion aviones[], int tamAv, Aerolinea aerolineas[], int tamA, Tipo tipos[], int tamT, Piloto* pilotos, int tamP){
	int retorno=-1;
	int i;
//4- Mostrar un listado de los aviones separados por aerol�nea.

	if(aviones!=NULL && aerolineas!=NULL && tamAv>0 && tamA>0){
	    printf("          *** Listado de Aviones por Aerolinea ***\n\n");
	    printf("        ID Avion     ID Tipo      Tipo     Aerolinea    Capacidad \n");
	    printf("-------------------------------------------------------------------------------------------------");
			for(i=0;i<tamA;i++){
				if(tipos[i].idTipo==aviones[i].idTipo && !aviones[i].isEmpty){
					show_OneAerolinea(aviones[i], tipos, aerolineas, pilotos, tamAv, tamT, tamA, tamP);
				}
			}
			retorno=0;
	}

	return retorno;
}


void show_OneAerolinea(Avion oneAvion, Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int top, int tamt, int tama, int tamP) {
	char auxAerolinea[25];
	char auxTipos[20];


	getAerolinea_byId(auxAerolinea, oneAvion.idAerolinea, aerolineas, tama);
	getTipo_ById(auxTipos, &oneAvion.idTipo, tipos, tamt);


	printf("\n      %d           %d           %s        %s            %d        \n",


																					oneAvion.idAvion,
																					oneAvion.idTipo,
																					auxTipos,
																					auxAerolinea,
																					oneAvion.capacidad);

}

//3- Informar Promedio de aviones jet sobre el total de aviones de una aerol�nea

int promedioDe_JetsPorAerolinea(Avion* aviones, int tamAv, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA)
{
	int retorno=-1;

	int jetPorAerolinea[5]={0,0,0,0,0};

	int totalAviones[5]={0,0,0,0,0};

	float promedioPorAerolinea[5]={0,0,0,0,0};


	if (aviones != NULL && tipos != NULL && aerolineas != NULL && tamAv > 0
			&& tamT > 0 && tamA > 0) {

		for (int i = 0; i < tamA; i++) {
			for (int j = 0; j < tamAv; j++) {
				if (aviones[j].isEmpty == 0 && aviones[j].idAerolinea == aerolineas[i].idAerolinea) {
					totalAviones[i]++;
					if (aviones[j].idTipo == 5000) {
						jetPorAerolinea[i]++;

					}
				}
			}
		}



		for(int i=0; i<tamA; i++)
		{
			if(totalAviones[i]>0 && jetPorAerolinea[i]>0){
				promedioPorAerolinea[i]= totalAviones[i]/jetPorAerolinea[i];
			}
		}


		 printf("          *** Listado de Aviones JET por Aerolinea ***\n\n");
		 printf("        ID Aerolinea    Aerolinea    Promedio de Jets     Jets      Total de Aviones \n");
		 printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0; i<tamA; i++){
			printf("      %-5d          %-12s            %.2f               %-5d           %-5d  \n", aerolineas[i].idAerolinea, aerolineas[i].descripcion,
																								promedioPorAerolinea[i], jetPorAerolinea[i], totalAviones[i]);
		}

	}
	return retorno;
}


int calcularJet_ByIdAerolinea(Avion *aviones, int tamAv, Tipo *tipos, int tamT,
		Aerolinea *aerolineas, int tamA, int *idAerolinea, int* totalAviones) {
	int i;
	int retorno = -1;
	int contJet = 0;
	int contResto = 0;


	for (i = 0; i < tamAv; i++) {
		if (!aviones[i].isEmpty && aviones[i].idAerolinea == *idAerolinea && aviones[i].idTipo == 5000) {
			contJet++;
		} else if (!aviones[i].isEmpty && aviones[i].idTipo != 5000) {
			contResto++;
		}
	}
	if (contJet > 0 && contResto >= 0) {
		*totalAviones = contJet + contResto;
		retorno=contJet;
	} else {
		printf("No hay aviones \n");
	}

	return retorno;

}



int hardcodearAviones(Avion vec[], int tam, int cant, int* idAvion)
{

    int todoOk = 0;
    Avion impostores[] =
    {
        {1, 0, 1000,5000,25,0},
        {3, 0, 1000,5000,30,0},
        {2, 0, 1002,5003,280,0},
        {1, 0, 1002,5001,200,0},
        {2, 0, 1003,5000,28,0},
        {3, 0, 1004,5003,290,0},
        {3, 0, 1003,5002,160,0},
        {1, 0, 1004,5003,296,0},
        {1, 0, 1001,5001,18,0},
        {2, 0, 1001,5002,165,0}
    };

    if(vec != NULL && tam > 0 && idAvion != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            *idAvion=i;
            vec[i].idAvion=*idAvion;

        }
        todoOk = 1;
    }
    return todoOk;

}

/*5- Informar la o las aerol�neas que pueden transportar mas pasajeros (mayor acumulador de
capacidades de sus aviones)
*/

int mayorCapacidadPorAerolinea(Avion* aviones, int tamAv, Aerolinea* aerolineas, int tamA){
	int retorno=-1;
	int acumCapacidad[5]={0,0,0,0,0};
	int mayorCapacidad=0;
	int flag=0;

	for(int i=0; i<tamA; i++){
		for(int j=0; j<tamAv; j++){
			if(aviones[j].isEmpty==0 && aviones[j].idAerolinea == aerolineas[i].idAerolinea)
			{
				acumCapacidad[i] += aviones[j].capacidad;

			}
		}
	}

	for(int i=0; i<tamA; i++)
	{
		if(!flag || (acumCapacidad[i]>mayorCapacidad) )
		{
			mayorCapacidad=acumCapacidad[i];

			flag=1;

		}
	}


		printf("\n\t>-LA AEROLINEA CON MAYOR CAPACIDAD ES-<\t\n");
		printf("AEROLINEA   CAPACIDAD");
		printf("-----------------------------------------\n");

	for(int i=0; i<tamA; i++)
	{
		if(acumCapacidad[i]==mayorCapacidad)
		{
			printf("| %-4s | %-5d \n",aerolineas[i].descripcion, mayorCapacidad);
		}

	}
	return retorno;
}

int aerolineaConMenosAviones(Avion* avion, int tamAv, Aerolinea* aerolineas, int tamA){
	int retorno=-1;
	int contAviones[5]={0,0,0,0,0};
	int menorCantidad=0;
	int flag=0;

	if(avion!=NULL && aerolineas!=NULL && tamAv>0 && tamA>0){
		for(int i=0; i<tamA; i++){
			for(int j=0; j<tamAv; j++){
				if(!avion[j].isEmpty && avion[j].idAerolinea == aerolineas[i].idAerolinea){
					contAviones[i]++;
				}
			}
		}
	}

	for(int i=0; i<tamA; i++){
		if(flag || contAviones[i]<menorCantidad){
			contAviones[i]=menorCantidad;
			flag=1;
		}
	}

	printf("\n\t>-LA AEROLINEA CON MENOR CANTIDAD DE AVIONES ES-<\t\n");
		printf("AEROLINEA   CANTIDAD");
		printf("-----------------------------------------\n");

	for(int i=0; i<tamA; i++)
	{
		if(contAviones[i]==menorCantidad)
		{
			printf("| %-4s | %-5d \n",aerolineas[i].descripcion, menorCantidad);
		}

	}

	return retorno;
}

// Pedir un avi�n y mostrar todos los vuelos que hizo el mismo.


