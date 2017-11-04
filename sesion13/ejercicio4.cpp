/* EJERCICIO4:  Programa que realiza estadísticas sobre datos meteorológicos
 * 
 * Autor: Mario Antonio López Ruiz
 * 1ºD
 */
#include <iostream>
using namespace std;

class Meteo{
	private:
		static const int FILAS = 90;
		static const int COLUMNAS = 3;
		int datos[FILAS][COLUMNAS];
		int amplitudes[FILAS];
		int util_fil;
		int util_col;
		int util_amplitudes;
	public:
		Meteo(){
			util_fil = 0;
			util_col = 0;
			util_amplitudes = 0;
		}

		//Rellena una fila con datos
		void AniadeMedida(int fila, int columna, int dato){
			datos[fila][columna] = dato;
			if(columna == 2)
				util_fil++;
		}
		
		
		//Calcula la amplitud de temperaturas de un dia
		int CalculaAmplitud(int fila){
			int amplitud;
			if(fila <= util_fil)//util_fil = 90
				amplitud = datos[fila][1] - datos[fila][0];//Segunda columna menos la primera
			else
				cout << "\nLa fila introducida no es válida. " << endl;

			return amplitud;
		}

		//rellena el vector de amplitudes
		void CalculaAmplitudes(){
			for(int i = 0; i < FILAS; i++){
				amplitudes[util_amplitudes] = CalculaAmplitud(i);
				util_amplitudes++;
			}

		}

		//Muestra la matriz de datos
		void MuestraMatriz(){
			for(int i = 0; i < FILAS; i++){
				for(int j = 0; j < COLUMNAS; j++){
					cout << datos[i][j] << " ";
				}
				cout << endl;
			}		
		}

		//Muestra el vector de amplitudes
		void MuestraAmplitudes(){
			for(int i = 0; i < util_amplitudes; i++)
				cout << amplitudes[i] << " ";
		}

		//Valor medio mensual de una columna(dato)
		int MediaMensual(int columna, int inicio, int fin){
			int media, suma = 0, i ;

			for(i = inicio; i < fin; i++){
				suma += datos[i][columna];
			}
			media = suma/i;

			return media;
		}

		//Valor medio mensual de amplitud
		int MediaMensualAmplitud(int inicio, int fin){
			int media, suma = 0, i;

			for(i = inicio; i < fin; i++){
				suma += amplitudes[i];
			}
			media = suma/i;

			return media;
		}

		//Valor maximo mensual de una columna(dato)
		int MaxMensual(int columna, int inicio, int fin){
			int maximo = -9999, i=0;

			for(i = inicio; i < fin; i++){
				if(datos[i][columna] > maximo)
					maximo = datos[i][columna];
			}

			return maximo;
		}

		//Valor maximo mensual de una columna(dato)
		int MaxMensualAmplitud(int inicio, int fin){
			int maximo = -9999, i=0;

			for(i = inicio; i < fin; i++){
				if(amplitudes[i] > maximo)
					maximo = amplitudes[i];
			}

			return maximo;
		}

		//Valor minimo mensual de una columna(dato)
		int MinMensual(int columna, int inicio, int fin){
			int minimo = 9999, i=0;

			for(i = inicio; i < fin; i++){
				if(datos[i][columna] < minimo)
					minimo = datos[i][columna];
			}

			return minimo;
		}

		//Valor maximo mensual de una columna(dato)
		int MinMensualAmplitud(int inicio, int fin){
			int min = 9999, i=0;

			for(i = inicio; i < fin; i++){
				if(amplitudes[i] < min)
					min = amplitudes[i];
			}

			return min;
		}
};




