/*
 * EJERCICIO 2: Calcular un Factorial y una Potencia con funciones.
 */

/* 
 * File:   ejercicio2.cpp
 * Author: Mario Antonio López Ruiz ~ 1ºD
 *
 */

#include <iostream>
using namespace std;

//Funcion para calcular el Factorial
int CalculaFactorial(int valor){
        const int UNO = 1;
        
	int resultado = UNO;//Evito multiplicar por 0

	for(int i=UNO; i<=valor; i++)
		resultado *= i;
	
	return resultado;
}

//Funcion para calcular la Potencia
int CalculaPotencia(int base, int exponente){
    const int UNO = 1;
    int resultado = UNO;//Evito multiplicar por 0

	for(int i=UNO; i<=exponente; i++){
		resultado = resultado * base;
	}

	return resultado;
}

int main(){
	//Definicion de variables
	const int COTA_INFERIOR = 1, COTA_SUPERIOR = 20;
	int valor_n, valor_x, potencia = 0, factorial = 0;
	
	//Peticion por pantalla
	do{
		cout << "\nIntroduzca un valor para n comprendido entre [1,20]: ";
		cin >> valor_n;
	}while(valor_n < COTA_INFERIOR || valor_n > COTA_SUPERIOR);

	cout << "\nIntroduzca un valor para x: ";
	cin >> valor_x;

	//Llamo a las funciones y guardo el resultado
	potencia = CalculaPotencia(valor_x, valor_n);
	factorial = CalculaFactorial(valor_n);

	//Muestro resultados por pantalla
	cout << "\nEl resultado de calcular el factorial de " << valor_n << " es: " << factorial << endl;
	cout << "\nEl resultado de calcular " << valor_n << " elevado a " << valor_x << " es: " << potencia << endl;


}

