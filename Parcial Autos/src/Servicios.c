/*
 * Servicios.c
 *
 *  Created on: 24 jul. 2022
 *      Author: Gian
 */
#include "Servicios.h"

void inicializarTrabajos(Trabajos* trabajos, int tamT){
	if(trabajos!=NULL && tamT>0){
		for(int i=0; i<tamT; i++){
			trabajos[i].isEmpty=0;
		}
	}
}



void hardcodearServicios(Servicios *servicios, int tamSv) {
	int idServicio[] = { 20000, 20001, 20002, 20003 };
	char servicio[][20] = { "Lavado", "Pulido", "Encerado", "Completo" };

	if (servicios != NULL && tamSv > 0) {
		for (int i = 0; i < tamSv; i++) {
			servicios[i].idServicio = idServicio[i];
			strcpy(servicios[i].descServicio, servicio[i]);
		}
	}
}

int getServicio_byId(char* descServicio, int idServicio, Servicios* servicios, int tamSv) {

	int retorno = -1;
	int i;

	if (servicios != NULL && tamSv > 0) {
		for (i = 0; i < tamSv; i++) {
			if (idServicio == servicios[i].idServicio) {
				strcpy(descServicio, servicios[i].descServicio);
			}
		}
		retorno = 1;
	}

	return retorno;
}


int listarServicios(Servicios* servicios,int tamSv){
	int retorno=-1;
	char descServ[20];
	if(servicios!=NULL && tamSv>0){
		printf("   *** Listado de Servicios ***\n\n");
		 printf("Id Servicio	 Servicios   	     \n");
		 printf("--------------------------------------\n");
		for(int i=0; i<tamSv; i++){
			getServicio_byId(descServ, servicios[i].idServicio, servicios, tamSv);
			printf("%-7d          %-8s \n", servicios[i].idServicio, descServ);
		}
	}

	return retorno;
}

int validarServicio(Servicios* servicios, int tamSv, int auxId, int* index){
	int retorno=-1;

	if(servicios!=NULL && tamSv>0 && auxId>=0){
		for(int i=0; i<tamSv; i++){
			if(auxId == servicios[i].idServicio){
				retorno=0;
				*index=i;
				break;
			}
		}
	}

	return retorno;
}

int altaDeTrabajo(Auto* autos, int tamA, Marca* marcas, int tamM, Color* colores, int tamC, Servicios* servicios, int tamSv, Trabajos* trabajos, int tamT, int* idTrabajo){
	int retorno=-1;
	Auto auxAuto;
	Trabajos auxTrabajo;
	int indexA=-1;
	int indexS=-1;
	int indexT=-1;
	if (autos != NULL && marcas != NULL && colores != NULL && servicios != NULL
			&& trabajos != NULL && tamA > 0 && tamM > 0 && tamC > 0 && tamSv > 0 && tamT > 0) {
		printf("\n\t>-ALTA DE TRABAJO-<\t\n");
		printf("-----------------------------------------\n");
		if (!buscarTrabajoLibre(trabajos, &indexT, tamT)) {
			mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
			auxAuto.idAuto = getValidInt("Ingrese el id del Auto a realizar el trabajo \n",
										 "Error, Ingrese solo numeros/id's validos \n", 0, tamA);
			if (!validarAuto(autos, tamA, auxAuto.idAuto, &indexA)) {
				listarServicios(servicios, tamSv);
				auxTrabajo.idServicio = getValidInt("Ingrese el Id de Servicio a Realizar \n",
													"Error, ingrese id's validos \n", 20000, 20003);
				if (!validarServicio(servicios, tamSv, auxTrabajo.idServicio, &indexS)) {
					strcpy(trabajos[indexT].patente, autos[indexA].patente);
					trabajos[indexT].idServicio=auxTrabajo.idServicio;
					trabajos[indexT].fecha.dia=getValidInt("Ingrese el Dia (1 - 31) \n", "Error. Ingrese numeros solo del 1 al 31 \n", 1, 31);
					trabajos[indexT].fecha.mes=getValidInt("Ingrese el Mes (1 - 12) \n", "Error. Ingrese numeros solo del 1 al 12 \n", 1, 12);
					trabajos[indexT].fecha.anio=getValidInt("Ingrese el Año (2020 - 2022) \n", "Error. Ingrese numeros solo del 2020 al 2022 \n", 2020, 2022);
					(*idTrabajo)++;
					trabajos[indexT].idTrabajo=*idTrabajo;
					trabajos[indexT].isEmpty=1;

				}else{
					printf("El id de servicio %d no existe \n", auxTrabajo.idServicio);
				}
			} else {
				printf("El id %d de auto no existe \n", auxAuto.idAuto);
			}

		}
	}

	return retorno;
}

int buscarTrabajoLibre(Trabajos* trabajos, int* index, int tamT){
	int retorno=-1;

	if(trabajos!=NULL && index!=NULL && tamT>0){
		for(int i=0; i<tamT; i++){
			if(trabajos[i].isEmpty==0){
				*index=i;
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

int listarTrabajos(Trabajos* trabajos, int tamT, Servicios* servicios, int tamSv){
	int retorno=-1;
	char descServicio[25];
	if(trabajos!=NULL && tamT>0){
		printf("   *** Listado de Trabajos ***\n\n");
		printf("Id Trabajo   Fecha 	Id Servicio  Servicio  Patente   \n");
		printf("--------------------------------------\n");
		for(int i=0; i<tamT; i++){
			if(trabajos[i].isEmpty==1){
				getServicio_byId(descServicio, trabajos[i].idServicio, servicios, tamSv);
				printf("%-8d     %02d/%02d/%02d   %-9d  %-8s  %-6s \n",trabajos[i].idTrabajo
																	  ,trabajos[i].fecha.dia
																	  ,trabajos[i].fecha.mes
																	  ,trabajos[i].fecha.anio
																	  ,trabajos[i].idServicio
																	  ,descServicio
																	  ,trabajos[i].patente);
			}
		}

	}

	return retorno;

}

int hardcodearClientes(Cliente vec[], int tam, int cant, int* idCliente)
{

    int todoOk = 0;
    Cliente impostores[] =
    {
        { 0, "Daniel",'m'},
		{ 0, "Florencia",'f'},
		{ 0, "Esteban",'m'},
		{ 0, "Cristian",'m'},
		{ 0, "Silvio",'m'},
		{ 0, "Marta",'f'},
		{ 0, "Julieta",'f'},
		{ 0, "Silvina",'f'},
		{ 0, "Mirtha",'f'},
		{ 0, "Raul",'m'}
    };

    if(vec != NULL && tam > 0 && idCliente != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            *idCliente=i;
            vec[i].idCliente=*idCliente;

        }
        todoOk = 1;
    }
    return todoOk;

}

int mostrarClientes(Cliente* clientes, int tamCl){
	int retorno=-1;

	if(clientes!=NULL && tamCl>0){
 printf("          *** Listado de Clientes ***\n\n");
 printf("ID Cliente  	 Nombre    	    Sexo    \n");
 printf("-----------------------------------------------\n");
		for(int i=0; i<tamCl; i++){
			mostrarUnCliente(clientes[i]);
		}
	}


	return retorno;
}

void mostrarUnCliente(Cliente unCliente){


	printf("%-6d          %-10s           %c     \n", unCliente.idCliente
													 , unCliente.nombre
													 , unCliente.sexo);

}
