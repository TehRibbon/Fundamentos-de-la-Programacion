/*Autor: Mario Antonio L�pez Ruiz   ~  1�D1*/
/*EJERCICIO 5: Programa que lee el salario por hora de un empleado, el n� de horas trabajadas en el mes actual,
	el n� de casos resueltos de forma satisfactoria y el grado medio de satisfacci�n de los clientes.
	Aplicarle una subida salarial en funci�n de varios factores.
	Aplicarle una subida del 4% si el n� de casos resueltos satisfactoriamente es mayor a 30
*/
#include <iostream>
using namespace std;

int main(){
	//Declaraci�n de variables
	double salario_por_hora, salario_final, salario_inicial;
	int horas_trabajadas, casos_resueltos;
	double grado_satisfaccion; //debe valer entre 0 y 5
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el el salario por hora del empleado: " ;
	cin >> salario_por_hora;
	
	cout << "\nIntroduzca el n�mero de horas trabajadas en el mes actual: " ;
	cin >> horas_trabajadas;
	
	cout << "\nIntroduzca el n�mero de casos resueltos satisfactoriamente: ";
	cin >> casos_resueltos;
	
	cout << "\nIntroduzca el grado medio de satisfacci�n de los usuarios con el empleado en cuesti�n:";
	cin >> grado_satisfaccion;
	
	//Calculos
	salario_inicial = salario_por_hora*horas_trabajadas;
	salario_final = salario_inicial;
	if(casos_resueltos>30) //Si ha resuelto mas de 30 casos
		salario_final = salario_inicial*1.04; //Aplico el 4% de subida

	//Muestro resultados por pantallaa
	cout << "\nEl salario final del cliente es de: " << salario_final << " �. " << endl;
}
