/*Ejercicio 1: Indicar el resultado de las operaciones*/

#include <iostream>
using namespace std;

int main(){
	int salario_base;
	int salario_final;
	int incremento;
	
	salario_base = 1000;
	salario_final = salario_base;//salario_final no tiene valor asignado, ya que salario_base no est� inicializada.
	
	incremento = 200;
	salario_final = salario_final + incremento;//salario final valdr� 200 (se le ha sumado 200)
	
	salario_base = 3500; //salario_base se inicializa con el valor 3500
	
	cout << "\nSalario base: " << salario_base; //Se muestra el salario base (cuyo valor es 3500)
	cout << "\nSalario final: " << salario_final;//Se muestra el valor del saldo final (cuyo valor es 200)
	
	/*Responda razonadamente a la siguiente pregunta: �El hecho de realizar la asignaci�n
	salario_final = salario_base; hace que ambas variables est�n ligadas
	durante todo el programa y que cualquier modificaci�n posterior de salario_base
	afecte a salario_final?
	-RESPUESTA: No, la asignaci�n salario_final = salario_base iguala el resultado de salario_final al valor de salario_base,
		pero si desp�es modificamos el valor de salario_base, el valor de salario_final no se ve afectado, ya que esas variables 
		no est�n ligadas.		*/
}
