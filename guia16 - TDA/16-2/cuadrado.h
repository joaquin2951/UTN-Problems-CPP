#ifndef CUADRADO_H
#define CUADRADO_H

struct Cuadrado{
	float lado;
};

Cuadrado crear_cuadrado(const float lado);
float perimetro(Cuadrado c);
float area(Cuadrado c);

#endif
