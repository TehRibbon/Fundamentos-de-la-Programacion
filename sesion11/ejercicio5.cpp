/*
 * Descifra un mensaje
 */

/* 
 * File:   ejercicio5.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 10 de noviembre de 2016, 20:02
 */

#include <iostream>
using namespace std;

int main(){
	
	const char CENTINELA = '#';
	const int TAMANIO = 1000;
	char mensaje_cifrado[TAMANIO];
	int total_utilizados=0;
	int contador_descifrados = 0;

	cout << "\nIntroduzca el mensaje cifrado: ";
	mensaje_cifrado[total_utilizados] = cin.get();
	while (mensaje_cifrado[total_utilizados] != CENTINELA){
		total_utilizados++;
		mensaje_cifrado[total_utilizados] = cin.get();
		
	}

	char mensaje_descifrado[total_utilizados];//No necesito mas posiciones

	for(int j=0; j<total_utilizados; j++){
		if(j==0 || mensaje_cifrado[j-1] == ' ' || mensaje_cifrado[j+1] == ' '){
			mensaje_descifrado[contador_descifrados] = mensaje_cifrado[j];
			contador_descifrados++;
		}
	}

	cout << "\nEl mensaje descifrado es: ";
	for(int k=0; k<contador_descifrados; k++)
		cout << mensaje_descifrado[k];
	cout << endl;
}
