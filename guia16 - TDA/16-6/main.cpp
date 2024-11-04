#include <iostream>
#include "Fecha.h"

using namespace std;

int main()
{
	
	//b. Escribir un programa que, haciendo uso del TDA Fecha, 
	//calcule el tiempo necesario para que una cantidad depositada en un banco
	//consiga una determinada rentabilidad, 
	//ofreciendo como resultado la fecha en que se puede retirar 
	//el dinero original más la rentabilidad deseada. 
	//Suponer que el banco ofrece una tasa de interés del 0.75% 
	//a los 30 días.	
	Fecha f_init, f_retiro;
	float cant_deposit, rentab;
	
	f_init = cargarFecha(1,1,2000);
	f_retiro = f_init;
	
	cant_deposit = 10.0;
	rentab = 3.0;
	
	
	float retiro = rentab;//lo que quiere retirar el user
	float cont = 0.0; // contador hasta llegar al retiro
	
	while(cont < retiro)
	{
		
		//incremento 30 dias f_retiro
		f_retiro.mes++;//suponiendo que todos los meses tienen 30 dias
		if(f_retiro.mes > 12){
			f_retiro.mes = 1;
			f_retiro.anio++;
		}
		
		cout << cont << endl;
		cont = cont + ((cant_deposit * 0.75) / 100.00);
		
		
	}
	
	diferenciaFecha(f_retiro,f_init);
	mostrarFechaAmericana(f_init);
	mostrarFechaAmericana(f_retiro);
	
	
	//c. Escribir otro programa que permita ingresar un mes y un año
	//y que en base a estos 2 números
	//se impriman todos los días de ese mes en formato Europeo.
	
	cout << endl << endl << endl;
	cout << "INCISO B) " << endl;
	
	int mes, anio;
	cout << "mes: "; cin >> mes;
	cout << "anio: "; cin >> anio;
	
	Fecha newFecha = cargarFecha(1,mes,anio);
	
	while(esValida(newFecha))
	{
		mostrarFechaEuropea(newFecha);
		newFecha.dia++;
	}
	
	
	
	
	return 0;
}
