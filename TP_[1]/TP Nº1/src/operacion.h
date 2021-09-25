/*
 * operation.h
 *
 *  Created on: 19 sep. 2021
 *      Author: Gian
 */

#ifndef OPERACION_H_
#define OPERACION_H_
#include <stdio.h>
#include <stdlib.h>

/// @fn int menuFive()
/// @brief la funcion Menu, como su nombre lo indica, hace de menu
/// con cinco opciones y un default en caso de que se haya seleccionado una opcion no valida.
/// @return devuelve el digito ingresado y lo guarda en el main a traves del entero opcion.
int menuFive();
/// @fn int operando1(int)
/// @brief la funcion le solicita al usuario que ingrese un numero entero.
/// @param num1 - el parametro para indicar que la funcion recibira un numero
/// en este caso, el primero.
/// @return al ser una fucion int, retorna un valor y lo guarda en la variable del main.
int operando1(int num1);
/// @fn int operando2(int)
/// @brief  la funcion le solicita al usuario que ingrese un numero entero.
/// @param num2 el parametro para indicar que la funcion recibira el segundo numero en este caso.
/// @return retorna un valor entero y lo guarda en la variable del main.
int operando2(int num2);
/// @fn long int factoreo(int)
/// @brief En esta funcion, se realiza el factorial de los numeros
/// @param num1 es el numero que recibe la funcion
/// @return devuelve un entero
long int factoreo( int num1);
/// @fn int sumar(int, int)
/// @brief Como su nombre lo indica, realiza la adicion de los numeros ingresados
/// @param num1 recibe el primer numero entero
/// @param num2 recibe el segundo numero entero
/// @return devuelve el resultado como entero
int sumar(int num1, int num2);
/// @fn int restar(int, int)
/// @brief Recibe los dos numeros ingresados y realiza la sustraccion
/// @param num1 recibe el primer numero entero
/// @param num2 recibe el segundo numero entero
/// @return	devuelve el resultado como entero
int restar(int num1, int num2);
/// @fn float dividir(int, int)
/// @brief la funcion se encarga de recibir los dos numeros enteros y dividirlos
/// en la funcion se realiza un casting para poder obtener un resultado en float.
/// @param num1 recibe el primer entero
/// @param num2 recibe el segundo entero
/// @return lo retorna con un float
float dividir(int num1, int num2);
/// @fn int multiplicar(int, int)
/// @brief la funcion recibe dos enteros y realiza una multiplicacion
/// @param num1 recibe el primer entero
/// @param num2 recibe el segundo entero
/// @return	devuelve el resultado como un int
int multiplicar(int num1, int num2);
/// @fn void operar(int, int, int*, int*, float*, int*, int*, int*)
/// @brief la funcion se encarga de mostrar los resultados. En su mayoria, punteros.
/// @param num1	primer entero ingresado
/// @param num2 segundo entero ingresado
/// @param sumatoria en forma de puntero para asignarle la direccion de memoria de la operacion
/// @param resta en forma de puntero para asignarle la direccion de memoria de la operacion
/// @param division en forma de puntero para asignarle la direccion de memoria de la operacion
/// @param multiplicacion en forma de puntero para asignarle la direccion de memoria de la operacion
/// @param factorizarA en forma de puntero para asignarle la direccion de memoria de la operacion
/// Utilizo dos Factorizar, porque tengo dos numeros que recibo en la funcion, primero num1 y luego en caso de num2.
/// A traves de estas dos tomo la direccion de memoria para devolverlas al main
/// y luego mostrarlas en su respectiva funcion
/// @param factorizarB en forma de puntero para asignarle la direccion de memoria de la operacion
void operar(int num1, int num2, int *sumatoria, int *resta, float *division, int *multiplicacion, long int *factorizarA, long int *factorizarB);
/// @fn void mostrar(int, int, float, int, int, int)
/// @brief La funcion se encarga de mostrar los resultados, va a mostrar esas direcciones
/// de memoria a las cuales apuntamos en la funcion previa
/// @param sumatoria muestro el valor
/// @param resta muestro el valor
/// @param division muestro el valor
/// @param multiplicacion muestro el valor
/// @param factorizar muestro el valor
/// @param factorizar2 muestro el valor
/// @param num1 recibe el primer entero para una validacion
/// @param num2	recibe el segundo entero para una validacion
void mostrar(int num1, int num2,int sumatoria, int resta, float division, int multiplicacion, long int factorizar, long int factorizar2);

#endif /* OPERACION_H_ */
