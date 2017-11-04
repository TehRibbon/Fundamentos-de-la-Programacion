//EJERCICIO 24:Intercambio de 3 variables leidas desde teclado
#include <iostream>
using namespace std;
int main(){
	//Declaracion de variables
	int x, y ,z;
	int auxiliar;
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el valor de x: " ;
	cin >> x;
	
	cout << "\nIntroduzca el valor de y: " ;
	cin >> y;
	
	cout << "\nIntroduzca el valor de z: ";
	cin >> z;
	
	//Intercambio las variables
	auxiliar = z;
	z = y;
	y = x;
	x = auxiliar;
	
	//Muestro el resultado por pantalla
	cout << "\nEl nuevo valor de x es: " << x;
	cout << "\nEl nuevo valor de y es: " << y;
	cout << "\nEl nuevo valor de z es: " << z;
}
