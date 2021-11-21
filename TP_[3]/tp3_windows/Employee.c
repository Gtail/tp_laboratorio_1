#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "inputUtn.h"
#include "Employee.h"

//CONSTRUCTORES
Employee* employee_new()
{
	Employee* auxEmployee;

	auxEmployee = (Employee*) malloc(sizeof(Employee));

	employee_setFields(auxEmployee, 0, " ", 0, 0);
	return auxEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee=employee_new();
	int auxId;
	int auxHoras;
	int auxSueldo;

	auxId=atoi(idStr);
	auxHoras=atoi(horasTrabajadasStr);
	auxSueldo=atoi(sueldoStr);

	if(pEmployee!= NULL && idStr!= NULL && nombreStr!= NULL && sueldoStr!= NULL && horasTrabajadasStr!= NULL)
	{
		if(employee_setFields(pEmployee, auxId, nombreStr, auxHoras, auxSueldo)==-1)
		{
			free(pEmployee);
		}
	}

	return pEmployee;
}

//GETTERS Y SETTERS
int employee_setFields(Employee* aEmp, int auxId, char* auxNombre, int auxHoras, int auxSueldo)
{
	int retorno=-1;
	int set_id;
	int set_Nombre;
	int set_HorasT;
	int set_Sueldo;

	if(aEmp != NULL)// && auxId>0 && auxNombre != NULL && auxSueldo>0 && auxHoras>0)
	{

		 set_id=employee_setId(aEmp,auxId);
		 set_Nombre=employee_setNombre(aEmp,auxNombre);
		 set_HorasT=employee_setHorasTrabajadas(aEmp,auxHoras);
		 set_Sueldo=employee_setSueldo(aEmp, auxSueldo);
		 printf("valor de set %d %d %d %d\n",set_id,set_Nombre,set_HorasT,set_Sueldo);

		 if(set_id==0 && set_Nombre==0 && set_HorasT==0 && set_Sueldo==0)
		{
			retorno=1;

		}
	}
	return retorno;
}

int employee_getId(Employee* aEmp,int* newId)
{
    int retorno=-1;

    if(aEmp != NULL && newId != NULL)
    {
        *newId= aEmp->id;
        retorno=0;
    }
    return retorno;
}


int employee_setId(Employee* pEmp,int newId)
{
    int retorno=-1;

    if(pEmp != NULL && newId >=0)
    {
    	pEmp->id= newId;
        retorno=0;
    }
    return retorno;
}


