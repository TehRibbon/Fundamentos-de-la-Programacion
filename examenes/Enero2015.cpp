//Programa que sugiere una contraseña formada con una encriptacion basada en el nombre y apellidos introducidos por pantalla
#include <iostream>
#include <stdio.h>
using namespace std;


class SecuenciaCaracteres{
	private:
		static const int TAMANIO = 50;
		char cadena[TAMANIO];		
		int util;
	public:
	
	//Constructor por defecto
	SecuenciaCaracteres(){
		util = 0;
	}

	//Devuelve una posicion concreta
	char GetPosicion(int posicion){
		char resultado;
		if(posicion < util && posicion >= 0)//Posicion valida
			resultado = cadena[posicion];

		return resultado;
	}

	//Cambia una caracter en una posicion concreta
	void SetPosicion(char letra, int posicion){
		if(posicion < util && posicion >= 0)
			cadena[posicion] = letra;
	}

	//Muestra la cadena completa
	void MuestraCadena(){
		for(int i=0; i < util; i++)
			cout << cadena[i];
		cout << endl;
	}

	//Añade un caracter
	void Aniade(char letra){
		if(util < TAMANIO){
			cadena[util] = letra;
			util++;
		}
	}

	void AniadeCadena(string cadena){
		for(int i=0; i < cadena.size(); i++){
			if(util < TAMANIO){
				cadena[util] = cadena.at(i);
				util++;
			}
		}
				
	}

	SecuenciaCaracteres GeneraPassword(int n){
		SecuenciaCaracteres password;
		int numeros = 1, cuenta_letras = 0;
		password.Aniade(numeros);

		for(int i=0; i < util; i++){
			if(cuenta_letras < n){
				cout << cadena[i];
				password.Aniade(cadena[i]);
				cuenta_letras++;
			}

			if(cadena[i] = ' ' && cadena[i+1] != ' '){
				cuenta_letras = 0;
				numeros++;
				password.Aniade(numeros);
				cout << numeros;
			}
		password.MuestraCadena();
		}

		return password;
		
	}
	//Borra la cadena
	void Borrar(){
		util = 0;
	}


};
int main(){
	const int TAMANIO = 50;
	SecuenciaCaracteres nombre, password;
	char dato;
	int entero;

	//Inicialización caracater a caracter
	cout << "\nIntroduzca su nombre y apellidos(finaliza con . ):" << endl;
	dato = getchar();
	while(dato != '.'){
		nombre.Aniade(dato);
		dato = getchar();
	}

	cout << "\nIntroduzca un numero entero: ";
	cin >> entero;
	nombre.MuestraCadena();


	password = nombre.GeneraPassword(entero);
	password.MuestraCadena();

}
