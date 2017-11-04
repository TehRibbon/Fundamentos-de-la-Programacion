/* Dado el precio de un art�culo se le aplica un porcentaje y se calcula el precio final
*/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos

using namespace std; 

int main(){                   //Programa Principal
   double precio_inicial;		//Precio del art�culo
   double precio_final;			//Precio tras aplicarle el porcentaje
   const double IVA = 0.15;	//Porcentaje a aplicarle al precio del articulo
   
   cout << " Introduzca el precio del art�culo: "; //Solicitamos introducir dato por pantalla(precio del art�culo
   cin >> precio_inicial;
   
   precio_final = precio_inicial - precio_inicial*IVA; //Calculo el valor del precio final
   
   cout << "\nEl precio final tras aplicarle el 21% de IVA es: " << precio_final << endl; //Mostramos el resultado por pantalla
   
   system("pause");
}
