#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "inputUtn.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id); //
int employee_getId(Employee* this,int* id); //en el puntero te dice cual es el id y lo guarda por referencia

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void chargeSalary(int *salario, char mensaje[], char mensajeError[]);

void Mostrar_UnEmpleado(Employee* auxEmpleado);
void Mostrar_ListaEmpleados(LinkedList *pArrayListEmployee);
int employee_setFields(Employee* aEmp, int auxId, char* auxNombre, int auxHoras, int auxSueldo);
int obtenerId(char* path, int* id);
void autoIncremental(char* path);
int buscar_EmpleadoPorId(LinkedList *pArrayListEmployee, int *id,Employee *auxEmployee);

int addEmployee(Employee* pEmp,int id);
int modificar_Empleado(LinkedList *pArrayListEmployee, int* id);
#endif // employee_H_INCLUDED

//recibis todos los char, validas que sean distintos de null y los convertis
// Una vez que
