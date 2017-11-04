/*
 * Ejercicio 46: Programa que lee un valor T y calcula la sumatoria dada en el enunciado. 
 */

/* 
 * File:   ejercicio46.cpp
 * Author: Mario Antonio López Ruiz ~ 1ºD
 *  
 */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	//Declaracion de variables
	const int POSITIVO = 0;
	int valor, resultado = 0, factorial;
	int i,j;
	//Peticion por pantalla
	do{
	cout << "\nIntroduzca el valor para calcular la sumatoria de sus factoriales: ";
	cin >> valor;
	}while(valor < POSITIVO);

	//Calculo de la sumatoria
	for(i=1; i<=valor; i++){
            factorial = 1;//Reinicio
            for(j=2; j<=i; j++){
                factorial *= j;
            }
            resultado += factorial;
	}

	//Muestro el resultado por pantalla
	cout << "\nEl resultado de aplicar a función al valor " << valor << " es: " << resultado << endl;
}

