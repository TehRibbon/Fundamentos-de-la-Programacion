/*
 * EJERCICIO 3: Calcula el maximo de 3 enteros.
 */

/* 
 * File:   ejercicio3.cpp
 * Author: Mario Antonio López Ruiz ~ 1ºD
 *
 */

#include <iostream>
using namespace std;

//Calcula el máximo de dos valores enteros
int Max(int primero, int segundo){
    int maximo = primero;
    if(segundo > primero)
        maximo = segundo;
    return maximo;
}

int Max3(int primero, int segundo, int tercero){
    int maximo;
    
    //Calculo el maximo de los dos primeros, y despues del resto
    maximo = Max(primero, segundo);
    maximo = Max(maximo, tercero);
    
    return maximo;
    
}

int main(){
    //Declaracion de variables
    int valor1, valor2, valor3;
    int maximo;
    
    //Peticiones por pantalla
    cout << "\nIntroduzca el primer valor: ";
    cin >> valor1;
    
    cout << "\nIntroduzca el segundo valor: ";
    cin >> valor2;
    
    cout << "\nIntroduzca el tercer valor: ";
    cin >> valor3;
    
    //Calculo el maximo
    maximo = Max3(valor1, valor2, valor3);
    
    //Muestro resultado por pantalla
    cout << "\El maximo de " << valor1 << " " << valor2 << " " << valor3 << " es: " << maximo << endl;
    
    

}

