/*Autor: Mario Antonio López Ruiz   ~  1ºD1*/
/*EJERCICIO 23: Usando el ejercicio de la población(12) pide al usuario que introduzca un nº de años. El programa filtra todos los valores
 * introducidos por el usuario.
 * El programa calcula también  el nº de años que tienen que pasar hasta que como mínimo se doble la población inicial.*/
#include <iostream>
using namespace std;

int main(){
	//Declaracion de variables
	const string ERROR_ENTRADA_POSITIVO = "\nValor erróneo, el dato debe ser positivo.";
	const string ERROR_ENTRADA_INTERVALO = "\nValor erróneo, el dato debe estar entre 0 y 1000.";
	const int COTA_INFERIOR = 0, COTA_SUPERIOR = 1000, DEN_TASA = 1000;
	long long int poblacion_inicial, poblacion_resultado, aux_poblacion, doble_poblacion, poblacion_resultado_doble;
	int tasa_natalidad, tasa_mortalidad, tasa_migracion;
	int aux_natalidad, aux_mortalidad, aux_migracion;//Aqui guardaremos la poblacion tras aplicar las tasas
	int num_anios;
	int contador = 0, contador_anios = 0;
	bool error;
	//bool entre_0_y_1000; <- Para el caso con 1 bucle
	
	//Peticiones por pantalla
	do{
		cout << "\nIntroduzca el valor para la población inicial: ";
		cin >> poblacion_inicial;

		error = poblacion_inicial < COTA_INFERIOR;
		if(error)
			cout << ERROR_ENTRADA_POSITIVO;
	}while(error);

	do{
		cout << "\nIntroduzca el valor para la tasa de natalidad: ";
		cin >> tasa_natalidad;

		error = (tasa_natalidad < COTA_INFERIOR) || (tasa_natalidad > COTA_SUPERIOR);
		if(error)
			cout << ERROR_ENTRADA_INTERVALO;
	}while(error);
	
	do{
		cout << "\nIntroduzca el valor para la tasa de mortalidad: ";
		cin >> tasa_mortalidad;

		error = (tasa_mortalidad < COTA_INFERIOR) || (tasa_mortalidad > COTA_SUPERIOR);
		if(error)
			cout << ERROR_ENTRADA_INTERVALO;
	}while(error);

	do{
		cout << "\nIntroduzca el valor para la tasa de migracion: ";
		cin >> tasa_migracion;

		error = (tasa_migracion < COTA_INFERIOR) || (tasa_migracion > COTA_SUPERIOR);
		if(error)
			cout << ERROR_ENTRADA_INTERVALO;
	}while(error);

	do{
		cout << "\nIntroduzca el número de años: " ;
		cin >> num_anios;

		error = num_anios < COTA_INFERIOR;
		if(error)
			cout << ERROR_ENTRADA_POSITIVO;
	}while(error);

	//Hay que tener en cuenta que la tasa es una razón total por cada mil (x por cada 1000 habitantes)
	//Calculamos las tasas teniendo en cuenta que la tasa es una razón total por cada mil (x por cada mil habitantes)
	aux_poblacion = poblacion_inicial;	//Para poder operar sobre la poblacion modificada

	while(contador < num_anios){

		aux_natalidad = (tasa_natalidad * aux_poblacion) / DEN_TASA;
		aux_mortalidad = (tasa_mortalidad * aux_poblacion) / DEN_TASA;
		aux_migracion = (tasa_migracion * aux_poblacion) / DEN_TASA;

		cout << " -> " << aux_natalidad << "  " << aux_mortalidad << " " << aux_migracion << endl;

		cout << "Poblacion: " << aux_poblacion << endl;

		poblacion_resultado = aux_poblacion + aux_natalidad - aux_mortalidad + aux_migracion; //Aplico los cambios en la poblacion
		aux_poblacion = poblacion_resultado; //Para aplicarlo sobre la poblacion cambiada
		cout << "Poblacion resultado: " << poblacion_resultado << endl;
		contador++;

	}


	//Ahora calculo el numero de años hasta que se dobla la poblacion
	doble_poblacion = poblacion_inicial * 2;
	aux_poblacion = poblacion_inicial;	

	while(poblacion_resultado_doble < doble_poblacion){

		aux_natalidad = (tasa_natalidad * aux_poblacion) / DEN_TASA;
		aux_mortalidad = (tasa_mortalidad * aux_poblacion) / DEN_TASA;
		aux_migracion = (tasa_migracion * aux_poblacion) / DEN_TASA;

		//Incrementos
		poblacion_resultado_doble = aux_poblacion + aux_natalidad - aux_mortalidad + aux_migracion; //Aplico los cambios en la poblacion
		aux_poblacion = poblacion_resultado_doble; //Para aplicarlo sobre la poblacion cambiada
		contador_anios++;

	}

	



	//Muestro el resultado por pantalla
	cout << "\nNúmero de habitantes pasados " << num_anios << " años: " << poblacion_resultado << endl;
	cout << "\nAños que han pasado hasta doblar la población: " << contador_anios << endl;
	cout << "\nPoblación transcurridos " << contador_anios << " años: " << poblacion_resultado_doble << endl;
	
	}
