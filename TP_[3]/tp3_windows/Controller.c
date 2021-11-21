#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


int menuTen()
{
	int opcion;

	printf("\n Opcion 1 Cargar los datos de los empleados en Modo Texto \n");
	printf("\n Opcion 2 Cargar los datos de los empleados en Modo Binario\n");
	printf("\n Opcion 3 Dar de Alta un empleado \n");
	printf("\n Opcion 4 Modificar un empleado \n");
	printf("\n Opcion 5 Dar de Baja un empleado  \n");
	printf("\n Opcion 6 Listar empleados \n");
	printf("\n Opcion 7 Ordenar empleados \n");
	printf("\n Opcion 8 Guardar los datos de los empleados en Modo Texto \n");
	printf("\n Opcion 9 Guardar los datos de los empleados en Modo Binario \n");
	printf("\n Opcion 10 Salir \n\n");

	scanf("%d", &opcion);

	return opcion;
}

int subMenu_One()
{
	int opcion;

	printf("\n Opcion 1 Modificar el Nombre \n");
	printf("\n Opcion 2 Modificar las Horas Trabajadas \n");
	printf("\n Opcion 3 Modificar el Salario \n");
	printf("\n Opcion 4 Salir \n");

	scanf("%d", &opcion);

	return opcion;
}

int subMenu_Dos()
{
	int opcion;

		printf("\n Opcion 1 Modificar el Nombre \n");
		printf("\n Opcion 2 Modificar las Horas Trabajadas \n");
		printf("\n Opcion 3 Salir \n");

		scanf("%d", &opcion);

		return opcion;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int tamList;
	int i;
	Employee *auxEmpleado;
	if (pArrayListEmployee != NULL) {
		tamList = ll_len(pArrayListEmployee);
		for (i = 0; i < tamList; i++) {
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			Mostrar_UnEmpleado(auxEmpleado);
			retorno = 1;
		}
	}
	return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;

    pFile=fopen(path,"r");
    printf("Antes de validacion parser\n");

    if(pFile!=NULL && pArrayListEmployee != NULL)
    {
    	ll_clear(pArrayListEmployee);
        if(parser_EmployeeFromText(pFile , pArrayListEmployee)!= -1)
        {
            printf("carga ok! \n");
            retorno=0;
        }
    }

    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;
	pFile=fopen(path,"rb");


	if( pArrayListEmployee!=NULL && path!=NULL)
	{

		if(pFile!= NULL)
		{

			if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==0){
			retorno=0;
			}
		}
	fclose(pFile);
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	//int contId=0;
	Employee *auxEmployee=employee_new();
	int id;

	if (obtenerId("last_id.txt", &id) == 1) {
		printf("ID obtenido \n");
		if (pArrayListEmployee != NULL) {
			printf("no dio NULL LA LISTA \n");
			if (addEmployee(auxEmployee, id) == 0) {
				autoIncremental("last_id.txt");
				retorno = 1;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int id;
	if (pArrayListEmployee != NULL) {
		controller_ListEmployee(pArrayListEmployee);
		id = getValidInt("\n Ingrese el ID del Empleado a Modificar \n",
				"\n Error, intente nuevamente ingresando SOLO numeros. \n", 0,
				5000);

		if (modificar_Empleado(pArrayListEmployee, &id) == 1) {
			retorno = 1;
		}
	}
	return retorno;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	int index;
	Employee *auxEmployee=NULL;
	int tamList;

	if(pArrayListEmployee!=NULL)
	{
	tamList=ll_len(pArrayListEmployee);
		controller_ListEmployee(pArrayListEmployee);
		id=getValidInt("Ingrese el ID del Empleado a eliminar", "ERROR. Intente Nuevamente", 0, 5000);
		if(buscar_EmpleadoPorId(pArrayListEmployee, &id, auxEmployee)==1)
		{
			index=ll_indexOf(pArrayListEmployee, auxEmployee);
			if(index>=0 && index<tamList){
			ll_remove(pArrayListEmployee, index);
			retorno=1;
			}
		}
	}

    return retorno;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int opcion;

	if (pArrayListEmployee != NULL) {
		printf("Ingrese como desea ordenarlo");
		do {
			opcion = subMenu_Dos();
			switch (opcion) {
			case 1:
				printf("Usted ha seleccionado Ordenar A - Z \n");
				if (ll_sort(pArrayListEmployee, employee_CompararNombre, 1)
						== 0) {
					printf("Ordenamiento Exitoso \n");
					retorno=1;
				}
				break;
			case 2:
				printf("Usted ha seleccionado Ordenar Z - A \n");
				if (ll_sort(pArrayListEmployee, employee_CompararNombre, 0)
						== 0) {
					printf("Ordenamiento Exitoso");
					retorno=1;
				}
				break;
			case 3:
				printf("Hasta Luego");
				break;
			}default:
				printf("Error, ingrese una opcion 1-3 !!!!! \n");
				break;
		} while (opcion != 3);

	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	int retorno;
	int i;
	int tamList;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	Employee *auxEmployee;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			tamList = ll_len(pArrayListEmployee);
			fprintf(pFile, "id,nombre,horas trabajadas,sueldo \n");
			for (i = 0; i < tamList; i++) {
				auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
				employee_getId(auxEmployee, &auxId);
				employee_getNombre(auxEmployee, auxNombre);
				employee_getHorasTrabajadas(auxEmployee, &auxHoras);
				employee_getSueldo(auxEmployee, &auxSueldo);

				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre,
						auxHoras, auxSueldo);

				retorno = 1;

			}
		}

	}
	fclose(pFile);
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 // abro el archivo de txt en modo txt pero esta vez, ingresar a save binary
 // se hace solo UNA vez
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	int tamList;
	Employee* auxEmployee;
	FILE* pFile;
	pFile=fopen(path,"wb");
	tamList=ll_len(pArrayListEmployee);

	if(path!=NULL && pArrayListEmployee!=NULL){
		for(i=0;i<tamList;i++){
			auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
			fwrite(auxEmployee,sizeof(Employee),1,pFile);
			retorno=1;
		}
	}
	fclose(pFile);
    return retorno;
}

