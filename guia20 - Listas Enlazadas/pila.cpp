#include <iostream>
using namespace std;


struct Pila
{
	float info;
	struct Pila * siguiente;
};

typedef Pila * PilaPtr;


void verPila(PilaPtr p);
void topOfStack(PilaPtr p);
void push(PilaPtr * p, float valor);
void pop(PilaPtr * p);


int main(int argc, char *argv[]) {

	
	PilaPtr p = NULL;
	
	push(&p,4.0);
	push(&p,7.3);
	
	verPila(p);
	
	pop(&p);
	pop(&p);
	pop(&p);
	
	verPila(p);
	
	cout << endl << "---------" << endl;
	
	push(&p,-23.7);
	push(&p,9.4);
	push(&p,10.9);
	push(&p,99.32);
	push(&p,233.0);
	
	verPila(p);
	
	pop(&p);
	
	verPila(p);
	
	topOfStack(p);
	return 0;
}


void verPila(PilaPtr p)//lo ves desde el ultimo elemento insertado hasta el primero
{
	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->siguiente;
	}
	cout << "NULL" << endl;
}

void topOfStack(PilaPtr p)
{
	cout << "ToS: " << p->info << endl;
}

void push(PilaPtr * p, float valor)
{
	//siempre insertamos en la primera posicion
	PilaPtr nuevo;
	if( (nuevo = new Pila) == NULL) cout << "no hay memoria" << endl;
	else
	{
		
		
		
		PilaPtr aux;
		aux = *p;
		*p = nuevo;
		
		nuevo->info = valor;
		nuevo->siguiente = aux;
		
	}
	
	
}

void pop(PilaPtr * p)
{
	
	if(*p != NULL)// si no esta vacia
	{
		PilaPtr aux;
		aux = *p;
		*p = (*p)->siguiente;
		delete aux;
	}
	else
		 cout << "pila vacia" << endl;
	
}
