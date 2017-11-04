/*
 * Encontrar los errores de las funciones planteadas
 */

/* 
 * File:   ejercicio1.cpp
 * Author: Mario Antonio López Ruiz ~ 1ºD
 *
 */

#include <iostream>

using namespace std;

//En el caso de que sa negativo, no se está devolviendo ningún valor
/**int ValorAbsoluto (int entero){
   if (entero < 0)
       entero = -entero;
   else
       return entero;
}**/

int ValorAbsoluto (int entero){
   if (entero < 0)
       entero = -entero;
	return entero;
}

//El tipo de la función es void y se está devolviendo un entero. Deberíamos quitar el return o cambiar el tipo de la función
/**void Cuadrado (int entero) {
   return entero*entero;
}**/
int Cuadrado (int entero) {
   return entero*entero;
}

//Se redefine la variable valor, por lo que se machaca el valor que le pasamos
/**void Imprime(double valor){
    double valor;
    
    cout << valor;
}**/

void Imprime(double valor){
    cout << valor;
}

//En el caso de que sea negativo, no decimos nada
bool EsPositivo(int valor) {
	bool resultado = false;
    if (valor > 0)
        resultado = true;
	return resultado;
}

