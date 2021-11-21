/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Gian
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "sector.h"
#include "inputUtn.h"
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
int registerEmployee(Employee* list, int len);
int autoIncremental(int idAuto);
int findEmployeeById(Employee list[], int tam, int IdEmployee);
int modifyOneEmployee(Employee list[], int tam, int IdEmployee);
int modifyEmployee(Employee list[], int tam);
int removeEmployee(Employee *list, int len, int id);
void chargeSalary(float *salario, char mensaje[], char mensajeError[]);
//float chargeSalary();


#endif /* ARRAYEMPLOYEES_H_ */
