/*
 * APARTADO B: Métodos públicos
 * No añadimos pendiente como dato miembro porque no es esencial para definir una recta.
 */

/* 
 * File:   ejercicio23B.cpp
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
		
	double CalculaPendiente(){
		double pendiente;

		pendiente = - A / B;

		return pendiente;
	}

	double Ordenada(int x){
		double ordenada;
		
		ordenada = (-C -x*A) / B;
		
		return ordenada;
	
	}

	double Abscisa(int y){
		double abscisa;
		
		abscisa = (-C -y*B) / A;

		return abscisa;
	}
};

int main(){
	//Creacion de objetos
	Recta recta_1, recta_2;

	//Declaracion de variables
	double a1, a2, b1, b2, c1, c2;
	double pendiente1, pendiente2;
	double abscisa, ordenada;

	double resultado_abs1, resultado_abs2, resultado_ord1, resultado_ord2;

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

	cout << "\nIntroduzca un valor para la abscisa: ";
	cin >> abscisa;

	cout << "\nIntroduzca un valor para la ordenada: ";
	cin >> ordenada;

	//Asigno coeficientes a la primera recta
	recta_1.A = a1;
	recta_1.B = b1;
	recta_1.C = c1;

	//Ahora con la segunda recta
	recta_2.A = a2;
	recta_2.B = b2;
	recta_2.C = c2;

	//Calculo la pendiente de cada recta
	pendiente1 = recta1.Pendiente();
	pendiente2 = recta2.Pendiente();


	resultado_abs1 = ;
	resultado_abs2;
	resultado_ord1;	
	resultado_ord2;
	//Muestro resultado por pantalla
	cout << "\nLa pendiente de la primera recta es: " << pendiente1 << endl;
	cout << "\nLa pendiente de la segunda recta es: " << pendiente2 << endl;
}

