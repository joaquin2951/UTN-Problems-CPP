#ifndef PILA_H
#define PILA_H
#define tope 3
struct Pila
{
	int elementos[tope];
	int tl;
};


Pila Crear(); //se crea la pila vacía
void Apilar(Pila & p, int elemento); //se añade un elemento
void Desapilar(Pila & p); //Se saca un elemento
int Cima(Pila p); //devuelve el ToS
bool Vacia(Pila p); //true si está vacía


#endif
