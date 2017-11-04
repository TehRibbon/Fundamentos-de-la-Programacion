/*
 * Elimina un bloque que borre todos los caracteres entre dos posiciones. (VERSIÓN EFICIENTE)
 */

/* 
 * File:   ejercicio13.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 17 de noviembre de 2016, 15:09
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Secuencia de caracteres
class SecuenciaCaracteres{
	private:
	   static const int TAMANIO = 25e+5;
	   char vector_privado[TAMANIO];
	   int total_utilizados;
	   
	   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
		  char intercambia;

		  intercambia = vector_privado[pos_izda];
		  vector_privado[pos_izda] = vector_privado[pos_dcha];
		  vector_privado[pos_dcha] = intercambia;
	   }
	public:
	   SecuenciaCaracteres()
		  :total_utilizados(0) {
	   }


	   int TotalUtilizados(){
		  return total_utilizados;
	   }
	   
	   int Capacidad(){
		  return TAMANIO;
	   }
	   
	   void EliminaTodos(){
		  total_utilizados = 0;
	   }
	   
	   void Aniade(char nuevo){
		  if (total_utilizados < TAMANIO){
		     vector_privado[total_utilizados] = nuevo;
		     total_utilizados++;
		  }
	   }
	   
	   void Modifica(int posicion, char nuevo){
		  if (posicion >= 0 && posicion < total_utilizados)
		     vector_privado[posicion] = nuevo;
	   }

	   char Elemento(int indice){
		  return vector_privado[indice];
	   }
	   
	   string ToString(){
		  // Si el número de caracteres en memoria es muy grande,
		  // es mucho más eficiente reservar memoria previamente
		  // y usar push_back

		  string cadena;

		  cadena.reserve(total_utilizados);

		  for (int i=0; i < total_utilizados; i++)
		     cadena.push_back(vector_privado[i]);
		     //cadena = cadena + vector_privado[i]  <- Evitarlo. Muy ineficiente para tamaños grandes;

		  return cadena;
	   }


		//MÉTODO EJERCICIO
		void EliminaBloque(int izda, int dcha){
			int num_a_borrar;
			int contador = 0;

			num_a_borrar = dcha - izda + 1;
	
			for(int i=dcha+1; i < total_utilizados; i++){
				vector_privado[i-num_a_borrar] = vector_privado[i];		
			}

			total_utilizados = total_utilizados - num_a_borrar;
		}




		void EliminaOcurrencias(char a_borrar){
			//Las posiciones que se vean modificadas van a tener que moverse una sola vez
			int escribir = 0, leer = 0;
			int decremento_total = 0;

			for(int i=0; i < total_utilizados; i++){
				if( i == escribir ){
					if(vector_privado[i] != a_borrar)
						escribir++;
					else
						decremento_total++;
					
				}					
				else{//vector_privado[i] == a_borrar
					if(vector_privado[i] != a_borrar){//Si es el caracter, no hago el cambio				
						vector_privado[escribir] = vector_privado[i];
						escribir++;
					}				
					else
						decremento_total++;
				}
				leer++;
			}
			total_utilizados -= decremento_total; //Actualizo el vector
		}

	   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, char buscado){
		  int i = pos_izda;
		  bool encontrado = false;

		  while (i <= pos_dcha  &&  !encontrado)
		     if (vector_privado[i] == buscado)
		        encontrado = true;
		     else
		        i++;

		  if (encontrado)
		     return i;
		  else
		     return -1;
	   }
	   
	   int PrimeraOcurrencia (char buscado){
		  return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
	   }
	  
	  
	   /////////////////////////////////////////////////////////////
	   // Búsquedas
	   
	   // Precond: 0 <= izda <= dcha < total_utilizados
	   int PosicionMinimoEntre(int izda, int dcha){
		  int posicion_minimo = -1;
		  char minimo;

		  minimo = vector_privado[izda];
		  posicion_minimo = izda;

		  for (int i = izda+1 ; i <= dcha ; i++)
		     if (vector_privado[i] < minimo){
		        minimo = vector_privado[i];
		        posicion_minimo = i;
		     }

		  return posicion_minimo;
	   }
	   
	   int PosicionMinimo(){
		  return PosicionMinimoEntre(0, total_utilizados - 1);
	   }
	   
	   int BusquedaBinaria (char buscado){
		  int izda, dcha, centro;
		  bool encontrado = false;

		  izda = 0;
		  dcha = total_utilizados - 1;
		  centro = (izda + dcha) / 2;

		  while (izda <= dcha  &&  !encontrado){
		     if (vector_privado[centro] == buscado)
		        encontrado = true;
		     else if (buscado < vector_privado[centro])
		        dcha = centro - 1;
		     else
		        izda = centro + 1;

		     centro = (izda + dcha) / 2;
		  }

		  if (encontrado)
		     return centro;
		  else
		     return -1;
	   }
	   
	   
	   /////////////////////////////////////////////////////////////
	   // Recorridos que modifican las componentes
	   
	   // Inserta un valor en la posición especificada
	   void Inserta(int pos_insercion, char valor_nuevo){
		  if (total_utilizados < TAMANIO  &&  pos_insercion >= 0    
		     &&  pos_insercion <= total_utilizados){

		     for (int i = total_utilizados ; i > pos_insercion ; i--)
		        vector_privado[i] = vector_privado[i-1];

		     vector_privado[pos_insercion] = valor_nuevo;
		     total_utilizados++;
		  }
	   }
	   
	   // Elimina una componente, dada por su posición
	   void Elimina (int posicion){
		  if (posicion >= 0 && posicion < total_utilizados){
		     int tope = total_utilizados-1;

		     for (int i = posicion ; i < tope ; i++)
		        vector_privado[i] = vector_privado[i+1];

		     total_utilizados--;
		  }
	   }
	   
	   
	   /////////////////////////////////////////////////////////////
	   // Algoritmos de ordenación
	   
	   void Ordena_por_Seleccion(){
		  int pos_min;

		  for (int izda = 0 ; izda < total_utilizados ; izda++){
		     pos_min = PosicionMinimoEntre(izda, total_utilizados - 1);
		     IntercambiaComponentes_en_Posiciones(izda, pos_min);
		  }
	   }
	   
	   /*
	   void Ordena_por_Insercion(){
		  int izda, i;
		  char a_desplazar;

		  for (izda=1; izda < total_utilizados; izda++){
		     a_desplazar = vector_privado[izda];

		     for (i=izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
		        vector_privado[i] = vector_privado[i-1];

		     vector_privado[i] = a_desplazar;
		  }
	   }
	   
	   // La siguiente versión de Ordena_por_Insercion reutiliza el método 
	   // InsertaOrdenadamente
	   */
	   
	   void InsertaOrdenadamente(char valor_nuevo){
		    int i;

		    if (total_utilizados > TAMANIO){
		       for (i=total_utilizados; i>0 && valor_nuevo < vector_privado[i-1]; i--)
		            vector_privado[i] = vector_privado[i-1];

		       vector_privado[i] = valor_nuevo;
		       total_utilizados++;
		    }
	   }
	   
	   
	   void Ordena_por_Insercion (){
		  for (int izda=1; izda < total_utilizados; izda++)
		     InsertaOrdenadamente(vector_privado[izda]);         
	   }
	   
	   
	   void Ordena_por_Burbuja(){
		  int izda, i;

		  for (izda = 0; izda < total_utilizados; izda++)
		    for (i = total_utilizados-1 ; i > izda ; i--)
		      if (vector_privado[i] < vector_privado[i-1])
		         IntercambiaComponentes_en_Posiciones(i, i-1);
	   }
	   
	   void Ordena_por_BurbujaMejorado(){
		  int izda, i;
		  bool cambio;

		  cambio= true;

		  for (izda=0; izda < total_utilizados && cambio; izda++){
		    cambio=false;

		    for (i=total_utilizados-1 ; i>izda ; i--)
		      if (vector_privado[i] < vector_privado[i-1]){
		         IntercambiaComponentes_en_Posiciones(i, i-1);
		         cambio=true;
		      }
		  }
	   }

};

