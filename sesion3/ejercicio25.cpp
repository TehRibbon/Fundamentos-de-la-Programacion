/*EJERCICIO 25: Programa que lee un car�cter, lo transforma a min�scula y lo imprime por pantalla*/

#include <iostream>
using namespace std;

int main(){
	//Declaracion de variables
	char mayuscula, minuscula;
	
	//Peticion por pantalla
	cout << "\Introduzca la letra que quiera transformar a min�scula: ";
	cin >> mayuscula;
	
	//Para pasar de mayuscula a minuscula hay que sumar 32 al char
	minuscula = mayuscula + 32;
	
	//Muestro resultado por patalla
	cout << "\Su car�cter en min�scula es: " << minuscula;

}
