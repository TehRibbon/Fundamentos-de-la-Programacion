#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

double FiltroEntero(string mensaje){
	int dato;
	const int COTA_INF = 0, COTA_SUP = 100;	

	do{
		cout << mensaje;
		cin >> dato;
	}while( (dato < COTA_INF) || (dato > COTA_SUP) );

	return dato;
}

char FiltroZona(string mensaje){
	char dato;
	const char COTA_INF = 'A', COTA_SUP = 'Z';	

	do{
		cout << mensaje;
		cin >> dato;
		dato = toupper(dato);
	}while( ( (dato < COTA_INF) || (dato > COTA_SUP) ) && dato != '@');

	return dato;
}

int main(){
	const string MSJ_TMP = "\nIntroduzca la temperatura: ", MSJ_HUM = "\nIntroduzca la humedad: ", MSJ_ZONA = "\nIntroduzca la zona(@ para finalizar): ";
	char zona, zona_elegida;
	double humedad, temperatura;
	double tmp_alta = -1, hum_baja = 200;

	zona = FiltroZona(MSJ_ZONA);
	while(zona != '@'){
		temperatura = FiltroEntero(MSJ_TMP);
		humedad = FiltroEntero(MSJ_HUM);
		
		if(temperatura >= tmp_alta && humedad <= hum_baja){
			tmp_alta = temperatura;
			hum_baja = humedad;
			zona_elegida = zona;
		}

		zona = FiltroZona(MSJ_ZONA);
	} 
	
	cout << "\nZona del planeta que tiene la tª más alta y la humedad más baja: ";
	cout << "\n\tZONA: " << zona_elegida << endl;
	cout << "\n\tTEMPERATURA: " << tmp_alta << endl;
	cout << "\n\tHUMEDAD: " << hum_baja << endl;




}
