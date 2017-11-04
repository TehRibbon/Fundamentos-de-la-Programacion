/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 22: Usando la solución del ejercicio 10 (función gaussiana) se pide construir un programa que imprima el resultado
 * de aplicar esa función a varios valores de abscisas.*/
#include <iostream>
#include <cmath>
using namespace std;


int main(){
	//Declaración de variables
	const double PI = 3.1416;
	const double POSITIVO = 0;
	double esperanza, desviacion_tipica, gaussiana;
	double minimo, maximo, incremento;
	double aux_minimo;
	double valor, contador = 1;
	double parentesis, division, cuadrado;//Variables auxiliares
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el valor para la esperanza: " ;
	cin >> esperanza;
	
	do{
		cout << "\nIntroduzca el valor para la desviación típica: ";
		cin >> desviacion_tipica;
	}while(desviacion_tipica < POSITIVO);

	cout << "\nIntroduzca un valor para el mínimo: ";
	cin >> minimo;

	do{
		cout << "\nIntroduzca un valor para el máximo: ";
		cin >> maximo;
	}while(maximo < minimo);

	do{
		cout << "\nIntroduzca un incremento: ";
		cin >> incremento;
	}while(incremento <= POSITIVO); //De esta forma el incremento no puede valer cero

	//Cálculo de la funcion gaussiana
	aux_minimo = minimo; //Para la primera iteración

	while(aux_minimo <= maximo){		

		//Como la funcion es muy extensa, voy a guardar los resultados parcialmente, para calcular el final de forma mas simple
		division = 1/(desviacion_tipica*sqrt(2*PI) );
		parentesis = pow( ( (aux_minimo-esperanza)/desviacion_tipica), 2);

		//Calculo la funcion gaussiana con sus partes calculadas previamente
		gaussiana = division * exp(-0.5*parentesis);

		//Muestro resultado por pantalla en cada iteración
		cout << "\nEl resultado de aplicar la funcion gaussiana es para x = " << aux_minimo << ": " << gaussiana << endl;

		//Incrementos
		aux_minimo = minimo + contador*incremento;
		contador++;

	}

	
	
	
	

}
