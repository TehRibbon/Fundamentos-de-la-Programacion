/*
 * 
 */

/* 
 * File:   ejercicio15.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 17 de noviembre de 2016, 18:25
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class TarifadorParking{
	private:
		static const int TAMANIO = 50;
		double limite[TAMANIO];
		double tarifas[TAMANIO];
		int util_tramos;
	public:
		//Constructor
		TarifadorParking(){
			for(int i=0; i < TAMANIO; i++){
				limite[TAMANIO] = 0;
				tarifas[TAMANIO] = 0;
			}
			util_tramos = 0;
		}

		void AniadeTramo(double limite_superior_tramo, double tarifa_tramo){
			limite[util_tramos] = limite_superior_tramo;
			tarifas[util_tramos] = tarifa_tramo;
			util_tramos++;
		}


		double GetTarifa(int minutos){//Supongo el tiempo ya filtrado
			double tarifa_a_aplicar, resultado;
			bool limite_superado = false;
			
			for(int i=0; i < util_tramos && !limite_superado; i++){
				if(minutos > limite[i]){
					tarifa_a_aplicar = tarifas[i-1]; //La anterior es la válida
					limite_superado = true;
				}
			}

			resultado = minutos*tarifa_a_aplicar;
			
		}

};

int MinutosEntreInstantes(int hora_ini, int hora_fin, int minutos_ini, int minutos_fin, int segundos_ini, int segundos_fin){
	int minutos_totales;
	int aux_horas, aux_minutos, aux_segundos;

	aux_horas = (hora_fin - hora_ini)*60;
	aux_minutos = minutos_fin - minutos_ini;
	aux_segundos = (segundos_fin - segundos_ini)/60;

	minutos_totales = aux_horas + aux_minutos + aux_segundos;

	return minutos_totales;
}

int main(){
	TarifadorParking parking1, parking2;
	const int CENTINELA = -1, TAMANIO = 50, POSITIVO = 0;
	int limite1[TAMANIO], limite2[TAMANIO];
	double tarifa1[TAMANIO], tarifa2[TAMANIO], dia_completo1, dia_completo2;
	int cont_limit1 = 1, cont_tarif1 = 1, cont_limit2 = 1, cont_tarif2 = 1;//contadores
	int horas_ini, horas_fin, minutos_ini, minutos_fin, segundos_ini, segundos_fin, minutos_totales;
	double resultados_p1, resultados_p2;	
	
	
	//Peticiones para el parking 1 
	do{
		cout << "\nLímite " << cont_limit1 << " del parking 1: ";
		cin >> limite1[cont_limit1-1];
		cont_limit1++;
	}while( (limite1[cont_limit1-1] != CENTINELA) || (limite1[cont_limit1-1] < POSITIVO) );

	do{
		cout << "\nTarifa Tramo " << cont_tarif1 << " del parking 1: ";
		cin >> tarifa1[cont_tarif1-1];
		cont_tarif1++;
	}while( (tarifa1[cont_tarif1-1] != CENTINELA) || (tarifa1[cont_tarif1-1] < POSITIVO) );

	cout << "\nTarifa día completo del parking 1: ";
	cin >> dia_completo1;

	for(int i=0; i < cont_limit1-1; i++){
		parking1.AniadeTramo(limite1[i], tarifa1[i]);
	}

	parking1.AniadeTramo(limite1[cont_limit1-1], dia_completo1);
	//Peticiones para el parking2

	do{
		cout << "\nLímite " << cont_limit2 << " del parking 2: ";
		cin >> limite2[cont_limit2-1];
		cont_limit2++;
	}while( (limite2[cont_limit2-1] != CENTINELA) || (limite2[cont_limit2-1] < POSITIVO) );

	
	do{
		cout << "\nTarifa Tramo " << cont_tarif2 << " del parking 2: ";
		cin >> tarifa2[cont_tarif2-1];
		cont_tarif2++;
	}while( (tarifa2[cont_tarif2-1] != CENTINELA)  (tarifa2[cont_tarif2-1] < POSITIVO) );


	cout << "\nTarifa día completo del parking 1: ";
	cin >> dia_completo2;

	for(int i=0; i < cont_limit2-1; i++){
		parking2.AniadeTramo(limite2[i], tarifa2[i]);
	}

	
	parking1.AniadeTramo(limite2[cont_limit2-1], dia_completo2);


	cout << "\nAhora vamos a introducir las horas de entrada y salida. (-1 para salir: " << endl;

	cin >> horas_ini;
	cin >> horas_fin;
	while( (horas_ini != CENTINELA) && (horas_fin != CENTINELA) ){
		cin >> minutos_ini;
		cin >> minutos_fin;
		cin >> segundos_ini;
		cin >> segundos_fin;
		
		minutos_totales = MinutosEntreInstantes(horas_ini, horas_fin, minutos_ini, minutos_fin, segundos_ini, segundos_fin);
		resultados_p1 = parking1.GetTarifa(minutos_totales);
		resultados_p2 = parking2.GetTarifa(minutos_totales);

		cout << resultados_p1 << " " << resultados_p2;		
		cin >> horas_ini;
		cin >> horas_fin;
	}


















}
