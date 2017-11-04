//Examen Parcial 2 (a) 2012

#include <iostream>
//#include <stdio.h>
using namespace std;

struct Letra{
	char letra;
	int apariciones;
};
class Frecuencias{
	private:
		static const int TAMANIO = 26;
		Letra letras[TAMANIO]; //Vector ordenado alfabéticamente con las letras introducidas únicamente
		int util_letras;
	public:
		//Constructor por defecto
		Frecuencias() {
			util_letras = 0;
		}

		//Devuelve las apariciones de un caracter concreto
		int GetApariciones(char caracter){
			int apariciones;
			

			//posicion = caracter - 'A';

			//Búsqueda secuencial
			for(int i=0; i<util_letras; i++){
				if(letras[i].letra == caracter)
					apariciones = letras[i].apariciones;
			}

			return apariciones;
		}

		int BuscaLetra(char letra){
			int posicion = -1;
			
			for(int i=0; i < util_letras; i++){
				if(letras[i].letra == letra)
					posicion = i;
			}

			return posicion;
		}

		void AniadeOrdenado(char letra){
			int posicion_existe = BuscaLetra(letra), aux_pos = 0;
			bool fin = false, desplaza = true;

			if(posicion_existe != -1)
				letras[posicion_existe].apariciones++;
			else{//Primera vez que se introduce la letra
				Letra nueva;
	
				nueva.letra = letra;
				nueva.apariciones = 1;

				for(int i=0; i < util_letras && !fin; i++){
					if(letra < letras[i].letra){
						aux_pos = i;
						fin = true;
					}
					else if(letra > letras[i].letra){
						aux_pos++;
						desplaza = true;
					}
				}

				//cout << "\nPosicion-> " <<  aux_pos << endl;
				if(util_letras > aux_pos && desplaza){
					for(int i = util_letras; i > aux_pos; i--){
						//cout << "\nUtil -> " << util_letras << " pos: " << i;					
						letras[i] = letras[i-1];
					}
					desplaza = false;
				}
				letras[aux_pos] = nueva;
				util_letras++;
			}
		}

		void MuestraLetras(){
			for(int i=0; i < util_letras; i++){
				cout << letras[i].letra << ": " << letras[i].apariciones << " ";
			}
			cout << endl;
		}
};



int main(){
	Frecuencias frecuencia;
	char entrada;

	cout << "\nComience a introducir el texto('.' para finalizar): " << endl;
	cin >> entrada;
	while(entrada != '.'){

		entrada = toupper(entrada);
		if( (entrada >= 'A') && (entrada <= 'Z') )
			frecuencia.AniadeOrdenado(entrada);
			//frecuencia.MuestraLetras();
		cin >> entrada;
	}

	cout << "\nResultado: ";
	frecuencia.MuestraLetras();
	

}
