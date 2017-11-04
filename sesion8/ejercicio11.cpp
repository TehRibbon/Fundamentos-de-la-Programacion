/*
 * Calcula el salario de un empleado de un servicio de atención telefónica
 */

/* 
 * File:   ejercicio11.cpp
 * Author: Mario Antonio López Ruiz
 *
 * Created on 14 de noviembre de 2016, 12:01
 */
#include <iostream>
using namespace std;

//Funcion que calcula el salario final del empleado
double CalculaSalarioFinal(double salario_por_hora, double segundos_trabajados, int casos_resueltos, double grado_satisfaccion){
	const int CASOS_COTA_INF = 20, CASOS_COTA_SUP = 30, A_SEGUNDOS = 3600;
	const double SATISFACCION_MINIMO = 4.0;
	const double SUBIDA_DOSP = 0.02, SUBIDA_TRESP = 0.03, SUBIDA_CUATROP = 0.04;
	double salario_inicial, salario_final;
	double horas_trabajadas;

	horas_trabajadas = segundos_trabajados/A_SEGUNDOS;

	salario_inicial = salario_por_hora*horas_trabajadas;
	salario_final = salario_inicial;

	if(casos_resueltos > CASOS_COTA_SUP)					//Si ha resuelto mas de 30 casos
		salario_final += salario_inicial*SUBIDA_CUATROP;	//Aplico 4% de subida (al salario inicial) 
	else if (casos_resueltos >= CASOS_COTA_INF)				//Si se encuentra entre 20 y 30 casos resueltos
		salario_final += salario_inicial*SUBIDA_TRESP;		//Aplico 2% de subida (al salario inicial) 

	if(grado_satisfaccion >= SATISFACCION_MINIMO)//Si la media del grado de satisfaccion es mayor o igual a 4
		salario_final += salario_inicial*SUBIDA_DOSP; //Aplico 2% de subida (al salario inicial) 

	return salario_final;
}


int main(){
	//Declaración de variables
	const int CENTINELA = -1, COTA_INF = 0, COTA_SUP_RES = 1, COTA_SUP_SATISF = 5;
	const int COD_FIRST = 1, COD_SECOND = 2, COD_THIRD = 3;
	int cod_empleado, cod_mayor_empleado, seg_llamada = 0, grado_satisfaccion = 0;
	int contador_casos = 0;
	int contador_casos1 = 0, contador_casos2 = 0, contador_casos3 = 0;
	int segundos_empleado1 = 0, segundos_empleado2 = 0, segundos_empleado3 = 0;
	double sum1 = 0, sum2 = 0, sum3 = 0;	//Sumatoria del grado de satisfaccion de cada empleado
	double salario_por_hora, mayor_media_satisf;
	double media_satisf1, media_satisf2, media_satisf3;
	double salario_final1, salario_final2, salario_final3;
	int res_satisfactoria;

	//Lectura de datos
	do{
		cout << "\nIntroduzca el salario por hora de los empleados: ";
		cin >> salario_por_hora;

	}while(salario_por_hora < COTA_INF);


	do{
		cout << "\nIntroduzca el código del empleado: ";
		cin >> cod_empleado;

		//Si se ha introducido el valor -1 no se piden mas datos
		if(cod_empleado != CENTINELA){ 
			do{
				cout << "\nIntroduzca el nº de segundos que ha durado la atención telefónica: ";
				cin >> seg_llamada;
			}while(seg_llamada < COTA_INF);

			do{
				cout << "\nIntroduzca 1 si se resolvió de formas satisfactoria, 0 en caso contrario: ";
				cin >> res_satisfactoria; 
			}while(res_satisfactoria < COTA_INF || res_satisfactoria > COTA_SUP_RES);

			do{
				cout << "\nIntroduzca el grado de satisfacción del usuario: ";
				cin >> grado_satisfaccion;
			}while(grado_satisfaccion < COTA_INF || grado_satisfaccion > COTA_SUP_SATISF);
		
			contador_casos++;
			//calculo el grado de satisfaccion de cada empleado y los segundos del total de llamadas
			if( cod_empleado == COD_FIRST){
				contador_casos1++;
				sum1 += grado_satisfaccion;
				segundos_empleado1 += seg_llamada;
			}else if( cod_empleado == COD_SECOND){
				contador_casos2++;
				sum2 += grado_satisfaccion;
				segundos_empleado2 += seg_llamada;
			}else{
				contador_casos3++;
				sum3 += grado_satisfaccion;
				segundos_empleado3 += seg_llamada;
								
			}


		}
	}while(cod_empleado != CENTINELA);

	//Calculo la media de cada empleado
	media_satisf1 = sum1/contador_casos1;
	media_satisf2 = sum2/contador_casos2;
	media_satisf3 = sum3/contador_casos3;

	//Calculo cual es la mayor media
	mayor_media_satisf = media_satisf1;
	cod_mayor_empleado = COD_FIRST;

	if(mayor_media_satisf < media_satisf2){
		cod_mayor_empleado = COD_SECOND;
		mayor_media_satisf = media_satisf2;

		if(mayor_media_satisf < media_satisf3){
			cod_mayor_empleado = COD_THIRD;
			mayor_media_satisf = media_satisf3;
		}

	}

	//Calculo el salario final de cada empleado

	salario_final1 = CalculaSalarioFinal(salario_por_hora, segundos_empleado1, contador_casos1, media_satisf1);
	salario_final2 = CalculaSalarioFinal(salario_por_hora, segundos_empleado2, contador_casos2, media_satisf2);
	salario_final3 = CalculaSalarioFinal(salario_por_hora, segundos_empleado3, contador_casos3, media_satisf3);

	//Muestro resultados por pantalla
	cout << "\n**************** RESULTADO ****************** " << endl;
		
	if(contador_casos == COTA_INF)
		cout << "\nNo se introdujo ningún caso." << endl;
	else{
		cout << "\nSalario final para el empleado 1: " << salario_final1 << endl;
		cout << "\nSalario final para el empleado 2: " << salario_final2 << endl;
		cout << "\nSalario final para el empleado 3: " << salario_final3 << endl;

		cout << "\nNúmero total de casos introducidos: " << contador_casos << endl;
		cout << "\nCódigo del empleado con mayor grado de satisfacción: " << cod_mayor_empleado << endl;
		cout << "\nGrado medio de satisfacción del empleado " << cod_mayor_empleado << ": " << mayor_media_satisf << endl;
	}
}
