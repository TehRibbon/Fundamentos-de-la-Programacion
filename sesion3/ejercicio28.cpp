/*EJERCICIO 28: Para los ejemplos mostrados, indicar si se produce desbordamiento o no, e indicar el resultado final
de cada operacion*/

#include <iostream>
using namespace std;

int main(){
	//Como ayuda para este ejercicio voy a escribir el tamaño de cada tipo de dato usado : 
	//int = 32 bits, long = 32 bits, double = 64 bits, float = 32 bits
	//Los casos en los que SI se produce desbordamiento es porque se usan mas bits de los que se disponen
	
	//Declaracion de variables
	//a)
	int chico, chico1, chico2;
	chico1 = 1234567;
	chico2 = 1234567;
	chico = chico1 * chico2;
	//SOLUCIÓN: Si produce desbordamiento, el resultado mostrado es -557712591
	
	//b)
	long grande;
	int chico1, chico2;
	chico1 = 1234567;
	chico2 = 1234567;
	grande = chico1 * chico2;
	//SOLUCIÓN: Si produce desbordamiento, el resultado mostrado es -557712591
	
	//c)
	double real, real1, real2;
	real1 = 123.1;
	real2 = 124.2;
	real = real1 * real2;
	//SOLUCIÓN: No produce desbordamiento, el resultado mostrado es: 15289.02, el cual es correcto
	
	//d)
	double real, real1, real2;
	real1 = 123456789.1;
	real2 = 123456789.2;
	resultado = real1 * real2;
	//SOLUCIÓN: No produce desbordamiento, el resultado es: 15241578787227558, el cual es correcto
	
	//e)
	double real, otro_real;
	real = 2e34;
	otro_real = real + 1;
	otro_real = otro_real - real;
	//SOLUCIÓN: Si se produce desbordamiento, da como resultado 0, el cual no tiene sentido
	
	//f)
	double real, otro_real;
	real = 1e+300;
	otro_real = 1e+200;
	otro_real = otro_real * real;
	//SOLUCIÓN: Si se produce desbordamiento (supera el tamaño de double)
	
	//g)
	float chico;
	double grande;
	grande = 2e+150;
	chico = grande;
	//SOLUCIÓN: Si se produce desbordamiento, float tiene un tamaño de 32 bits y double de 64 bits
}
