/*EJERCICIO 2: Programa que teniendo la intensidad y resistencia imprime el voltaje correspondiente aplicando la Ley de Ohm
		Ley de Ohm: voltaje = intensidad*resistencia
	*/

#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	double voltaje, intensidad, resistencia;
	
	cout << "\nIntroduzca el valor para la intensidad: ";
	cin >> intensidad;
	cout << "\nIntroduzca el valor para la resistencia: ";
	cin >> resistencia;
	 
	//Calculo ahora el valor para el voltaje
	voltaje = intensidad * resistencia;
	
	cout << "\nEl valor resultante para el voltaje es: " << voltaje << endl;
}
