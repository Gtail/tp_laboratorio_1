/*
 * Autos.c
 *
 *  Created on: 24 jul. 2022
 *      Author: Gian
 */

#include "Autos.h"

// hardcodeos
int subMenu_Modify(){
	printf("----------------------------MENU MODIFICAR------------------------------\n");
		int option;

		printf("\n Opcion 1 Modificar Color \n");
		printf("\n Opcion 2 Modificar Modelo \n");
		printf("\n Opcion 3 Mostrar Lista \n");
		printf("\n Opcion 4 Salir \n");

		scanf("%d", &option);

		return option;
}

void hardcodearMarcas(Marca *marcas, int tamM) {
	int idMarca[] = { 1000, 1001, 1002, 1003, 1004 };
	char marca[][20] = { "Renault", "Ford", "Fiat", "Chevrolet", "Peugeot" };

	if (marcas != NULL && tamM > 0) {
		for (int i = 0; i < tamM; i++) {
			marcas[i].idMarca = idMarca[i];
			strcpy(marcas[i].descripcion, marca[i]);
		}
	}
}

void hardcodearColores(Color *colores, int tamC) {
	int idColor[] = { 5000, 5001, 5002, 5003, 5004 };
	char color[][20] = { "Negro", "Blanco", "Rojo", "Gris", "Azul" };

	if (colores != NULL && tamC > 0) {
		for (int i = 0; i < tamC; i++) {
			colores[i].idColor = idColor[i];
			strcpy(colores[i].nombreColor, color[i]);
		}
	}
}



