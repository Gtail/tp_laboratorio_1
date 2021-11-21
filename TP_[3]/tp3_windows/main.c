#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    int flagText=0;
    int flagBin=0;
    int flagC_Bin=0;
    int flagC_Text=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    ll_clear(listaEmpleados);



    printf("Bienvenido, elija una opcion \n\n");

    do{
    	option=menuTen();
        switch(option)
        {
            case 1:
            	printf("\n Usted ha seleccionado 1: Cargar Empleados Modo Texto \n");

            	if(flagText==0 && flagBin==0){
				if(controller_loadFromText("data.csv", listaEmpleados)!= -1)
				{
					printf("Carga exitosa\n");
				}else{
					printf("error carga datos\n");
				}
				flagText=1;
            	}else{
            		printf("\n La lista ya ha sido cargada \n");
            	}

                break;
            case 2:
            	printf("\n Usted ha seleccionado 2: Cargar Empleados Modo Binario \n");
            	if(flagText==1&&flagC_Bin==0)
            	{
            		printf("\n Una vez cargada la lista en Modo Texto, guarde en Binario y cargue! \n");
            	}
            	if(flagC_Bin==1){
            	if(controller_loadFromBinary("data.bin" , listaEmpleados)!=-1)
				{
            		printf("La carga en Binario es exitosa \n");
				}else{
					printf("No se concretó la carga en Modo Binario \n");
				}
            	}

            	break;
            case 3:
            	printf("\n Usted ha seleccionado 3: Alta de Empleado \n");
            	if(controller_addEmployee(listaEmpleados)==1){
            		printf("Alta exitosa \n");
            	}else
            	{
            		printf("No se concreto el Alta \n");
            	}
            	break;
            case 4:
            	printf("\n Usted ha seleccionado 4: Modificacion Empleado \n");
            	if(controller_editEmployee(listaEmpleados)==1)
            	{
            		printf("Modificacion Exitosa \n");
            	}else
            	{
            		printf("No se concreto la Modificacion \n");
            	}
            	break;
            case 5:
            	printf("\n Usted ha seleccionado 5: Baja de Empleado \n");
            	if(controller_removeEmployee(listaEmpleados)==1)
            	{
            		printf("Baja Exitosa \n");
            	}else
            	{
            		printf("No se concreto la Baja \n");
            	}
            	break;
            case 6:
            	printf("\n Usted ha seleccionado 6: Listar Empleados \n");
            	if(controller_ListEmployee(listaEmpleados)==1){
            		printf("Listado exitoso \n");
            	}
            	break;
            case 7:
            	printf("\n Usted ha seleccionado 7: Ordenar Empleados \n");
            	if(controller_sortEmployee(listaEmpleados)==1)
				{
					printf("Ordenamiento exitoso \n");
				}
            	break;
            case 8:
            	printf("\n Usted ha seleccionado 8: Guardar empleados en Modo Texto \n");
            	if(flagText==1 && flagC_Text==0)
            	if(controller_saveAsText("data.csv", listaEmpleados)==1)
            	{
            		printf("Guardado en Modo Texto exitoso \n");
            	}
            	break;
            case 9:
            	printf("\n Usted ha seleccionado 9: Guardar empleados en Modo Binario \n");
            	if(flagText==1 && flagC_Bin==0){
            	if(controller_saveAsBinary("data.bin" , listaEmpleados)==1)
            	{
            		printf("Guardado en Modo Binario exitoso \n");
            	}
            	flagC_Bin=1;
            	}
            	break;
            case 10:
            	printf("Hasta Luego \n");
            	break;
        }
    }while(option!=10);

    return 0;
}

