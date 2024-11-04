#include <iostream>
#include "Fecha.h"

using namespace std;

bool esBisiesto(int anio)
{
	bool es = false;
	
	if(anio % 4 == 0)
	{
		if(anio % 100 == 0){
			if(anio % 400 == 0)
				es = true;
		}
		else
			 es = true;
	}
	
	return es;
}

Fecha cargarFecha(int d, int m, int a)
{
	Fecha f;
	f.dia = d;
	f.mes = m;
	f.anio = a;
	
	return f;
}


int dia(Fecha f)
{
	return f.dia;
}

int mes(Fecha f)
{
	return f.mes;
}

int anio(Fecha f)
{
	return f.anio;
}

int esValida(Fecha f)
{
	if(f.anio < 0 || f .mes < 1 || f.mes > 12 || f.dia < 1 || f.dia > 31)
		return 0;
	else
	{
		int valido;
		
		switch(f.mes)
		{
			//31 dias
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: valido = 1; break;
		
		//30 dias	
		case 4:
		case 6:
		case 9: 
		case 11: if(f.dia > 30) valido = 0;
		else valido = 1; break;
		
		//28 dias || 29 dias en bisiesto
		case 2: if( (!esBisiesto(f.anio) && f.dia > 28) || (esBisiesto(f.anio) && f.dia > 29))  valido = 0;
		else valido = 1; break;
		
		}
		
		return valido;
	}
}

int diferenciaFecha(Fecha f1, Fecha f2)
{
	//f2 siempre es menor
	if(esValida(f1) and esValida(f2))
	{
		int diasTotales_1 = ((f1.anio - 1) * 365) + ((f1.mes - 1 ) *30) + f1.dia;
		int diasTotales_2 = ((f2.anio - 1) * 365) + ((f2.mes - 1 ) *30) + f2.dia;
		
		return diasTotales_1 - diasTotales_2;
	}
	else
		return -1;

}

int diaSemanaFecha(Fecha f)
{
  return 0;//sin programar
}

void mostrarFechaEuropea(Fecha f)
{
	if(esValida(f))
		cout << f.dia << "/" << f.mes << "/" << f.anio << endl;
	else
		cout << "Fecha Invalida" << endl;
}

void mostrarFechaAmericana(Fecha f)
{
	if(esValida(f))
		cout << f.mes << "/" << f.dia << "/" << f.anio << endl;
	else
		cout << "Fecha Invalida" << endl;
}
