/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 8: Programa que lee el número de un año e indica si es bisiesto o no.

Un año es bisiesto si:
	->Es múltiplo de cuatro, pero no de cien.
	->Los múltiplos de cuatrocientos siempre son bisiestos.*/

#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	int anio;
	bool es_bisiesto;

	//Peticiones por pantalla
	cout << "\nIntroduzca un año para comprobar si es bisiesto: ";
	cin >> anio;

	//Comprobaciones
	es_bisiesto = ( (anio%4 == 0) && (anio%100 != 0) ) || (anio%400 == 0);

	//Muestro resultados por pantalla
	if(es_bisiesto)
		cout << "\nEl año: " << anio << " SI es bisiesto. " << endl;
	else
		cout << "\nEl año: " << anio << " NO es bisiesto. " << endl;	
}
