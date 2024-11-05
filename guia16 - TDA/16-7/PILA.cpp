#include <iostream>
#include "PILA.h"

using namespace std;



Pila Crear()
{
	Pila p;
	p.tl = 0;
	return p;
} //se crea la pila vacía


void Apilar(Pila & p, int elemento)
{
	if(p.tl == tope)
		cout << "No se pueden agregar mas elementos.\n";
	else
		p.elementos[p.tl++] = elemento;
}//se añade un elemento


void Desapilar(Pila & p)
{
	if(Vacia(p))
		cout << "No se pueden quitar mas elementos.\n";
	else
		p.tl--;
}//Se saca un elemento


int Cima(Pila p)
{
	return p.elementos[p.tl-1];
}//devuelve el ToS


bool Vacia(Pila p)
{
	if(p.tl == 0) return true;
	return false;
}//true si está vacía
