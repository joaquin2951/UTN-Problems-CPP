#ifndef RECTANGULO_H
#define RECTANGULO_H

struct Rectangulo{
	float base;
	float altura;
};

Rectangulo crear_rectangulo(const float base, const float altura);
float perimetro(Rectangulo r);
float area(Rectangulo r);
#endif
