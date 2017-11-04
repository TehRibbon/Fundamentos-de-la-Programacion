/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 11: Usando la solución del ejercicio 5, implementar otro criterio para la subida salarial:
	4% +  para los empleados que han resuelto mas de 30 casos
	2% + si el grado de satisfaccion  del cliente es mayor o igual a 4.0
	Hay que considerar que ambas subidas son compatibles (pueden aplicarse ambas si se cumplen las condiciones)*/

#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	const int CASOS_COTA_INF = 20, CASOS_COTA_SUP = 30; //Cotas inferior y superior
	const double SATISFACCION_MINIMO = 4.0; //Cota para el grado de satisfaccion
	const double SUBIDA_DOSP = 0.02, SUBIDA_TRESP = 0.03, SUBIDA_CUATROP = 0.04; //Porcentajes a incrementar
	double salario_por_hora, salario_inicial, salario_final;
	int horas_trabajadas, casos_resueltos;
	double grado_satisfaccion; //debe valer entre 0 y 5
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el el salario por hora del empleado: " ;
	cin >> salario_por_hora;
	
	cout << "\nIntroduzca el número de horas trabajadas en el mes actual: " ;
	cin >> horas_trabajadas;
	
	cout << "\nIntroduzca el número de casos resueltos satisfactoriamente: ";
	cin >> casos_resueltos;
	
	cout << "\nIntroduzca el grado medio de satisfacción de los usuarios con el empleado en cuestión:";
	cin >> grado_satisfaccion;
	
	//Calculos
	salario_inicial = salario_por_hora*horas_trabajadas;
	salario_final = salario_inicial;
	
	
	if(casos_resueltos > CASOS_COTA_SUP)					//Si ha resuelto mas de 30 casos
		salario_final += salario_inicial*SUBIDA_CUATROP;	//Aplico 4% de subida (al salario inicial) 
	else if (casos_resueltos >= CASOS_COTA_INF)				//Si se encuentra entre 20 y 30 casos resueltos
		salario_final += salario_inicial*SUBIDA_TRESP;		//Aplico 2% de subida (al salario inicial) 

	if(grado_satisfaccion >= SATISFACCION_MINIMO)//Si la media del grado de satisfaccion es mayor o igual a 4
		salario_final += salario_inicial*SUBIDA_DOSP; //Aplico 2% de subida (al salario inicial) 

	//Muestro resultados por pantalla
	cout << "\nEl salario final del cliente es de: " << salario_final << " euros. " << endl;
}
