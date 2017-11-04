/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 29: Programa que pide por pantalla una serie de temperaturas y devuelve la subsecuencia de esas temperaturas, ordenadas de menor a mayor, de mayor longuitud.*/
#include <iostream>
using namespace std;


int main(){
	//Declaracion de variables
	const double CENTINELA = -1.0, INICIAL = 1;	
	double temperatura, temperatura_anterior, resultado;
	int contador ; //Acumula las temperaturas introducidas
	int inicio, inicio_aux;
	int longuitud, longuitud_aux;
	int resultado_pos_ini, resultado_longuitud;
	bool primero = true, primera_cad = true;
	
	do{
		//Peticiones por pantalla
		cout << "\nIntroduzca el valor de la temperatura: ";
		cin >> temperatura;


			if(primero){//Evito errores en la primera iteracion
				primero = false;
				inicio = INICIAL;		
				inicio_aux = INICIAL;
				longuitud = INICIAL;
				longuitud_aux = INICIAL;
				contador = INICIAL;
				resultado_longuitud = longuitud;
				resultado_pos_ini = inicio;
			}
			else{
				if(temperatura > temperatura_anterior){
					longuitud++;
				}
				else{
					if(!primera_cad){//Ya hay una subcadena guardada
						if(longuitud_aux > longuitud){//La subcadena anterior era mayor
							resultado_longuitud = longuitud_aux;
							resultado_pos_ini = inicio_aux;
						}
						else{//La subcadena actual es mayor
							resultado_longuitud = longuitud;
							resultado_pos_ini = inicio;
						}
					}
					else{//Es la primera subcadena
						resultado_pos_ini = inicio;
						resultado_longuitud = longuitud;
					}
			
					//Guardo valores anteriores
					inicio_aux = inicio;
					longuitud_aux = longuitud;

					//Reinicio
					inicio = contador+INICIAL;
					longuitud = INICIAL;
					primera_cad = false;
				}		

				contador++;
			}
		//Guardo la temperatura para comparar
		temperatura_anterior = temperatura;

	}while(temperatura != CENTINELA);
	

	
	//Muestro resultados por pantalla
	cout << "\nLa primera posicion de la subsecuencia de numeros ordenada de mayor a menor es: " << resultado_pos_ini << endl;
	cout << "\nY la longuitud de la subsecuencia es de: "<< resultado_longuitud << " unidades. " << endl;
}
