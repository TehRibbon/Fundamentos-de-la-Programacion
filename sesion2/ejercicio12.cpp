/*Autor: Mario Antonio L�pez Ruiz    ~  1�D*/
/*EJERCICIO 12:Estudiar una poblaci�n para 3 a�os aplicando una tasa de mortalidad, migracion y natalidad introducidas por el usuario*/
#include <iostream>
using namespace std;

int main(){
	//Declaracion de variables
	int poblacion_inicial, poblacion_resultado;
	int tasa_natalidad, tasa_mortalidad, tasa_migracion;
	int aux_natalidad, aux_mortalidad, aux_migracion;//Aqui guardaremos la poblacion tras aplicar las tasas
	
	//Peticiones por pantalla
	cout << "\nIntroduzca el valor para la poblaci�n inicial: ";
	cin >> poblacion_inicial;
	
	cout << "\nIntroduzca el valor para la tasa de natalidad: ";
	cin >> tasa_natalidad;
	
	cout << "\nIntroduzca el valor para la tasa de mortalidad: ";
	cin >> tasa_mortalidad;
	
	//Con la migraci�n hay un problema y es que puede ser positiva o negativa, y de la forma que indica el ejercicio no tenemos forma de saber que signo tiene
	//(la he tomado como positiva en todos los casos)
	cout << "\nIntroduzca el valor para la tasa de migraci�n: " ;
	cin >> tasa_migracion;
	
	//Hay que tener en cuenta que la tasa es una raz�n total por cada mil (x por cada 1000 habitantes)
	//Calculamos las tasas teniendo en cuenta que la tasa es una raz�n total por cada mil (x por cada mil habitantes)
	aux_natalidad = (tasa_natalidad * poblacion_inicial) / 1000;
	aux_mortalidad = (tasa_mortalidad * poblacion_inicial) / 1000;
	aux_migracion = (tasa_migracion * poblacion_inicial) / 1000;
	
	//Aplicamos los cambios en esa poblacion (1er a�o) -> Tal y como viene indicado en el ejercicio no se puede saber si la migracion es positiva o negativa
	poblacion_resultado = poblacion_inicial + aux_natalidad - aux_mortalidad + aux_migracion;
	
	//Tenemos que volver a aplicarlo para los dos siguientes a�os con la poblacion cambiada
	//AVISO: SE EST� REPITIENDO C�DIGO -> ineficiente
	//Con el uso de funciones no se repetir�a c�digo
	aux_natalidad = (tasa_natalidad * poblacion_resultado) / 1000;
	aux_mortalidad = (tasa_mortalidad * poblacion_resultado) / 1000;
	aux_migracion = (tasa_migracion * poblacion_resultado) / 1000;
	
	poblacion_resultado = poblacion_inicial + aux_natalidad - aux_mortalidad + aux_migracion;
	
	aux_natalidad = (tasa_natalidad * poblacion_resultado) / 1000;
	aux_mortalidad = (tasa_mortalidad * poblacion_resultado) / 1000;
	aux_migracion = (tasa_migracion * poblacion_resultado) / 1000;
	
	poblacion_resultado = poblacion_inicial + aux_natalidad - aux_mortalidad + aux_migracion;
	
	//Muestro el resultado por pantalla
	cout << "\nEl resultado para la poblaci�n tras aplicar las diferentes tasas es: " << poblacion_resultado << endl;
	
	}
