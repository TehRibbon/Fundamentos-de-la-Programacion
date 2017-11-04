/*
 * Programa que trabaja con una circunferencia
 */

/* 
 * File:   ejercicio48.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 30 de noviembre de 2016, 18:48
 */
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
const double PI = 3.1416;

//Representa un par de valores reales
struct CoordenadasPunto2D{
	double A;
	double B;
};

class Circunferencia{
	private:
		CoordenadasPunto2D centro;
		double radio;

	public:
		//Constructor por defecto
		Circunferencia(){
			centro.A = 0;
			centro.B = 0;
			radio = 0;
		}
	
		//Constructor por parametros
		Circunferencia(CoordenadasPunto2D punto, double un_radio){
			centro = punto;
			radio = un_radio;
		};

		//Devuelve la longuitud de la circunferencia
		double Longuitud(){
			double longuitud;

			longuitud = 2*PI*radio;

			return longuitud;
		}

		//Devueve el área del circulo
		double Area(){
			double area;

			area = PI * (radio * radio);

			return area;
		}
		
		//Verifica si contiene a un punto cualquiera
		bool CompruebaPunto(CoordenadasPunto2D punto){
			bool esta_dentro = false;
			double desigualdad1, desigualdad2;

			desigualdad1 = (centro.A - punto.A)*(centro.A - punto.A) + (centro.B - punto.B)*(centro.B - punto.B);

			desigualdad2 = radio*radio;

			if(desigualdad1 <= desigualdad2)
				esta_dentro = true;		

			return esta_dentro;
		}
};

//Muestra un mensaje
void MuestraMensaje(string mensaje){
	cout << mensaje << endl;
}

//Funcion para mostrar un dato de tipo entero
double IntroduceDouble(string mensaje){
	double valor;
	cout << mensaje;
	cin >> valor;
	
	return valor;
}

//Funcion para tomar un dato tipo caracter
char IntroduceChar(string mensaje){
	char valor;
	cout << mensaje;
	cin >> valor;
	
	return valor;
}

//main
int main(){
	//Declaración de variables
	double coordX1, coordY1;
	double longuitud, area, radio;
	
	const char FIN = 'n', CONTINUA = 's';
	char opcion;
	bool esta_dentro;
	string MSGX1, MSGY1, MSGPUNTO, MSGRADIO, MSGOTRO, MSGCONTINUA, MSGFIN, MSGBON, MSGPUNTO_COMPROBAR;
	CoordenadasPunto2D punto, punto_comprobar;
	
	MSGPUNTO = "\nVamos a introducir los valores para el centro de la circunferencia.";
	MSGPUNTO_COMPROBAR = "\nIntroduzca los datos para comprobar si el punto esta en la circunferencia.";
	MSGRADIO = "\nIntroduzca el valor del radio. ";
	MSGX1 = "\n\tIntroduzca el valor para la coordenada x: ";
	MSGY1 = "\n\tIntroduzca el valor para la coordenada y: ";
	MSGOTRO = "\n¿Desea introducir datos para otra circunferencia? (n/s)";
	MSGCONTINUA = "\nHa seleccionado introducir mas datos.";
	MSGBON = "\n*********************************************************";
	MSGFIN = "\nFin del programa.";

	do{
		//Peticiones por pantalla
		//Primer punto
		MuestraMensaje(MSGPUNTO);
		punto.A = IntroduceDouble(MSGX1);
		punto.B = IntroduceDouble(MSGY1);

		MuestraMensaje(MSGPUNTO_COMPROBAR);
		punto_comprobar.A = IntroduceDouble(MSGX1);
		punto_comprobar.B = IntroduceDouble(MSGY1);

		//radio
		radio = IntroduceDouble(MSGRADIO);

		//Creo el objeto
		Circunferencia circunferencia(punto, radio);

		longuitud = circunferencia.Longuitud();
		area = circunferencia.Area();

		esta_dentro = circunferencia.CompruebaPunto(punto_comprobar);

		//Resultado
		cout << "\nLa longuitud de la circunferencia es: " <<  longuitud << endl;
		cout << "\nEl área del círculo es: " << area << endl;

		if(esta_dentro)
			cout << "\nEl punto introducido está dentro de la circunferencia.";
		else
			cout << "\nEl punto no está introducido en la circunferencia.";

		//Opcion
		opcion = IntroduceChar(MSGOTRO);

		if(opcion == FIN){
			cout << MSGBON << endl;
			cout << MSGFIN << endl;
		}else if(opcion == CONTINUA){
			cout << MSGCONTINUA << endl;
			cout << MSGBON << endl;
		}

	}while(opcion != FIN);
	
}
