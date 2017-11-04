/**EJERCICIO 27: Escribir una serie de expresiones lógicas que se cumplan según la condición dada**/

#include <iostream>
using namespace std;

int main(){
	//Declaracion de variables
	//Inicializo los bool a false para no tener que poner un else en cada expresión lógica
	bool es_minuscula = false, entre_18_y_65 = false, entre_1_y_100 = false, es_bisiesto = false;
	char letra;
	int edad, adivine, anio;
	
	//Peticiones por pantalla
	cout << "\nIntroduzca una letra: " ;
	cin >> letra;
	
	cout << "\nIntroduzca una edad: " ;
	cin >> edad;
	
	cout << "\nIntroduzca un numero a adivinar: ";
	cin >> adivine;
	
	cout << "\nIntroduzca un año: ";
	cin >> anio;
	
	//Expresiones booleanas
		es_minuscula = (letra >= 'a') && (letra <='z') ;

		entre_18_y_65 = edad<18 || edad>65;

		entre_1_y_100 = (adivine >= 1) && (adivine <= 100);
	
		es_bisiesto = (anio%4 == 0 && anio%100 != 0 ) || (anio%400 == 0) ;
		
			
	//Muestro resultados por pantalla		
	cout << "\nResultado de comprobar si su letra es minuscula: " << es_minuscula << endl;
	cout << "\nResultado de comprobar si su edad es menor que 18 y mayor que 65: " << entre_18_y_65 << endl;
	cout << "\nResultado de comprobar si el nº introducido está entre 1 y 100: " << entre_1_y_100 << endl;
	cout << "\nResultado de comprobar si el año introducido es  bisiesto: " << es_bisiesto << endl;
}
