/*
 * EJERCICIO 48: Calcula la función gaussiana mostrando un menú con opciones
 */

/* 
 * File:   ejercicio48.cpp
 * Author: Mario Antonio López Ruiz ~ 1ºD
 *
 * Created on 10 de noviembre de 2016, 22:15
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

void MuestraResultado(double resultado, double minimo){
    cout << "\nEl resultado de calcular la funcion gaussiana para el valor " << minimo << " es: " << resultado << endl;
}

//Calculo de la funcion gaussiana
double CalculaGaussiana(double esperanza, double desviacion, double minimo, double maximo, double incremento){
    double gaussiana = 0;
    double division = 0, parentesis = 0;//variables auxiliares
   
    while(minimo <= maximo){
        division = 1/(desviacion*sqrt(2*PI) );
        parentesis = pow( ( (minimo-esperanza)/desviacion), 2);

        //Calculo la funcion gaussiana con sus partes calculadas previamente
        gaussiana = division * exp(-0.5*parentesis);
        MuestraResultado(gaussiana, minimo);
        minimo = minimo + incremento;
    }
    
    return gaussiana;
}

int TomaOpcion(){
    int opcion;
    
    cout << "\nIntroduzca su opción -> ";
    cin >> opcion;
    return opcion;
}

int main(){
	//Declaración de variables
	double esperanza, desviacion, gaussiana;
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
               MuestraSegundoMenu();
               opcion = TomaOpcion();
               if(opcion == 3){
                   IntroduceRangoAbscisas(minimo,maximo,incremento);
                   CalculaGaussiana(esperanza, desviacion, minimo, maximo, incremento);
                }
               break;
            case 2:
                fin = true;
                break;
            case 3:
                IntroduceRangoAbscisas(minimo, maximo, incremento);
                CalculaGaussiana(esperanza, desviacion, minimo, maximo, incremento);
                break;
            case 4:
                MuestraMenu();
                break; 

            }
        }while(fin == false);

	

}
