/*
 * calculos.c
 *
 *  Created on: 6 abr. 2022
 *      Author: Gian
 */

#include "calculos.h"

int menuSix() {
	int opcion;

	printf("1) Ingrese Kilometros \n");

	printf("2) Ingrese Precio de vuelos op 3) LATAM op 4) Aerolineas \n");

	printf("6) Calcular Operaciones \n");

	printf("7) Informar Resultados \n");

	printf("8) Carga Forzada \n\n");

	printf("9) Salir \n\n");


	scanf("%d", &opcion);
	return opcion;
}

int subMenu(){
	int opcion;

	printf("3) Cargar Precio Latam \n");
	printf("4) Cargar Precio Aerolineas \n");
	printf("5) Volver al menu principal \n");

	scanf("%d", &opcion);

	return opcion;

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

int esNumerico(char cadena[])
{
    int i;
    int retorno;

    retorno=1;
    for(i=0 ;cadena[i] != '\0';i++ )
    {
        if(!(isdigit(cadena[i]) ))		//(cadena[i]<'0' || cadena[i]> '9')
        {
            retorno=0;
        }
    }
    return retorno;
}

int esNumericoFlotante(char cadena[])
{
	int retorno;
	int cantPuntos;

	retorno=-1;
	cantPuntos=0;
	for(int i=0 ; cadena[i] != '\0';i++)
	{
		if(cadena[i]== '.' && cantPuntos ==0)
		{
			cantPuntos++;
			continue;
		}
		if(cadena[i] <'0' || cadena[i] > '9')
		{
			retorno=0;
		}
	}
	return retorno;
}


float calcularDescuento(float num)
{
	float resultado;

	resultado=num*0.9;

	return resultado;
}


float calcularInteres(float num)
{
	float resultado;



	resultado= num*1.25;

	return resultado;
}

float calcularBtc(float num)
{
	float resultado;
	float btc;
	btc=4606954.55;

	resultado=1*num/btc;

	return resultado;
}

float precioUnitario(float num, float num2)
{
	float resultado;

	resultado=num/num2;

	return resultado;
}

float diferenciaPrecio(float num, float num2) //LATAM - AEROLINEAS
{
	float resultado;

	resultado=num-num2;

	return resultado;
}

void calcularCostos(float km, float LATAM, float Aerolineas, float *descuentoL, float *descuentoA, float *interesL,float *interesA, float *btcL,float *btcA,  float *unitarioL, float *unitarioA, float *diferencia)
{


	*descuentoL=calcularDescuento(LATAM);
	*descuentoA=calcularDescuento(Aerolineas);
	*interesL=calcularInteres(LATAM);
	*interesA=calcularInteres(Aerolineas);
	*btcL=calcularBtc(LATAM);
	*btcA=calcularBtc(Aerolineas);
	*unitarioL=precioUnitario(LATAM, km);
	*unitarioA=precioUnitario(Aerolineas, km);
	*diferencia=diferenciaPrecio(LATAM, Aerolineas);

}



void mostrarResultadosL(float km,float precioDebito, float precioCredito, float precioBtc, float precioUnitario){

	printf("LATAM \n");
	printf("Kilometros : %f \n", km);
	printf("El precio con tarjeta de Debito : %f \n", precioDebito);
	printf("El precio con tarjeta de Credito : %f\n", precioCredito);
	printf("El precio con BTC : %f \n",  precioBtc);
	printf("El precio Unitario es : %f \n", precioUnitario);

}

void mostrarResultadosA(float precioDebito, float precioCredito, float precioBtc, float precioUnitario, float diferencia)
{

	printf("Aerolíneas \n");
	printf("El precio con tarjeta de Debito : %f \n", precioDebito);
	printf("El precio con tarjeta de Credito : %f \n", precioCredito);
	printf("El precio con BTC : %f \n", precioBtc);
	printf("El precio Unitario es : %f \n", precioUnitario);
	printf("La diferencia de precio es : %f \n", diferencia);

}


void mostrarResultadosTotales(float km, float precioDebitoL, float precioCreditoL, float precioBtcL, float precioUnitarioL, float precioDebitoA, float precioCreditoA, float precioBtcA,float precioUnitarioA, float diferencia)
{

	mostrarResultadosA(precioDebitoA, precioCreditoA, precioBtcA, precioUnitarioA, diferencia);
	mostrarResultadosL(km,precioDebitoL,  precioCreditoL,  precioBtcL,  precioUnitarioL);

}

void cargaForzada(float LATAM, float Aerolineas, float descuentoL, float descuentoA, float interesL,float interesA, float btcL,float btcA,  float unitarioL, float unitarioA, float diferencia)
{
	float kmForzada=7090.00;
	LATAM=162965;
	Aerolineas=159339;

	calcularCostos(kmForzada, LATAM, Aerolineas, &descuentoL, &descuentoA, &interesL, &interesA, &btcL, &btcA, &unitarioL, &unitarioA, &diferencia);
	mostrarResultadosTotales(kmForzada, descuentoL, interesL, btcL, unitarioL, descuentoA, interesA, btcA, unitarioA, diferencia);


}

