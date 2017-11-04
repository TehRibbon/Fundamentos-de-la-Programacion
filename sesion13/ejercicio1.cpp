/*EJERCICIO 1: El usuario introduce el número de filas para una matriz y todos los datos que va a contener la misma (tiene que ser simétrica). Construir la  matriz suavizada (50 x 30) teniendo en cuenta:
	-La tabla resultante sera simétrica
	-Los valores de la diagonal principal seran iguales a los de la tabla original
	-Los valores del triángulo superior de la tabla se calculan:
		->Si (i, j) es una posición en el triángulo superior de la tabla resultante, su valor es el medio de los valores que ocupan las posiciones de las columnas j, j+1, ..., n-1 en la fila de la tabla original.
 * Autor: Mario Antonio López Ruiz ~ 45109755q
 * 1ºD
 */

#include <iostream>
using namespace std;

int main(){
	double suavizada[50][30], original[50][30];
	double elemento, suma, media;
	int filas, aux_suavizada = 0, aux_triangulo = 0, contador_media=0;
	int i,j;


	cout << "\nIntroduce el numero de filas de la matriz original: ";
	cin >> filas;

	if(filas <= 300){
		cout << "\nAhora vamos a introducir los datos de la matriz:" << endl;
		for(i=0; i < filas; i++){
			for(j=0; j < filas; j++){
				cout << "\tElemento ["<<i<<"][" << j << "]: ";
				cin >> elemento;
				original[i][j] = elemento;
			}
		}
	}else
		cout << "\nLa matriz no puede ser >30. " << endl;

	cout << "\nLa matriz original es : " << endl;
	for(i=0; i < filas; i++){
		cout << "\t";
		for(j=0; j < filas; j++){
			cout << original[i][j] << " ";
		}
		cout << endl;
	}
	for(i=0; i < filas; i++, aux_suavizada++){
		for(j = 0; j < filas; j++){
			if(i==j)
				suavizada[i][j] = original[i][j];//Diagonal principal igual a la original
			else if(j >= aux_suavizada){//Está en el triángulo superior
				aux_triangulo = j;
				while(aux_triangulo < filas){
					suma += original[i][aux_triangulo];
					aux_triangulo++;
					contador_media++;
				}
				media = suma/contador_media;			
				suavizada[i][j] = media;
				media = suma = contador_media = 0;
			}else
				suavizada[i][j] = original[i][j];
				
		}	
	}

	cout << "\nLa matriz resultante es : " << endl;
	for(i=0; i < filas; i++){
		cout << "\t";
		for(j=0; j < filas; j++){
			cout << suavizada[i][j] << "\t";
		}
		cout << endl;
	}
	
}


