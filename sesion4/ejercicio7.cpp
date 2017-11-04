/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 7: Programa que lee 3 valores enteros desde teclado y nos dice si están ordenados (ascendente o descendentemente) o no.


*/

#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	int primero, segundo, tercero;
	bool ascendente = false, descendente = false;
	//Peticiones por pantalla
	cout << "\nIntroduzca el primer valor: ";
	cin >> primero;
	
	cout << "\nIntroduzca el segundo valor: ";
	cin >> segundo;
	
	cout << "\nIntroduzca el tercer valor: ";
	cin >> tercero;
	
	//Comprobaciones
	if( (primero < segundo) and (segundo < tercero))
		ascendente = true;
	else if ( (primero > segundo) and (segundo > tercero) )
		descendente = true;	
	
	//Muestro resultados por pantalla

	if(ascendente)
		cout << "\nLos números: " << primero << " " << segundo << " " << tercero << " introducidos están ordenados ascendentemente. " << endl;
	else if(descendente)
		cout << "\nLos números: "<< primero << " " << segundo << " " << tercero << " introducidos están ordenados descendentemente. " << endl;
	else
		cout << "\nLos números: " << primero << " " << segundo << " " << tercero << " introducidos no están ordenados. " << endl;

}