//FUNCIONES DE LECTURA DE DATOS
int LeeIntMayorIgualQue(int valor, string mensaje){
	int entrada;

	do{
		cout << mensaje;
		cin >> entrada;
	}while(entrada < valor);

	return entrada;
}

int LeeIntRango(int cota_inf, int cota_sup){
	int entrada;
	
	do{
		cout << "\nIntroduzca un valor entre " << cota_inf << " y " << cota_sup << ": ";
		cin >> entrada;
	}while( (entrada < cota_inf) || (entrada > cota_sup) );

	return entrada;
}
int main(){
	const char CENTINELA = '#';
	const int COTA_INFERIOR = 0;
	const string MENSAJE_IZD = "\nIntroduzca un valor para la posición de la izquierda: ";
	
	SecuenciaCaracteres texto;
	
	char entrada;
	int izda, dcha;
	int ultimo;

	cout << "\nIntroduzca los caractéres (# para acabar): ";
		
	entrada = cin.get();
	while (entrada != CENTINELA){
		texto.Aniade(entrada);
		entrada = cin.get();
	}
	
	ultimo = texto.TotalUtilizados();

	//Lecturas por pantalla
	izda = LeeIntMayorIgualQue(COTA_INFERIOR, MENSAJE_IZD);
	dcha = LeeIntRango(izda, ultimo);

	texto.EliminaBloque(izda, dcha);
	
	cout << "\nEl texto resultante es: " << texto.ToString() << endl;


}

