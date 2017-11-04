/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 10: Dado un tiempo de entrada(hora, minuto y segundo) calcula la tarifa final a cobrar.
	->Si permanece más de 660 minutos se paga una única tarifa de 31.55 euros
	->Desde el minuto 0 al 30: 0.0412 euros cada minuto
	->Desde el minuto 31 al 90: 0.0370 euros cada minuto
	->Desde el minuto 91 al 120: 0.0311 euros cada minuto
	->Desde el minuto 121 al 660: 0.0305 euros cada minuto

	ERRATA: En el enunciado del problema, en los ejemplos 4, 5, 6, la solución que se muestra como correcta es errónea.
	->Para entrada 2 1 30 2 41 31 el tiempo total es de 40 minutos y la tarifa es 0.0370 --- RESULTADO:40*0.0370 = 1.48 (y no 1.606)
	->Para entrada 2 1 30 3 41 31 el tiempo total es de 100 minutos y la tarifa es 0.0311 --- RESULTADO:100*0.0311 = 3.11 (y no 3.767)
	->Para entrada 2 1 30 5 41 31 el tiempo total es de 220 minutos y la tarifa es 0.0305 --- RESULTADO:220*0.0305 = 6.71 (y no 7.439)
	*/

#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	const double TARIFA_0_30 = 0.0412, TARIFA_31_90 = 0.0370, TARIFA_91_120 = 0.0311, TARIFA_121_660 = 0.0305, TARIFA_660_MAS = 31.55;

	double tarifa = 0, precio_final = 0;
	int hora_ini, minutos_ini, segundos_ini;
	int hora_fin, minutos_fin, segundos_fin;
	int aux_horas = 0, aux_minutos = 0, aux_segundos = 0;
	int resto_segundos = 0;//Contiene la suma total en segundos
	int minutos_totales = 0;
	bool tiempo_negativo = false, dia_completo = false;

	//Peticiones por pantalla
	cout << "\nIntroduzca la hora de entrada: " ;
	cin >> hora_ini;

	cout << "\nIntroduzca los minutos de entrada: " ;
	cin >> minutos_ini;

	cout << "\nIntroduzca los segundos de entrada: " ;
	cin >> segundos_ini;

	cout << "\nIntroduzca la hora de salida: " ;
	cin >> hora_fin;

	cout << "\nIntroduzca los minutos de entrada: " ;
	cin >> minutos_fin;

	cout << "\nIntroduzca los segundos de entrada: " ;
	cin >> segundos_fin;
	
	//Calculo el numero de minutos totales
	aux_horas = (hora_fin - hora_ini)*60;
	aux_minutos = minutos_fin - minutos_ini;
	aux_segundos = (segundos_fin - segundos_ini)/60;

	//Aqui calculo el tiempo en segundos total, para saber si es negativo o no
	minutos_totales = aux_horas + aux_minutos + aux_segundos;
	resto_segundos = ((segundos_fin - segundos_ini)%60) + aux_horas*3600 + aux_minutos*60; 

	cout << "\nResto segundos: " << resto_segundos <<  endl;
	//Compruebo si el tiempo total es negativo
	if( resto_segundos < 0 ) 
		tiempo_negativo = true;	

	//Comprobaciones
	if( minutos_totales >= 0 && !tiempo_negativo ){
		tarifa = TARIFA_0_30;

		if( minutos_totales >= 31) {
			tarifa = TARIFA_31_90;

			if( minutos_totales >= 91){
				tarifa = TARIFA_91_120;

				if( minutos_totales >= 121){
					tarifa = TARIFA_121_660;

					if( minutos_totales > 660){
						dia_completo = true;   //Definimos esta variable ya que siempre va a ser el mismo precio
					}
				}
			}
		}
	}
	
	//Calculo el precio final en función de los minutos pasados en el parking y la tarifa	
	if(!dia_completo)
		precio_final = tarifa*minutos_totales;
	else
		precio_final = TARIFA_660_MAS;


	//Muestro resultados por pantalla
	if(tiempo_negativo){
		precio_final = -1;
		cout << "\nSe ha equivocado al introducir la hora de salida, el tiempo: " << resto_segundos << " en segundos es negativo. : " << precio_final << endl;
			
	}else{
		cout << "\nHa permanecido en el parking un total de: " << minutos_totales << " minutos, al cual le corresponde una precio de: " << precio_final << endl;
		cout << "\nBuen viaje." << endl;
	}


}
