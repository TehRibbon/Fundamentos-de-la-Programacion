/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 24: Programa que dos valores para establecer un intervalo (con unas precondiciones), después solicita un valor y comprueba si
	 está dentro de ese rango, para así realizar los cálculos necesarios.
*/
#include <iostream>
using namespace std;

int main(){	
	//Declaración de variables
	const string ERROR_ENTRADA_MIN = "\nValor erróneo, min debe ser positivo. ";
	const string ERROR_ENTRADA_MAX = "\nValor erróneo, max debe ser mayor a min. ";
	const string ERROR_INTERVALO = "\nHa introducido un valor fuera del intervalo establecido. ";
	const string ERROR_INTENTOS = "\nNúmero de intentos sobrepasado. " ;
	const int MAX_ENTRADAS = 3, POSITIVO = 0;
	double min, max; 
	double nuevo;
	double resultado1, resultado2;
	int contador = 0; //Inicializo a cero
	bool error_entrada, error_intervalo;
	//Peticiones por pantalla
	//->min debe ser positivo
	//->max debe ser mayor que min
	do{
		cout << "\nIntroduzca un valor para min: ";
		cin >> min;

		error_entrada = min < POSITIVO;

		if(error_entrada)
			cout << ERROR_ENTRADA_MIN << endl;

	}while(error_entrada);
		
	do{
		cout << "\nIntroduzca un valor para max: ";
		cin >> max;
		
		error_entrada = max <= min; //Para mostrar mensaje de error en caso de introducir mal los valores

		if(error_entrada)
			cout << ERROR_ENTRADA_MAX << endl;
			
	}while(error_entrada);

	//El valor debe estar dentro del intervalo[min,max] y no se deben superar 3 intentos
	do{
		cout << "\nIntroduzca un valor dentro del intervalo [min,max]: ";
		cin >> nuevo; 

		//Guardo el resultado en un bool
		error_intervalo = ( (nuevo < min) or (nuevo > max) );
		
		if(error_intervalo){
			cout << ERROR_INTERVALO << endl;
			contador++;		
		}
	}while( ( (nuevo < min) or (nuevo > max) ) && (contador < MAX_ENTRADAS) );
	
	
	//Calculos
	resultado1 = nuevo - min;
	resultado2 = max - nuevo;

	//Muestro resultados por pantalla: 
	if(contador >= MAX_ENTRADAS)
		cout << ERROR_INTENTOS << endl;
	else
		cout << "\nEl resultado es: " << resultado1 << " " << resultado2 << endl;
	

}
