/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 14: Modificar la solución del ejercicio 8 (año bisiesto) para que no se mezclen E/S y C (entradas/salidas y cómputos)
dentro de la misma estructura condicional.*/

#include <iostream>
using namespace std;

int main(){
	//DeclaraciÃ³n de variables
	const int MULTIPLO_CUATRO = 4, MULTIPLO_100 = 100, MULTIPLO_400 = 400, ES_MULTIPLO = 0;
	int anio;
	bool es_bisiesto;

	//Peticiones por pantalla
	cout << "\nIntroduzca un aÃ±o para comprobar si es bisiesto: ";
	cin >> anio;


	//Comprobaciones
	es_bisiesto = ( (anio%MULTIPLO_CUATRO == ES_MULTIPLO) && (anio%MULTIPLO_100 != ES_MULTIPLO) ) || (anio%MULTIPLO_400 == ES_MULTIPLO);

	//Muestro resultados por pantalla
	if(es_bisiesto)
		cout << "\nEl aÃ±o: " << anio << " SI es bisiesto. " << endl;
	else
		cout << "\nEl aÃ±o: " << anio << " NO es bisiesto. " << endl;	
}
