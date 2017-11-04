#include <iostream>
using namespace std;


class Jugador{
	private:
		int dorsal;
		int tiros_libres, tiros_dobles, tiros_triples;
	public:
		//Constructor sin parametros
		Jugador(){
			dorsal = -1;
			tiros_libres = tiros_dobles = tiros_triples = 0;
		}

		//Constructor pasandole el dorsal como parámetro
		Jugador(int _dorsal){
			dorsal = _dorsal;
			tiros_libres = tiros_dobles = tiros_triples = 0;
		}

		//Devuelve la puntuacion total del jugador
		int PuntuacionTotal(){
			return tiros_libres+tiros_dobles*2+tiros_triples*3;
		}

		//Asigna el dorsal
		void SetDorsal(int numero){
			dorsal = numero;	
		}

		//Devuelve el dorsal
		int GetDorsal(){
			return dorsal;	
		}

		//Devuelve tiros 
		int GetLibres(){
			return tiros_libres;	
		}

		int GetDobles(){
			return tiros_dobles;	
		}

		int GetTriples(){
			return tiros_triples;	
		}

		void SumaLibres(int n){
			tiros_libres += n;	
		}

		void SumaDobles(int n){
			tiros_dobles += n;	
		}

		void SumaTriples(int n){
			tiros_triples += n;	
		}
};

int main(){
	const int TAMANIO = 15;
	Jugador jugadores[TAMANIO];
	int dorsal, jugadores_introducidos = 0;;
	int libres, dobles, triples;
	double total_libres = 0, puntuacion_total = 0, dorsal_maximo, puntos_maximo = -1, jugadores_encima = 0;
	double media_libres, media_total;
	

	//for(int i=1; i <= TAMANIO; i++)
	//	jugadores[i].SetDorsal(i);


	cout << "\nIntroduzca el dorsal: ";
	cin >> dorsal;
	while(dorsal != -1){
		jugadores[jugadores_introducidos].SetDorsal(dorsal);
		cout << "\nTiros libres: ";
		cin >> libres;

		cout << "\nTiros dobles: ";
		cin >> dobles;

		cout << "\nTiros triples: ";
		cin >> triples;


		jugadores[jugadores_introducidos].SumaLibres(libres);
		jugadores[jugadores_introducidos].SumaDobles(dobles);
		jugadores[jugadores_introducidos].SumaTriples(triples);

		jugadores_introducidos++;

		cout << "\nIntroduzca el dorsal: ";
		cin >> dorsal;
	}

	for(int i=0; i<=jugadores_introducidos; i++){
		total_libres += jugadores[i].GetLibres();
		puntuacion_total += jugadores[i].PuntuacionTotal();
		if(jugadores[i].PuntuacionTotal() > puntos_maximo){
			puntos_maximo = jugadores[i].PuntuacionTotal();
			dorsal_maximo = jugadores[i].GetDorsal();
		}
	}


	media_libres = total_libres/jugadores_introducidos;
	media_total = puntuacion_total/jugadores_introducidos;


	for(int i=0; i<= jugadores_introducidos; i++){
		if(jugadores[i].PuntuacionTotal() > media_total)
			jugadores_encima++;
	}
	cout << "\nPuntuación total del equipo: " << puntuacion_total << endl;
	cout << "\nMedia en tiros libres: " << media_libres << endl;
	cout << "\nMedia en anotación total: " << media_total << endl;
	cout << "\nMáximo anotador: " << dorsal_maximo << " con " << puntos_maximo << endl;
	cout << "\nNúmero de jugadores por encima de la media: " << jugadores_encima << endl;








}
