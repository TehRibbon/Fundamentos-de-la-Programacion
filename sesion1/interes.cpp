/*EJERCICIO 5: Se da un valor para el capital introducido por pantalla y hay que calcular el total
aplicandole un inter�s*/

#include <iostream>
using namespace std;

int main(){
	//Declaraci�n de variables
	double capital, interes, total;
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el valor del capital a modificar: ";
	cin >> capital;
	
	cout << "\nIntroduzca el valor para el inter�s: ";
	cin >> interes;
	
	//C�lculos
	total = capital+capital*(interes/100);
	
	//Muestro el resultado por pantalla
	cout << "\nEl resultado del total es: " << total << endl;
	
	/*CUESTI�N: En la asignaci�n que calcula la variable total,�se podr�a sustituir dicha variable por capital?, es decir:
	capital = capital + capital*(interes/100)*/
	
	/*RESPUESTA: Si, podemos realizar esa asignaci�n y el resultado ser�a correcto, pero no aconsejable, ya que
	pierdes el valor inicial del capital(introducido por el usuario), y no podr�as usarlo en operaciones 
	posteriores si lo necesitase.
	Aqu� una comprobaci�n:*/
	
	capital = capital + capital * (interes/100);//El valor del capital ya no es el que introdujo el usuario
	cout << "\nEl valor para capital con la asignaci�n NO RECOMENDADA queda como: " << capital << endl;
	
	
}
