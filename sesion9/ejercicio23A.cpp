/*
 * APARTADO A: Definicion de la clase Recta y creación de objetos
 */

/* 
 * File:   ejercicio23A.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 21 de noviembre de 2016, 12:26
 */
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Recta{
	public:
		double A;
		double B;
		double C;
		
};

int main(){
	//Creacion de objetos
	Recta recta_1, recta_2;

	//Declaracion de variables
	double a1, a2, b1, b2, c1, c2;
	double pendiente1, pendiente2;

	cout << "\nIntroduzca los valores para la primera recta: " << endl;
	cout << "\tA -> " ;
	cin >> a1;

	cout << "\tB -> " ;
	cin >> b1;

	cout << "\tC -> " ;
	cin >> c1;

	cout << "\nIntroduzca los valores para la segunda recta: " << endl;
	cout << "\tA -> " ;
	cin >> a2;

	cout << "\tB -> " ;
	cin >> b2;

	cout << "\tC -> " ;
	cin >> c2;

	//Asigno coeficientes a la primera recta
	recta_1.A = a1;
	recta_1.B = b1;
	recta_1.C = c1;

	//Ahora con la segunda recta
	recta_2.A = a2;
	recta_2.B = b2;
	recta_2.C = c2;

	//Calculo la pendiente de cada recta
	pendiente1 = - recta_1.A / recta_1.B;
	pendiente2 = - recta_2.A / recta_2.B;

	//Muestro resultado por pantalla
	cout << "\nLa pendiente de la primera recta es: " << pendiente1 << endl;
	cout << "\nLa pendiente de la segunda recta es: " << pendiente2 << endl;
}

