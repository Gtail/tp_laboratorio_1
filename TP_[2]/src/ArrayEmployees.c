/*
 * ArrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Gian
 */

#include "ArrayEmployees.h"

int subMenu(){

	printf("\n Seleccione 1- Alta de Empleado 2- Modisicar Empleado 3- Mostrar por Descipcion 4- Informar \n");
	int option;

	printf("\n Opcion 1 Alta de Empleado \n");
	printf("\n Opcion 2 Modificar Empleado \n");
	printf("\n Opcion 3 Baja de Empleado \n");
	printf("\n Opcion 4 Informar \n");
	scanf("%d", &option);

	return option;

}
int subMenu2(){

	printf("\n Seleccione | 1- Listar empleados alfabeticamente Apellido y Sector | 2- Total y Promedio de los Salarios | 3- Salir \n");
	int option;

	printf("\n Opcion 1 Informar Listado de empleados Alfabeticamente Apellido y Sector");
	printf("\n Opcion 2 Total y Promedio de los Salarios");
	printf("\n Opcion 3 Salir");
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


int initEmployees(Employee* list, int len)
{
	int ret=-1;
	for (int i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
			ret=0;
		}

	return ret;
}



int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {

	int ret = 0;
	int index;
	id=0;


	if (list != NULL && len > 0) {
		index = findEmptySpace(list, len);
		if (index != -1) {
			//getStringLetras("\n Ingrese el nombre del empleado \n", name);
			if (getStringSoloLetras("\n Ingrese el nombre del empleado \n","\n Error, intente nuevamente ingresando SOLO letras. \n",name,51,2) != 1) {
				printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
			} else {
				strcpy(list[index].name, name);
				printf("\n Todo ok");
			}
			//getStringLetras("\n Ingrese el Apellido del empleado", lastName);
			if (getStringSoloLetras("\n Ingrese el Apellido del empleado \n","\n Error, intente nuevamente ingresando SOLO letras. \n",lastName,51,2) != 1){
				printf("\n Error, intente nuevamente ingresando SOLO letras. \n");
			}else {
				strcpy(list[index].lastName, lastName);
				printf("\n Todo ok \n");
			}

			chargeSalary(&salary, "\n Inrese el salario", "\n Error, cargue el salario nuevamente");

			sector=getValidInt(
							"\n Ingrese el ID de Sector (1 sistemas | 2 administracion | 3 produccion) \n",
							"\n Error, ingrese solo (1 sistemas | 2 administracion | 3 produccion) \n",
							0, 4);
			id++;
			list[index].idSector=sector;
			list[index].salary=salary;
			list[index].isEmpty = FULL;
			list[index].id=id;
			ret = 1;
		}
	}
	return ret;
}

// hacer de alta que cargue en el campo idSector de employee lo que guarde en ideSector
// de la estructura Sector
// si la funcion addEmployee me devuelve 1, se pudo hacer la carga y solo debo cargar idSector
//

int registerEmployee(Employee* list, int len){
	int ret=0;
	int id=0;
	char name[51];
	char lastName[51];
	float salary=0;
	int sector=0;


	if(addEmployee(list, len,id, name, lastName,salary,sector)!= 0){
		printf("\n La alta de un empleado ha sido exitosa \n");
		ret = 1;
	}
	return ret;
}

int autoIncremental(int idAuto){
	idAuto+=1;
	return idAuto;
}

/*
*/

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

void showEmployeeList(Employee list[], int tam) {

	if (list != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (list[i].isEmpty == FULL) {
				showEmployee(list[i]);
			}
		}
	}
}
int modifyEmployee(Employee list[], int tam) {
	int retorno = 0;
	int IdCliente;
	int Index;
	int modificar;

	showEmployeeList(list, tam);
	IdCliente =  getValidInt("Ingrese un ID de Empleado a Modificar","Error, intente nuevamente", 0, 100);
	Index = findEmployeeById(list, tam, IdCliente);
	if(Index != -1){
		showEmployee(list[Index]);//modifico los campos que me pide la funcion
		modificar = modifyOneEmployee(list, tam, IdCliente);
		if(modificar == 1){
			printf("La modificacion ha sido exitosa");
			showEmployee(list[Index]);
			retorno=1;
		}
	}
	return retorno;
	}

int modifyOneEmployee(Employee list[], int tam, int IdEmployee) {
int opcion;
int error = 0;
int index;
float auxSalary;


	IdEmployee = getValidInt("\n Ingrese el ID de Empleado a Modificar \n",
			"\n Error. Ingrese un ID valido \n", 0, 100);
			index = findEmployeeById(list, tam, IdEmployee);
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
				} while (opcion != 3);
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
			"\n Error. Ingrese un ID valido \n", 0, 100);
	printf("\n Esta seguro de ELIMINAR el Cliente %d ? s/n \n", IdEmployee);
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
			scanf("%c", &respuesta);
		}
	}
	return retorno;
}






