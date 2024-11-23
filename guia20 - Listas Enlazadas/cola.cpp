#include <iostream>
using namespace std;

struct Cola
{
	int info;
	struct Cola * siguiente;
};

typedef Cola * ColaPtr;


void push(ColaPtr * c, int valor);
void pop(ColaPtr * c);
void verCola(ColaPtr c);


int main(int argc, char *argv[]) {
		
	ColaPtr c = NULL;
	
	push(&c,2);
	push(&c,5);
	
	verCola(c);
	
	pop(&c);
	pop(&c);
	pop(&c);
	
	verCola(c);
	
	cout << endl << endl;
	
	push(&c,1);
	push(&c,37);
	push(&c,55);
	push(&c,543);
	push(&c,21);
	push(&c,2);
	push(&c,5);
	
	verCola(c);
	
	return 0;
}


void push(ColaPtr * c, int valor)
{
	//inserto por orden de llegada, o sea, una insercion normal
	ColaPtr actual;
	ColaPtr nuevo;
	ColaPtr anterior;
	
	if( (nuevo = new Cola) == NULL ) cout << "no hay memoria." << endl;
	else
	{
		nuevo->info = valor;
		nuevo->siguiente = NULL;
		
		anterior = NULL;
		actual = *c;
		
		while(actual != NULL)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(anterior == NULL)
			*c = nuevo;
		else
			anterior->siguiente = nuevo;

	}
	
}

void pop(ColaPtr * c)
{
	//saco el primer elemento que llegó a la cola
	if(*c != NULL){
	ColaPtr temp;
	temp = *c;
	*c = (*c)->siguiente;
	delete temp;
	}
	else
		 cout << "COLA VACIA" << endl;
	
}

void verCola(ColaPtr c)
{
	//veo la cola desde el primero hasta el ultimo
	if(c != NULL)
	{
		cout << "PRIMERO EN LLEGAR -> ";
		while(c != NULL)
		{
			cout << c->info << " --> ";
			c = c->siguiente;
		}
		cout << "FIN COLA" << endl;
	}
	else
		 cout << "COLA VACIA." << endl;
	
}
