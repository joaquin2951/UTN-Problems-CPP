#ifndef CIRCULO_H
#define CIRCULO_H
struct Circulo{
	float radio;
};

Circulo crear_circulo(const float radio);
float perimetro(Circulo c);
float area(Circulo c);


#endif
