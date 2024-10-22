#include "circulo.h"

#define PI 3.14

Circulo crear_circulo(const float radio){
	Circulo c;
	c.radio = radio;
	return c;
}
	
	
float perimetro(Circulo c){
	return (2.0 * c.radio * PI);
}
	
float area(Circulo c){
	return (PI * c.radio * c.radio);
}
