#ifndef PILA_H
#define PILA_H
#define tope 3
struct Pila
{
	int elementos[tope];
	int tl;
};


Pila Crear(); //se crea la pila vac�a
void Apilar(Pila & p, int elemento); //se a�ade un elemento
void Desapilar(Pila & p); //Se saca un elemento
int Cima(Pila p); //devuelve el ToS
bool Vacia(Pila p); //true si est� vac�a


#endif
