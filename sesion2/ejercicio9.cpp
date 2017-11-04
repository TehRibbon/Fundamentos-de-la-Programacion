/*Autor: Mario Antonio López Ruiz   ~  1ºD*/
/*EJERCICIO 9: Utilizando la solucion del ejercicio 4, aplicar una serie de porcentajes al salario*/


#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	double salario_base, salario_final;
	const double PRIMERA_SUBIDA = 1.02, SEGUNDA_SUBIDA = 1.03;
	
	//Petición por pantalla
	cout << "Introduzca el saldo base a modificar: ";
	cin >> salario_base;
	
	//Cálculos
	salario_final = salario_base * PRIMERA_SUBIDA;
	
	//Muestro resultado por pantalla del primer porcentaje
	cout << "\nEl resultado de aplicarle un incremento del 2%: " << salario_final << endl;
	
	//Calculo y muestro por pantalla para el segundo porcentaje
	salario_final = salario_final * SEGUNDA_SUBIDA;
	
	cout << "\El resultado de aplicarle un incremento del 3% (además del 2% anterior): " << salario_final << endl;
}
