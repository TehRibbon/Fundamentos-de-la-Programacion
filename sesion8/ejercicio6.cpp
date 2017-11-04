/*
 * Calculo de la sumatoria de un factorial mediante funciones
 */

/* 
 * File:   ejercicio6.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 14 de noviembre de 2016, 12:01
 */
#include <iostream>
using namespace std;

//Funcion que calcula un factorial dado un numero
long int Factorial(int valor){
	long int factorial = valor;

	for(int i=1; i<valor; i++)
		factorial *= i;
	return factorial;
}

//Funcion que calcula la sumatoria de factoriales
long int SumaFactoriales(int valor){
	long int resultado = 0, factorial = 1;	

	//Calculo de la sumatoria
	for(int i=1; i<=valor; i++){
		factorial = Factorial(i);
        resultado += factorial;
	}

	return resultado;
}

//Segunda versión, con un solo bucle
long int SumaFactoriales2(int valor){
	long int resultado = 0, factorial_ant = 1;

	for(int i=1; i<=valor; i++){
        factorial_ant = factorial_ant * i;
        resultado += factorial_ant;
    }
    
	return resultado;
}

int LeeIntRango(){
	const int COTA_INF = 1, COTA_SUP = 20;
	int valor;

	do{
		cout << "\nIntroduzca un valor dentro del intervalo [1,20]: " ;
		cin >> valor;
	}while(valor < COTA_INF || valor > COTA_SUP);

	return valor;
}
int main(){
	//Declaracion de variables	
	long int resultado_version1, resultado_version2;//int desborda
	int valor;

	valor = LeeIntRango();
	
	resultado_version1 = SumaFactoriales(valor);
	resultado_version2 = SumaFactoriales2(valor);

	cout << "\nEl resultado con la versión 1 para el valor " << valor << " es: " << resultado_version1 << endl;

	cout << "\nEl resultado con la versión 2 para el valor " << valor << " es: " << resultado_version2 << endl;
}
