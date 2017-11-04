/*Autor: Mario Antonio L�pez Ruiz   ~  1�D*/
/*EJERCICIO 10: C�lculo de la funci�n gaussiana dados una esperanza y desviaci�n t�pica introducida por pantalla*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//Declaraci�n de variables
	const double PI = 3.1416;
	double esperanza, desviacion_tipica, gaussiana;
	double valor;//Valor de x introducido por el usuario
	double parentesis, division, cuadrado;//Variables auxiliares
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el valor para la esperanza: " ;
	cin >> esperanza;
	
	cout << "\nIntroduzca el valor para la desviaci�n t�pica: ";
	cin >> desviacion_tipica;
	
	cout << "\nIntroduzca el valor de x deseado: ";
	cin >> valor;
	
	//C�lculo de la funci�n gaussiana
	//Como la funci�n es muy extensa, voy a guardar los resultados parcialmente, para calcular el final de forma mas simple
	division = 1/(desviacion_tipica*sqrt(2*PI) ); // Calculo la parte de fuera del par�ntesis
	parentesis = pow( ( (valor-esperanza)/desviacion_tipica), 2); //Calculo la parte de dentro del par�ntesis

	//Calculo la funcion gaussiana con sus partes calculadas previamente
	gaussiana = division * exp(-0.5*parentesis);
	
	cout << "El resultado de aplicar la funcion gaussiana es: " << gaussiana;
	
	
	

}
