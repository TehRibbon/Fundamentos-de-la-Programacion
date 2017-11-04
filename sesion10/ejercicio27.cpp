/*
 * Programa que calcula la funcion gaussiana mediante el uso de una clase
 */

/* 
 * File:   ejercicio27.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 30 de noviembre de 2016, 18:48
 */
#include <iostream>
#include <cmath>

using namespace std;

//CONSTANTES
const double PI = 3.1416;
const int POSITIVO = 0;

//Menu principal
void MuestraMenu(){
    cout << "\n1 - Introducir los parámetros de la función. ";
    cout << "\n2 - Salir del programa. " ;

} 

//Menu secundario
void MuestraSegundoMenu(){
    cout << "\n3 - Introducir rango de valores de abscisas. ";
    cout << "\n4 - Volver al menú anterior (menú principal).";
}

//Obtiene parametros para la función gaussiana
void EligeParametrosFuncion(double &esperanza, double &desviacion){
    cout << "\nIntroduce el valor de la esperanza: ";
    cin >> esperanza;
    
    do{
        cout << "\nIntroduce el valor para la desviación típica: ";
        cin >> desviacion;
    }while(desviacion <= POSITIVO); //No contemplo el valor 0
}

//Obtiene los parametros para las abscisas
void IntroduceRangoAbscisas(double &minimo, double &maximo, double &incremento){
    cout << "\nIntroduzca el valor para el minimo: ";
    cin >> minimo;
    
    do{
        cout << "\nIntroduzca el valor para el maximo: ";
        cin >> maximo;
    }while(maximo <= minimo);
    
    do{
        cout << "\nIntroduzca el valor del incremento: ";
        cin >> incremento;
    }while(incremento <= POSITIVO);
    
}

void MuestraResultadoCDF(double cdf, double minimo){
	cout << "\t\tCDF(" << minimo << ")=" << cdf << endl;
}


void MuestraResultadoGauss(double resultado, double minimo){
    cout << "f(" << minimo << ")=" << resultado << endl;
}

double Potencia(double base, double exponente){
	double resultado = 1;
	
	for(int i=1; i<exponente; i++){
		resultado *= base;
	}

	return resultado;
}

int TomaOpcion(){
    int opcion;
    
    cout << "\nIntroduzca su opción -> ";
    cin >> opcion;
    return opcion;
}


//Definicion de la clase
class Gaussiana{
	private:
		double esperanza;
		double desviacion;
		double gaussiana;
	public:
		//Constructor por defecto
		Gaussiana(){
			esperanza = 0;
			desviacion = 0;	
			gaussiana = 0;
		}

		//Constructor con parámetros
		Gaussiana(double esperanzaP, double desviacionP){
			esperanza = esperanzaP;
			desviacion = desviacionP;
			gaussiana = 0;
		}

		//Da un valor a la esperanza
		void SetEsperanza(double valor){
			esperanza = valor;
		}

		//Da un valor a la desviacion
		void SetDesviacion(double valor){
			desviacion = valor;
		}

		//Da un valor a la funcion
		void SetGauss(double valor){
			gaussiana = valor;
		}

		//Devuelve el valor de la esperanza
		double GetEsperanza(){
			return esperanza;
		}

		//Devuelve el valor de la desviacion
		double GetDesviacion(){
			return desviacion;
		}
	
		//Devuelve el valor de la funcion
		double GetGauss(){
			return gaussiana;
		}


		//Calcula el valor de CDF
		double CDF(double minimo){
			const double B0 = 0.2316419, B1 = 0.319381530, B2 = -0.356563782, B3 = 1.781477937, B4 = -1.821255978, B5 = 1.330274429;
			const int UNO = 1, DOS = 2, TRES = 3, CUATRO = 4, CINCO = 5;
			double t , t2, t3, t4, t5;
			double resultado;
			double parentesis;

	
			t = UNO/(UNO+B0*minimo);
			t2 = Potencia(t,DOS);
			t3 = Potencia(t,TRES);
			t4 = Potencia(t,CUATRO);
			t5 = Potencia(t,CINCO);

			parentesis = B1*t + B2*t2 + B3*t3 + B4*t4 + B5*t5;
			resultado = UNO-(gaussiana*parentesis);

			return resultado;
	
		}

		//Calculo de la funcion gaussiana entre dos valores
		void CalculaGaussiana(double minimo, double maximo, double incremento){
			double cdf = 0;
			double division = 0, parentesis = 0;//variables auxiliares
		   
			while(minimo <= maximo){
				division = 1/(desviacion*sqrt(2*PI) );
				parentesis = pow( ( (minimo-esperanza)/desviacion), 2);

				//Calculo la funcion gaussiana con sus partes calculadas previamente
				gaussiana = division * exp(-0.5*parentesis);
				MuestraResultadoGauss(gaussiana, minimo);

				cdf = CDF(minimo);
				MuestraResultadoCDF(cdf,minimo);
		
				minimo = minimo + incremento;

			}

		}


};


int main(){
	//Declaración de variables
	Gaussiana funcion;
	double esperanza, desviacion;
    double minimo, maximo, incremento;
	double valor;//Valor de x introducido por el usuario
	double resultado;
	int opcion;
        bool fin = false;
        
        
        
        do{
            MuestraMenu();
            opcion = TomaOpcion();
            
            switch (opcion){
            case 1:
               EligeParametrosFuncion(esperanza, desviacion); 
			   funcion.SetEsperanza(esperanza);
			   funcion.SetDesviacion(desviacion);
               MuestraSegundoMenu();
               opcion = TomaOpcion();
               if(opcion == 3){
                   IntroduceRangoAbscisas(minimo,maximo,incremento);
                   funcion.CalculaGaussiana(minimo, maximo, incremento);
               }
               break;
            case 2:
                fin = true;
                break;
            case 3:
                IntroduceRangoAbscisas(minimo, maximo, incremento);
                funcion.CalculaGaussiana(minimo, maximo, incremento);
                break;
            case 4:
                MuestraMenu();
                break; 

            }
        }while(fin == false);

	

}

