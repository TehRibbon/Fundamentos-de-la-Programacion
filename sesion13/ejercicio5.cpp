/*EJERCICIO 5: El juego de la vida

 * Autor: Mario Antonio López Ruiz ~ 45109755q
 */

#include <iostream>
#include <stdlib.h>//para srand
#include <time.h>//Para time()
using namespace std;

class Tablero{
	private:
		static const int FILAS = 20;
		static const int COLUMNAS = 20;
		bool tablero[FILAS][COLUMNAS];
	public:
		//Constructor por defecto
		Tablero(){
			InicializaTablero();
		}

		//Da valores al tablero de forma aleatoria (1 o 0)
		void InicializaTablero(){
			int num;

			srand(time(NULL));

			for(int i=0; i < FILAS; i++){
				for(int j=0; j < COLUMNAS; j++){
					num = rand()%2;//Número aleatorio entre 0 y 1
					tablero[i][j] = num;
				}
			}
		}

		//Incluye una célula en una posicion concreta
		void IncluyeCelula(int fila, int columna){//Set
			if( (fila >= 0 && fila < FILAS) && (columna >= 0 && columna < COLUMNAS))//posicion válida
				tablero[fila][columna] = true;
		}

		//Elimina una célula de una posicion concreta
		void MuereCelula(int fila, int columna){
			if( (fila >= 0 && fila < FILAS) && (columna >= 0 && columna < COLUMNAS))//posicion válida
				tablero[fila][columna] = false;
		
		}

	
		//Devuelve el estado de una casilla
		bool GetCasilla(int fila, int columna){//Get
			return tablero[fila][columna];
		}

		//Devuelve el numero de células vecinas vivas
		int CompruebaAlrededorCasilla(int fila, int columna){
			int contador_ocupadas = 0;

			for(int i = fila-1; i <= fila+1; i++){
				for(int j = columna-1; j <= columna+1; j++){
					if( (i >= 0 && i < FILAS) && (j >= 0 && j < COLUMNAS) ){//Si la casilla se encuentra en un estado válido
						if( (i != fila) || (j != columna) ){//No cuento la casilla en la que estoy
							//cout << "\nDentro en " << i << " " << j;
							//cout << "->" << tablero[i][j];
							if(tablero[i][j] == true){
								contador_ocupadas++;
								//cout << "\nEn la fila y columna: " << i << " " << j << " hay una celula viva. ";
							}
						}
					}
				}
			}
			
			return contador_ocupadas;
		}

		//Avanza a la siguiente generacion
		void SiguienteGeneracion(){
			bool aux[FILAS][COLUMNAS]; //Matriz auxiliar para no machacar datos

			for(int i = 0; i < FILAS; i++)
				for(int j = 0; j < COLUMNAS; j++)
					aux[i][j] = EvolucionaCasilla(i, j);// = EvolucionaCasilla(i,j);

			for(int n = 0; n < FILAS; n++)
				for(int m = 0; m < COLUMNAS; m++)
					tablero[n][m] = aux[n][m];
		}

		//Comprueba si se cumplen las reglas o no
		bool EvolucionaCasilla(int fila, int columna){
			int vivas_vecinas = 0;//Contador de celulas vecinas vivas
			bool casilla_actual, evolucion;//Para guardar si la casilla contiene una célula viva o no(casilla ocupada o vacía)

			evolucion = tablero[fila][columna];//Guardo lo que ya contiene esa casilla

			vivas_vecinas = CompruebaAlrededorCasilla(fila, columna);
			casilla_actual = GetCasilla(fila, columna);

			if(!casilla_actual){//Si está vacía (= casilla_actual == false
				if(vivas_vecinas == 3){
					if( (fila >= 0 && fila < FILAS) && (columna >= 0 && columna < COLUMNAS))
						evolucion = true;
				}
				//En caso contrario sigue vacía
			}else{//Si está ocupada}
				if( (vivas_vecinas != 2) && (vivas_vecinas != 3) ){
					if( (fila >= 0 && fila < FILAS) && (columna >= 0 && columna < COLUMNAS))
						evolucion = false;
				 }
				//Caso contrario siguen vivas
			}
			return evolucion;
		}

		//Función que muestra el tablero
		void MuestraTablero(){
			for(int i=0; i < FILAS; i++){
				cout << "\t\t";
				for(int j=0; j < COLUMNAS; j++){
					cout << tablero[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main(){
	Tablero tablero;
	const int INICIO = 1, FIN = 5;
	cout << "\n¡BIENVENIDO AL JUEGO DE LA VIDA!" << endl;
	cout << "\n\tEn esta demostración, vamos a mostrar los resultados para 5 generaciones. ";
	cout << "\n\tEl tablero inicial es: " << endl;

	tablero.InicializaTablero();
	tablero.MuestraTablero();

	cout << "\nAhora muestro para cada generación siguiente: ";
	
	for(int i = INICIO; i <= FIN; i++){
		cout << "\n\tGeneración " << i << ":" << endl; 
		tablero.SiguienteGeneracion();
		tablero.MuestraTablero();
	}


	cout << "\nFin del juego. " << endl;


}
