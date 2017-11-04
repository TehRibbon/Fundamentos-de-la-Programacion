/*
 * Resolver el ejercicio de la Poblacion con una clase
 */

/* 
 * File:   ejercicio28.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 30 de noviembre de 2016, 18:48
 */
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Función que lee un valor dentro del rango definido

long long LeeIntRango(const int COTA_INFERIOR, const int COTA_SUPERIOR, string mensaje){
	long long entrada;

	do{
		cout << "\nIntroduzca el valor para la " << mensaje ;
		cin >> entrada;
	}while(entrada < COTA_INFERIOR || entrada > COTA_SUPERIOR);

	return entrada;	
}

int LeeIntMayorIgualQue(const int VALOR){
	int entrada;

	do{
		cout << "\nIntroduzca el valor para el numero de años: ";
		cin >> entrada;
	}while(entrada < VALOR);

	return entrada;
}

class Poblacion{
	private:
		int tasa_natalidad;
		int tasa_mortalidad;
		int tasa_migracion;
		long long poblacion;
	public:

		//Constructor por defecto
		Poblacion(){
			tasa_natalidad = tasa_mortalidad = tasa_migracion = 1;
			poblacion = 0;
		}

		//Constructor por parámetros
		Poblacion(int tasaNat, int tasaMort, int tasaMigr, int poblacion){
			tasa_natalidad = tasaNat;
			tasa_mortalidad = tasaMort;
			tasa_migracion = tasaMigr;
			this->poblacion = poblacion;
		}

		//Da un valor a la poblacion
		void SetPoblacion(long long valor){
			poblacion = valor;
		}

		//Calcula los habitantes tras un numero de años al aplicar las tasas
		long long int HabitantesTrasAnios(int num_anios){
			const int DEN_TASA = 1000;		
			int contador = 0;
			long long int poblacion_resultado;
			long long int aux_natalidad, aux_mortalidad, aux_migracion;
			long long int aux_poblacion = poblacion;

			while(contador < num_anios){
				//Calculo las tasas con la nueva poblacion
				aux_natalidad = (tasa_natalidad * aux_poblacion) / DEN_TASA;
				aux_mortalidad = (tasa_mortalidad * aux_poblacion) / DEN_TASA;
				aux_migracion = (tasa_migracion * aux_poblacion) / DEN_TASA;

				poblacion_resultado = aux_poblacion + aux_natalidad - aux_mortalidad + aux_migracion; //Aplico los cambios en la poblacion
				aux_poblacion = poblacion_resultado; //Para aplicarlo sobre la poblacion cambiada
				contador++;

			}

			return poblacion_resultado;
		}


		//Calcula el numero de años hasta doblar la poblacion
		int AniosDoblarPoblacion(long long &poblacion_resultado_doble){
			const int DEN_TASA = 1000;	
			long long aux_poblacion = poblacion, doble_poblacion = poblacion * 2;
			int aux_natalidad, aux_mortalidad, aux_migracion;
			int contador_anios = 0;

			while(poblacion_resultado_doble < doble_poblacion){
				//Calculo las tasas con la nueva población
				aux_natalidad = (tasa_natalidad * aux_poblacion) / DEN_TASA;
				aux_mortalidad = (tasa_mortalidad * aux_poblacion) / DEN_TASA;
				aux_migracion = (tasa_migracion * aux_poblacion) / DEN_TASA;

				//Incrementos
				poblacion_resultado_doble = aux_poblacion + aux_natalidad - aux_mortalidad + aux_migracion; //Aplico los cambios en la poblacion
				aux_poblacion = poblacion_resultado_doble; //Para aplicarlo sobre la poblacion cambiada
				contador_anios++;

			}

			return contador_anios;
		}
};


int main(){
	//Declaracion de variables
	const int COTA_INFERIOR = 0, COTA_SUPERIOR = 1000;
	long long poblacion_inicial, poblacion_resultado = 0, aux_poblacion, doble_poblacion, poblacion_resultado_doble;
	int tasa_natalidad, tasa_mortalidad, tasa_migracion;
	int num_anios;
	int contador_anios = 0;
	string poblacion_inicialS, tasa_natalidadS, tasa_mortalidadS, tasa_migracionS, numero_aniosS;



	//Mensajes para las peticiones por pantalla
	poblacion_inicialS = "poblacion inicial: ";
	tasa_natalidadS = "tasa de natalidad: ";
	tasa_mortalidadS = "tasa de mortalidad: ";
	tasa_migracionS = "tasa de migracion: ";
	//numero_anios = "numero de años: ";


	//Peticiones por pantalla	
	poblacion_inicial = LeeIntMayorIgualQue(COTA_INFERIOR);
	tasa_natalidad = LeeIntRango(COTA_INFERIOR, COTA_SUPERIOR, tasa_natalidadS);
	tasa_mortalidad = LeeIntRango(COTA_INFERIOR, COTA_SUPERIOR, tasa_mortalidadS);
	tasa_migracion = LeeIntRango(COTA_INFERIOR, COTA_SUPERIOR, tasa_migracionS);
	num_anios = LeeIntMayorIgualQue(COTA_INFERIOR);

	//Creo el objeto
	Poblacion poblacion(tasa_natalidad, tasa_mortalidad, tasa_migracion, poblacion_inicial);

	//Calculamos las tasas teniendo en cuenta que la tasa es una razón total por cada mil (x por cada 1000 habitantes)

	//Para poder operar sobre la poblacion modificada
	poblacion_resultado = poblacion.HabitantesTrasAnios(num_anios);

	//Ahora calculo el numero de años hasta que se dobla la poblacion	
	contador_anios = poblacion.AniosDoblarPoblacion(poblacion_resultado_doble);

	//Muestro el resultado por pantalla
	cout << "\nNúmero de habitantes pasados " << num_anios << " años: " << poblacion_resultado << endl;
	cout << "\nAños que han pasado hasta doblar la población: " << contador_anios << endl;
	cout << "\nPoblación transcurridos " << contador_anios << " años: " << poblacion_resultado_doble << endl;
	
	}
