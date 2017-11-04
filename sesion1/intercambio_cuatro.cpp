/*Intercambia el valor de 4 variables haciendo una rotación*/
#include <iostream>
using namespace std;

int main(){
	int aux1,aux2,aux3;//Variables auxiliares para realizar el intercambio
	int primero = 1, segundo = 2, tercero = 3, cuarto = 4;
	
	
	cout << "Vamos a intercambiar los valores: " << primero << " " << segundo << " " << tercero << " " << cuarto << endl;
	aux1 = segundo; //Asignamos las variables auxiliares a sus respectivos valores
	aux2 = tercero;
	aux3 = cuarto;
	
	segundo = primero;
	tercero = aux1;
	cuarto = aux2;
	primero = aux3;
	
	cout << "\nMostramos los valores cambiados: " << primero << " " << segundo << " " << tercero << " " << cuarto << endl;
}

