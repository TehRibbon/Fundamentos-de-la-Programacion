/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*Ejercicio 30: Programa que lee un número entero arbitrario y separa sus dígitos.*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main(){
	//Declaracion de variables
	const double COTA_INF = 0, VAL = 10;
	int izq, resto, valor;
	int numero, numero_aux, contador = -1;//Así evito mostrar un 0 por la izquierda
	bool es_negativo = false;

	//Petición por pantalla
	cout << "\nIntroduzca un numero: ";
	cin >> numero;
	
	if(numero < COTA_INF)
		cout << "-";
	
	numero_aux = abs(numero);

	//Primero calculo el numero de digitos que tiene el numero
	while(numero_aux != COTA_INF){
		numero_aux = numero_aux/VAL;
		contador++;
	}

	//Retomo el valor original
	numero_aux = abs(numero);

	while(numero_aux != COTA_INF){
		valor = pow(VAL,contador);
		izq = numero_aux/valor;
		numero_aux = numero_aux%valor;
		//Voy mostrando los digitos
		cout << izq << " ";
		contador--;
	}
	cout << endl;
}
