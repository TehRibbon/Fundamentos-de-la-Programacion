/*Autor: Mario Antonio L�pez Ruiz   ~  1�D*/
/*EJERCICIO 11: Reescribir ejercicios 3,6,9 y 10 usando constantes*/
/*Como los ejercicios 3,9 y 10 realizados anteriormente est�n escritos usando constantes, implemento �nicamente el ejercicio 6*/

/*EJERCICIO 6: Calcular el numero de segundos que hay entre dos instantes del mismo d�a*/
#include <iostream>
using namespace std;


int main(){
    //Declaraci�n de variables
	const int HORAS_A_SEGUNDOS = 3600;
	const int MINUTOS_A_SEGUNDOS = 60;
	
	int hora_inicio, minutos_inicio, segundos_inicio;
	int hora_fin, minutos_fin, segundos_fin;
	int segundos_solucion = 0;
	
	//Peticiones por pantalla
	cout << "\nIntroduzca la hora inicial: ";
	cin >> hora_inicio;

	cout << "\nIntroduzca los minutos iniciales: ";
	cin >> minutos_inicio;
		
	cout << "\nIntroduzca los segundos iniciales: ";
	cin >> segundos_inicio;
	
	cout << "\nIntroduzca la hora final: ";
	cin >> hora_fin;

	cout << "\nIntroduzca los minutos finales: ";
	cin >> minutos_fin;
		
	cout << "\nIntroduzca los segundos finales: ";
	cin >> segundos_fin;
	
	//C�lculos
	
	//Podr�amos hacer la suma en una l�nea pero el c�digo se ver�a mas "lioso"
	segundos_solucion += (hora_fin - hora_inicio) * HORAS_A_SEGUNDOS;
	segundos_solucion += (minutos_fin - minutos_inicio) * MINUTOS_A_SEGUNDOS; 
	segundos_solucion += segundos_fin - segundos_inicio;
	
	//Muestro el resultado por pantalla
	cout << "\nEl resultado en segundos es: " << segundos_solucion << endl; 
}
