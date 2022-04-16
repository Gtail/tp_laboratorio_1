/*
 * calculos.h
 *
 *  Created on: 6 abr. 2022
 *      Author: Gian
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int menuSix();
int subMenu();
void chargeSalary(float *salario, char mensaje[], char mensajeError[]);
/***
 * \fn int esNumerico(char cadena[]);
 * \brief Verifica si el valor que recibio es numerico
 * \param cadena :Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 */
int esNumerico(char cadena[]);

/***
 *
 * \fn int esNumericoFlotante(char[])
 * \brief
 *
 * \param cadena
 * \return
 */
int esNumericoFlotante(char cadena[]);

/**
 * @brief Valida si lo ingresado es un flotante o no
 *
 * @param salario Flotante que se recibe por referencia
 * @param mensaje Mensaje de pedir el dato al usuario
 * @param mensajeError Mensaje de error
 */
void chargeSalary(float *salario, char mensaje[], char mensajeError[]);

/**
 * @brief Valida si lo ingresado es un numero
 *
 * @param cadena variable que es utilizada para verificar si es numero o no
 * @return retorna 0 en caso de error, 1 en caso de ser verdadero
 */
int esNumerico(char cadena[]);

/**
 * @brief Valida si lo ingresado es un numero flotante
 *
 * @param cadena Variable implementada para validar si es numero o no
 * @return Retorna -1 en caso de error, 0 en caso de ser verdadero
 */
int esNumericoFlotante(char cadena[]);

/**
 * @brief Calcula 10% de descuento
 * sobre el numero ingresado
 * @param num variable de entrada para realizar el calculo
 * @return devuelve el resultado final del calculo
 */
float calcularDescuento(float num);

/**
 * @brief Calcula un 25% de incremento
 * sobre el numero ingresado
 * @param num variable de entrada para realizar el calculo
 * @return devuelve el resultado final del calculo
 */
float calcularInteres(float num);

/**
 * @brief Calcula el valor en Bitcoin
 * del numero ingresado
 * @param num variable de entrada para realizar el calculo
 * @return devuelve el resultado final del calculo
 */
float calcularBtc(float num);

/**
 * @brief Calcula la diferencia entre
 * dos valores ingresados
 * @param num variable de entrada para realizar el calculo
 * @param num2 variable de entrada para realizar el calculo
 * @return devuelve el resultado final del calculo
 */
float diferenciaPrecio(float num, float num2);

/**
 * @brief Ejecuta todas las funciones previas juntas
 *
 * @param km variable de entrada para realizar el calculo
 * @param LATAM variable de entrada para realizar el calculo
 * @param Aerolineas variable de entrada para realizar el calculo
 * @param descuentoL guarda el resultado final de descuento
 * @param descuentoA guarda el resultado final de descuento
 * @param interesL guarda el resultado final de incremento
 * @param interesA guarda el resultado final de incremento
 * @param btcL guarda el resultado final de la conversion
 * @param btcA guarda el resultado final de la conversion
 * @param unitarioL guarda el resultado final del valor unitario
 * @param unitarioA guarda el resultado final del valor unitario
 * @param diferencia guarda el resultado de la diferencia entre valores
 */
void calcularCostos(float km, float LATAM, float Aerolineas, float *descuentoL, float *descuentoA, float *interesL,float *interesA, float *btcL,float *btcA,  float *unitarioL, float *unitarioA, float *diferencia);

/**
 * @brief Muestra los resultados de los calculos
 * de uno de los valores ingresados
 * @param km valor ingresado
 * @param precioDebito Resultado final del descuento
 * @param precioCredito Resultado final del incremento
 * @param precioBtc Resultado final de la conversion
 * @param precioUnitario Resultado final del valor unitario
 */
void mostrarResultadosL(float km,float precioDebito, float precioCredito, float precioBtc, float precioUnitario);

/**
 * @brief Muestra los resultados de los calculos
 * de uno de los valores ingresados
 * @param precioDebito Resultado final del descuento
 * @param precioCredito Resultado final del incremento
 * @param precioBtc Resultado final de la conversion
 * @param precioUnitario Resultado final del valor unitario
 * @param diferencia Resultado final de la diferencia entre valores
 */
void mostrarResultadosA(float precioDebito, float precioCredito, float precioBtc, float precioUnitario, float diferencia);

/**
 * @brief Ejecuta a las dos funciones previas juntas
 *
 * @param km
 * @param precioDebitoL Resultado final del descuento
 * @param precioCreditoL Resultado final del incremento
 * @param precioBtcL Resultado final de la conversion
 * @param precioUnitarioL Resultado final del valor unitario
 * @param precioDebitoA Resultado final del descuento
 * @param precioCreditoA Resultado final del incremento
 * @param precioBtcA Resultado final de la conversion
 * @param precioUnitarioA  Resultado final del valor unitario
 * @param diferencia Resultado final de la diferencia entre valores
 */
void mostrarResultadosTotales(float km,float precioDebitoL, float precioCreditoL, float precioBtcL, float precioUnitarioL, float precioDebitoA, float precioCreditoA, float precioBtcA,float precioUnitarioA, float diferencia);

/**
 * @brief Realiza la carga forzada de datos,
 * ejecuta los calculos y muestra los resultados finales
 * @param LATAM Valor seteado en 159339
 * @param Aerolineas Valor seteado en 162965
 * @param descuentoL Descuento sobre el valor LATAM
 * @param descuentoA Descuento sobre el valor Aerolineas
 * @param interesL Interes sobre el valor LATAM
 * @param interesA Interes sobre el valor Aerolineas
 * @param btcL Conversion sobre el valor LATAM
 * @param btcA  Conversion sobre el valor Aerolineas
 * @param unitarioL Resultado final del valor unitario LATAM
 * @param unitarioA Resultado final del valor unitario Aerolineas
 * @param diferencia Resultado final de la diferencia entre valores LATAM - AEROLINEAS
 */
void cargaForzada(float LATAM, float Aerolineas, float descuentoL, float descuentoA, float interesL,float interesA, float btcL,float btcA,  float unitarioL, float unitarioA, float diferencia);








#endif /* CALCULOS_H_ */
