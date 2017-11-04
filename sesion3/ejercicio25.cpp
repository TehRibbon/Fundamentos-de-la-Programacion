/*EJERCICIO 25: Programa que lee un carácter, lo transforma a minúscula y lo imprime por pantalla*/

#include <iostream>
using namespace std;

int main(){
	//Declaracion de variables
	char mayuscula, minuscula;
	
	//Peticion por pantalla
	cout << "\Introduzca la letra que quiera transformar a minúscula: ";
	cin >> mayuscula;
	
	//Para pasar de mayuscula a minuscula hay que sumar 32 al char
	minuscula = mayuscula + 32;
	
	//Muestro resultado por patalla
	cout << "\Su carácter en minúscula es: " << minuscula;

}
