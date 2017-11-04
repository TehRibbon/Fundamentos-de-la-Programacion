/*EJERCICIO 3: Programa que solicita la longuitud del radio y calcula el área del círculo y la longuitud de la 
	circunferencia correspondiente, mostrando el resultado por pantalla.*/
#include <iostream>
using namespace std;

int main(){
	const double PI = 3.1416;
	double radio, area, longuitud_circunferencia;
	
	//Pedimos por pantalla el valor para la longuitud
	cout << "Introduzca el valor de la longuitud del radio: " ;
	cin >> radio;
	
	//Calculamos el valor del area
	area = PI * (radio * radio);
	
	//Calculo la longuitud de la circunferencia
	longuitud_circunferencia = 2*PI*radio;
	
	cout << "\nEl resultado del área es: " << area << endl;
	cout << "\nEl resultado de la longuitud de la circunferencia es: " << longuitud_circunferencia << endl;
}
