/*
 * ArrayEmployees.c
 *
 *  Created on: 29 nov. 2021
 *      Author: Gian
 */


#include "ArrayEmployees.h"

int subMenu(){

	printf("\n Seleccione 1- Alta de Empleado 2- Modificar Empleado 3- Mostrar por Descipcion 4- Informar \n");
	int option;

	printf("\n Opcion 1 Alta de Empleado \n");
	printf("\n Opcion 2 Modificar Empleado \n");
	printf("\n Opcion 3 Baja de Empleado \n");
	printf("\n Opcion 4 Informar \n");
	scanf("%d", &option);

	return option;

}
int subMenu2(){

	printf("\n Seleccione | 5- Listar empleados alfabeticamente Apellido y Sector | 6- Total y Promedio de los Salarios | 7- Salir \n");
	int option;

	printf("\n Opcion 5 Informar Listado de empleados Alfabeticamente Apellido y Sector");
	printf("\n Opcion 6 Total y Promedio de los Salarios");
	printf("\n Opcion 7 Salir");
	scanf("%d", &option);

	return option;

}

int subMenu_Modify(){
	printf("\n Seleccione | 1- Modificar Nombre | 2- Modificar Apellido | 3- Salir \n");
		int option;

		printf("\n Opcion 1 Modificar Nombre del Empleado \n");
		printf("\n Opcion 2 Modificar Apellido del Empleado \n");
		printf("\n Opcion 3 Modificar Salario del Empleado \n");
		printf("\n Opcion 4 Modificar Sector del Empleado \n");
		printf("\n Opcion 5 Salir \n");
		scanf("%d", &option);

		return option;
}


int initEmployees(Employee list[], int len)
{
	int ret=-1;
	for (int i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
			ret=0;
		}

	return ret;
}



int addEmployee(Employee list[], int len, int id, char name[], char lastName[],
		float salary, int sector) {


	int ret = 0;
	int index;

	printf("el id addEmployee %d\n",id);

	index = findEmptySpace(list, len);
	if(index != -1)
	{


		if (getStringSoloLetras("\n Ingrese el nombre del empleado \n","\n Error, intente nuevamente ingresando SOLO letras. \n",name,51,2) != 1)
		{
			printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
		} else {
			strcpy(list[index].name, name);
			printf("\n Todo ok");
		}

		if(getStringSoloLetras("\n Ingrese el Apellido del empleado \n","\n Error, intente nuevamente ingresando SOLO letras. \n",lastName,51,2) != 1)
		{
			printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
		}else
		{
			strcpy(list[index].lastName, lastName);
			printf("\n Todo ok \n");
		}

		chargeSalary(&salary, "\n Inrese el salario", "\n Error, cargue el salario nuevamente");

		sector=getValidInt("\n Ingrese el ID de Sector (1 sistemas | 2 administracion | 3 produccion) \n",
						"\n Error, ingrese solo (1 sistemas | 2 administracion | 3 produccion) \n",
						0, 4);


		list[index].id=id;
		list[index].idSector=sector;
		list[index].salary=salary;
		list[index].isEmpty = FULL;
		ret = 1;

	}
	return ret;
}


int registerEmployee(Employee list[], int len, int id){

	int ret=0;
	char name[51];
	char lastName[51];
	float salary=0;
	int sector=0;

	if(addEmployee(list, len, id, name, lastName,salary,sector)!=0)
	{
		printf("\n El alta de un empleado ha sido exitosa \n");

		ret = 1;

	}

	return ret;
}




int findEmptySpace(Employee list[], int len) {
	int index;
	index = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == EMPTY) {
				index = i;
				break;
			}
		}
	}
	return index;
}

void chargeSalary(float *salario, char mensaje[], char mensajeError[]) {
	char auxSalario[51];

	printf("%s", mensaje);
	scanf("%s", auxSalario);

	while (esNumericoFlotante(auxSalario)==0 && esNumerico(auxSalario)==0) {
		printf("%s", mensajeError);
		scanf("%s", auxSalario);
	}

	*salario = atof(auxSalario);

}

