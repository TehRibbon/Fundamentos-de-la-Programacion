/*Autor: Mario Antonio L�pez Ruiz   ~  1�D1*/
/*EJERCICIO 7: Programa que lee 3 valores enteros desde teclado y nos dice si est�n ordenados (ascendente o descendentemente) o no.


*/

#include <iostream>
using namespace std;

int main(){
	//Declaraci�n de variables
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
		cout << "\nLos n�meros: " << primero << " " << segundo << " " << tercero << " introducidos est�n ordenados ascendentemente. " << endl;
	else if(descendente)
		cout << "\nLos n�meros: "<< primero << " " << segundo << " " << tercero << " introducidos est�n ordenados descendentemente. " << endl;
	else
		cout << "\nLos n�meros: " << primero << " " << segundo << " " << tercero << " introducidos no est�n ordenados. " << endl;

}
