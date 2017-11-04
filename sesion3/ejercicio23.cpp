/*EJERCICIO	23:Dadas tres variables correspondientes a las horas, los minutos y los segundos,
calcular el valor de cada una dentro de su rango correspondiente*/

#include <iostream>
using namespace std;

int main(){
	//Declaracion de variables
	const int DESBORDA_SEGUNDOS=60, DESBORDA_MINUTOS=60, DESBORDA_HORAS=24;
	int horas, minutos, segundos, dias = 0;
	int aux_horas, aux_minutos, aux_segundos; 
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el valor para las horas: ";
	cin >> horas;
	
	cout << "\nIntroduzca el valor para los minutos: ";
	cin >> minutos;
	
	cout << "\nIntroduzca el valor para los segundos: ";
	cin >> segundos;
	
	//Calculos
	aux_segundos = segundos/DESBORDA_SEGUNDOS;
	segundos = segundos%DESBORDA_SEGUNDOS;
	minutos += aux_segundos;
	
	aux_minutos = minutos/DESBORDA_MINUTOS;
	minutos = minutos%DESBORDA_MINUTOS;
	horas += aux_minutos;
	
	aux_horas = horas/DESBORDA_HORAS;
	horas = horas%DESBORDA_HORAS;
	dias += aux_horas;
	
	
	//Muestro el resultado por pantalla
	cout << "\nNúmero de días: " << dias;
	cout << "\nNúmero de horas: " << horas;
	cout << "\nNúmero de minutos: " << minutos;
	cout << "\nNúmero de segundos: " << segundos;
}