int validarMarca(Marca* marcas, int tamM, int* idMarca) {
	int retorno = -1;
	int i;

	if (marcas != NULL && tamM > 0) {
		for (i = 0; i < tamM; i++) {
			if (*idMarca == marcas[i].idMarca) {
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}

int getMarca_byId(char* descMarca, int idAerolinea, Marca* marcas, int tamM) {

	int retorno = -1;
	int i;

	if (marcas != NULL && tamM > 0) {
		for (i = 0; i < tamM; i++) {
			if (idAerolinea == marcas[i].idMarca) {
				strcpy(descMarca, marcas[i].descripcion);
			}
		}
		retorno = 1;
	}

	return retorno;
}

int validarColor(Color* colores, int tamC, int* idColor) {
	int retorno = -1;
	int i;

	if (colores != NULL && tamC > 0) {
		for (i = 0; i < tamC; i++) {
			if (*idColor == colores[i].idColor) {
				printf("Llegue \n");
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}

int getColor_byId(char* color, int idColor, Color* colores, int tamC) {

	int retorno = -1;
	int i;

	if (colores != NULL && tamC > 0) {
		for (i = 0; i < tamC; i++) {
			if (idColor == colores[i].idColor) {
				strcpy(color, colores[i].nombreColor);
			}
		}
		retorno = 1;
	}

	return retorno;
}




int inicializarAutos(Auto* autos, int tamA){
	int retorno=-1;

	if(autos!=NULL && tamA>0){
		for(int i=0; i<tamA; i++){
			autos[i].isEmpty=0;
		}
		retorno=0;
	}

	return retorno;
}

int findEmptyAuto(Auto* autos, int tamA, int* index){
	int retorno=-1;

	if(autos!=NULL && index!=NULL && tamA>0){
		for(int i=0; i<tamA; i++){
			if(autos[i].isEmpty==0){
				*index=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

int altaDeAuto(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC, int* idAuto, Cliente* clientes, int tamCl){
	int retorno=-1;
	int index=-1;
	Auto auxAuto;


		printf("\n\t>-ALTA DE AUTO-<\t\n");
		printf("-----------------------------------------\n");

	if(autos!=NULL && marcas!=NULL && colores!=NULL && tamA>0 && tamM>0 && tamC>0 && idAuto!=NULL){
		findEmptyAuto(autos, tamA, &index);
		if(index!=-1){
			mostrarClientes(clientes, tamCl);
			printf("Ingrese el id de Cliente \n");
			auxAuto.idMarca=getValidInt("Ingrese la Marca del Auto 1000 Renault, 1001 Ford, 1002 Fiat, 1003 Chevrolet, 1004 Peugeot \n", "Error. Solo Ingrese la Marca del Auto 1000 Renault, 1001 Ford, 1002 Fiat, 1003 Chevrolet, 1004 Peugeot \n", 1000, 1004);
			if(validarMarca(marcas, tamM, &auxAuto.idMarca)==0){
				puts("Marca Asignada \n");
				autos[index].idMarca=auxAuto.idMarca;
			}else{
				printf("Marca %d Invalida \n", auxAuto.idMarca);
			}


			auxAuto.idColor=getValidInt("Ingrese el Color del Auto 5000 Negro, 5001 Blanco, 5002 Rojo, 5003 Gris, 5004 Azul \n", "Error. Solo Ingrese el Color del Auto 5000 Negro, 5001 Blanco, 5002 Rojo, 5003 Gris, 5004 Azul \n", 5000, 5004);
			if(validarColor(colores, tamC, &auxAuto.idColor)==0){
				puts("Color Asignado \n");
				autos[index].idColor=auxAuto.idColor;
			}else{
				printf("Marca %d Invalida \n", auxAuto.idColor);
			}

			printf("Ingrese el tipo de caja: a automatico - m manual \n");
			fflush(stdin);
			strlwr(&autos[index].caja);
			scanf("%c", &autos[index].caja);
			while(autos[index].caja != 'm' && autos[index].caja != 'a'){
				printf("Error. Ingrese el tipo de caja SOLO: a automatico - m manual \n");
				fflush(stdin);
				strlwr(&autos[index].caja);
				scanf("%c", &autos[index].caja);
			}

			if(getStringAlfaNumerico("Ingrese la patente del Auto \n", "Error, solo ingrese letras y Numeros \n", auxAuto.patente, 20, 2)){
				strcpy(autos[index].patente, auxAuto.patente);
			}
			(*idAuto)++;
			autos[index].idAuto=*idAuto;
			autos[index].isEmpty=1;
			retorno=0;
		}
	}

	return retorno;
}

int modificarAuto(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC){
	int retorno=-1;
	int index=-1;
	int opcion;
	Auto auxAuto;


	if(autos!=NULL && marcas!=NULL && colores!=NULL && tamA>0 && tamM>0 && tamC>0){
		printf("\n\t>-MODIFICACION DE AUTO-<\t\n");
		printf("-----------------------------------------\n");
		mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
		auxAuto.idAuto=getValidInt("Ingrese el Id del Auto a Modificar \n", "Error, ingrese solo numeros/id-s existentes", 0, tamA);
		validarAuto(autos, tamA, auxAuto.idAuto, &index);
		if(index!=-1){
			do{
			opcion=subMenu_Modify();
				switch(opcion){
				case 1:
					puts("Usted a elegido la opcion 1: Modificar Color \n");
					auxAuto.idColor=getValidInt("Ingrese el Color del Auto 5000 Negro, 5001 Blanco, 5002 Rojo, 5003 Gris, 5004 Azul \n", "Error. Solo Ingrese el Color del Auto 5000 Negro, 5001 Blanco, 5002 Rojo, 5003 Gris, 5004 Azul \n", 5000, 5004);
					while(validarColor(colores, tamC, &auxAuto.idColor)==-1){
						puts("Color Invalido. Intente Nuevamente\n");
						auxAuto.idColor=getValidInt("Ingrese el Color del Auto 5000 Negro, 5001 Blanco, 5002 Rojo, 5003 Gris, 5004 Azul \n", "Error. Solo  Solo Ingrese el Color del Auto 5000 Negro, 5001 Blanco, 5002 Rojo, 5003 Gris, 5004 Azul \n", 5000, 5004);
					}
					auxAuto.idMarca=autos[index].idMarca;
					break;
				case 2:
					puts("Usted a elegido la opcion 2: Modificar Modelo \n");
					autos[index].idMarca=getValidInt("Ingrese la Marca del Auto 1000 Renault, 1001 Ford, 1002 Fiat, 1003 Chevrolet, 1004 Peugeot \n", "Error. Solo Ingrese la Marca del Auto 1000 Renault, 1001 Ford, 1002 Fiat, 1003 Chevrolet, 1004 Peugeot \n", 1000, 1004);
						if(validarMarca(marcas, tamM, &autos[index].idMarca)==-1){
							puts("Marca NO valida \n");
						}else{
							puts("Marca Asignada");
						}
					break;
				case 3:
					puts("Usted a elegido la opcion 3: Listar Autos \n");
					mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
					break;
				case 4:
					puts("Menu Principal \n");

					break;
				}
			}while(opcion!=3);

		}

	}


	return retorno;
}

int mostrarAutos(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC){
	int retorno=-1;

	if(autos!=NULL && marcas!=NULL && colores!=NULL && tamA>0 && tamM>0 && tamC>0){
 printf("          *** Listado de Autos ***\n\n");
 printf("ID Auto  	 Marca    	    Color     	    Patente        Transmision \n");
 printf("-------------------------------------------------------------------------------------------------\n");
		for(int i=0; i<tamA; i++){
			if(autos[i].isEmpty==1){
				mostrarUnAuto(autos[i], marcas, tamM, colores, tamC);
			}
		}
	}


	return retorno;
}

void mostrarUnAuto(Auto unAuto, Marca* marcas, int tamM, Color* colores, int tamC){
	char descMarca[20];
	char nombreColor[20];

	getMarca_byId(descMarca, unAuto.idMarca, marcas, tamM);
	getColor_byId(nombreColor, unAuto.idColor, colores, tamC);

	printf("%-6d          %-10s           %-10s      %-10s        %c    \n", unAuto.idAuto
																		 , descMarca
																		 , nombreColor
																		 , unAuto.patente
																		 , unAuto.caja);

}


int hardcodearAutos(Auto vec[], int tam, int cant, int* idAuto)
{

    int todoOk = 0;
    Auto impostores[] =
    {
        { 0, 1000,5001,0,'m',"MTY321",1},
		{ 0, 1003,5002,0,'a',"DBZ210",1},
		{ 0, 1004,5000,0,'m',"MPR023",1},
		{ 0, 1002,5003,0,'a',"OWN255",1},
		{ 0, 1001,5004,0,'a',"FYJ642",1},
		{ 0, 1003,5001,0,'m',"EDZ401",1},
		{ 0, 1001,5000,0,'a',"EFW873",1},
		{ 0, 1004,5003,0,'m',"GDY329",1},
		{ 0, 1003,5004,0,'m',"HPK622",1},
		{ 0, 1002,5001,0,'m',"FYD210",1}
    };

    if(vec != NULL && tam > 0 && idAuto != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            *idAuto=i;
            vec[i].idCliente=i;
            vec[i].idAuto=*idAuto;

        }
        todoOk = 1;
    }
    return todoOk;

}

int validarAuto(Auto* autos, int tamA, int auxId, int* index){
	int retorno=-1;

	if(autos!=NULL && tamA>0 && auxId>=0){
		for(int i=0; i<tamA; i++){
			if(auxId == autos[i].idAuto){
				retorno=0;
				*index=i;
				break;
			}
		}
	}

	return retorno;
}

int eliminarAuto(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC){
	int retorno = -1;
	int index = -1;
	Auto auxAuto;
	char respuesta[4];
	strcpy(respuesta, "no");

	if (autos != NULL && marcas != NULL && colores != NULL && tamA > 0 && tamM > 0 && tamC > 0) {
		mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
		auxAuto.idAuto = getValidInt("Ingrese el id de Auto a Eliminar \n",
				"Error, Ingrese solo numeros/id's validos", 0, tamA);

		if (!validarAuto(autos, tamA, auxAuto.idAuto, &index)) {
			printf("Esta seguro de eliminar el auto %d? \n	", auxAuto.idAuto);
			scanf("%s",respuesta);
			if (!(stricmp(respuesta, "si"))) {
				autos[index].isEmpty = 0;
				retorno=0;
			} else {
				puts("Baja anulada \n");
			}
		}
	}

	return retorno;
}


int listarMarcas(Marca* marcas,int tamM){
	int retorno=-1;
	char descMarca[20];
	if(marcas!=NULL && tamM>0){
		printf("   *** Listado de Marcas ***\n\n");
		 printf("Id Marca		  Marca    	     \n");
		 printf("--------------------------------------\n");
		for(int i=0; i<tamM; i++){
			getMarca_byId(descMarca, marcas[i].idMarca, marcas, tamM);
			printf("%-16d          %-8s \n", marcas[i].idMarca, descMarca);
		}
	}

	return retorno;
}

int listarColores(Color* colores,int tamC){
	int retorno=-1;
	char descColor[20];
	if(colores!=NULL && tamC>0){
		printf("   *** Listado de Colores ***\n\n");
		 printf("Id Color		  Color   	     \n");
		 printf("--------------------------------------\n");
		for(int i=0; i<tamC; i++){
			getColor_byId(descColor, colores[i].idColor, colores, tamC);
			printf("%-16d          %-8s \n", colores[i].idColor, descColor);
		}
	}

	return retorno;
}



