/*
 * Ejercicio que calcula la sumatoria de factoriales de un numero usando un solo bucle
 */

/* 
 * File:   ejercicio47.cpp
 * Author: Mario Antonio López Ruiz ~ 1ºD
 *
 * Created on 10 de noviembre de 2016, 20:56
 */

#include <iostream>
using namespace std;
        
/*
 * 
 */

int main() {
    //Declaración de variables
    const int POSITIVO = 0;
    int resultado = 0, valor, factorial_ant = 1;
    int i, j;
       
    //Petición por pantalla
    do{
        cout << "\nIntroduzca un valor para calcular la sumatoria: ";
        cin >> valor;
    
    }while(valor < POSITIVO);
    
    //Cálculos
    for(i=1; i<=valor; i++){
        factorial_ant = factorial_ant * i;
        resultado += factorial_ant;
    }
    
    //Muestro resultado por pantalla
    cout << "\nEl resultado de calcular la sumatoria de " << valor << " es: " << resultado << endl;
}

