#include "Cuadrado.h"


Cuadrado crear_cuadrado(const float lado){
	Cuadrado c;  c.lado = lado;
	return c;
}
	
float perimetro(Cuadrado c){
	return 4.0*c.lado;
}
	
float area(Cuadrado c){
	return c.lado * c.lado;
}