void showEmployee(Employee oneEmployee) {

	printf("\n ID |ID SECTOR| NOMBRE | APELLIDO | SALARIO");
	printf("\n %d | %d      | %s     | %s       | %.2f \n", oneEmployee.id, oneEmployee.idSector, oneEmployee.name, oneEmployee.lastName,oneEmployee.salary);

}

void showEmployeeList(Employee list[], int len) {

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == FULL) {
				showEmployee(list[i]);
			}
		}
	}
}
int modifyEmployee(Employee list[], int len, int IdEmployee) {
	int retorno = 0;
	int modificar;

	showEmployeeList(list, len);

		modificar = modifyOneEmployee(list, len, IdEmployee);
		if(modificar == 1){
			printf("\n La modificacion ha sido exitosa \n");

			retorno=1;
		}
	return retorno;
	}


int modifyOneEmployee(Employee list[], int len, int IdEmployee) {
int opcion;
int error = 0;
int index;
float auxSalary;


	IdEmployee = getValidInt("\n Ingrese el ID de Empleado a Modificar \n",
			"\n Error. Ingrese un ID valido \n", 0, 100);
			index = findEmployeeById(list, len, IdEmployee);
			if (index != -1) {
				printf(
						"\n Elija: 1- Modificar Direccion. 2- Modificar Localidad. 3- Salir \n");
				do {
					opcion=subMenu_Modify();
					switch (opcion) {
					case 1:
				if (getStringSoloLetras("\n Ingrese el nombre del empleado \n",
						"\n Error, intente nuevamente ingresando SOLO letras. \n",
						list[index].name, 51, 2) != 1) {
					printf(
							"\n Error, intente nuevamente ingresando SOLO letras. \n");
				} else {

					printf("\n Todo ok \n");
				}
						error = 1;
						break;
					case 2:
				if (getStringSoloLetras("\n Ingrese el Apellido del empleado \n",
						"\n Error, intente nuevamente ingresando SOLO letras. \n",
						list[index].lastName, 51, 2) != 1) {
					printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
				} else {
					printf("\n Todo ok \n");
				}
						error = 1;
						break;
					case 3:
						chargeSalary(&auxSalary, "\n Ingrese el Nuevo Salario \n", "\n Error, ingrese SOLO numeros \n");
						list[index].salary=auxSalary;
						break;
					case 4:
						list[index].idSector=getValidInt("\n Ingrese el ID de Sector (1 sistemas | 2 administracion | 3 produccion) \n",
													"\n Error, ingrese solo (1 sistemas | 2 administracion | 3 produccion) \n",
													0, 4);
						break;
					}
				} while (opcion != 4);
				showEmployee(list[index]);
			}
		return error;
		}

int findEmployeeById(Employee list[], int tam, int IdEmployee) {

	int retorno = -1;

	for (int i = 0; i < tam; i++) {

		if (list[i].isEmpty == FULL && list[i].id == IdEmployee) {

			retorno = i;

			break;
		}

	}

	return retorno;
}

int removeEmployee(Employee *list, int len, int id) {
	int IdEmployee;
	char respuesta;
	int index;
	int retorno = -1;

	showEmployeeList(list, len);

	IdEmployee = getValidInt("\n Ingrese el ID de Cliente a Eliminar \n",
			"\n Error. Ingrese un ID valido \n", 0, 1000);
	printf("\n Esta seguro de ELIMINAR el Cliente %d ? s/n \n", IdEmployee);
	fflush(stdin);
	scanf("%c", &respuesta);
	if (respuesta == 's') {
		{
			index = findEmployeeById(list, len, IdEmployee);
			if (index != -1) {
				list[index].isEmpty = EMPTY;
				printf("\n Se ha eliminado el ID %d correctamente \n", IdEmployee);
			} else {
				printf("\n No se ha encontrado el ID a eliminar \n");
			}
		}
		while (respuesta != 's' && respuesta != 'n') {
			printf(
					"\n ERROR. SOLO s/n. Esta seguro de ELIMINAR el Cliente %d ? s/n \n",
					IdEmployee);
			fflush(stdin);
			scanf("%c", &respuesta);
		}
	}
	return retorno;
}


