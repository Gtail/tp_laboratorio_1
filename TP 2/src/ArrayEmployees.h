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
int findEmptySpace(Employee list[], int len);
int registerEmployee(Employee* list, int len, int id);
int autoIncremental(int idAuto);
int findEmployeeById(Employee list[], int tam, int IdEmployee);
int modifyOneEmployee(Employee list[], int tam, int IdEmployee);
int modifyEmployee(Employee list[], int tam, int IdEmployee);
int removeEmployee(Employee *list, int len, int idAuto);
void chargeSalary(float *salario, char mensaje[], char mensajeError[]);

int sortEmployees(Employee *list, int len, int order);
void printEmployees(Employee lista[],int len, eSector sector[], int top);
void show_OneEmployee(Employee oneEmployee, eSector sector[], int top);

float calculate_Wages(Employee list[], int len);
int calculate_Employees(Employee list[], int len);
float calculate_Wages(Employee list[], int len);
float calculate_AverageSalary(Employee list[], int len);
int calculate_ExceedSalary(Employee list[], int len);
void informes(Employee list[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
