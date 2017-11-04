/*Autor: Mario Antonio López Ruiz    ~  1ºD*/
/*EJERCICIO 13: Lee un valor de 3 dígitos e imprime cada uno de ellos separados por un espacio.*/
#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	int valor;
	int centena, decena, unidad, auxiliar;
	
	//Peticion por pantalla
	cout << "\nIntroduzca un número de 3 dígitos: ";
	cin >> valor;
	
	//Voy separando el numero en 3 partes y guardo cada parte en una variable
	centena = valor/100;
	auxiliar = valor%100; //en auxiliar estan guardadas las decenas y centenas sin separar
	decena = auxiliar/10;
	unidad = auxiliar%10;
	cout << "\n" << centena << " " << decena << " " << unidad << endl;
	
}
