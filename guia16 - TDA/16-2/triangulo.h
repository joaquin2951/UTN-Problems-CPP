#ifndef TRIANGULO_H
#define TRIANGULO_H

struct Triangulo{
	float base;
	float lado1;
	float lado2;
};

Triangulo crear_triangulo(const float base, const float lado1, const float lado2);
float perimetro(Triangulo t);
float area(Triangulo t);


#endif
