#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int retorno=-1;
	int contEmp=0;
	FILE* fid;

	char* id=(char*)malloc(sizeof (char)*10);
	char* nombre=(char*)malloc(sizeof (char)*256);
	char* horas=(char*)malloc(sizeof (char)*10);
	char* sueldo=(char*)malloc(sizeof (char)*10);

	fid=fopen("last_id.txt","w");
//	int cantLeido=0;

	Employee* auxEmpleado;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);

			while (!feof(pFile))
			{
					auxEmpleado=employee_new();

					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo)==4)
					{
						auxEmpleado=employee_newParametros(id, nombre, horas, sueldo);

							if(auxEmpleado != NULL)
							{
								ll_add(pArrayListEmployee, auxEmpleado);
								Mostrar_UnEmpleado(auxEmpleado);
								//free(auxEmpleado);
								contEmp+=1;
								retorno=0;

							}
					}


			}
					fprintf(fid,"%d",contEmp);
					fclose(fid);
	}
	fclose(pFile);

	return retorno;
}




/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	Employee *auxEmpleado;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{

		while (!feof(pFile)) {
			auxEmpleado = employee_new();

			if (auxEmpleado != NULL) {
				if (fread(auxEmpleado, sizeof(Employee), 1, pFile)==1) {
					ll_add(pArrayListEmployee, auxEmpleado);
					printf("ID %d", auxEmpleado->id);
					retorno=0;
				}else{
					employee_delete(auxEmpleado);
				}
			}
		}
	}
	return retorno;
}