int employee_setNombre(Employee* pEmp,char* nombre)
{
	int retorno=-1;

	if(pEmp!=NULL && nombre!=NULL)
	{

			strcpy(pEmp->nombre,nombre);
			retorno=0;
	}

	return retorno;
}
int employee_getNombre(Employee* pEmp,char* nombre)
{
	int retorno=-1;

	if(pEmp!=NULL && nombre!=NULL)
	{

		strcpy(nombre,pEmp->nombre);
		retorno=0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* pEmp,int horasTrabajadas)
{
	 int retorno=-1;

	    if(pEmp!= NULL && horasTrabajadas>0)
	    {

	        pEmp->horasTrabajadas=horasTrabajadas;
	        retorno=0;
	    }
	    return retorno;
}

int employee_getHorasTrabajadas(Employee* pEmp,int* horasTrabajadas)
{
	 int retorno=-1;
	    if(pEmp!= NULL && horasTrabajadas != NULL)
	    {

	        *horasTrabajadas= pEmp->horasTrabajadas;
	        retorno=0;
	    }
	    return retorno;
}

int employee_setSueldo(Employee* pEmp,int sueldo)
{
	int retorno;

	    retorno=-1;
	    if(pEmp != NULL && sueldo>0)
	    {

	       pEmp->sueldo= sueldo;
	       retorno=0;
	    }
	    return retorno;
}

int employee_getSueldo(Employee* pEmp,int* sueldo)
{
	  int retorno=-1;


	    if(pEmp != NULL && sueldo>0)
	    {
	    	*sueldo= pEmp->sueldo;
	        retorno=0;

	    }
	    return retorno;
}

void employee_delete(Employee *pEmp) {
	if (pEmp != NULL) {
		free(pEmp);
	}
}

//hacer funcion similar al parser que recorra todos los datos del archivo para saber
// cual es el maximo id. lo hago solo una vez (cuando la parraylist=0)
// si la lista es != 0 ignoro la funcion y uso el max id clasico
// tiene que cargarlo en lastId

int addEmployee(Employee* pEmp,int id) {

	int retorno =-1;
	char nombre[256];
	int salario;
	int horas=0;
	int auxId;


			if (getStringSoloLetras("\n Ingrese el nombre del empleado \n","\n Error, intente nuevamente ingresando SOLO letras. \n",nombre,51,2) != 1) {
				printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
			}
			horas=getValidInt("\n Ingrese la cantidad de Horas Trabajadas \n","\n Error, intente nuevamente ingresando SOLO numeros. \n", 0, 5000);


			chargeSalary(&salario, "\n Inrese el salario", "\n Error, cargue el salario nuevamente");


			if(employee_setFields(pEmp, id, nombre, horas, salario)==1)
			{
				printf(" Estoy en SET \n");
				printf("%d %s %d %d \n",id, nombre, salario, horas);
				retorno=0;
			}else{
			printf("%d %s %d %d \n",id, nombre, salario, horas);
				printf(" Error en el set \n");
			}


	return retorno;
	}

int modificar_Empleado(LinkedList *pArrayListEmployee, int *id) {
	int retorno = -1;
	int i;
	Employee *auxEmployee;
	int tamList;
	int opcion;

	int auxHoras;
	int auxId;
	char auxNombre[128];
	int auxSalario;

	if (pArrayListEmployee != NULL && id != NULL) {
		tamList = ll_len(pArrayListEmployee);
		for (i = 0; i < tamList; i++) {
			/*auxEmployee = ll_get(pArrayListEmployee, i);
			if (auxEmployee->id == id) {*/
				if (buscar_EmpleadoPorId(pArrayListEmployee, id, auxEmployee) == 1) {
					printf("Bienvenido, elija una opcion \n\n");

					do {
						opcion = subMenu_One();
						switch (opcion) {
						case 1:
							printf(
									"\n Usted ha seleccionado 1: Modificar el Nombre \n");
							if (getStringSoloLetras(
									"\n Ingrese el Nuevo Nombre \n",
									"\n ERROR. Ingrese el Nuevo Nombre \n",
									auxNombre, 128, 2) != 1) {
								printf("\n Error. Reinicie el proceso \n");
							} else {
								printf(
										"\n La carga del NUEVO nombre ha sido un exito \n");
								employee_setNombre(auxEmployee, auxNombre);
								Mostrar_UnEmpleado(auxEmployee);
								retorno = 1;

							}
							break;
						case 2:
							printf(
									"\n Usted ha seleccionado 2: Modificar las Horas Trabajadas \n");
							auxHoras =
									getValidInt(
											"\n Ingrese la Nueva Cantidad de HS trabajadas \n",
											"\n ERROR. Ingrese la Cantidad de HS nuevamente \n",
											0, 15000);
							if (auxHoras >= 0) {
								employee_setHorasTrabajadas(auxEmployee,
										auxHoras);
								Mostrar_UnEmpleado(auxEmployee);
								retorno = 1;
							}
							break;
						case 3:
							printf(
									"\n Usted ha seleccionado 3: Modificar el Salario \n");
							chargeSalary(&auxSalario,
									"\n Ingrese el Nuevo Salario \n",
									"\n ERROR. Ingrese el Nuevo Salario \n");
							if (auxSalario > 0) {
								employee_setSueldo(auxEmployee, auxSalario);
								Mostrar_UnEmpleado(auxEmployee);
								retorno = 1;
							}
							break;
						case 4:
							printf("\n Hasta Luego \n");
							break;
						}
					} while (opcion != 4);
				}

			}
		}
	return retorno;
	}




int buscar_EmpleadoPorId(LinkedList *pArrayListEmployee, int *id,Employee *auxEmployee) {
	int retorno = -1;
	int i;
	auxEmployee=NULL;
	int tamList;


	if (pArrayListEmployee != NULL && id != NULL) {
		tamList = ll_len(pArrayListEmployee);
		for (i = 0; i < tamList; i++) {
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if (auxEmployee->id == id) {
			retorno=1;
			}
		}
	}

	return retorno;
}



void chargeSalary(int *salario, char mensaje[], char mensajeError[]) {
	char auxSalario[51];

	printf("%s", mensaje);
	scanf("%s", auxSalario);

	while (esNumerico(auxSalario)==0) {
		printf("%s", mensajeError);
		scanf("%s", auxSalario);
	}

	*salario = atoi(auxSalario);

}



int obtenerId(char* path, int* id)
{
	int retorno=-1;
	FILE* pFile;

	if(path!=NULL && id!=NULL)
	{
		pFile=fopen(path,"r");
		fscanf(pFile,"%d",id);
		retorno=1;
	}
	fclose(pFile);
	return retorno;
}

void autoIncremental(char* path)
{
	FILE* pFile;
	int id=0;

		if(path!=NULL)
		{
			pFile=fopen(path,"w");
			id+=1;
			fprintf(pFile,"%n",&id);
		}
		fclose(pFile);
}

void Mostrar_UnEmpleado(Employee* auxEmpleado)
{
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSalario;

	employee_getId(auxEmpleado, &auxId);
	employee_getNombre(auxEmpleado, &auxNombre);
	employee_getHorasTrabajadas(auxEmpleado, &auxHoras);
	employee_getSueldo(auxEmpleado, &auxSalario);

    printf("| %4d  | %-15s  | %-4d  |$%-8d  |\n",auxId,auxNombre,auxHoras,auxSalario);
}

int employee_CompararNombre(void *e1, void *e2) {
	int retorno;
	Employee *auxEmp;
	Employee *auxEmp_Dos;
	char auxNombre[128];
	char auxNombre_Dos[128];

	if (e1 != NULL && e2 != NULL) {
		auxEmp = (Employee*) e1;
		auxEmp_Dos = (Employee*) e2;

		employee_getNombre(auxEmp, auxNombre);
		employee_getNombre(auxEmp_Dos, auxNombre_Dos);

		if (strcmp(auxNombre, auxNombre_Dos) > 0) {
			retorno = 1;
		} else if (strcmp(auxNombre, auxNombre_Dos) < 0) {
			retorno = 0;
		} else {
			retorno = -1;
		}

	}

	return retorno;
}