int sortEmployees(Employee *list, int len, int order) {

	int retorno = -1;
	Employee auxEmployee;

	if (list != NULL && len > 0 && order >= 0 && order <= 1) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (list[i].isEmpty==FULL && list[j].isEmpty==FULL) {
					if ((strcmp(list[i].lastName, list[j].lastName) > 0 && order == 1)
							|| (strcmp(list[i].lastName, list[j].lastName) < 0 && order == 0)) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					} else if (list[i].lastName == list[j].lastName
							&& list[i].idSector > list[j].idSector) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					} else if (list[i].lastName == list[j].lastName
							&& list[i].idSector < list[j].idSector) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}


int calculate_Employees(Employee list[], int len) {
	int retorno=-1;
	int i;
	int empleados;
	empleados=0;
	i=0;

	if(list!=NULL&&len>0)
	{
		for(i=0;i<len;i++){
			if(list[i].isEmpty==FULL){
				empleados++;
			}
		}
		retorno=empleados;
	}

	return retorno;
}

float calculate_Wages(Employee list[], int len){
	float retorno=-1;
	int i;
	float salario;
	salario=0;

	if(list!=NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty==FULL){
				salario+=list[i].salary;
			}
		}
		retorno=salario;
	}


	return retorno;
}


float calculate_AverageSalary(Employee list[], int len){
	int Employees;
	float Salary;
	float promedio;
	Salary=calculate_Wages(list, len);
	Employees=calculate_Employees(list, len);
	if(Salary>0 && Employees>0){
		promedio=Salary/Employees;
	}else{
		printf("\n No se pudo realizar el promedio\n");
	}
	return promedio;
}

int calculate_ExceedSalary(Employee list[], int len){
	int retorno=-1;
	int contEmp=0;
	float promedio;
	int i;

	if(list!=NULL && len>0){
		promedio=calculate_AverageSalary(list, len);
		for(i=0; i<len ;i++){
			if(promedio<list[i].salary)
			{
				contEmp++;
			}
		}
		retorno=contEmp;
	}

	return retorno;
}

void informes(Employee list[], int len)
{
	float salario_Total;
	float promedio_Salarial;
	int empleados_MejorPagos;
	salario_Total=0;
	promedio_Salarial=0;
	empleados_MejorPagos=0;

	salario_Total=calculate_Wages(list, len);
	promedio_Salarial=calculate_AverageSalary(list, len);
	empleados_MejorPagos=calculate_ExceedSalary(list, len);

	printf("\n SALARIO TOTAL | PROMEDIO SALARIAL | CANT QUE SUPERA EL SALARIO PROMEDIO \n");
    printf("\n     %f        | %f                |    %d       \n  ",salario_Total
															        ,promedio_Salarial
															        ,empleados_MejorPagos);

}


void printEmployees(Employee lista[],int len, eSector sector[], int top)
{

    if(lista !=NULL && len>0)
    {
        for (int i=0; i<len; i++)
        {
            if(lista[i].isEmpty ==FULL)
            {

                show_OneEmployee(lista[i], sector, top);


            }
        }
    }
    else
    {
        printf("\n No hay empleados que listar\n");
    }
}

void show_OneEmployee(Employee oneEmployee, eSector sector[], int top) {
	char auxSector[51];

	getSector_byId(auxSector, oneEmployee.idSector, sector, top);
	printf("\n ID |ID SECTOR| NOMBRE | APELLIDO | SALARIO  | SECTOR");
	printf("\n %d | %d      | %s     | %s       | %.2f     | %s       \n", oneEmployee.id,
																		oneEmployee.idSector,
																		oneEmployee.name,
																		oneEmployee.lastName,
																		oneEmployee.salary,
																		auxSector);

}
