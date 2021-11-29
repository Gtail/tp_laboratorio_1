/*
 * ArrayEmployees.h
 *
 *  Created on: 29 nov. 2021
 *      Author: Gian
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include "Sector.h"
#include "inputUtn.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define EMPTY 0
#define FULL 1


struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int idSector;//FK
	int isEmpty;
}typedef Employee;

int subMenu();
int subMenu2();

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee list[], int tam, int IdEmployee);
int removeEmployee(Employee *list, int len, int idAuto);
int sortEmployees(Employee *list, int len, int order);
void printEmployees(Employee lista[],int len, eSector sector[], int top);

/**
 * @fn int registerEmployee(Employee*, int, int)
 * @brief Registra un empleado a traves de la funcion addEmployee
 *
 * @param list lista de empleados
 * @param len tamanio de la lista
 * @param id idEmpleado
 * @return
 */
int registerEmployee(Employee* list, int len, int id);

/**
 * @fn int modifyOneEmployee(Employee[], int, int)
 * @brief Modifica un empleado pidiendo un Id de Empleado
 *
 * @param list lista de empleados
 * @param tam tamanio de dicha lista
 * @param IdEmployee auxiliar de ID empleado
 * @return
 */
int modifyOneEmployee(Employee list[], int len, int IdEmployee);

/**
 * @fn int modifyEmployee(Employee[], int, int)
 * @brief Modifica a traves de modify one employee y
 * valida con el retorno
 * @param list
 * @param len
 * @param IdEmployee
 * @return
 */
int modifyEmployee(Employee list[], int len, int IdEmployee);
/**
 * @fn void chargeSalary(float*, char[], char[])
 * @brief Recibe un flotante y lo carga a traves de un
 * auxiliar de char que despues es convertido nuevamente
 * en flotante para poder ser cargado
 * @param salario auxiliar
 * @param mensaje al usuario
 * @param mensajeError al usuario
 */
void chargeSalary(float *salario, char mensaje[], char mensajeError[]);

/**
 * @fn int findEmptySpace(Employee[], int)
 * @brief Busca espacio libre dentro de la lista
 *  de empleados
 * @param list lista de empleados
 * @param len tamanio de la lista
 * @return
 */
int findEmptySpace(Employee list[], int len);

/**
 * @fn void show_OneEmployee(Employee, eSector[], int)
 * @brief muestra un empleado con todos los campos
 * y la descripcion del sector
 * @param oneEmployee auxiliar de empleado
 * @param sector lista de sector
 * @param top tamanio de la misma
 */
void show_OneEmployee(Employee oneEmployee, eSector sector[], int top);


/**
 * @fn float calculate_Wages(Employee[], int)
 * @brief Recorre la lista de empleados existentes
 * y calcula el salario total
 *
 * @param list lista de empleados
 * @param len tamaño de la lista
 * @return el total de los salarios
 */
float calculate_Wages(Employee list[], int len);

/**
 * @fn int calculate_Employees(Employee[], int)
 * @brief Recorre la lista de empleados existentes
 * y los cuenta
 * @param list lista de empleados
 * @param len tamanio de la misma
 * @return devuelve el total de los empleados activos
 */
int calculate_Employees(Employee list[], int len);
/**
 * @fn float calculate_AverageSalary(Employee[], int)
 * @brief Calcula el promedio de los salarios total
 * en caso de que se pueda
 * @param list lista de empleados
 * @param len tamanio de la misma
 * @return devuelve el promedio
 */
float calculate_AverageSalary(Employee list[], int len);
/**
 * @fn int calculate_ExceedSalary(Employee[], int)
 * @brief recorre la lista comparando el salario
 * promedio calculado de la funcion anteriormente
 * descripta, con el salario de cada uno de los
 * empleados activos y cuenta los que estan por
 * encima del promedio
 *
 * @param list lista de empleados
 * @param len tamanio de la misma
 * @return devuelve el total de los empleados que
 * ganan por encima del promedio
 */
int calculate_ExceedSalary(Employee list[], int len);
/**
 * @fn void informes(Employee[], int)
 * @brief funcion dedicada a informar el total de
 * los salarios, el promedio de los salarios,
 * y la cantidad que superan el promedio
 *
 * @param list lista de empleados
 * @param len tamanio de la misma
 */
void informes(Employee list[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
