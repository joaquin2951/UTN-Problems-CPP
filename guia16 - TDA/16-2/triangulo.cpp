#include "triangulo.h"
#include <cmath>
using namespace std;


Triangulo crear_triangulo(const float base, const float lado1, const float lado2){
	Triangulo t;
	t.base = base; t.lado1 = lado1; t.lado2 = lado2;
	return t;
}
	
float perimetro(Triangulo t){
	return t.base + t.lado1 + t.lado2;
}
	
float area(Triangulo t){
	
	
	return (t.base * t.lado1) / 2.0;
}
