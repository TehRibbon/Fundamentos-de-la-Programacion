/*EJERCICIO 4: Programa que lee el valor de salario base por pantalla, 
lo incrementa en un porcentaje y muestra el resultado por pantalla*/

#include <iostream>
using namespace std;

int main(){
	/*La alternativa que he elegido es la b, introducir el resultado final en una variable. Así, si quiero utilizar
	el saldo_base en otra operación puedo hacerlo sin problemas. Además, al guardar el saldo final en otra variable, 
	puedo hacer operaciones con ese valor si fuese necesario*/
	
	//Declaración de variables
	double saldo_base, saldo_final;
	const double porcentaje = 1.02;
	
	//Petición por pantalla
	cout << "Introduzca el saldo base a modificar: ";
	cin >> saldo_base;
	
	//Cálculos
	saldo_final = saldo_base * porcentaje;
	
	//Muestro resultado por pantalla
	cout << "\nEl resultado de aplicarle un incremento del 2% es: " << saldo_final << endl;

}
