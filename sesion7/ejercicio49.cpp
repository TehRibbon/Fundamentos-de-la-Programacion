/*
 * EJERCICIO 49: Calcula las secuencias de un numero secuenciable
 */

/* 
 * File:   ejercicio49.cpp
 * Author: Mario Antonio López Ruiz ~ 1ºD
 *
 * Created on 10 de noviembre de 2016, 22:15
 */

#include <iostream>
using namespace std;

int main(){
	//Declaracion de variables
	int numero, aux, mitad, suma = 0;
	bool fin = false, secuenciable = false;
	int i,j;
	//Peticion por pantalla
	cout << "\nIntroduzca un numero para calcular secuencias: ";
	cin >> numero;

	mitad = (numero/2)+1; //No tiene sentido sumar mitad + mitad+1 ya que pasamos el valor
	aux = mitad;

	while(fin == false){
		aux -= 1;
		for(i = aux; i <= mitad; i++){
			//cout << i << " " ;
			suma += i;
			//cout << suma << " ";
		}
		if(suma == numero){//Muestro la secuencia
			secuenciable = true;
			cout << "\nUna subsecuencia es: ";
			for(j = aux; j <= mitad; j++)
				cout << j << " ";
			cout << endl;
		}else if (suma > numero)//Quito el valor mas alto
			mitad = mitad - 1;
	

		if(aux == 1)
			fin = true;

		suma = 0; //Reinicio
	}

	if(!secuenciable)
		cout << "\nEl número introducido no es secuenciable. " << endl;

	


}
