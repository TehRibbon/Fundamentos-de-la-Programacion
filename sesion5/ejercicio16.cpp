/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/2
/*Para compilar este programa hay que usar g++11 -> (UBUNTU): g++ -std=c++11 -c ejercicio16.cpp
 *															  g++ -o ejercicio16 ejercicio16.o
 */
/*EJERCICIO 16: Programa que lee 2 valores por pantalla y nos dice si los tres valores leídos están ordenados de forma
ascendente, ordenados de forma descendente o no están ordenados. 
Para resolver este problema, debe usar una variable de tipo enumerado.*/
#include <iostream>
using namespace std;

enum class FormaOrdenados
	{ascendente, descendente, sinOrden};

int main(){
	//Declaración de variables
	int primero, segundo, tercero;
	FormaOrdenados orden; // hay que configurar compilador para -std=c++11 or .std=gnu++11
	
	//Lo inicializo como no ordenados para ahorrarnos una comprobación if mas adelante
	orden = FormaOrdenados::sinOrden;
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el primer valor: ";
	cin >> primero;
	
	cout << "\nIntroduzca el segundo valor: ";
	cin >> segundo;
	
	cout << "\nIntroduzca el tercer valor: ";
	cin >> tercero;
	
	//Comprobaciones
	if( (primero < segundo) and (segundo < tercero))
		orden = FormaOrdenados::ascendente;
	else if ( (primero > segundo) and (segundo > tercero) )
		orden = FormaOrdenados::descendente;	
	
	//Muestro resultados por pantalla
	if(orden == FormaOrdenados::ascendente)
		cout << "\nLos números: " << primero << " " << segundo << " " << tercero << " están ordenados de forma ascendente. "<< endl;
	else if(orden == FormaOrdenados::descendente)
		cout << "\nLos números: " << primero << " " << segundo << " " << tercero << " están ordenados de forma descendente. " << endl;
	else
		cout << "\nLos números: " << primero << " " << segundo << " " << tercero << " no están ordenados ni ascendente ni descendentemente. " << endl;
}
