#include "rectangulo.h"



Rectangulo crear_rectangulo(const float base, const float altura){
 Rectangulo r;
 r.base = base;  r.altura = altura;
 
 return r;
}

float perimetro(Rectangulo r){
	return (2.0 * r.base) + (2.0 * r.altura);
}
	
float area(Rectangulo r){
	return r.base * r.altura;
}
