/*Autor: Mario Antonio L�pez Ruiz   ~  1�D1*/
/*EJERCICIO 14: Modificar la soluci�n del ejercicio 8 (a�o bisiesto) para que no se mezclen E/S y C (entradas/salidas y c�mputos)
dentro de la misma estructura condicional.*/

#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	const int MULTIPLO_CUATRO = 4, MULTIPLO_100 = 100, MULTIPLO_400 = 400, ES_MULTIPLO = 0;
	int anio;
	bool es_bisiesto;

	//Peticiones por pantalla
	cout << "\nIntroduzca un año para comprobar si es bisiesto: ";
	cin >> anio;


	//Comprobaciones
	es_bisiesto = ( (anio%MULTIPLO_CUATRO == ES_MULTIPLO) && (anio%MULTIPLO_100 != ES_MULTIPLO) ) || (anio%MULTIPLO_400 == ES_MULTIPLO);

	//Muestro resultados por pantalla
	if(es_bisiesto)
		cout << "\nEl año: " << anio << " SI es bisiesto. " << endl;
	else
		cout << "\nEl año: " << anio << " NO es bisiesto. " << endl;	
}
