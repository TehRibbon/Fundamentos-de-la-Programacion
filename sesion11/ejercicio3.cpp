/*
 * Modificar la solución del ejercicio 2 usando un algoritmo más eficiente.
 */

/* 
 * File:   ejercicio3.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 10 de noviembre de 2016, 18:35
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
//Voy a suponer que los elementos introducidos no se encuentran repetidos
int main(){
	//Declaración de variables
	const int TAMANIO = 1000;
	const int CENTINELA = -1;
	int contador=0, contador_mayores = 0;
	double vector[TAMANIO], entrada;
	double referencia;
	int k;

	//Petición por pantalla
	do{
		cout << "\nIntroduzca un valor: (-1 para acabar): " ;
		cin >> entrada;
		
		if(entrada != CENTINELA){
			vector[contador] = entrada;
			contador++;
		}

	}while(entrada != CENTINELA);
	
	
	cout << "\nIntroduzca el valor de referencia: " ;
	cin >> referencia;

	//k primeros valores mayores que la referencia
	cout << "\nIntroduzca el valor de k: ";
	cin >> k;

	//Creo el vector de copia
	double mayores_que[contador]; //HAY QUE USAR CONSTANTES<--------------------- (Funciona solo en g++)
	double temporal; //Variable auxiliar para la ordenacion

	
	for(int i=0; i<contador; i++){
		if((vector[i] > referencia)){
			mayores_que[contador_mayores] = vector[i];

			temporal = mayores_que[contador_mayores];
			int j = contador_mayores-1;
	
			while( (mayores_que[j] > temporal) && (j >= 0)){//Mientras que el anterior sea mas grande
				mayores_que[j+1] = mayores_que[j];
				mayores_que[j] = temporal;				
				j--;
			} 

			contador_mayores++;
		}
	}

	
	
	//Muestro el resultado por pantalla
	if(contador == 0)
		cout << "\nNo se ha introducido ningún valor. " << endl;
	else{
		cout << "\nEl vector resultante para el valor de referencia = " << referencia << " y con el valor de k = " << k << " es :";
		for(int j=0; j<contador_mayores; j++)
			cout << mayores_que[j] << " ";
		cout << endl;
	}


	
}
