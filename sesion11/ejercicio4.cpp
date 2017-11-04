/*
 * Calcula la moda de un vector de caracteres.
 */

/* 
 * File:   ejercicio4.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 10 de noviembre de 2016, 19:23
 */

#include <iostream>
#include <fstream>
using namespace std;

struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
};

int main(){
	const int TAMANIO = 25e+5;
	const char CENTINELA = '#';
	FrecuenciaCaracter moda[26];
	char caracteres[TAMANIO];
	int util = 0;
	int aux_posicion;
	int posicion_moda = 0, mayor_moda = 0;
	
	//Inicializo
	for(int i = 0; i < 26; i++){
		moda[i].caracter = i+'A';
		moda[i].frecuencia = 0;
	}

	cout << "\nIntroduzca los caractéres: ";

	caracteres[util] = cin.get();
	while (caracteres[util] != CENTINELA){
		util++;		
		caracteres[util] = cin.get();
	}

	for(int j = 0; j < util; j++){
		if( ( (caracteres[j] >= 'A') && (caracteres[j] <= 'Z') ) || ( (caracteres[j] >= 'a') && (caracteres[j] <= 'z') ) ){ //Ignoro caracteres que no sean letras
			if( ( (caracteres[j] >= 'a') && (caracteres[j] <= 'z') ) )
				caracteres[j] = toupper(caracteres[j]);//Paso a mayúscula

			aux_posicion = caracteres[j] - 'A';		
			moda[aux_posicion].frecuencia++;
		}
	}


	//Veo cual es la mayor moda
	for(int  n = 0; n < 26; n++){

		if(moda[n].frecuencia > mayor_moda){
			mayor_moda = moda[n].frecuencia;
			posicion_moda = n;
		}

	}

	cout << "\nLa moda es: " << moda[posicion_moda].caracter << " y aparece " << moda[posicion_moda].frecuencia << " veces. " << endl;

}
