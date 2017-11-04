/*EJERCICIO 2: Definir la clase TableroBuscaMinas para implementar una clase que simule el tablero del Buscaminas. 
 * Implementar una funcion para añadir una mina, y otra para comprobar el número de minas que rodean una casilla en concreto.
 * Autor: Mario Antonio López Ruiz ~ 45109755q
 * 1ºD
 */

#include <iostream>
using namespace std;

class TableroBuscaMinas{
	private:
		static const int FILAS = 50, COLUMNAS = 30;
		bool datos[FILAS][COLUMNAS];
		int util_filas, util_columnas;
	public:
		//Constructor por defecto
		TableroBuscaMinas(){
			for(int i = 0; i < FILAS; i++)
				for(int j = 0; j < COLUMNAS; j++)
					datos[i][j] = false;
		}
						
		void MuestraTablero(){
			for(int i = 0; i < FILAS; i++){
				for(int j = 0; j < COLUMNAS; j++)
					cout << datos[i][j] << " ";
				cout << endl;
			}
		
		}

		//Método para incluir una mina en una determinada casilla
		void IncluyeMina(int fila, int columna){
			datos[fila][columna] = true;
		} 

		//Devuelve el número de minas que rodean a la casilla
		int MinasAlrededor(int fila, int columna){
			int num_minas = 0;

			for(int i = fila-1; i <= fila+1; i++){
				for(int j = columna-1; j <= columna+1; j++){
					if( (i >= 0 && i < FILAS) && (j >= 0 && j < COLUMNAS) ){//Si la casilla es válida en el tablero
						if( i != fila || j != columna)
							if(datos[i][j] ==  true)
								num_minas++;
					}
				}
			}
			return num_minas;
		}
};

int main(){
	TableroBuscaMinas tablero;
	int fila, columna, minas_alrededor;

	tablero.MuestraTablero();

	cout << "\nIntroduce la fila y columna en la que quieres depositar una mina: (-1 para acabar)" << endl;
	cout << "\tFila: ";
	cin >> fila;
	cout << "\tColumna: ";
	cin >> columna;
	while(fila != -1 && columna != -1){
		tablero.IncluyeMina(fila, columna);
		cout << "\tFila: ";
		cin >> fila;
		cout << "\tColumna: ";
		cin >> columna;
	}
	
	tablero.MuestraTablero();

	cout << "\nIntroduce una casilla para comprobar cuantas minas tiene alrededor: (-1 para acabar)" << endl;
	cout << "\tFila: ";
	cin >> fila;
	cout << "\tColumna: ";
	cin >> columna;
	while(fila != -1 && columna != -1){
		minas_alrededor = tablero.MinasAlrededor(fila, columna);
		cout << "\nLa casilla " << fila << " " << columna << " tiene " << minas_alrededor << " minas alrededor. " << endl;

		cout << "\tFila: ";
		cin >> fila;
		cout << "\tColumna: ";
		cin >> columna;
	
	}

	cout << "\nFin del programa. " << endl;
	


}
