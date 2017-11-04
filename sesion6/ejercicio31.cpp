/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*Ejercicio 31: Implementar el algoritmo de la multiplicación rusa para dos numeros n y m*/

#include <iostream>
using namespace std;
int main(){
//Declaracion de variables
	const int PAR = 2, CERO = 0, UNIDAD = 1;
	bool es_impar;
	int n, m;
	int mitad, doble;
	int resultado = 0;


	//Peticiones por pantalla
	cout << "\nIntroduzca el valor para el multiplicando: ";
	cin >> n;
	cout << "\nIntroduzca el valor para el multiplicador: ";
	cin >> m;

	//Para no perder los valores iniciales
	doble = m;	
	mitad = n;
	
	//Calculos	
	while(mitad>=UNIDAD){
		es_impar = (mitad%PAR != CERO);
		if(es_impar || mitad == UNIDAD){
			resultado += doble;	
		}
		doble = doble*PAR;
		mitad = mitad/PAR;
		
	}

	//Muestro resultados por pantalla
	cout << "\nEl resultado de multiplicar " << n << " x " << m << " es: " << resultado << endl;
}
