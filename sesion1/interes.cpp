/*EJERCICIO 5: Se da un valor para el capital introducido por pantalla y hay que calcular el total
aplicandole un interés*/

#include <iostream>
using namespace std;

int main(){
	//Declaración de variables
	double capital, interes, total;
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el valor del capital a modificar: ";
	cin >> capital;
	
	cout << "\nIntroduzca el valor para el interés: ";
	cin >> interes;
	
	//Cálculos
	total = capital+capital*(interes/100);
	
	//Muestro el resultado por pantalla
	cout << "\nEl resultado del total es: " << total << endl;
	
	/*CUESTIÓN: En la asignación que calcula la variable total,¿se podría sustituir dicha variable por capital?, es decir:
	capital = capital + capital*(interes/100)*/
	
	/*RESPUESTA: Si, podemos realizar esa asignación y el resultado sería correcto, pero no aconsejable, ya que
	pierdes el valor inicial del capital(introducido por el usuario), y no podrías usarlo en operaciones 
	posteriores si lo necesitase.
	Aquí una comprobación:*/
	
	capital = capital + capital * (interes/100);//El valor del capital ya no es el que introdujo el usuario
	cout << "\nEl valor para capital con la asignación NO RECOMENDADA queda como: " << capital << endl;
	
	
}
