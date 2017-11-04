/*
 * Programa que calcula la distancia euclidea entre dos puntos cualesquiera
 */

/* 
 * File:   ejercicio47.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 30 de noviembre de 2016, 18:48
 */
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Representa un par de valores reales
struct CoordenadasPunto2D{
	double A;
	double B;
};

//Calcula la distancia euclidea entre dos puntos
double DistanciaEuclidea(CoordenadasPunto2D un_punto, CoordenadasPunto2D otro_punto){
	double coordX1, coordY1, coordX2, coordY2;
	CoordenadasPunto2D puntoA, puntoB;
	double distancia_resultado = 0;	
	double primer_parentesis, segundo_parentesis;

	coordX1 = un_punto.A;
	coordY1 = un_punto.B;
	coordX2 = otro_punto.A;
	coordY2 = otro_punto.B;

	primer_parentesis = pow(coordX2 - coordX1, 2);
	segundo_parentesis = pow(coordY2 - coordY1, 2);

	distancia_resultado = sqrt(primer_parentesis + segundo_parentesis);
	return distancia_resultado;
}

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
	double coordX1, coordX2, coordY1, coordY2;
	double distancia;		
	
	const char FIN = 'n', CONTINUA = 's';
	char opcion;
	string MSGX1, MSGY1, MSGPUNTO, MSGOTRO_PUNTO, MSGOTRO, MSGCONTINUA, MSGFIN, MSGBON;
	
	MSGPUNTO = "\nVamos a introducir los valores para un punto";
	MSGOTRO_PUNTO = "\nAhora los valores para otro punto. ";
	MSGX1 = "\n\tIntroduzca el valor para la coordenada x: ";
	MSGY1 = "\n\tIntroduzca el valor para la coordenada y: ";
	MSGOTRO = "\n¿Desea calcular la distancia Euclidea de otros dos valores? (s para continuar, n para finalizar): ";
	MSGCONTINUA = "\nHa seleccionado calcular otra distancia Euclidea.";
	MSGBON = "\n*********************************************************";
	MSGFIN = "\nFin del programa.";

	CoordenadasPunto2D un_punto;
	CoordenadasPunto2D otro_punto;
	do{
		//Peticiones por pantalla
		//Primer punto
		MuestraMensaje(MSGPUNTO);
		un_punto.A = IntroduceDouble(MSGX1);
		//coordX1 = IntroduceDouble(MSGX1);
		un_punto.B = IntroduceDouble(MSGY1);

		//Segundo punto
		MuestraMensaje(MSGOTRO_PUNTO);
		otro_punto.A = IntroduceDouble(MSGX1);
		otro_punto.B = IntroduceDouble(MSGY1);

		//Calculo la distancia euclidea
		distancia = DistanciaEuclidea(un_punto, otro_punto);

		//Resultado
		cout << "\nLa distancia Euclídea es: " << distancia << endl;
		
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
