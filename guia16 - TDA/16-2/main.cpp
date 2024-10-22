#include <iostream>
#include "circulo.h"
#include "cuadrado.h"
#include "rectangulo.h"
#include "triangulo.h"

using namespace std;

int main(){
	
	Circulo c;
	Cuadrado cuad;
	Rectangulo r;
	Triangulo t;
	
	
	c = crear_circulo(5);
	cuad = crear_cuadrado(5.0);
	r = crear_rectangulo(20.0,5);
	t = crear_triangulo(2,1,1);
	
	
	cout << perimetro(c) << endl;
	cout << area(c) << endl << endl;
	
	cout << perimetro(cuad) << endl;
	cout << area(cuad) << endl << endl;
	
	cout << perimetro(r) << endl;
	cout << area(r) << endl << endl;
	
	cout << perimetro(t) << endl;
	cout << area(t) << endl << endl;
	
	return 0;
}