int main(){
	Meteo meteo;
	const int COTA1 = 0, COTA2 = 30, COTA3 = 60, COTA4 = 90;
	const int FILAS = 90, COLUMNAS = 3;
	double amplitudes[FILAS], util_amplitud = 0;
	int temperatura7, temperatura13, precipitaciones, amplitud;
	int dato, prueba;

	int valor_medio_temp7_1, valor_medio_temp7_2, valor_medio_temp7_3;
	int valor_medio_temp13_1, valor_medio_temp13_2, valor_medio_temp13_3;
	int valor_medio_prec_1, valor_medio_prec_2, valor_medio_prec_3;
	int valor_medio_ampl_1, valor_medio_ampl_2, valor_medio_ampl_3;

	int max_temp7_1, max_temp7_2, max_temp7_3;
	int max_temp13_1, max_temp13_2, max_temp13_3;
	int max_prec_1, max_prec_2, max_prec_3;
	int max_ampl_1, max_ampl_2, max_ampl_3;

	int min_temp7_1, min_temp7_2, min_temp7_3;
	int min_temp13_1, min_temp13_2, min_temp13_3;
	int min_prec_1, min_prec_2, min_prec_3;
	int min_ampl_1, min_ampl_2, min_ampl_3;
	

	cout << "Introduzca los datos:(temp 07:00, temp 13:00, precipitaciones) ";

	for(int i = 0; i < 90; i++){
		for(int j = 0; j < 3; j++){
			cin >> dato;
			meteo.AniadeMedida(i,j, dato);
		}
		amplitudes[i] = meteo.CalculaAmplitud(i);
		util_amplitud++;
	}
	
	meteo.CalculaAmplitudes();
	//meteo.MuestraAmplitudes();
	//meteo.MuestraMatriz();

	//columna = 0 -> temperatura7 | columna = 1 -> temperatura13 | columna = 2 -> precipitaciones
	//Calculo valores medios mensuales para cada medida
	valor_medio_temp7_1 = meteo.MediaMensual(0,COTA1, COTA2);
	valor_medio_temp7_2 = meteo.MediaMensual(0,COTA2, COTA3);
	valor_medio_temp7_3 = meteo.MediaMensual(0,COTA3, COTA4);
	
	valor_medio_temp13_1 = meteo.MediaMensual(1,COTA1, COTA2);
	valor_medio_temp13_2 = meteo.MediaMensual(1,COTA2, COTA3);
	valor_medio_temp13_3 = meteo.MediaMensual(1,COTA3, COTA4);
	
	valor_medio_prec_1 = meteo.MediaMensual(2,COTA1, COTA2);
	valor_medio_prec_2 = meteo.MediaMensual(2,COTA2, COTA3);
	valor_medio_prec_3 = meteo.MediaMensual(2,COTA3, COTA4);
		
	valor_medio_ampl_1 = meteo.MediaMensualAmplitud(COTA1, COTA2);
	valor_medio_ampl_2 = meteo.MediaMensualAmplitud(COTA2, COTA3);
	valor_medio_ampl_3 = meteo.MediaMensualAmplitud(COTA3, COTA4);

	//Calculo maximos mensuales para cada medida
	max_temp7_1 = meteo.MaxMensual(0,COTA1, COTA2);
	max_temp7_2 = meteo.MaxMensual(0,COTA2, COTA3);
	max_temp7_3 = meteo.MaxMensual(0,COTA3, COTA4);

	max_temp13_1 = meteo.MaxMensual(1,COTA1, COTA2);
	max_temp13_2 = meteo.MaxMensual(1,COTA2, COTA3);
	max_temp13_3 = meteo.MaxMensual(1,COTA3, COTA4);

	max_prec_1 = meteo.MaxMensual(2,COTA1, COTA2);
	max_prec_2 = meteo.MaxMensual(2,COTA2, COTA3);
	max_prec_3 = meteo.MaxMensual(2,COTA3, COTA4);

	max_ampl_1 = meteo.MaxMensualAmplitud(COTA1, COTA2);
	max_ampl_2 = meteo.MaxMensualAmplitud(COTA2, COTA3);
	max_ampl_3 = meteo.MaxMensualAmplitud(COTA3, COTA4);

	//Calculo minimos mensuales para cada medida
	min_temp7_1 = meteo.MinMensual(0,COTA1, COTA2);
	min_temp7_2 = meteo.MinMensual(0,COTA2, COTA3);
	min_temp7_3 = meteo.MinMensual(0,COTA3, COTA4);
		
	min_temp13_1 = meteo.MinMensual(1,COTA1, COTA2);
	min_temp13_2 = meteo.MinMensual(1,COTA2, COTA3);
	min_temp13_3 = meteo.MinMensual(1,COTA3, COTA4);

	min_prec_1 = meteo.MinMensual(2,COTA1, COTA2);
	min_prec_2 = meteo.MinMensual(2,COTA2, COTA3);
	min_prec_3 = meteo.MinMensual(2,COTA3, COTA4);

	min_ampl_1 = meteo.MinMensualAmplitud(COTA1, COTA2);
	min_ampl_2 = meteo.MinMensualAmplitud(COTA2, COTA3);
	min_ampl_3 = meteo.MinMensualAmplitud(COTA3, COTA4);
	

	cout << "\nValores medios de los 3 meses para la temperatura a las 07:00: " << valor_medio_temp7_1 << " " << valor_medio_temp7_1 << " " <<  valor_medio_temp7_1;

	cout << "\nValores medios de los 3 meses para la temperatura a las 13:00: " << valor_medio_temp13_1 << " " << valor_medio_temp7_1 << " " <<  valor_medio_temp7_1;

	cout << "\nValores medios de los 3 meses para las precipitaciones: " << valor_medio_prec_1 << " " << valor_medio_prec_2 << " " <<  valor_medio_prec_3;

	cout << "\nValores medios de la amplitud: " << valor_medio_ampl_1 << " " << valor_medio_ampl_2 << " " <<  valor_medio_ampl_3 << endl;

	cout << "\nValores maximos para la temperatura a las 07:00: " << max_temp7_1 << " " << max_temp7_2 << " " << max_temp7_3;
	cout << "\nValores maximos para la temperatura a las 13:00: " << max_temp13_1 << " " << max_temp13_2 << " " << max_temp13_3;
	cout << "\nValores maximos para las precipitaciones: " << max_prec_1 << " " << max_prec_2 << " " << max_prec_3;
	cout << "\nValores maximos para la amplitud: " << max_ampl_1 << " " << max_ampl_2 << " " << max_ampl_3 << endl;

	cout << "\nValores minimos para la temperatura a las 07:00: " << min_temp7_1 << " " << min_temp7_2 << " " << min_temp7_3;
	cout << "\nValores minimos para la temperatura a las 13:00: " << min_temp13_1 << " " << min_temp13_2 << " " << min_temp13_3;
	cout << "\nValores minimos para las precipitaciones: " << min_prec_1 << " " << min_prec_2 << " " << min_prec_3;
	cout << "\nValores minimos para la amplitud: " << min_ampl_1 << " " << min_ampl_2 << " " << min_ampl_3 << endl;

}
